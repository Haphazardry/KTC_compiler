
// Generated from SysY.g4 by ANTLR 4.13.2


#include "SysYListener.h"
#include "SysYVisitor.h"

#include "SysYParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct SysYParserStaticData final {
  SysYParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SysYParserStaticData(const SysYParserStaticData&) = delete;
  SysYParserStaticData(SysYParserStaticData&&) = delete;
  SysYParserStaticData& operator=(const SysYParserStaticData&) = delete;
  SysYParserStaticData& operator=(SysYParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag sysyParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<SysYParserStaticData> sysyParserStaticData = nullptr;

void sysyParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (sysyParserStaticData != nullptr) {
    return;
  }
#else
  assert(sysyParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<SysYParserStaticData>(
    std::vector<std::string>{
      "compUnit", "decl", "constDecl", "bType", "constDef", "constInitVal", 
      "varDecl", "varDef", "initVal", "funcDef", "funcType", "funcFParams", 
      "funcFParam", "block", "blockItem", "stmt", "exp", "cond", "lVal", 
      "primaryExp", "unaryExp", "funcRParams", "mulExp", "addExp", "relExp", 
      "eqExp", "lAndExp", "lOrExp", "constExp"
    },
    std::vector<std::string>{
      "", "'const'", "'int'", "'float'", "'bool'", "'void'", "'if'", "'else'", 
      "'while'", "'break'", "'continue'", "'return'", "", "", "", "", "'('", 
      "')'", "'['", "']'", "'{'", "'}'", "'<'", "'<='", "'>'", "'>='", "'+'", 
      "'-'", "'*'", "'/'", "'%'", "'&&'", "'||'", "'!'", "':'", "';'", "','", 
      "'='", "'=='", "'!='"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "Identifier", "Integer_const", 
      "Boolean_const", "Float_const", "LeftParen", "RightParen", "LeftBracket", 
      "RightBracket", "LeftBrace", "RightBrace", "Less", "LessEqual", "Greater", 
      "GreaterEqual", "Plus", "Minus", "Star", "Div", "Mod", "And", "Or", 
      "Not", "Colon", "Semi", "Comma", "Assign", "Equal", "NotEqual", "Whitespace", 
      "Newline", "BlockComment", "LineComment"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,43,368,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,1,0,1,0,4,0,61,8,0,11,0,12,0,62,1,1,1,1,3,1,67,8,1,1,2,1,2,1,2,1,2,
  	1,2,5,2,74,8,2,10,2,12,2,77,9,2,1,2,1,2,1,3,1,3,1,3,1,3,3,3,85,8,3,1,
  	4,1,4,1,4,1,4,1,4,5,4,92,8,4,10,4,12,4,95,9,4,1,4,1,4,1,4,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,5,5,108,8,5,10,5,12,5,111,9,5,3,5,113,8,5,1,5,3,5,
  	116,8,5,1,6,1,6,1,6,1,6,5,6,122,8,6,10,6,12,6,125,9,6,1,6,1,6,1,7,1,7,
  	1,7,1,7,1,7,5,7,134,8,7,10,7,12,7,137,9,7,1,7,1,7,1,7,1,7,1,7,5,7,144,
  	8,7,10,7,12,7,147,9,7,1,7,1,7,3,7,151,8,7,1,8,1,8,1,8,1,8,1,8,5,8,158,
  	8,8,10,8,12,8,161,9,8,3,8,163,8,8,1,8,3,8,166,8,8,1,9,1,9,1,9,1,9,3,9,
  	172,8,9,1,9,1,9,1,9,1,10,1,10,1,11,1,11,1,11,5,11,182,8,11,10,11,12,11,
  	185,9,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,5,12,195,8,12,10,12,
  	12,12,198,9,12,3,12,200,8,12,1,13,1,13,5,13,204,8,13,10,13,12,13,207,
  	9,13,1,13,1,13,1,14,1,14,3,14,213,8,14,1,15,1,15,1,15,1,15,1,15,1,15,
  	3,15,221,8,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,232,8,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,246,
  	8,15,1,15,3,15,249,8,15,1,16,1,16,1,17,1,17,1,18,1,18,1,18,1,18,1,18,
  	5,18,260,8,18,10,18,12,18,263,9,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	3,19,272,8,19,1,20,1,20,1,20,1,20,3,20,278,8,20,1,20,1,20,1,20,3,20,283,
  	8,20,1,21,1,21,1,21,5,21,288,8,21,10,21,12,21,291,9,21,1,22,1,22,1,22,
  	1,22,1,22,1,22,5,22,299,8,22,10,22,12,22,302,9,22,1,23,1,23,1,23,1,23,
  	1,23,1,23,5,23,310,8,23,10,23,12,23,313,9,23,1,24,1,24,1,24,1,24,1,24,
  	1,24,5,24,321,8,24,10,24,12,24,324,9,24,1,25,1,25,1,25,1,25,1,25,1,25,
  	5,25,332,8,25,10,25,12,25,335,9,25,1,26,1,26,1,26,1,26,1,26,1,26,5,26,
  	343,8,26,10,26,12,26,346,9,26,1,27,1,27,1,27,1,27,1,27,1,27,5,27,354,
  	8,27,10,27,12,27,357,9,27,1,28,1,28,1,28,1,28,1,28,1,28,1,28,3,28,366,
  	8,28,1,28,0,6,44,46,48,50,52,54,29,0,2,4,6,8,10,12,14,16,18,20,22,24,
  	26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,0,6,1,0,2,5,2,0,26,27,
  	33,33,1,0,28,30,1,0,26,27,1,0,22,25,1,0,38,39,395,0,60,1,0,0,0,2,66,1,
  	0,0,0,4,68,1,0,0,0,6,84,1,0,0,0,8,86,1,0,0,0,10,115,1,0,0,0,12,117,1,
  	0,0,0,14,150,1,0,0,0,16,165,1,0,0,0,18,167,1,0,0,0,20,176,1,0,0,0,22,
  	178,1,0,0,0,24,186,1,0,0,0,26,201,1,0,0,0,28,212,1,0,0,0,30,248,1,0,0,
  	0,32,250,1,0,0,0,34,252,1,0,0,0,36,254,1,0,0,0,38,271,1,0,0,0,40,282,
  	1,0,0,0,42,284,1,0,0,0,44,292,1,0,0,0,46,303,1,0,0,0,48,314,1,0,0,0,50,
  	325,1,0,0,0,52,336,1,0,0,0,54,347,1,0,0,0,56,365,1,0,0,0,58,61,3,2,1,
  	0,59,61,3,18,9,0,60,58,1,0,0,0,60,59,1,0,0,0,61,62,1,0,0,0,62,60,1,0,
  	0,0,62,63,1,0,0,0,63,1,1,0,0,0,64,67,3,4,2,0,65,67,3,12,6,0,66,64,1,0,
  	0,0,66,65,1,0,0,0,67,3,1,0,0,0,68,69,5,1,0,0,69,70,3,6,3,0,70,75,3,8,
  	4,0,71,72,5,36,0,0,72,74,3,8,4,0,73,71,1,0,0,0,74,77,1,0,0,0,75,73,1,
  	0,0,0,75,76,1,0,0,0,76,78,1,0,0,0,77,75,1,0,0,0,78,79,5,35,0,0,79,5,1,
  	0,0,0,80,85,5,2,0,0,81,85,5,3,0,0,82,85,5,4,0,0,83,85,3,56,28,0,84,80,
  	1,0,0,0,84,81,1,0,0,0,84,82,1,0,0,0,84,83,1,0,0,0,85,7,1,0,0,0,86,93,
  	5,12,0,0,87,88,5,18,0,0,88,89,3,56,28,0,89,90,5,19,0,0,90,92,1,0,0,0,
  	91,87,1,0,0,0,92,95,1,0,0,0,93,91,1,0,0,0,93,94,1,0,0,0,94,96,1,0,0,0,
  	95,93,1,0,0,0,96,97,5,37,0,0,97,98,3,10,5,0,98,9,1,0,0,0,99,116,3,56,
  	28,0,100,116,5,13,0,0,101,116,5,15,0,0,102,116,5,14,0,0,103,112,5,20,
  	0,0,104,109,3,10,5,0,105,106,5,36,0,0,106,108,3,10,5,0,107,105,1,0,0,
  	0,108,111,1,0,0,0,109,107,1,0,0,0,109,110,1,0,0,0,110,113,1,0,0,0,111,
  	109,1,0,0,0,112,104,1,0,0,0,112,113,1,0,0,0,113,114,1,0,0,0,114,116,5,
  	21,0,0,115,99,1,0,0,0,115,100,1,0,0,0,115,101,1,0,0,0,115,102,1,0,0,0,
  	115,103,1,0,0,0,116,11,1,0,0,0,117,118,3,6,3,0,118,123,3,14,7,0,119,120,
  	5,36,0,0,120,122,3,14,7,0,121,119,1,0,0,0,122,125,1,0,0,0,123,121,1,0,
  	0,0,123,124,1,0,0,0,124,126,1,0,0,0,125,123,1,0,0,0,126,127,5,35,0,0,
  	127,13,1,0,0,0,128,135,5,12,0,0,129,130,5,18,0,0,130,131,3,56,28,0,131,
  	132,5,19,0,0,132,134,1,0,0,0,133,129,1,0,0,0,134,137,1,0,0,0,135,133,
  	1,0,0,0,135,136,1,0,0,0,136,151,1,0,0,0,137,135,1,0,0,0,138,145,5,12,
  	0,0,139,140,5,18,0,0,140,141,3,56,28,0,141,142,5,19,0,0,142,144,1,0,0,
  	0,143,139,1,0,0,0,144,147,1,0,0,0,145,143,1,0,0,0,145,146,1,0,0,0,146,
  	148,1,0,0,0,147,145,1,0,0,0,148,149,5,37,0,0,149,151,3,16,8,0,150,128,
  	1,0,0,0,150,138,1,0,0,0,151,15,1,0,0,0,152,166,3,32,16,0,153,162,5,20,
  	0,0,154,159,3,16,8,0,155,156,5,36,0,0,156,158,3,16,8,0,157,155,1,0,0,
  	0,158,161,1,0,0,0,159,157,1,0,0,0,159,160,1,0,0,0,160,163,1,0,0,0,161,
  	159,1,0,0,0,162,154,1,0,0,0,162,163,1,0,0,0,163,164,1,0,0,0,164,166,5,
  	21,0,0,165,152,1,0,0,0,165,153,1,0,0,0,166,17,1,0,0,0,167,168,3,20,10,
  	0,168,169,5,12,0,0,169,171,5,16,0,0,170,172,3,22,11,0,171,170,1,0,0,0,
  	171,172,1,0,0,0,172,173,1,0,0,0,173,174,5,17,0,0,174,175,3,26,13,0,175,
  	19,1,0,0,0,176,177,7,0,0,0,177,21,1,0,0,0,178,183,3,24,12,0,179,180,5,
  	36,0,0,180,182,3,24,12,0,181,179,1,0,0,0,182,185,1,0,0,0,183,181,1,0,
  	0,0,183,184,1,0,0,0,184,23,1,0,0,0,185,183,1,0,0,0,186,187,3,6,3,0,187,
  	199,5,12,0,0,188,189,5,18,0,0,189,196,5,19,0,0,190,191,5,18,0,0,191,192,
  	3,32,16,0,192,193,5,19,0,0,193,195,1,0,0,0,194,190,1,0,0,0,195,198,1,
  	0,0,0,196,194,1,0,0,0,196,197,1,0,0,0,197,200,1,0,0,0,198,196,1,0,0,0,
  	199,188,1,0,0,0,199,200,1,0,0,0,200,25,1,0,0,0,201,205,5,20,0,0,202,204,
  	3,28,14,0,203,202,1,0,0,0,204,207,1,0,0,0,205,203,1,0,0,0,205,206,1,0,
  	0,0,206,208,1,0,0,0,207,205,1,0,0,0,208,209,5,21,0,0,209,27,1,0,0,0,210,
  	213,3,2,1,0,211,213,3,30,15,0,212,210,1,0,0,0,212,211,1,0,0,0,213,29,
  	1,0,0,0,214,215,3,36,18,0,215,216,5,37,0,0,216,217,3,32,16,0,217,218,
  	5,35,0,0,218,249,1,0,0,0,219,221,3,32,16,0,220,219,1,0,0,0,220,221,1,
  	0,0,0,221,222,1,0,0,0,222,249,5,35,0,0,223,249,3,26,13,0,224,225,5,6,
  	0,0,225,226,5,16,0,0,226,227,3,34,17,0,227,228,5,17,0,0,228,231,3,30,
  	15,0,229,230,5,7,0,0,230,232,3,30,15,0,231,229,1,0,0,0,231,232,1,0,0,
  	0,232,249,1,0,0,0,233,234,5,8,0,0,234,235,5,16,0,0,235,236,3,34,17,0,
  	236,237,5,17,0,0,237,238,3,30,15,0,238,249,1,0,0,0,239,240,5,9,0,0,240,
  	249,5,35,0,0,241,242,5,10,0,0,242,249,5,35,0,0,243,245,5,11,0,0,244,246,
  	3,32,16,0,245,244,1,0,0,0,245,246,1,0,0,0,246,247,1,0,0,0,247,249,5,35,
  	0,0,248,214,1,0,0,0,248,220,1,0,0,0,248,223,1,0,0,0,248,224,1,0,0,0,248,
  	233,1,0,0,0,248,239,1,0,0,0,248,241,1,0,0,0,248,243,1,0,0,0,249,31,1,
  	0,0,0,250,251,3,46,23,0,251,33,1,0,0,0,252,253,3,54,27,0,253,35,1,0,0,
  	0,254,261,5,12,0,0,255,256,5,18,0,0,256,257,3,32,16,0,257,258,5,19,0,
  	0,258,260,1,0,0,0,259,255,1,0,0,0,260,263,1,0,0,0,261,259,1,0,0,0,261,
  	262,1,0,0,0,262,37,1,0,0,0,263,261,1,0,0,0,264,265,5,16,0,0,265,266,3,
  	32,16,0,266,267,5,17,0,0,267,272,1,0,0,0,268,272,3,36,18,0,269,272,5,
  	13,0,0,270,272,5,15,0,0,271,264,1,0,0,0,271,268,1,0,0,0,271,269,1,0,0,
  	0,271,270,1,0,0,0,272,39,1,0,0,0,273,283,3,38,19,0,274,275,5,12,0,0,275,
  	277,5,16,0,0,276,278,3,42,21,0,277,276,1,0,0,0,277,278,1,0,0,0,278,279,
  	1,0,0,0,279,283,5,17,0,0,280,281,7,1,0,0,281,283,3,40,20,0,282,273,1,
  	0,0,0,282,274,1,0,0,0,282,280,1,0,0,0,283,41,1,0,0,0,284,289,3,32,16,
  	0,285,286,5,36,0,0,286,288,3,32,16,0,287,285,1,0,0,0,288,291,1,0,0,0,
  	289,287,1,0,0,0,289,290,1,0,0,0,290,43,1,0,0,0,291,289,1,0,0,0,292,293,
  	6,22,-1,0,293,294,3,40,20,0,294,300,1,0,0,0,295,296,10,1,0,0,296,297,
  	7,2,0,0,297,299,3,40,20,0,298,295,1,0,0,0,299,302,1,0,0,0,300,298,1,0,
  	0,0,300,301,1,0,0,0,301,45,1,0,0,0,302,300,1,0,0,0,303,304,6,23,-1,0,
  	304,305,3,44,22,0,305,311,1,0,0,0,306,307,10,1,0,0,307,308,7,3,0,0,308,
  	310,3,44,22,0,309,306,1,0,0,0,310,313,1,0,0,0,311,309,1,0,0,0,311,312,
  	1,0,0,0,312,47,1,0,0,0,313,311,1,0,0,0,314,315,6,24,-1,0,315,316,3,46,
  	23,0,316,322,1,0,0,0,317,318,10,1,0,0,318,319,7,4,0,0,319,321,3,46,23,
  	0,320,317,1,0,0,0,321,324,1,0,0,0,322,320,1,0,0,0,322,323,1,0,0,0,323,
  	49,1,0,0,0,324,322,1,0,0,0,325,326,6,25,-1,0,326,327,3,48,24,0,327,333,
  	1,0,0,0,328,329,10,1,0,0,329,330,7,5,0,0,330,332,3,48,24,0,331,328,1,
  	0,0,0,332,335,1,0,0,0,333,331,1,0,0,0,333,334,1,0,0,0,334,51,1,0,0,0,
  	335,333,1,0,0,0,336,337,6,26,-1,0,337,338,3,50,25,0,338,344,1,0,0,0,339,
  	340,10,1,0,0,340,341,5,31,0,0,341,343,3,50,25,0,342,339,1,0,0,0,343,346,
  	1,0,0,0,344,342,1,0,0,0,344,345,1,0,0,0,345,53,1,0,0,0,346,344,1,0,0,
  	0,347,348,6,27,-1,0,348,349,3,52,26,0,349,355,1,0,0,0,350,351,10,1,0,
  	0,351,352,5,32,0,0,352,354,3,52,26,0,353,350,1,0,0,0,354,357,1,0,0,0,
  	355,353,1,0,0,0,355,356,1,0,0,0,356,55,1,0,0,0,357,355,1,0,0,0,358,366,
  	3,46,23,0,359,366,3,44,22,0,360,366,3,40,20,0,361,366,3,48,24,0,362,366,
  	3,50,25,0,363,366,3,52,26,0,364,366,3,54,27,0,365,358,1,0,0,0,365,359,
  	1,0,0,0,365,360,1,0,0,0,365,361,1,0,0,0,365,362,1,0,0,0,365,363,1,0,0,
  	0,365,364,1,0,0,0,366,57,1,0,0,0,38,60,62,66,75,84,93,109,112,115,123,
  	135,145,150,159,162,165,171,183,196,199,205,212,220,231,245,248,261,271,
  	277,282,289,300,311,322,333,344,355,365
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  sysyParserStaticData = std::move(staticData);
}

}

SysYParser::SysYParser(TokenStream *input) : SysYParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

SysYParser::SysYParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  SysYParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *sysyParserStaticData->atn, sysyParserStaticData->decisionToDFA, sysyParserStaticData->sharedContextCache, options);
}

