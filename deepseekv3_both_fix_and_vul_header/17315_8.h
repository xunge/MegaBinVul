#include <string>
#include <memory>

struct Token {
    const char* begin;
    const char* end;
    Token(const char* b, const char* e) : begin(b), end(e) {}
};

struct String_Constant {
    String_Constant(const char* p, const std::string& s) : p(p), s(s) {}
    const char* p;
    std::string s;
};

struct String_Obj {
    String_Obj() {}
    String_Obj(std::nullptr_t) {}
    String_Obj(String_Obj&&) {}
    String_Obj(const String_Obj&) {}
    String_Obj(String_Constant* sc) {}
    String_Obj(int) {}
    template<typename T, typename... Args>
    String_Obj(Args&&... args) {}
};

template<char c>
struct exactly {};

struct Parser {
    const char* position;
    const char* pstate;
    struct {
        std::string to_string() { return ""; }
    } lexed;

    template<typename T>
    bool lex(bool) { return false; }

    template<typename T>
    bool peek() { return false; }

    template<typename T>
    bool peek(const char*) { return false; }

    template<typename T, typename U>
    const char* sequence(const char*) { return nullptr; }

    String_Obj parse_interpolated_chunk(Token) { return String_Obj(); }
    String_Obj parse_url_function_argument();
};

namespace Util {
    std::string rtrim(const std::string&) { return ""; }
}

#define SASS_MEMORY_NEW(T, ...) String_Obj(new T(__VA_ARGS__))
#define hash_lbrace '{'
#define real_uri_value int
#define interpolant int