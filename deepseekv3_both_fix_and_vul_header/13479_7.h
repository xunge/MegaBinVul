#include <cstddef>
#include <cstdint>

enum class TokenType {
  Eof,
  Lpar,
  Rpar,
  LparAnn,
  Int,
  Nat,
  AlignEqNat,
  OffsetEqNat
};

struct Token {
  TokenType type;
  const char* text;
  std::size_t length;
};

class WastLexer {
public:
  Token GetToken();
  
private:
  const char* cursor_;
  const char* token_start_;
  
  char PeekChar();
  bool MatchString(const char* str);
  bool ReadBlockComment();
  bool ReadLineComment();
  void ReadChar();
  void ReadWhitespace();
  Token GetStringToken();
  Token GetInfToken();
  Token GetNanToken();
  Token GetHexNumberToken(TokenType type);
  Token GetNumberToken(TokenType type);
  Token GetReservedToken();
  Token GetKeywordToken();
  Token GetIdChars();
  Token GetIdToken();
  Token GetNameEqNumToken(const char* str, TokenType type);
  bool IsKeyword(char c);
  bool IsIdChar(char c);
  
  Token BareToken(TokenType type) {
    return Token{type, nullptr, 0};
  }
  
  Token TextToken(TokenType type, std::size_t length) {
    return Token{type, token_start_, length};
  }
  
  void ERROR(const char* msg) {}
  
  static constexpr char kEof = -1;
};