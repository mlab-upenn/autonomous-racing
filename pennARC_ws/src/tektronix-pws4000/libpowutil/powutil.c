#define _BSD_SOURCE

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <time.h>
#include <sys/time.h>

#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <pthread.h>
#include "parsec_barrier.h"

#define ERROR_CHECK(x) {int r = x; if (r) perror(#x);}
#define TRUE 1
#define FALSE 0

static const uint64_t BILLION = 1000000000;
static const uint64_t MILLION = 1000000;

// Tektronix PWS 4000 series power supply commands
static const char* MEASURE_VOLTAGE = "MEAS:VOLT?";
static const char* MEASURE_CURRENT = "MEAS:CURR?";
static const char* HELLO = "*IDN?";

static int PowerSupply_fd = -1;
static int Log_fd = -1;
static uint32_t PollingInterval_ms = 50;

static pthread_t BackgroundThread;
static pthread_barrier_t Barrier;
static pthread_mutex_t DoMeasurementLock = PTHREAD_MUTEX_INITIALIZER;

static uint64_t get_us(struct timeval* tval) {
  return (tval->tv_sec * MILLION) + tval->tv_usec;
}

static uint64_t interval(struct timeval* start, struct timeval* end) {
  uint64_t elapsed = 0;
  if ((end->tv_usec - start->tv_usec)<0) {
    elapsed = (end->tv_sec - start->tv_sec - 1) * MILLION;
    elapsed += MILLION + end->tv_usec - start->tv_usec;
  } else {
    elapsed = (end->tv_sec - start->tv_sec) * MILLION;
    elapsed += end->tv_usec - start->tv_usec;
  }
  return elapsed;
}

static double readCurrent() {

  const char* msg = MEASURE_CURRENT;
  const int msg_len = strlen(msg);

  char current[64];
  current[0] = '\0'; // clear current
  
  const ssize_t bytesWritten = write(PowerSupply_fd, msg, msg_len);
  if ( bytesWritten < 0 ) {
    perror("write");
  }
  
  const ssize_t bytesRead = read(PowerSupply_fd, current, sizeof(current));
  if ( bytesRead < 0 ) {
    printf("errno=%d sizeof(current)=%d\n", errno, sizeof(current));
    perror("read");
  }
  
  current[bytesRead-1] = '\0'; // response from power supply doesn't have a trailing NUL
  
  char* errPtr;
  double amps = strtod(current, &errPtr);
  if ( errPtr == current ) { // error occurred
    perror("strtod");
  }

  return amps;
}

static uint64_t cpuStateTimes[2][10];
static const int USER = 0;
static const int NICE = 1;
static const int SYSTEM = 2;
static const int IDLE = 3;
static const int IOWAIT = 4;
static const int IRQ = 5;
static const int SOFTIRQ = 6;
static const int STEAL = 7;
static const int GUEST = 8;
static const int GUEST_NICE = 9;

static int currentSlots = 0;

static void printCpuStates(uint64_t arr[10]) {
  for (int i = 0; i < 10; i++) {
    printf("%llu ", arr[i]);
  }
  printf("\n");
}

static void parseCpuStateTimes(char* times, uint64_t output[10]) {
  for (int i = 0; i < 10; i++) {
    char* endptr;
    errno = 0; // to be able to tell when strtoll() fails
    uint64_t t = strtoll(times, &endptr, 10);

    if ((errno == ERANGE && (t == LONG_MAX || t == LONG_MIN))
        || (errno != 0 && t == 0)) {
      perror("strtol");
      assert(FALSE);
    }

    output[i] = t;
    //printf("parsed time: %llu\n", t);
    times = endptr;
  }
}

static double computeCpuUtilization(uint64_t curr[10], uint64_t prev[10]) {
  // NB: we ignore GUEST and GUEST_NICE since we aren't in a virtualized environment
  // hat tip to http://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in-percentage-in-linux for this code
  uint64_t PrevIdle = prev[IDLE] + prev[IOWAIT];
  uint64_t CurrIdle = curr[IDLE] + curr[IOWAIT];
  uint64_t PrevNonIdle = prev[USER] + prev[NICE] + prev[SYSTEM] + prev[IRQ] + prev[SOFTIRQ] + prev[STEAL];
  uint64_t CurrNonIdle = curr[USER] + curr[NICE] + curr[SYSTEM] + curr[IRQ] + curr[SOFTIRQ] + curr[STEAL];
  uint64_t PrevTotal = PrevIdle + PrevNonIdle;
  uint64_t CurrTotal = CurrIdle + CurrNonIdle;

  if (CurrTotal > PrevTotal) {
    double CPU_Percentage = ((CurrTotal-PrevTotal) - (CurrIdle-PrevIdle)) / (double) (CurrTotal-PrevTotal);
    return CPU_Percentage; 
  } else { // avoid divide-by-0
    return -1.0;
  }
}