SysYParser::~SysYParser() {
  delete _interpreter;
}

const atn::ATN& SysYParser::getATN() const {
  return *sysyParserStaticData->atn;
}

std::string SysYParser::getGrammarFileName() const {
  return "SysY.g4";
}

const std::vector<std::string>& SysYParser::getRuleNames() const {
  return sysyParserStaticData->ruleNames;
}

const dfa::Vocabulary& SysYParser::getVocabulary() const {
  return sysyParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SysYParser::getSerializedATN() const {
  return sysyParserStaticData->serializedATN;
}


//----------------- CompUnitContext ------------------------------------------------------------------

SysYParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::DeclContext *> SysYParser::CompUnitContext::decl() {
  return getRuleContexts<SysYParser::DeclContext>();
}

SysYParser::DeclContext* SysYParser::CompUnitContext::decl(size_t i) {
  return getRuleContext<SysYParser::DeclContext>(i);
}

std::vector<SysYParser::FuncDefContext *> SysYParser::CompUnitContext::funcDef() {
  return getRuleContexts<SysYParser::FuncDefContext>();
}

SysYParser::FuncDefContext* SysYParser::CompUnitContext::funcDef(size_t i) {
  return getRuleContext<SysYParser::FuncDefContext>(i);
}


size_t SysYParser::CompUnitContext::getRuleIndex() const {
  return SysYParser::RuleCompUnit;
}

void SysYParser::CompUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompUnit(this);
}

