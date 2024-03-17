#include "ccwc.h"

ccwc::ccwc() : 
  cflag(false),
  lflag(false),
  wflag(false),
  mflag(false),
  fileName(nullptr)
{
}

void ccwc::parseOptions(int argc, char* argv[])
{
  int opt;
  const char* optstring = "-clwm";
  
  while((opt = getopt(argc, argv, optstring)) != EOF)
  {
    switch(opt)
    {
      case 'c' : cflag = true;
        break;
      case 'l' : lflag = true;
        break;
      case 'w' : wflag = true;
        break;
      case 'm' : mflag = true;
        break;
      case  1  : fileName = optarg;
        break;
      case '?' :
      default  : 
        {
          printUsage();
          exit(EXIT_FAILURE);
        }
        break;
    }
  }

  //for step 5
  if(fileName && argc == 2)
  {
    cflag = lflag = wflag = true;
  }
}

void ccwc::evaluateOptions()
{
  if(cflag) evaluateNoOfBytes();
  if(lflag) evaluateNoOfLines();
  if(wflag) evaluateNoOfWords();
  if(mflag) evaluateNoOfChars();
  
  printFileName();
}

void ccwc::evaluateNoOfBytes()
{
  size_t value = 0;
  FILE* fp = (fileName) ? fopen(fileName,"r") : stdin;
  
  if(fp == nullptr)
  {
    std::cerr 
      << "Error reading from input" << std::endl;

    exit(EXIT_FAILURE);
  }

  char ch = fgetc(fp);
  while(ch != EOF)
  {
    ++value;
    ch = fgetc(fp);
  }

  std::cout << value << " ";
}

void ccwc::evaluateNoOfLines()
{
  size_t value = 0;
  FILE* fp = (fileName) ? fopen(fileName,"r") : stdin;

  if(fp == nullptr)
  {
    std::cerr 
      << "Error reading from input" << std::endl;

    exit(EXIT_FAILURE);
  }

  char ch = fgetc(fp);
  while(ch != EOF)
  {
    if(ch == '\n')
    {
      ++value;
    }
    ch = fgetc(fp);
  }
  
  std::cout << value << " ";
}

void ccwc::evaluateNoOfWords()
{
  size_t value = 0;
  FILE* fp = (fileName) ? fopen(fileName,"r") : stdin;

  if(fp == nullptr)
  {
    std::cerr 
      << "Error reading from input" << std::endl;

    exit(EXIT_FAILURE);
  }

  char ch = fgetc(fp);
  bool isWordFound = false;
  while(ch != EOF)
  {
    if(isspace(ch))
    {
      if(isWordFound)
      {
        ++value;
        isWordFound = false;
      }
    }
    else
    {
      isWordFound = true;
    }
    ch = fgetc(fp);
  }

  if(isWordFound)
  {
    ++value;
  }

  std::cout << value << " ";
}

void ccwc::evaluateNoOfChars()
{
  size_t value = 0;
  FILE* fp = (fileName) ? fopen(fileName,"r") : stdin;

  if(fp == nullptr)
  {
    std::cerr 
      << "Error reading from input" << std::endl;

    exit( EXIT_FAILURE );
  }

  setlocale(LC_CTYPE, "C.utf8");

  wchar_t ch = fgetwc(fp);
  while(ch != WEOF)
  {
    ++value;
    ch = fgetwc(fp);
  }

  std::cout << value << " ";
}

void ccwc::printUsage()
{
  std::cout << "Usage: ccwc [option] [filename]" << std::endl;
  std::cout
    << "\t[options]" << "\n"
    << "\tc : number of bytes" << "\n" 
    << "\tl : number of lines" << "\n" 
    << "\tw : number of words" << "\n" 
    << "\tm : number of characters" << std::endl;
}

void ccwc::printFileName()
{
  std::cout << fileName << std::endl;
}

ccwc::~ccwc()
{
}
