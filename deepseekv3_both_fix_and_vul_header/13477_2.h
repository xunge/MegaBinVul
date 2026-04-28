#include <cassert>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

enum class TokenType { Rpar };
enum class Result { Ok };

struct Token {
  std::string_view text() const;
};

struct ExprList {
  void push_back(std::unique_ptr<class CodeMetadataExpr>);
};

class CodeMetadataExpr {
public:
  CodeMetadataExpr(std::string_view, std::vector<uint8_t>&&);
};

class WastParser {
public:
  Result ParseCodeMetadataAnnotation(ExprList* exprs);
  Token Consume();
  Result ParseQuotedText(std::string*, bool);
  TokenType Peek();
};

#define WABT_TRACE(x)
#define WABT_USE(x)
#define CHECK_RESULT(x) x
#define EXPECT(x)