void SysYParser::CompUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompUnit(this);
}


std::any SysYParser::CompUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitCompUnit(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::CompUnitContext* SysYParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, SysYParser::RuleCompUnit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(60);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(58);
        decl();
        break;
      }

      case 2: {
        setState(59);
        funcDef();
        break;
      }

      default:
        break;
      }
      setState(62); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8791371838) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

SysYParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ConstDeclContext* SysYParser::DeclContext::constDecl() {
  return getRuleContext<SysYParser::ConstDeclContext>(0);
}

SysYParser::VarDeclContext* SysYParser::DeclContext::varDecl() {
  return getRuleContext<SysYParser::VarDeclContext>(0);
}


size_t SysYParser::DeclContext::getRuleIndex() const {
  return SysYParser::RuleDecl;
}

void SysYParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void SysYParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}


std::any SysYParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::DeclContext* SysYParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 2, SysYParser::RuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(66);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(64);
        constDecl();
        break;
      }

      case SysYParser::T__1:
      case SysYParser::T__2:
      case SysYParser::T__3:
      case SysYParser::Identifier:
      case SysYParser::Integer_const:
      case SysYParser::Float_const:
      case SysYParser::LeftParen:
      case SysYParser::Plus:
      case SysYParser::Minus:
      case SysYParser::Not: {
        enterOuterAlt(_localctx, 2);
        setState(65);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

SysYParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BTypeContext* SysYParser::ConstDeclContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

std::vector<SysYParser::ConstDefContext *> SysYParser::ConstDeclContext::constDef() {
  return getRuleContexts<SysYParser::ConstDefContext>();
}

SysYParser::ConstDefContext* SysYParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<SysYParser::ConstDefContext>(i);
}

tree::TerminalNode* SysYParser::ConstDeclContext::Semi() {
  return getToken(SysYParser::Semi, 0);
}

std::vector<tree::TerminalNode *> SysYParser::ConstDeclContext::Comma() {
  return getTokens(SysYParser::Comma);
}

tree::TerminalNode* SysYParser::ConstDeclContext::Comma(size_t i) {
  return getToken(SysYParser::Comma, i);
}


size_t SysYParser::ConstDeclContext::getRuleIndex() const {
  return SysYParser::RuleConstDecl;
}

void SysYParser::ConstDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDecl(this);
}

void SysYParser::ConstDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDecl(this);
}


std::any SysYParser::ConstDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstDecl(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstDeclContext* SysYParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, SysYParser::RuleConstDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    match(SysYParser::T__0);
    setState(69);
    bType();
    setState(70);
    constDef();
    setState(75);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::Comma) {
      setState(71);
      match(SysYParser::Comma);
      setState(72);
      constDef();
      setState(77);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(78);
    match(SysYParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

SysYParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ConstExpContext* SysYParser::BTypeContext::constExp() {
  return getRuleContext<SysYParser::ConstExpContext>(0);
}


size_t SysYParser::BTypeContext::getRuleIndex() const {
  return SysYParser::RuleBType;
}

void SysYParser::BTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBType(this);
}

void SysYParser::BTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBType(this);
}


