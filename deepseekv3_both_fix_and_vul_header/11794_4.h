#include <string>
#include <sstream>
#include <memory>

struct ContextOptions {};

struct Expression {
    enum { NULL_VAL };
    virtual ~Expression() = default;
    virtual int concrete_type();
    struct ParserState pstate();
    virtual std::string to_string(const ContextOptions&);
};

struct String_Constant : Expression {
    void quote_mark(int);
};

struct ParserState {
    std::string src;
};

struct Context {
    ContextOptions c_options;
};

struct Backtraces {};
struct Signature {};

struct Selector_List_Obj {};
using Expression_Obj = std::shared_ptr<Expression>;
using String_Constant_Ptr = std::shared_ptr<String_Constant>;

template<typename T, typename U>
std::shared_ptr<T> Cast(const std::shared_ptr<U>& u) {
    return std::dynamic_pointer_cast<T>(u);
}

#define ARG(argname, type) std::make_shared<type>()

namespace Parser {
    Selector_List_Obj parse_selector(const char*, Context&, Backtraces, ParserState, const std::string&, bool);
    Selector_List_Obj parse_selector(const char*, Context&, Backtraces, ParserState, const std::string&);
}

void error(const std::string&, ParserState, Backtraces);
std::string function_name(Signature);

struct Env {};