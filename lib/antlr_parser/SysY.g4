/*
g4 文件框架：
1. grammar声明
2. header/option 额外设置（这里省略）
3. Parser 规则
4. Lexer 规则
5. Fragment 辅助规则，可定义片段
6. 自定义代码（这里省略）
7. 跳过空白和注释 
*/

grammar SysY;

// Parser 规则

compUnit
    :   (decl | funcDef)+
    ;

decl
    :   constDecl
    |   varDecl
    ;

constDecl
    :   'const' bType constDef (Comma constDef)* Semi
    ;

bType
    :   'int'
    |   'float'
    |   'bool'
    ;

constDef
    :   Identifier (LeftBracket constExp RightBracket)* Assign constInitVal
    ;

constInitVal
    :   constExp
    |   Integer_const
    |   Float_const
    |   Boolean_const
    |   LeftBrace (constInitVal (Comma constInitVal)*)? RightBrace
    ;

varDecl
    :   bType varDef (Comma varDef)* Semi
    ;

varDef
    :   Identifier (LeftBracket constExp RightBracket)*
    |   Identifier (LeftBracket constExp RightBracket)* Assign initVal
    ;

initVal
    :   exp
    |   LeftBrace (initVal (Comma initVal)*)? RightBrace
    ;

funcDef
    :   funcType Identifier LeftParen (funcFParams)? RightParen block
    ;

funcType
    :   'void'
    |   'int'
    |   'float'
    |   'bool'
    ;

funcFParams
    :   funcFParam (Comma funcFParam)*
    ;

funcFParam
    :   bType Identifier (LeftBracket RightBracket (LeftParen (exp)? RightParen)?)?
    ;

block
    :   LeftBrace (blockItem)* RightBrace
    ;

blockItem
    :   decl
    |   stmt
    ;

// 语句规则
stmt
    :   lVal Assign exp Semi                    #assignStat
    |   (exp)? Semi                             #semiStat
    |   block                                   #blockStat
    |   'if' LeftParen cond RightParen stmt ('else' stmt)?  #ifStat
    |   'while' LeftParen cond RightParen stmt   #whileStat
    |   'break' Semi                            #breakStat
    |   'continue' Semi                         #continueStat
    |   'return' (exp)? Semi                     #returnStat
    ;

exp
    :   addExp
    ;

cond
    :   lOrExp
    ;

lVal
    :   Identifier (LeftBracket exp RightBracket)*
    ;

primaryExp
    :   LeftParen exp RightParen
    |   lVal
    |   Integer_const
    |   Float_const
    ;

unaryExp
    :   primaryExp                              #primaryExpr
    |   Identifier LeftParen (funcRParams)? RightParen   #functionExpr
    |   op=(Plus | Minus | Not) unaryExp          #signExpr
    ;

funcRParams
    :   exp (Comma exp)*
    ;

mulExp
    :   unaryExp
    |   mulExp (Star | Div | Mod) unaryExp
    ;

addExp
    :   mulExp
    |   addExp (Plus | Minus) mulExp
    ;

relExp
    :   addExp
    |   relExp (LessEqual | GreaterEqual | Less | Greater) addExp
    ;

eqExp
    :   relExp
    |   eqExp (Equal | NotEqual) relExp
    ;

lAndExp
    :   eqExp
    |   lAndExp And eqExp
    ;

lOrExp
    :   lAndExp
    |   lOrExp Or lAndExp
    ;

constExp
    :   addExp
    ;

// Lexer 规则

// 标识符
Identifier
    :   Nondigit (Nondigit | Digit)*
    ;

// 十进制数
fragment Decimal_const
    :   NonZeroDigit Digit*
    ;

// 八进制数
fragment Octal_const
    :   '0' OctalDigit*
    ;

// 十六进制数
fragment Hexadecimal_const
    :   HexPrefix HexDigit+
    ;

// 整型常量
Integer_const
    :   Decimal_const
    |   Octal_const
    |   Hexadecimal_const
    ;

// 布尔常量
Boolean_const
    :   'true' | 'false'
    ;

// 浮点数常量
Float_const
    :   Digit+ '.' Digit*
    |   '.' Digit+
    ;

// 定义符号
LeftParen : '(';
RightParen : ')';
LeftBracket : '[';
RightBracket : ']';
LeftBrace : '{';
RightBrace : '}';

Less : '<';
LessEqual : '<=';
Greater : '>';
GreaterEqual : '>=';

Plus : '+';
Minus : '-';
Star : '*';
Div : '/';
Mod : '%';

And : '&&';
Or  : '||';
Not : '!';

Colon : ':';
Semi : ';';
Comma : ',';

Assign : '=';

Equal : '==';
NotEqual : '!=';

// 辅助片段：字母、数字等
fragment Nondigit
    :   [a-zA-Z_]
    ;
fragment Digit
    :   [0-9]
    ;
fragment NonZeroDigit
    :   [1-9]
    ;
fragment OctalDigit
    :   [0-7]
    ;
fragment HexDigit
    :   [0-9A-Fa-f]
    ;
fragment HexPrefix
    :   '0' [xX]
    ;

// 跳过空白和注释
Whitespace
    :   [ \t]+ -> skip
    ;
Newline
    :   ('\r' '\n'? | '\n') -> skip
    ;
BlockComment
    :   '/*' .*? '*/' -> skip
    ;
LineComment
    :   '//' ~[\r\n]* -> skip
    ;