static double readCpuUtilization() {

    char statBuf[256];
    
    int cpufd = open("/proc/stat", O_RDONLY);
    assert( cpufd >= 0 );

    const ssize_t bytesRead = read(cpufd, statBuf, sizeof(statBuf)-1);
    if ( bytesRead < 0 ) {
      printf("errno=%d sizeof(statBuf)=%d\n", errno, sizeof(statBuf));
      perror("read cpufd");
    }

    statBuf[bytesRead] = '\0';
    //printf("statBuf: %s\n", statBuf);

    ERROR_CHECK( close(cpufd); )

    parseCpuStateTimes(statBuf+3/*skip "cpu" prefix*/, cpuStateTimes[currentSlots]);
    //printCpuStates(cpuStateTimes[currentSlots]);
    //printCpuStates(cpuStateTimes[!currentSlots]);
    double cpuUtil = computeCpuUtilization(cpuStateTimes[currentSlots], cpuStateTimes[!currentSlots]);
    currentSlots = !currentSlots;
    return cpuUtil;
}

static void* poll(void* _) {

  // check in with main thread's setup()
  int r = pthread_barrier_wait(&Barrier);
  if ( r != 0 && r != PTHREAD_BARRIER_SERIAL_THREAD ) {
    perror("pthread_barrier_wait in setup()");
  }

  struct timeval start; //, end;
  const int BUFSIZE = 256;
  char buf[BUFSIZE];

  while (TRUE) {

    // if we get blocked on the lock, we shouldn't be measuring anymore
    ERROR_CHECK( pthread_mutex_lock( &DoMeasurementLock ); )
    ERROR_CHECK( pthread_mutex_unlock( &DoMeasurementLock ); )

    gettimeofday(&start, NULL);
    double amps = readCurrent();
    //gettimeofday(&end, NULL);

    //const uint64_t currentMeasurement_us = interval(&start, &end);

    //gettimeofday(&start, NULL);
    double cpuUtil = readCpuUtilization();
    //gettimeofday(&end, NULL);

    //const uint64_t cpuMeasurement_us = interval(&start, &end);

    int bytesWritten = snprintf(buf, BUFSIZE, "%f amps, %f cpuutil, %llu\n", amps, cpuUtil, get_us(&start));
    bytesWritten = write(Log_fd, buf, bytesWritten);
    if ( bytesWritten < 0 ) {
      perror("log write() in poll");
    }

    //printf("USER_HZ = %ld\n", sysconf(_SC_CLK_TCK));

    usleep( 1000 * PollingInterval_ms );
  } // end while(TRUE)

  return NULL;
}

// below: public API

int setup(const char* log, unsigned int pollingInterval_ms) {
  PollingInterval_ms = pollingInterval_ms;

  PowerSupply_fd = open("/dev/usbtmc0", O_RDWR);
  assert( PowerSupply_fd >= 0 );
  
  Log_fd = open(log, O_WRONLY | O_CREAT | O_APPEND, 0662);
  assert( Log_fd >= 0 );

  // fill in cpuStateTimes[currentSlot] for future comparison
  readCpuUtilization();

  ERROR_CHECK( pthread_barrier_init(&Barrier, NULL, 2); );
  // don't have background thread measure yet
  ERROR_CHECK( pthread_mutex_unlock( &DoMeasurementLock ); )

  // fork background thread to do the polling
  ERROR_CHECK( pthread_create(&BackgroundThread, NULL, poll, NULL); )

  // barrier with background thread
  int r = pthread_barrier_wait(&Barrier);
  if ( r != 0 && r != PTHREAD_BARRIER_SERIAL_THREAD ) {
    perror("pthread_barrier_wait in setup()");
  }

  // background thread is up and running now

  return 0;
}

void startMeasuring() {
  // background thread is blocked on this lock, tell it to start measuring by unlocking it
  ERROR_CHECK( pthread_mutex_unlock( &DoMeasurementLock ); )
}

void stopMeasuring() {
  // tell background thread to stop measuring
  ERROR_CHECK( pthread_mutex_lock( &DoMeasurementLock ); )
}

int teardown() {
  
  // tell background thread to stop running
  ERROR_CHECK( pthread_cancel(BackgroundThread) );

  // join with background thread
  ERROR_CHECK( pthread_join(BackgroundThread, NULL); );

  ERROR_CHECK( close(PowerSupply_fd); )

  return 0;
}