std::any SysYParser::BTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBType(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BTypeContext* SysYParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 6, SysYParser::RuleBType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(84);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__1: {
        enterOuterAlt(_localctx, 1);
        setState(80);
        match(SysYParser::T__1);
        break;
      }

      case SysYParser::T__2: {
        enterOuterAlt(_localctx, 2);
        setState(81);
        match(SysYParser::T__2);
        break;
      }

      case SysYParser::T__3: {
        enterOuterAlt(_localctx, 3);
        setState(82);
        match(SysYParser::T__3);
        break;
      }

      case SysYParser::Identifier:
      case SysYParser::Integer_const:
      case SysYParser::Float_const:
      case SysYParser::LeftParen:
      case SysYParser::Plus:
      case SysYParser::Minus:
      case SysYParser::Not: {
        enterOuterAlt(_localctx, 4);
        setState(83);
        constExp();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

SysYParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::ConstDefContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

tree::TerminalNode* SysYParser::ConstDefContext::Assign() {
  return getToken(SysYParser::Assign, 0);
}

SysYParser::ConstInitValContext* SysYParser::ConstDefContext::constInitVal() {
  return getRuleContext<SysYParser::ConstInitValContext>(0);
}

std::vector<tree::TerminalNode *> SysYParser::ConstDefContext::LeftBracket() {
  return getTokens(SysYParser::LeftBracket);
}

tree::TerminalNode* SysYParser::ConstDefContext::LeftBracket(size_t i) {
  return getToken(SysYParser::LeftBracket, i);
}

std::vector<SysYParser::ConstExpContext *> SysYParser::ConstDefContext::constExp() {
  return getRuleContexts<SysYParser::ConstExpContext>();
}

SysYParser::ConstExpContext* SysYParser::ConstDefContext::constExp(size_t i) {
  return getRuleContext<SysYParser::ConstExpContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::ConstDefContext::RightBracket() {
  return getTokens(SysYParser::RightBracket);
}

tree::TerminalNode* SysYParser::ConstDefContext::RightBracket(size_t i) {
  return getToken(SysYParser::RightBracket, i);
}


size_t SysYParser::ConstDefContext::getRuleIndex() const {
  return SysYParser::RuleConstDef;
}

void SysYParser::ConstDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDef(this);
}

void SysYParser::ConstDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDef(this);
}


std::any SysYParser::ConstDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstDef(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstDefContext* SysYParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 8, SysYParser::RuleConstDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    match(SysYParser::Identifier);
    setState(93);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::LeftBracket) {
      setState(87);
      match(SysYParser::LeftBracket);
      setState(88);
      constExp();
      setState(89);
      match(SysYParser::RightBracket);
      setState(95);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(96);
    match(SysYParser::Assign);
    setState(97);
    constInitVal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstInitValContext ------------------------------------------------------------------

SysYParser::ConstInitValContext::ConstInitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ConstExpContext* SysYParser::ConstInitValContext::constExp() {
  return getRuleContext<SysYParser::ConstExpContext>(0);
}

tree::TerminalNode* SysYParser::ConstInitValContext::Integer_const() {
  return getToken(SysYParser::Integer_const, 0);
}

tree::TerminalNode* SysYParser::ConstInitValContext::Float_const() {
  return getToken(SysYParser::Float_const, 0);
}

tree::TerminalNode* SysYParser::ConstInitValContext::Boolean_const() {
  return getToken(SysYParser::Boolean_const, 0);
}

tree::TerminalNode* SysYParser::ConstInitValContext::LeftBrace() {
  return getToken(SysYParser::LeftBrace, 0);
}

tree::TerminalNode* SysYParser::ConstInitValContext::RightBrace() {
  return getToken(SysYParser::RightBrace, 0);
}

std::vector<SysYParser::ConstInitValContext *> SysYParser::ConstInitValContext::constInitVal() {
  return getRuleContexts<SysYParser::ConstInitValContext>();
}

SysYParser::ConstInitValContext* SysYParser::ConstInitValContext::constInitVal(size_t i) {
  return getRuleContext<SysYParser::ConstInitValContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::ConstInitValContext::Comma() {
  return getTokens(SysYParser::Comma);
}

tree::TerminalNode* SysYParser::ConstInitValContext::Comma(size_t i) {
  return getToken(SysYParser::Comma, i);
}


size_t SysYParser::ConstInitValContext::getRuleIndex() const {
  return SysYParser::RuleConstInitVal;
}

void SysYParser::ConstInitValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstInitVal(this);
}

void SysYParser::ConstInitValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstInitVal(this);
}


std::any SysYParser::ConstInitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstInitVal(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstInitValContext* SysYParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 10, SysYParser::RuleConstInitVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(115);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(99);
      constExp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(100);
      match(SysYParser::Integer_const);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(101);
      match(SysYParser::Float_const);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(102);
      match(SysYParser::Boolean_const);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(103);
      match(SysYParser::LeftBrace);
      setState(112);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8792436736) != 0)) {
        setState(104);
        constInitVal();
        setState(109);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SysYParser::Comma) {
          setState(105);
          match(SysYParser::Comma);
          setState(106);
          constInitVal();
          setState(111);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(114);
      match(SysYParser::RightBrace);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

SysYParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BTypeContext* SysYParser::VarDeclContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

std::vector<SysYParser::VarDefContext *> SysYParser::VarDeclContext::varDef() {
  return getRuleContexts<SysYParser::VarDefContext>();
}

SysYParser::VarDefContext* SysYParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<SysYParser::VarDefContext>(i);
}

tree::TerminalNode* SysYParser::VarDeclContext::Semi() {
  return getToken(SysYParser::Semi, 0);
}

std::vector<tree::TerminalNode *> SysYParser::VarDeclContext::Comma() {
  return getTokens(SysYParser::Comma);
}

tree::TerminalNode* SysYParser::VarDeclContext::Comma(size_t i) {
  return getToken(SysYParser::Comma, i);
}


size_t SysYParser::VarDeclContext::getRuleIndex() const {
  return SysYParser::RuleVarDecl;
}

void SysYParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void SysYParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}


std::any SysYParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::VarDeclContext* SysYParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, SysYParser::RuleVarDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    bType();
    setState(118);
    varDef();
    setState(123);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::Comma) {
      setState(119);
      match(SysYParser::Comma);
      setState(120);
      varDef();
      setState(125);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(126);
    match(SysYParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

SysYParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::VarDefContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

std::vector<tree::TerminalNode *> SysYParser::VarDefContext::LeftBracket() {
  return getTokens(SysYParser::LeftBracket);
}

tree::TerminalNode* SysYParser::VarDefContext::LeftBracket(size_t i) {
  return getToken(SysYParser::LeftBracket, i);
}

std::vector<SysYParser::ConstExpContext *> SysYParser::VarDefContext::constExp() {
  return getRuleContexts<SysYParser::ConstExpContext>();
}

SysYParser::ConstExpContext* SysYParser::VarDefContext::constExp(size_t i) {
  return getRuleContext<SysYParser::ConstExpContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::VarDefContext::RightBracket() {
  return getTokens(SysYParser::RightBracket);
}

tree::TerminalNode* SysYParser::VarDefContext::RightBracket(size_t i) {
  return getToken(SysYParser::RightBracket, i);
}

tree::TerminalNode* SysYParser::VarDefContext::Assign() {
  return getToken(SysYParser::Assign, 0);
}

SysYParser::InitValContext* SysYParser::VarDefContext::initVal() {
  return getRuleContext<SysYParser::InitValContext>(0);
}


size_t SysYParser::VarDefContext::getRuleIndex() const {
  return SysYParser::RuleVarDef;
}

void SysYParser::VarDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDef(this);
}

void SysYParser::VarDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDef(this);
}


std::any SysYParser::VarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitVarDef(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::VarDefContext* SysYParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 14, SysYParser::RuleVarDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(150);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(128);
      match(SysYParser::Identifier);
      setState(135);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SysYParser::LeftBracket) {
        setState(129);
        match(SysYParser::LeftBracket);
        setState(130);
        constExp();
        setState(131);
        match(SysYParser::RightBracket);
        setState(137);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(138);
      match(SysYParser::Identifier);
      setState(145);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SysYParser::LeftBracket) {
        setState(139);
        match(SysYParser::LeftBracket);
        setState(140);
        constExp();
        setState(141);
        match(SysYParser::RightBracket);
        setState(147);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(148);
      match(SysYParser::Assign);
      setState(149);
      initVal();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitValContext ------------------------------------------------------------------

SysYParser::InitValContext::InitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ExpContext* SysYParser::InitValContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

tree::TerminalNode* SysYParser::InitValContext::LeftBrace() {
  return getToken(SysYParser::LeftBrace, 0);
}

tree::TerminalNode* SysYParser::InitValContext::RightBrace() {
  return getToken(SysYParser::RightBrace, 0);
}

std::vector<SysYParser::InitValContext *> SysYParser::InitValContext::initVal() {
  return getRuleContexts<SysYParser::InitValContext>();
}

SysYParser::InitValContext* SysYParser::InitValContext::initVal(size_t i) {
  return getRuleContext<SysYParser::InitValContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::InitValContext::Comma() {
  return getTokens(SysYParser::Comma);
}

tree::TerminalNode* SysYParser::InitValContext::Comma(size_t i) {
  return getToken(SysYParser::Comma, i);
}


size_t SysYParser::InitValContext::getRuleIndex() const {
  return SysYParser::RuleInitVal;
}

void SysYParser::InitValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitVal(this);
}

void SysYParser::InitValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitVal(this);
}


std::any SysYParser::InitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitInitVal(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::InitValContext* SysYParser::initVal() {
  InitValContext *_localctx = _tracker.createInstance<InitValContext>(_ctx, getState());
  enterRule(_localctx, 16, SysYParser::RuleInitVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(165);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::Identifier:
      case SysYParser::Integer_const:
      case SysYParser::Float_const:
      case SysYParser::LeftParen:
      case SysYParser::Plus:
      case SysYParser::Minus:
      case SysYParser::Not: {
        enterOuterAlt(_localctx, 1);
        setState(152);
        exp();
        break;
      }

      case SysYParser::LeftBrace: {
        enterOuterAlt(_localctx, 2);
        setState(153);
        match(SysYParser::LeftBrace);
        setState(162);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 8792420352) != 0)) {
          setState(154);
          initVal();
          setState(159);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SysYParser::Comma) {
            setState(155);
            match(SysYParser::Comma);
            setState(156);
            initVal();
            setState(161);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(164);
        match(SysYParser::RightBrace);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

SysYParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::FuncTypeContext* SysYParser::FuncDefContext::funcType() {
  return getRuleContext<SysYParser::FuncTypeContext>(0);
}

tree::TerminalNode* SysYParser::FuncDefContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

tree::TerminalNode* SysYParser::FuncDefContext::LeftParen() {
  return getToken(SysYParser::LeftParen, 0);
}

tree::TerminalNode* SysYParser::FuncDefContext::RightParen() {
  return getToken(SysYParser::RightParen, 0);
}

SysYParser::BlockContext* SysYParser::FuncDefContext::block() {
  return getRuleContext<SysYParser::BlockContext>(0);
}

SysYParser::FuncFParamsContext* SysYParser::FuncDefContext::funcFParams() {
  return getRuleContext<SysYParser::FuncFParamsContext>(0);
}


size_t SysYParser::FuncDefContext::getRuleIndex() const {
  return SysYParser::RuleFuncDef;
}

void SysYParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void SysYParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
}


std::any SysYParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncDefContext* SysYParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 18, SysYParser::RuleFuncDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    funcType();
    setState(168);
    match(SysYParser::Identifier);
    setState(169);
    match(SysYParser::LeftParen);
    setState(171);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8791371804) != 0)) {
      setState(170);
      funcFParams();
    }
    setState(173);
    match(SysYParser::RightParen);
    setState(174);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

SysYParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::FuncTypeContext::getRuleIndex() const {
  return SysYParser::RuleFuncType;
}

void SysYParser::FuncTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncType(this);
}

void SysYParser::FuncTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncType(this);
}


std::any SysYParser::FuncTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncType(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncTypeContext* SysYParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 20, SysYParser::RuleFuncType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 60) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamsContext ------------------------------------------------------------------

SysYParser::FuncFParamsContext::FuncFParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::FuncFParamContext *> SysYParser::FuncFParamsContext::funcFParam() {
  return getRuleContexts<SysYParser::FuncFParamContext>();
}

SysYParser::FuncFParamContext* SysYParser::FuncFParamsContext::funcFParam(size_t i) {
  return getRuleContext<SysYParser::FuncFParamContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::FuncFParamsContext::Comma() {
  return getTokens(SysYParser::Comma);
}

tree::TerminalNode* SysYParser::FuncFParamsContext::Comma(size_t i) {
  return getToken(SysYParser::Comma, i);
}


size_t SysYParser::FuncFParamsContext::getRuleIndex() const {
  return SysYParser::RuleFuncFParams;
}

void SysYParser::FuncFParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParams(this);
}

void SysYParser::FuncFParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParams(this);
}


std::any SysYParser::FuncFParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncFParams(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncFParamsContext* SysYParser::funcFParams() {
  FuncFParamsContext *_localctx = _tracker.createInstance<FuncFParamsContext>(_ctx, getState());
  enterRule(_localctx, 22, SysYParser::RuleFuncFParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    funcFParam();
    setState(183);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::Comma) {
      setState(179);
      match(SysYParser::Comma);
      setState(180);
      funcFParam();
      setState(185);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamContext ------------------------------------------------------------------

SysYParser::FuncFParamContext::FuncFParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BTypeContext* SysYParser::FuncFParamContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

tree::TerminalNode* SysYParser::FuncFParamContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

std::vector<tree::TerminalNode *> SysYParser::FuncFParamContext::LeftBracket() {
  return getTokens(SysYParser::LeftBracket);
}

tree::TerminalNode* SysYParser::FuncFParamContext::LeftBracket(size_t i) {
  return getToken(SysYParser::LeftBracket, i);
}

std::vector<tree::TerminalNode *> SysYParser::FuncFParamContext::RightBracket() {
  return getTokens(SysYParser::RightBracket);
}

tree::TerminalNode* SysYParser::FuncFParamContext::RightBracket(size_t i) {
  return getToken(SysYParser::RightBracket, i);
}

std::vector<SysYParser::ExpContext *> SysYParser::FuncFParamContext::exp() {
  return getRuleContexts<SysYParser::ExpContext>();
}

SysYParser::ExpContext* SysYParser::FuncFParamContext::exp(size_t i) {
  return getRuleContext<SysYParser::ExpContext>(i);
}


size_t SysYParser::FuncFParamContext::getRuleIndex() const {
  return SysYParser::RuleFuncFParam;
}

void SysYParser::FuncFParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParam(this);
}

void SysYParser::FuncFParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParam(this);
}


std::any SysYParser::FuncFParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncFParam(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncFParamContext* SysYParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 24, SysYParser::RuleFuncFParam);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    bType();
    setState(187);
    match(SysYParser::Identifier);
    setState(199);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::LeftBracket) {
      setState(188);
      match(SysYParser::LeftBracket);
      setState(189);
      match(SysYParser::RightBracket);
      setState(196);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SysYParser::LeftBracket) {
        setState(190);
        match(SysYParser::LeftBracket);
        setState(191);
        exp();
        setState(192);
        match(SysYParser::RightBracket);
        setState(198);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

SysYParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::BlockContext::LeftBrace() {
  return getToken(SysYParser::LeftBrace, 0);
}

tree::TerminalNode* SysYParser::BlockContext::RightBrace() {
  return getToken(SysYParser::RightBrace, 0);
}

std::vector<SysYParser::BlockItemContext *> SysYParser::BlockContext::blockItem() {
  return getRuleContexts<SysYParser::BlockItemContext>();
}

SysYParser::BlockItemContext* SysYParser::BlockContext::blockItem(size_t i) {
  return getRuleContext<SysYParser::BlockItemContext>(i);
}


size_t SysYParser::BlockContext::getRuleIndex() const {
  return SysYParser::RuleBlock;
}

void SysYParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void SysYParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any SysYParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BlockContext* SysYParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 26, SysYParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    match(SysYParser::LeftBrace);
    setState(205);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 43152162654) != 0)) {
      setState(202);
      blockItem();
      setState(207);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(208);
    match(SysYParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

SysYParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::DeclContext* SysYParser::BlockItemContext::decl() {
  return getRuleContext<SysYParser::DeclContext>(0);
}

SysYParser::StmtContext* SysYParser::BlockItemContext::stmt() {
  return getRuleContext<SysYParser::StmtContext>(0);
}


size_t SysYParser::BlockItemContext::getRuleIndex() const {
  return SysYParser::RuleBlockItem;
}

void SysYParser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void SysYParser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
}


std::any SysYParser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BlockItemContext* SysYParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 28, SysYParser::RuleBlockItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(212);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(210);
      decl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(211);
      stmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

SysYParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::StmtContext::getRuleIndex() const {
  return SysYParser::RuleStmt;
}

void SysYParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IfStatContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::IfStatContext::LeftParen() {
  return getToken(SysYParser::LeftParen, 0);
}

SysYParser::CondContext* SysYParser::IfStatContext::cond() {
  return getRuleContext<SysYParser::CondContext>(0);
}

tree::TerminalNode* SysYParser::IfStatContext::RightParen() {
  return getToken(SysYParser::RightParen, 0);
}

std::vector<SysYParser::StmtContext *> SysYParser::IfStatContext::stmt() {
  return getRuleContexts<SysYParser::StmtContext>();
}

SysYParser::StmtContext* SysYParser::IfStatContext::stmt(size_t i) {
  return getRuleContext<SysYParser::StmtContext>(i);
}

SysYParser::IfStatContext::IfStatContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::IfStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStat(this);
}
void SysYParser::IfStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStat(this);
}

std::any SysYParser::IfStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitIfStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BlockStatContext ------------------------------------------------------------------

