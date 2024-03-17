#include "src/ccwc.h"

int main( int argc, char * argv[] )
{
  ccwc obj;

  obj.parseOptions(argc, argv);
  obj.evaluateOptions();

  return EXIT_SUCCESS;
}
