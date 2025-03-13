/*
g4 文件框架
1.grammar声明
2.header/option 额外设置
3.Parser 规则
4.Lexer 规则
5.Fragment 辅助规则，可定义片段
6.自定义代码
7.跳过空白和注释 
*/
grammar SysY;

// @header {
// package antlr;
// }

//Parser

compUnit
    :   (decl|funcDef)+
    ;

decl
    :   constDecl
    |   varDecl
    ;

constDecl
    :   'const' bType constDef (','constDef)* ';'
    ;

bType
    :   'int'
    |   'float'
    |   'bool'
    |   constExp
    ;

constDef
    :   Identifier ('['constExp']')* '=' constInitVal
    ;

constInitVal
    :   constExp
    |   Integer_const
    |   Float_const
    |   Boolean_const
    |   '{' (constInitVal(','constInitVal)*)? '}'
    ;
varDecl
    :   bType varDef (','varDef)* ';'
    ;
varDef
    :   Identifier ('['constExp']')*
    |   Identifier ('['constExp']')* '=' initVal
    ;
initVal
    :   exp
    |   '{'(initVal(','initVal)*)?'}'
    ;
funcDef
    :   funcType Identifier '('(funcFParams)?')' block
    ;
funcType
    :   'void'
    |   'int'
    |   'float'
    |   'bool'
    ;
funcFParams
    :   funcFParam (','funcFParam)*
    ;
funcFParam
    :   bType Identifier ('['']'('['exp']')*)?
    ;
block
    :   '{'(blockItem)*'}'
    ;
blockItem
    :   decl
    |   stmt
    ;
//普通语句
stmt
    :   lVal '=' exp ';'                    #assignStat
    |   (exp)? ';'                          #semiStat
    |   block                               #blockStat
    |   'if' '('cond')' stmt ('else'stmt)?  #ifStat
    |   'while' '('cond')' stmt             #whileStat
    |   'break'';'                          #breakStat
    |   'continue'';'                       #continueStat
    |   'return' (exp)? ';'                 #returnStat
    ;
exp
    :   addExp
    ;
cond
    :   lOrExp
    ;
lVal
    :   Identifier ('['exp']')*
    ;
primaryExp
    :   '(' exp ')'
    |   lVal
    |   Integer_const
    |   Float_const
    ;
//number
//    :   Integer_const
//    ;
unaryExp
    :   primaryExp                          #primaryExpr
    |   Identifier '(' (funcRParams)? ')'   #functionExpr
    |   op=('+'|'-'|'!') unaryExp           #signExpr
    ;

funcRParams
    :   params+=exp (','params+=exp)*
    ;
mulExp
    :   unaryExp
    |   mulExp op=('*'|'/'|'%') unaryExp
    ;
addExp
    :   mulExp
    |   addExp op=('+'|'-') mulExp
    ;
relExp
    :   addExp
    |   relExp op=('<='|'>='|'<'|'>') addExp
    ;
eqExp
    :   relExp
    |   eqExp op=('=='|'!=') relExp
    ;
lAndExp
    :   eqExp
    |   lAndExp '&&' eqExp
    ;
lOrExp
    :   lAndExp
    |   lOrExp '||' lAndExp
    ;
constExp
    :   addExp
    |   mulExp
    |   unaryExp
    |   relExp
    |   eqExp
    |   lAndExp
    |   lOrExp
    ;

//  标识符
Identifier
    :   Nondigit (Nondigit|Digit)*
    ;
//  十进制
fragment Decimal_const
    :   NonZeroDigit Digit*
    ;
//  八进制
fragment Octal_const
    :   '0' OctalDigit*
    ;
//  十六进制
fragment Hexadecimal_const
    :   HexPrefix  HexDigit+
    ;
//  整型
Integer_const
    :   Decimal_const
    |   Octal_const
    |   Hexadecimal_const
    ;
// 布尔型
Boolean_const
    :   'true' | 'false'
    ;
// 浮点型 +至少一个 *零次或多次
Float_const
    :   Digit+ '.' Digit* 
    |   '.' Digit+
    ;


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
    :   '0'[xX]
    ;

Whitespace
    :   [ \t]+
        -> skip
    ;

Newline
    :   (   '\r' '\n'?
        |   '\n'
        )
        -> skip
    ;

BlockComment
    :   '/*' .*? '*/'
        -> skip
    ;

LineComment
    :   '//' ~[\r\n]*
        -> skip
    ;
