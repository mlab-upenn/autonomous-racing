#ifndef __POWUTIL_H_
#define __POWUTIL_H_ 1

/** Setup power and utilization in a background thread.
    @param log name of file to log measurements to
    @param pollingInterval_ms time to wait between measurements, in milliseconds
 */
int setup(const char* log, unsigned int pollingInterval_ms);

/** Start taking measurements and logging them. Requires that setup() has been called. */
void startMeasuring();

/** Stop taking measurements */
void stopMeasuring();

/** Clean up. Requires that stopMeasuring() has been called first. */
int teardown();

#endif