SysYParser::BlockContext* SysYParser::BlockStatContext::block() {
  return getRuleContext<SysYParser::BlockContext>(0);
}

SysYParser::BlockStatContext::BlockStatContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::BlockStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockStat(this);
}
void SysYParser::BlockStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockStat(this);
}

std::any SysYParser::BlockStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBlockStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStatContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::ReturnStatContext::Semi() {
  return getToken(SysYParser::Semi, 0);
}

SysYParser::ExpContext* SysYParser::ReturnStatContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::ReturnStatContext::ReturnStatContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::ReturnStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStat(this);
}
void SysYParser::ReturnStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStat(this);
}

std::any SysYParser::ReturnStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitReturnStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ContinueStatContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::ContinueStatContext::Semi() {
  return getToken(SysYParser::Semi, 0);
}

SysYParser::ContinueStatContext::ContinueStatContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::ContinueStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinueStat(this);
}
void SysYParser::ContinueStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinueStat(this);
}

std::any SysYParser::ContinueStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitContinueStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SemiStatContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::SemiStatContext::Semi() {
  return getToken(SysYParser::Semi, 0);
}

SysYParser::ExpContext* SysYParser::SemiStatContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::SemiStatContext::SemiStatContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::SemiStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSemiStat(this);
}
void SysYParser::SemiStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSemiStat(this);
}

std::any SysYParser::SemiStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitSemiStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignStatContext ------------------------------------------------------------------

SysYParser::LValContext* SysYParser::AssignStatContext::lVal() {
  return getRuleContext<SysYParser::LValContext>(0);
}

tree::TerminalNode* SysYParser::AssignStatContext::Assign() {
  return getToken(SysYParser::Assign, 0);
}

SysYParser::ExpContext* SysYParser::AssignStatContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

tree::TerminalNode* SysYParser::AssignStatContext::Semi() {
  return getToken(SysYParser::Semi, 0);
}

SysYParser::AssignStatContext::AssignStatContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::AssignStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignStat(this);
}
void SysYParser::AssignStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignStat(this);
}

std::any SysYParser::AssignStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitAssignStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakStatContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::BreakStatContext::Semi() {
  return getToken(SysYParser::Semi, 0);
}

SysYParser::BreakStatContext::BreakStatContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::BreakStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStat(this);
}
void SysYParser::BreakStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStat(this);
}

std::any SysYParser::BreakStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBreakStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStatContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::WhileStatContext::LeftParen() {
  return getToken(SysYParser::LeftParen, 0);
}

SysYParser::CondContext* SysYParser::WhileStatContext::cond() {
  return getRuleContext<SysYParser::CondContext>(0);
}

tree::TerminalNode* SysYParser::WhileStatContext::RightParen() {
  return getToken(SysYParser::RightParen, 0);
}

SysYParser::StmtContext* SysYParser::WhileStatContext::stmt() {
  return getRuleContext<SysYParser::StmtContext>(0);
}

SysYParser::WhileStatContext::WhileStatContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::WhileStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStat(this);
}
void SysYParser::WhileStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStat(this);
}

std::any SysYParser::WhileStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitWhileStat(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::StmtContext* SysYParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 30, SysYParser::RuleStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(248);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SysYParser::AssignStatContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(214);
      lVal();
      setState(215);
      match(SysYParser::Assign);
      setState(216);
      exp();
      setState(217);
      match(SysYParser::Semi);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SysYParser::SemiStatContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(220);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8791371776) != 0)) {
        setState(219);
        exp();
      }
      setState(222);
      match(SysYParser::Semi);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<SysYParser::BlockStatContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(223);
      block();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<SysYParser::IfStatContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(224);
      match(SysYParser::T__5);
      setState(225);
      match(SysYParser::LeftParen);
      setState(226);
      cond();
      setState(227);
      match(SysYParser::RightParen);
      setState(228);
      stmt();
      setState(231);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
      case 1: {
        setState(229);
        match(SysYParser::T__6);
        setState(230);
        stmt();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<SysYParser::WhileStatContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(233);
      match(SysYParser::T__7);
      setState(234);
      match(SysYParser::LeftParen);
      setState(235);
      cond();
      setState(236);
      match(SysYParser::RightParen);
      setState(237);
      stmt();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<SysYParser::BreakStatContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(239);
      match(SysYParser::T__8);
      setState(240);
      match(SysYParser::Semi);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<SysYParser::ContinueStatContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(241);
      match(SysYParser::T__9);
      setState(242);
      match(SysYParser::Semi);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<SysYParser::ReturnStatContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(243);
      match(SysYParser::T__10);
      setState(245);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8791371776) != 0)) {
        setState(244);
        exp();
      }
      setState(247);
      match(SysYParser::Semi);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

SysYParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::AddExpContext* SysYParser::ExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}


size_t SysYParser::ExpContext::getRuleIndex() const {
  return SysYParser::RuleExp;
}

void SysYParser::ExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp(this);
}

void SysYParser::ExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp(this);
}


std::any SysYParser::ExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ExpContext* SysYParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 32, SysYParser::RuleExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    addExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

SysYParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::LOrExpContext* SysYParser::CondContext::lOrExp() {
  return getRuleContext<SysYParser::LOrExpContext>(0);
}


size_t SysYParser::CondContext::getRuleIndex() const {
  return SysYParser::RuleCond;
}

void SysYParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void SysYParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}


std::any SysYParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::CondContext* SysYParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 34, SysYParser::RuleCond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    lOrExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

SysYParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::LValContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

std::vector<tree::TerminalNode *> SysYParser::LValContext::LeftBracket() {
  return getTokens(SysYParser::LeftBracket);
}

tree::TerminalNode* SysYParser::LValContext::LeftBracket(size_t i) {
  return getToken(SysYParser::LeftBracket, i);
}

std::vector<SysYParser::ExpContext *> SysYParser::LValContext::exp() {
  return getRuleContexts<SysYParser::ExpContext>();
}

SysYParser::ExpContext* SysYParser::LValContext::exp(size_t i) {
  return getRuleContext<SysYParser::ExpContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::LValContext::RightBracket() {
  return getTokens(SysYParser::RightBracket);
}

tree::TerminalNode* SysYParser::LValContext::RightBracket(size_t i) {
  return getToken(SysYParser::RightBracket, i);
}


size_t SysYParser::LValContext::getRuleIndex() const {
  return SysYParser::RuleLVal;
}

void SysYParser::LValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLVal(this);
}

void SysYParser::LValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLVal(this);
}


std::any SysYParser::LValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitLVal(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::LValContext* SysYParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 36, SysYParser::RuleLVal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(254);
    match(SysYParser::Identifier);
    setState(261);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(255);
        match(SysYParser::LeftBracket);
        setState(256);
        exp();
        setState(257);
        match(SysYParser::RightBracket); 
      }
      setState(263);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExpContext ------------------------------------------------------------------

SysYParser::PrimaryExpContext::PrimaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::PrimaryExpContext::LeftParen() {
  return getToken(SysYParser::LeftParen, 0);
}

SysYParser::ExpContext* SysYParser::PrimaryExpContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

tree::TerminalNode* SysYParser::PrimaryExpContext::RightParen() {
  return getToken(SysYParser::RightParen, 0);
}

SysYParser::LValContext* SysYParser::PrimaryExpContext::lVal() {
  return getRuleContext<SysYParser::LValContext>(0);
}

tree::TerminalNode* SysYParser::PrimaryExpContext::Integer_const() {
  return getToken(SysYParser::Integer_const, 0);
}

tree::TerminalNode* SysYParser::PrimaryExpContext::Float_const() {
  return getToken(SysYParser::Float_const, 0);
}


size_t SysYParser::PrimaryExpContext::getRuleIndex() const {
  return SysYParser::RulePrimaryExp;
}

void SysYParser::PrimaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExp(this);
}

void SysYParser::PrimaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExp(this);
}


