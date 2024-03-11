#include "wc.h"

void wc :: validateAndEvaluate( int argc, char * argv[] )
{
  if( argc == ARGS_WITH_OPTION )
  {
    checkOptionsAndEvaluate( argv );
  }
  else if( argc == ARGS_WITHOUT_OPTION )
  {
    evaluate( argv );
  }
  else
  {
    printUsage();
  }
}

void wc :: checkOptionsAndEvaluate( char * argv[] )
{
  if( strlen(argv[1]) != ACCEPTED_OPTION_LENGTH )
  {
    printUsage();
    exit( EXIT_FAILURE );
  }
  
  evaluate( argv[1][1]/*option*/, argv[2]/*filename*/ );
}

void wc :: printUsage()
{
  std::cerr 
    << "Usage : ccwc [options] [file-name]" << std::endl;

  std::cerr 
    << "\n\t[options]" << "\n"
    << "\tc : number of bytes" << "\n" 
    << "\tl : number of lines" << "\n" 
    << "\tw : number of words" << "\n" 
    << "\tm : number of characters" << std::endl;
}

void wc :: evaluate( char * argv[] )
{
  size_t lines = 0, words = 0, bytes = 0; 
  evaluateNoOfLines( argv[1], lines );
  evaluateNoOfWords( argv[1], words );
  evaluateNoOfBytes( argv[1], bytes );
  printValue( lines, words, bytes, argv[1] );
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
    case 'm' :
      {
        size_t value = 0;
        evaluateNoOfChars( fileName, value );
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

void wc :: evaluateNoOfChars( char * fileName, size_t & value )
{
  FILE* file = fopen( fileName , "r" );
  if( file == nullptr )
  {
    std::cerr 
      << "Error opening file" << std::endl;

    exit( EXIT_FAILURE );
  }

  setlocale(LC_CTYPE, "C.utf8");

  wchar_t ch = fgetwc(file);
  while( ch  != WEOF )
  {
    ++value;
    ch = fgetwc(file);
  }
}

void wc :: printValue( size_t value, char * fileName )
{
  std::cout 
    << value << " "
    << fileName << std::endl;
}

void wc :: printValue( size_t bytes, size_t lines, size_t words, char * fileName )
{
  std::cout 
    << bytes << " "
    << lines << " "
    << words << " "
    << fileName << std::endl;
}
