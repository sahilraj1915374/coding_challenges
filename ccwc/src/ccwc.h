#include <iostream>
#include <unistd.h>

class ccwc
{
  public:
    /*
     * @brief ccwc : construtor
     */
    ccwc();
    
    /*
     * @brief parseOptions  : parses the options and arguments
     * @param int argc      : argument count
     * @param char * argv[] : arguement vector
     */
    void parseOptions(int argc, char* argv[]);

    /*
     * @brief evaluateOptions : evalutes the provided option
     */
    void evaluateOptions();

    /*
     * @brief ~ccwc destructor
     */
    ~ccwc();
  
  private:
    /*
     * @brief evaluateNoOfBytes : evaluates number of bytes
     */
    void evaluateNoOfBytes();

    /*
     * @brief evaluateNoOfLines : evaluates number of lines 
     */
    void evaluateNoOfLines();

    /*
     * @brief evaluateNoOfWords : evaluates number of words
     */
    void evaluateNoOfWords();

    /*
     * @brief evaluateNoOfChars : evaluates number of characters
     */
    void evaluateNoOfChars();

    /*
     * @brief printUsage : prints usage of the program
     */
    void printUsage();

    /*
     * @brief printFileName : prints provided filename
     */
    void printFileName();
    
    /*
     * @brief cflag : for -c
     */
    bool cflag;
    /*
     * @brief lflag : for -l
     */
    bool lflag;
    /*
     * @brief wflag : for -w
     */
    bool wflag;
    /*
     * @brief mflag : for -m
     */
    bool mflag;
    /*
     * @brief fileName : for provided file name
     */
    char* fileName;
};