std::any SysYParser::PrimaryExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitPrimaryExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::PrimaryExpContext* SysYParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 38, SysYParser::RulePrimaryExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(271);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::LeftParen: {
        enterOuterAlt(_localctx, 1);
        setState(264);
        match(SysYParser::LeftParen);
        setState(265);
        exp();
        setState(266);
        match(SysYParser::RightParen);
        break;
      }

      case SysYParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(268);
        lVal();
        break;
      }

      case SysYParser::Integer_const: {
        enterOuterAlt(_localctx, 3);
        setState(269);
        match(SysYParser::Integer_const);
        break;
      }

      case SysYParser::Float_const: {
        enterOuterAlt(_localctx, 4);
        setState(270);
        match(SysYParser::Float_const);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExpContext ------------------------------------------------------------------

SysYParser::UnaryExpContext::UnaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::UnaryExpContext::getRuleIndex() const {
  return SysYParser::RuleUnaryExp;
}

void SysYParser::UnaryExpContext::copyFrom(UnaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PrimaryExprContext ------------------------------------------------------------------

SysYParser::PrimaryExpContext* SysYParser::PrimaryExprContext::primaryExp() {
  return getRuleContext<SysYParser::PrimaryExpContext>(0);
}

SysYParser::PrimaryExprContext::PrimaryExprContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void SysYParser::PrimaryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpr(this);
}
void SysYParser::PrimaryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpr(this);
}

std::any SysYParser::PrimaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SignExprContext ------------------------------------------------------------------

SysYParser::UnaryExpContext* SysYParser::SignExprContext::unaryExp() {
  return getRuleContext<SysYParser::UnaryExpContext>(0);
}

tree::TerminalNode* SysYParser::SignExprContext::Plus() {
  return getToken(SysYParser::Plus, 0);
}

tree::TerminalNode* SysYParser::SignExprContext::Minus() {
  return getToken(SysYParser::Minus, 0);
}

tree::TerminalNode* SysYParser::SignExprContext::Not() {
  return getToken(SysYParser::Not, 0);
}

SysYParser::SignExprContext::SignExprContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void SysYParser::SignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignExpr(this);
}
void SysYParser::SignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignExpr(this);
}

std::any SysYParser::SignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitSignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionExprContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::FunctionExprContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

tree::TerminalNode* SysYParser::FunctionExprContext::LeftParen() {
  return getToken(SysYParser::LeftParen, 0);
}

tree::TerminalNode* SysYParser::FunctionExprContext::RightParen() {
  return getToken(SysYParser::RightParen, 0);
}

SysYParser::FuncRParamsContext* SysYParser::FunctionExprContext::funcRParams() {
  return getRuleContext<SysYParser::FuncRParamsContext>(0);
}

SysYParser::FunctionExprContext::FunctionExprContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void SysYParser::FunctionExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionExpr(this);
}
void SysYParser::FunctionExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionExpr(this);
}

std::any SysYParser::FunctionExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFunctionExpr(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::UnaryExpContext* SysYParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 40, SysYParser::RuleUnaryExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(282);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SysYParser::PrimaryExprContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(273);
      primaryExp();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SysYParser::FunctionExprContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(274);
      match(SysYParser::Identifier);
      setState(275);
      match(SysYParser::LeftParen);
      setState(277);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8791371776) != 0)) {
        setState(276);
        funcRParams();
      }
      setState(279);
      match(SysYParser::RightParen);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<SysYParser::SignExprContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(280);
      antlrcpp::downCast<SignExprContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8791261184) != 0))) {
        antlrcpp::downCast<SignExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(281);
      unaryExp();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncRParamsContext ------------------------------------------------------------------

SysYParser::FuncRParamsContext::FuncRParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::ExpContext *> SysYParser::FuncRParamsContext::exp() {
  return getRuleContexts<SysYParser::ExpContext>();
}

SysYParser::ExpContext* SysYParser::FuncRParamsContext::exp(size_t i) {
  return getRuleContext<SysYParser::ExpContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::FuncRParamsContext::Comma() {
  return getTokens(SysYParser::Comma);
}

tree::TerminalNode* SysYParser::FuncRParamsContext::Comma(size_t i) {
  return getToken(SysYParser::Comma, i);
}


size_t SysYParser::FuncRParamsContext::getRuleIndex() const {
  return SysYParser::RuleFuncRParams;
}

void SysYParser::FuncRParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncRParams(this);
}

void SysYParser::FuncRParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncRParams(this);
}


std::any SysYParser::FuncRParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncRParams(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncRParamsContext* SysYParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 42, SysYParser::RuleFuncRParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(284);
    antlrcpp::downCast<FuncRParamsContext *>(_localctx)->expContext = exp();
    antlrcpp::downCast<FuncRParamsContext *>(_localctx)->params.push_back(antlrcpp::downCast<FuncRParamsContext *>(_localctx)->expContext);
    setState(289);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::Comma) {
      setState(285);
      match(SysYParser::Comma);
      setState(286);
      antlrcpp::downCast<FuncRParamsContext *>(_localctx)->expContext = exp();
      antlrcpp::downCast<FuncRParamsContext *>(_localctx)->params.push_back(antlrcpp::downCast<FuncRParamsContext *>(_localctx)->expContext);
      setState(291);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulExpContext ------------------------------------------------------------------

SysYParser::MulExpContext::MulExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::UnaryExpContext* SysYParser::MulExpContext::unaryExp() {
  return getRuleContext<SysYParser::UnaryExpContext>(0);
}

SysYParser::MulExpContext* SysYParser::MulExpContext::mulExp() {
  return getRuleContext<SysYParser::MulExpContext>(0);
}

tree::TerminalNode* SysYParser::MulExpContext::Star() {
  return getToken(SysYParser::Star, 0);
}

tree::TerminalNode* SysYParser::MulExpContext::Div() {
  return getToken(SysYParser::Div, 0);
}

tree::TerminalNode* SysYParser::MulExpContext::Mod() {
  return getToken(SysYParser::Mod, 0);
}


size_t SysYParser::MulExpContext::getRuleIndex() const {
  return SysYParser::RuleMulExp;
}

void SysYParser::MulExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExp(this);
}

void SysYParser::MulExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExp(this);
}


std::any SysYParser::MulExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitMulExp(this);
  else
    return visitor->visitChildren(this);
}


SysYParser::MulExpContext* SysYParser::mulExp() {
   return mulExp(0);
}

SysYParser::MulExpContext* SysYParser::mulExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, parentState);
  SysYParser::MulExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, SysYParser::RuleMulExp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(293);
    unaryExp();
    _ctx->stop = _input->LT(-1);
    setState(300);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<MulExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMulExp);
        setState(295);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(296);
        antlrcpp::downCast<MulExpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1879048192) != 0))) {
          antlrcpp::downCast<MulExpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(297);
        unaryExp(); 
      }
      setState(302);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AddExpContext ------------------------------------------------------------------

SysYParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::MulExpContext* SysYParser::AddExpContext::mulExp() {
  return getRuleContext<SysYParser::MulExpContext>(0);
}

SysYParser::AddExpContext* SysYParser::AddExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}

tree::TerminalNode* SysYParser::AddExpContext::Plus() {
  return getToken(SysYParser::Plus, 0);
}

tree::TerminalNode* SysYParser::AddExpContext::Minus() {
  return getToken(SysYParser::Minus, 0);
}


size_t SysYParser::AddExpContext::getRuleIndex() const {
  return SysYParser::RuleAddExp;
}

void SysYParser::AddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExp(this);
}

void SysYParser::AddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExp(this);
}


std::any SysYParser::AddExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitAddExp(this);
  else
    return visitor->visitChildren(this);
}


SysYParser::AddExpContext* SysYParser::addExp() {
   return addExp(0);
}

SysYParser::AddExpContext* SysYParser::addExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, parentState);
  SysYParser::AddExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, SysYParser::RuleAddExp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(304);
    mulExp(0);
    _ctx->stop = _input->LT(-1);
    setState(311);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AddExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAddExp);
        setState(306);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(307);
        antlrcpp::downCast<AddExpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == SysYParser::Plus

        || _la == SysYParser::Minus)) {
          antlrcpp::downCast<AddExpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(308);
        mulExp(0); 
      }
      setState(313);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelExpContext ------------------------------------------------------------------

SysYParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::AddExpContext* SysYParser::RelExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}

SysYParser::RelExpContext* SysYParser::RelExpContext::relExp() {
  return getRuleContext<SysYParser::RelExpContext>(0);
}

