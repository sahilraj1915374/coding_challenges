#include "wc.h"

void wc :: validateAndEvaluate( int argc, char * argv[] )
{
  validate( argc, ACCEPTED_ARGUMENTS );
  validate( strlen(argv[1]), ACCEPTED_OPTION_LENGTH );
  evaluate( argv[1][1], argv[2] );
}

void wc :: validate( int leftOperand, int rightOperand )
{
  if( leftOperand != rightOperand )
  {
    printUsage();
    exit( EXIT_FAILURE );
  }
}

void wc :: printUsage()
{
  std::cerr 
    << "Usage : ccwc [options] [file-name]" << std::endl;

  std::cerr 
    << "\n\t[options]" << "\n"
    << "\tc : number of bytes" << std::endl;
}

void wc :: evaluate( char option, char * fileName )
{
  switch( option )
  {
    case 'c' : 
      {
        size_t value = 0;
        evaluateNoOfBytes( fileName, value );
        printValue( value, fileName );
      }
      break;
    case 'l' :
      {
        size_t value = 0;
        evaluateNoOfLines( fileName, value );
        printValue( value, fileName );
      }
      break;
    case 'w' :
      {
        size_t value = 0;
        evaluateNoOfWords( fileName, value );
        printValue( value, fileName );
      }
      break;

    default : printUsage();
  }
}

void wc :: evaluateNoOfBytes( char * fileName, size_t & value )
{
  std::ifstream file( fileName );

  if( !file.is_open() )
  {
    std::cerr 
      << "Error opening file" << std::endl;

    exit( EXIT_FAILURE );
  }

  char ch;
  while( file.get(ch) )
  {
    ++value;
  }
}

void wc :: evaluateNoOfLines( char * fileName, size_t & value )
{
  std::ifstream file( fileName );

  if( !file.is_open() )
  {
    std::cerr 
      << "Error opening file" << std::endl;

    exit( EXIT_FAILURE );
  }

  char ch;
  while( file.get(ch) )
  {
    if( ch == '\n' )
    {
      ++value;
    }
  }
}

void wc :: evaluateNoOfWords( char * fileName, size_t & value )
{
  std::ifstream file( fileName );

  if( !file.is_open() )
  {
    std::cerr 
      << "Error opening file" << std::endl;

    exit( EXIT_FAILURE );
  }

  char ch;
  bool isWordFound = false;
  while( file.get(ch) )
  {
    if( isspace(ch) )
    {
      if( isWordFound )
      {
        ++value;
        isWordFound = false;
      }
    }
    else
    {
      isWordFound = true;
    }
  }

  if( isWordFound )
  {
    ++value;
  }
}

void wc :: printValue( size_t value, char * fileName )
{
  std::cout 
    << value << " "
    << fileName << std::endl;
}
