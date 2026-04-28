#include <vector>
#include <string>

enum class TokenType {
    Lpar,
    LparAnn,
    Rpar,
    Eof,
    Invalid
};

struct Loc {
};

struct Token {
    Loc loc;
    TokenType token_type_;
    std::string text_;

    Token(Loc l, TokenType type) : loc(l), token_type_(type) {}
    TokenType token_type() const { return token_type_; }
    std::string text() const { return text_; }
    std::string to_string() const { return ""; }
};

struct Features {
    bool annotations_enabled() const { return false; }
    bool code_metadata_enabled() const { return false; }
};

struct Options {
    Features features;
};

class Lexer {
public:
    Token GetToken() { return Token(Loc(), TokenType::Eof); }
};

class WastParser {
    std::vector<Token> tokens_;
    Lexer* lexer_;
    Options* options_;

public:
    TokenType Peek(size_t n);
    void Error(Loc loc, const char* msg, ...) {}
};