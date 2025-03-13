
// Generated from SysY.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  SysYLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, Identifier = 12, Integer_const = 13, 
    Boolean_const = 14, Float_const = 15, LeftParen = 16, RightParen = 17, 
    LeftBracket = 18, RightBracket = 19, LeftBrace = 20, RightBrace = 21, 
    Less = 22, LessEqual = 23, Greater = 24, GreaterEqual = 25, Plus = 26, 
    Minus = 27, Star = 28, Div = 29, Mod = 30, And = 31, Or = 32, Not = 33, 
    Colon = 34, Semi = 35, Comma = 36, Assign = 37, Equal = 38, NotEqual = 39, 
    Whitespace = 40, Newline = 41, BlockComment = 42, LineComment = 43
  };

  explicit SysYLexer(antlr4::CharStream *input);

  ~SysYLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