tree::TerminalNode* SysYParser::RelExpContext::LessEqual() {
  return getToken(SysYParser::LessEqual, 0);
}

tree::TerminalNode* SysYParser::RelExpContext::GreaterEqual() {
  return getToken(SysYParser::GreaterEqual, 0);
}

tree::TerminalNode* SysYParser::RelExpContext::Less() {
  return getToken(SysYParser::Less, 0);
}

tree::TerminalNode* SysYParser::RelExpContext::Greater() {
  return getToken(SysYParser::Greater, 0);
}


size_t SysYParser::RelExpContext::getRuleIndex() const {
  return SysYParser::RuleRelExp;
}

void SysYParser::RelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExp(this);
}

void SysYParser::RelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExp(this);
}


std::any SysYParser::RelExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitRelExp(this);
  else
    return visitor->visitChildren(this);
}


SysYParser::RelExpContext* SysYParser::relExp() {
   return relExp(0);
}

SysYParser::RelExpContext* SysYParser::relExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, parentState);
  SysYParser::RelExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, SysYParser::RuleRelExp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(315);
    addExp(0);
    _ctx->stop = _input->LT(-1);
    setState(322);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<RelExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelExp);
        setState(317);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(318);
        antlrcpp::downCast<RelExpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 62914560) != 0))) {
          antlrcpp::downCast<RelExpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(319);
        addExp(0); 
      }
      setState(324);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqExpContext ------------------------------------------------------------------

SysYParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::RelExpContext* SysYParser::EqExpContext::relExp() {
  return getRuleContext<SysYParser::RelExpContext>(0);
}

SysYParser::EqExpContext* SysYParser::EqExpContext::eqExp() {
  return getRuleContext<SysYParser::EqExpContext>(0);
}

tree::TerminalNode* SysYParser::EqExpContext::Equal() {
  return getToken(SysYParser::Equal, 0);
}

tree::TerminalNode* SysYParser::EqExpContext::NotEqual() {
  return getToken(SysYParser::NotEqual, 0);
}


size_t SysYParser::EqExpContext::getRuleIndex() const {
  return SysYParser::RuleEqExp;
}

void SysYParser::EqExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExp(this);
}

void SysYParser::EqExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExp(this);
}


std::any SysYParser::EqExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitEqExp(this);
  else
    return visitor->visitChildren(this);
}


SysYParser::EqExpContext* SysYParser::eqExp() {
   return eqExp(0);
}

SysYParser::EqExpContext* SysYParser::eqExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, parentState);
  SysYParser::EqExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, SysYParser::RuleEqExp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(326);
    relExp(0);
    _ctx->stop = _input->LT(-1);
    setState(333);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<EqExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEqExp);
        setState(328);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(329);
        antlrcpp::downCast<EqExpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == SysYParser::Equal

        || _la == SysYParser::NotEqual)) {
          antlrcpp::downCast<EqExpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(330);
        relExp(0); 
      }
      setState(335);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LAndExpContext ------------------------------------------------------------------

SysYParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::EqExpContext* SysYParser::LAndExpContext::eqExp() {
  return getRuleContext<SysYParser::EqExpContext>(0);
}

SysYParser::LAndExpContext* SysYParser::LAndExpContext::lAndExp() {
  return getRuleContext<SysYParser::LAndExpContext>(0);
}

tree::TerminalNode* SysYParser::LAndExpContext::And() {
  return getToken(SysYParser::And, 0);
}


size_t SysYParser::LAndExpContext::getRuleIndex() const {
  return SysYParser::RuleLAndExp;
}

void SysYParser::LAndExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLAndExp(this);
}

void SysYParser::LAndExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLAndExp(this);
}


std::any SysYParser::LAndExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitLAndExp(this);
  else
    return visitor->visitChildren(this);
}


SysYParser::LAndExpContext* SysYParser::lAndExp() {
   return lAndExp(0);
}

SysYParser::LAndExpContext* SysYParser::lAndExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, parentState);
  SysYParser::LAndExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, SysYParser::RuleLAndExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(337);
    eqExp(0);
    _ctx->stop = _input->LT(-1);
    setState(344);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LAndExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLAndExp);
        setState(339);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(340);
        match(SysYParser::And);
        setState(341);
        eqExp(0); 
      }
      setState(346);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LOrExpContext ------------------------------------------------------------------

SysYParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::LAndExpContext* SysYParser::LOrExpContext::lAndExp() {
  return getRuleContext<SysYParser::LAndExpContext>(0);
}

SysYParser::LOrExpContext* SysYParser::LOrExpContext::lOrExp() {
  return getRuleContext<SysYParser::LOrExpContext>(0);
}

tree::TerminalNode* SysYParser::LOrExpContext::Or() {
  return getToken(SysYParser::Or, 0);
}


size_t SysYParser::LOrExpContext::getRuleIndex() const {
  return SysYParser::RuleLOrExp;
}

void SysYParser::LOrExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLOrExp(this);
}

void SysYParser::LOrExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLOrExp(this);
}


std::any SysYParser::LOrExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitLOrExp(this);
  else
    return visitor->visitChildren(this);
}


SysYParser::LOrExpContext* SysYParser::lOrExp() {
   return lOrExp(0);
}

SysYParser::LOrExpContext* SysYParser::lOrExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, parentState);
  SysYParser::LOrExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 54;
  enterRecursionRule(_localctx, 54, SysYParser::RuleLOrExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(348);
    lAndExp(0);
    _ctx->stop = _input->LT(-1);
    setState(355);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LOrExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLOrExp);
        setState(350);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(351);
        match(SysYParser::Or);
        setState(352);
        lAndExp(0); 
      }
      setState(357);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstExpContext ------------------------------------------------------------------

SysYParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::AddExpContext* SysYParser::ConstExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}

SysYParser::MulExpContext* SysYParser::ConstExpContext::mulExp() {
  return getRuleContext<SysYParser::MulExpContext>(0);
}

SysYParser::UnaryExpContext* SysYParser::ConstExpContext::unaryExp() {
  return getRuleContext<SysYParser::UnaryExpContext>(0);
}

SysYParser::RelExpContext* SysYParser::ConstExpContext::relExp() {
  return getRuleContext<SysYParser::RelExpContext>(0);
}

SysYParser::EqExpContext* SysYParser::ConstExpContext::eqExp() {
  return getRuleContext<SysYParser::EqExpContext>(0);
}

SysYParser::LAndExpContext* SysYParser::ConstExpContext::lAndExp() {
  return getRuleContext<SysYParser::LAndExpContext>(0);
}

SysYParser::LOrExpContext* SysYParser::ConstExpContext::lOrExp() {
  return getRuleContext<SysYParser::LOrExpContext>(0);
}


size_t SysYParser::ConstExpContext::getRuleIndex() const {
  return SysYParser::RuleConstExp;
}

void SysYParser::ConstExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExp(this);
}

void SysYParser::ConstExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExp(this);
}


std::any SysYParser::ConstExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstExpContext* SysYParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 56, SysYParser::RuleConstExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(365);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(358);
      addExp(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(359);
      mulExp(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(360);
      unaryExp();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(361);
      relExp(0);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(362);
      eqExp(0);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(363);
      lAndExp(0);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(364);
      lOrExp(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool SysYParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 22: return mulExpSempred(antlrcpp::downCast<MulExpContext *>(context), predicateIndex);
    case 23: return addExpSempred(antlrcpp::downCast<AddExpContext *>(context), predicateIndex);
    case 24: return relExpSempred(antlrcpp::downCast<RelExpContext *>(context), predicateIndex);
    case 25: return eqExpSempred(antlrcpp::downCast<EqExpContext *>(context), predicateIndex);
    case 26: return lAndExpSempred(antlrcpp::downCast<LAndExpContext *>(context), predicateIndex);
    case 27: return lOrExpSempred(antlrcpp::downCast<LOrExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SysYParser::mulExpSempred(MulExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::addExpSempred(AddExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::relExpSempred(RelExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::eqExpSempred(EqExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void SysYParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  sysyParserInitialize();
#else
  ::antlr4::internal::call_once(sysyParserOnceFlag, sysyParserInitialize);
#endif
}
