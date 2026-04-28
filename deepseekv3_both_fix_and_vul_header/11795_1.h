#include <string>
#include <sstream>

struct Expression {
    enum Type { NULL_VAL };
    Type concrete_type() const;
    struct PState {
    };
    PState pstate() const;
    std::string to_string(const void* options) const;
};

struct String_Constant {
    void quote_mark(int);
};

template<typename T>
T* Cast(Expression*);

struct Env {};
struct Signature {};
struct ParserState {
    const char* src;
};
struct Backtraces {};
struct Context {
    void* c_options;
};
struct Selector_List {
    size_t length() const;
    struct Complex_Selector* first() const;
};
struct Complex_Selector {
    struct Compound_Selector* head() const;
    Complex_Selector* tail() const;
};
struct Compound_Selector {};

using Expression_Obj = Expression*;
using String_Constant_Ptr = String_Constant*;
using Selector_List_Obj = Selector_List*;
using Complex_Selector_Obj = Complex_Selector*;
using Compound_Selector_Obj = Compound_Selector*;

namespace Parser {
    Selector_List* parse_selector(const char*, Context&, Backtraces, Expression::PState, const char*, bool = false);
}

void error(const std::string&, Expression::PState, Backtraces);
std::string function_name(Signature);
Expression* ARG(const std::string&, const char*);

struct ExpressionType {};
const char* Expression = "Expression";