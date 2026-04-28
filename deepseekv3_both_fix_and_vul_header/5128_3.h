#include <vector>
#include <cassert>
#include <iostream>
#include <cstdint>
#include <stdexcept>

using Index = uint32_t;

class Type;
class Expression;
class FunctionType;
class Import;
class Call;
class WasmModule;

extern bool debug;
extern std::vector<FunctionType*> functionTypes;
extern std::vector<Import*> functionImports;
extern std::vector<std::vector<Call*>> functionCalls;
extern WasmModule wasm;

class Type {};

class FunctionType {
public:
    std::vector<Type> params;
    Type result;
};

class Import {
public:
    Type type;
};

class Expression {};

class Call {
public:
    std::vector<Expression*> operands;
    Type type;
    void finalize();
};

class WasmBinaryBuilder {
public:
    uint32_t getU32LEB();
    Expression* popNonVoidExpression();
    void throwError(const char* msg);
    void visitCall(Call* curr);
    void finalize();
};

class WasmModule {
public:
    FunctionType* getFunctionType(Type type);
};