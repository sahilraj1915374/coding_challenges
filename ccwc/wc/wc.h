#pragma once
#include <iostream>
#include <string.h>
#include <fstream>

#define ARGS_WITH_OPTION 3
#define ARGS_WITHOUT_OPTION 2 
#define ACCEPTED_OPTION_LENGTH 2

class wc
{
  public:
    static wc getInstance()
    {
      wc instance;
      return instance;
    }

    void validateAndEvaluate( int argc, char * argv[] );

  private:
    void printUsage();
    void checkOptionsAndEvaluate( char * argv[] );
    void evaluate( char option, char * fileName );
    void evaluate( char * argv[] );
    void evaluateNoOfBytes( char * fileName , size_t & value );
    void evaluateNoOfLines( char * fileName , size_t & value );
    void evaluateNoOfWords( char * fileName , size_t & value );
    void evaluateNoOfChars( char * fileName , size_t & value );
    void printValue( size_t value, char * fileName );
    void printValue( size_t lines, size_t words, size_t bytes, char * fileName );
};
