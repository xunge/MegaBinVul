#include <vector>
#include <iterator>

using Index = unsigned;

enum Nullability { Nullable, NonNullable };
enum RefAsOp { RefAsNonNull };

class HeapType {
public:
    // 添加必要的HeapType成员函数
};

class Type {
public:
    bool isTuple() const;
    bool isNonNullable() const;
    HeapType getHeapType() const;
    size_t size() const;
    Type operator[](Index i) const;
    Type(HeapType, Nullability);
    Type(const class Tuple&);
    bool operator!=(const Type& other) const;
    const Type* begin() const;
    const Type* end() const;
};

struct Tuple {
    Tuple(const std::vector<Type>& types);
};

class WasmFeatures {
public:
    bool hasGCNNLocals() const;
};

class Wasm {
public:
    WasmFeatures features;
};

class Expression {
public:
    Type type;
};

class Builder {
public:
    Builder(Wasm&);
    Expression* makeLocalSet(Index, Expression*);
    Expression* makeLocalGet(Index, Type);
    Expression* makeTupleExtract(Expression*, Index);
    Expression* makeRefAs(RefAsOp, Expression*);
    Index addVar(Expression*, Type);
};

class WasmBinaryBuilder {
public:
    void pushExpression(Expression* curr);
    void requireFunctionContext(const char*);
    Wasm wasm;
    Expression* currFunction;
    std::vector<Expression*> expressionStack;
};