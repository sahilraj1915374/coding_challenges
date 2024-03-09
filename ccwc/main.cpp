#include "wc/wc.h"

int main( int argc, char * argv[] )
{
  wc::getInstance().validateAndEvaluate( argc, argv );
  return EXIT_SUCCESS;
}
