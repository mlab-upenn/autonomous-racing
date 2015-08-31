#include <unistd.h>
#include "powutil.h"

int main(int argc, char* argv[]) {

  setup("log.times", 100);

  startMeasuring();
  sleep( 1/*seconds*/ );
  stopMeasuring();

  sleep( 2 );

  startMeasuring();
  sleep( 1/*seconds*/ );
  stopMeasuring();

  teardown();

  return 0;
}
