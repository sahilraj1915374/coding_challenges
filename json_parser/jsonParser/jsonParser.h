#pragma once

enum Tokens
{
  LEFT_BRACE,
  RIGHT_BRACE,
  LEFT_BRACKET,
  RIGHT_BRACKET,
  COLON,
  COMMA,
  STRING,
  NUMBER,
  BOOLEAN,
  NULL
};

class JsonParser
{
  public: 
    void tokenize();
    void parse();

  private:
    struct TokenData
    {
      Tokens token;
      char * value;
    };
};
