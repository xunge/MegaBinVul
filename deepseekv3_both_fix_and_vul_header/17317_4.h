#include <string>
#include <memory>

class String;
class String_Constant;
class Expression;
class Block;
class Declaration;
class Context;

typedef std::shared_ptr<String> String_Obj;
typedef std::shared_ptr<Expression> Expression_Obj;
typedef std::shared_ptr<Block> Block_Obj;
typedef std::shared_ptr<Declaration> Declaration_Ptr;
typedef std::shared_ptr<Declaration> Statement_Ptr;

#define SASS_MEMORY_NEW(T, ...) std::make_shared<T>(__VA_ARGS__)

struct ParserState {
    // implementation details
};

struct Context {
    struct Options {
        // implementation details
    } c_options;
};

class Expand {
public:
    Expression_Obj eval;
    Context ctx;
    Block_Obj operator()(Block_Obj block);
    Statement_Ptr operator()(Declaration_Ptr d);
    template<typename T> std::shared_ptr<T> Cast(Expression_Obj expr);
};

class String {
public:
    ParserState pstate();
    Expression_Obj perform(Expression_Obj* eval);
};

class String_Constant : public String {
public:
    String_Constant(ParserState pstate, std::string str);
};

class Expression {
public:
    std::string to_string(Context::Options options);
    bool is_invisible();
    Expression_Obj perform(Expression_Obj* eval);
};

class Block {
    // implementation details
};

class Declaration {
public:
    Block_Obj block();
    String_Obj property();
    Expression_Obj value();
    ParserState pstate();
    bool is_important();
    bool is_custom_property();
    int tabs();
    void tabs(int tabs);
    Declaration(ParserState pstate, String_Obj prop, Expression_Obj val, bool important, bool custom, Block_Obj block);
};