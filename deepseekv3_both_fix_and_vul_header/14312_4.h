#include <vector>
#include <cstdint>

using Index = uint32_t;
using Type = int32_t;

struct Expression {
    virtual ~Expression() = default;
};

struct Block {
    Type type;
    std::vector<Expression*> list;
    void finalize(Type type);
};

struct Builder {
    Builder(void* wasm);
    Expression* makeLocalSet(Index index, Expression* value);
};

struct LetData {
    Index numNewVars;
    Index absoluteStart;
};

class WasmBinaryBuilder {
public:
    void visitLet(Block* curr);
private:
    std::vector<LetData> letStack;
    struct FunctionContext {
        std::vector<Type> vars;
    };
    FunctionContext* currFunction;
    void* wasm;
    
    void startControlFlow(Block* curr);
    Type getType();
    void requireFunctionContext(const char* str);
    void readVars();
    Expression* popNonVoidExpression();
    Expression* getBlockOrSingleton(Type type);
};