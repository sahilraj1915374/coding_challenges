#pragma once
#include <iostream>
#include <string.h>
#include <fstream>

#define ACCEPTED_ARGUMENTS 3
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
    void validate( int leftOperand, int rightOperand );
    void evaluate( char option, char * fileName );
    void evaluateNoOfBytes( char * fileName , size_t & value );
    void evaluateNoOfLines( char * fileName , size_t & value );
    void evaluateNoOfWords( char * fileName , size_t & value );
    void printValue( size_t value, char * fileName );
};
