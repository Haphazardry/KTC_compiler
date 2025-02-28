
// Generated from C.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  CLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, Auto = 17, Break = 18, Case = 19, Char = 20, 
    Const = 21, Continue = 22, Default = 23, Do = 24, Double = 25, Else = 26, 
    Enum = 27, Extern = 28, Float = 29, For = 30, Goto = 31, If = 32, Breakpoint = 33, 
    Inline = 34, Int = 35, Long = 36, Register = 37, Restrict = 38, Return = 39, 
    Short = 40, Signed = 41, Sizeof = 42, Static = 43, Struct = 44, Switch = 45, 
    Typedef = 46, Union = 47, Unsigned = 48, Void = 49, Volatile = 50, While = 51, 
    Alignas = 52, Alignof = 53, Atomic = 54, Bool = 55, Complex = 56, Generic = 57, 
    Imaginary = 58, Noreturn = 59, StaticAssert = 60, ThreadLocal = 61, 
    LeftParen = 62, RightParen = 63, LeftBracket = 64, RightBracket = 65, 
    LeftBrace = 66, RightBrace = 67, Less = 68, LessEqual = 69, Greater = 70, 
    GreaterEqual = 71, LeftShift = 72, RightShift = 73, Plus = 74, PlusPlus = 75, 
    Minus = 76, MinusMinus = 77, Star = 78, Div = 79, Mod = 80, And = 81, 
    Or = 82, AndAnd = 83, OrOr = 84, Caret = 85, Not = 86, Tilde = 87, Question = 88, 
    Colon = 89, Semi = 90, Comma = 91, Assign = 92, MulAssign = 93, DivAssign = 94, 
    ModAssign = 95, PlusAssign = 96, MinusAssign = 97, LeftShiftAssign = 98, 
    RightShiftAssign = 99, AndAssign = 100, XorAssign = 101, OrAssign = 102, 
    Equal = 103, NotEqual = 104, Arrow = 105, Dot = 106, Ellipsis = 107, 
    Identifier = 108, Constant = 109, DigitSequence = 110, StringLiteral = 111, 
    MultiLineMacro = 112, Directive = 113, AsmBlock = 114, Whitespace = 115, 
    Newline = 116, BlockComment = 117, LineComment = 118
  };

  explicit CLexer(antlr4::CharStream *input);

  ~CLexer() override;


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

