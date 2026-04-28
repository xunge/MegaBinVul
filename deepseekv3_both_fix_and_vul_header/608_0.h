#include <vector>
#include <memory>

class Expression {
public:
    std::vector<Expression*> operands;
};

class Module {
public:
    std::allocator<Expression*> allocator;
};

class Builder {
public:
    Builder(Module& wasm);
    Expression* makeBlock(const char* name, std::vector<Expression*>& list, int type);
    Expression* makeIf(Expression* cond, Expression* ifTrue, Expression* ifFalse, int type);
    Expression* makeLoop(const char* name, Expression* body);
    Expression* makeBreak(const char* name, Expression* value, Expression* cond);
    Expression* makeSwitch(std::vector<const char*>& targets, const char* default_, Expression* cond, Expression* value);
    Expression* makeCall(const char* target, std::vector<Expression*>, int type, bool isReturn);
    Expression* makeCallIndirect(int fullType, Expression* target, std::vector<Expression*>, int type, bool isReturn);
    Expression* makeLocalGet(int index, int type);
    Expression* makeLocalSet(int index, Expression* value);
    Expression* makeLocalTee(int index, Expression* value);
    Expression* makeGlobalGet(const char* name, int type);
    Expression* makeGlobalSet(const char* name, Expression* value);
    Expression* makeAtomicLoad(int bytes, int offset, Expression* ptr, int type);
    Expression* makeLoad(int bytes, bool signed_, int offset, int align, Expression* ptr, int type);
    Expression* makeAtomicStore(int bytes, int offset, Expression* ptr, Expression* value, int valueType);
    Expression* makeStore(int bytes, int offset, int align, Expression* ptr, Expression* value, int valueType);
    Expression* makeAtomicRMW(int op, int bytes, int offset, Expression* ptr, Expression* value, int type);
    Expression* makeAtomicCmpxchg(int bytes, int offset, Expression* ptr, Expression* expected, Expression* replacement, int type);
    Expression* makeAtomicWait(Expression* ptr, Expression* expected, Expression* timeout, int expectedType, int offset);
    Expression* makeAtomicNotify(Expression* ptr, Expression* notifyCount, int offset);
    Expression* makeSIMDExtract(int op, Expression* vec, int index);
    Expression* makeSIMDReplace(int op, Expression* vec, int index, Expression* value);
    Expression* makeSIMDShuffle(Expression* left, Expression* right, std::vector<int>& mask);
    Expression* makeSIMDBitselect(Expression* left, Expression* right, Expression* cond);
    Expression* makeSIMDShift(int op, Expression* vec, Expression* shift);
    Expression* makeConst(int value);
    Expression* makeMemoryInit(int segment, Expression* dest, Expression* offset, Expression* size);
    Expression* makeDataDrop(int segment);
    Expression* makeMemoryCopy(Expression* dest, Expression* source, Expression* size);
    Expression* makeMemoryFill(Expression* dest, Expression* value, Expression* size);
    Expression* makeUnary(int op, Expression* value);
    Expression* makeBinary(int op, Expression* left, Expression* right);
    Expression* makeSelect(Expression* cond, Expression* ifTrue, Expression* ifFalse);
    Expression* makeDrop(Expression* value);
    Expression* makeReturn(Expression* value);
    Expression* makeHost(int op, const char* nameOperand, std::vector<Expression*>&& operands);
    Expression* makeNop();
    Expression* makeUnreachable();
    Expression* makePush(Expression* value);
    Expression* makePop(int type);
};

class Block : public Expression {
public:
    const char* name;
    std::vector<Expression*> list;
    int type;
};

class If : public Expression {
public:
    Expression* condition;
    Expression* ifTrue;
    Expression* ifFalse;
    int type;
};

class Loop : public Expression {
public:
    const char* name;
    Expression* body;
};

class Break : public Expression {
public:
    const char* name;
    Expression* value;
    Expression* condition;
};

class Switch : public Expression {
public:
    std::vector<const char*> targets;
    const char* default_;
    Expression* condition;
    Expression* value;
};

class Call : public Expression {
public:
    const char* target;
    std::vector<Expression*> operands;
    int type;
    bool isReturn;
};

class CallIndirect : public Expression {
public:
    int fullType;
    Expression* target;
    std::vector<Expression*> operands;
    int type;
    bool isReturn;
};

class LocalGet : public Expression {
public:
    int index;
    int type;
};

class LocalSet : public Expression {
public:
    int index;
    Expression* value;
    bool isTee();
};

class GlobalGet : public Expression {
public:
    const char* name;
    int type;
};

class GlobalSet : public Expression {
public:
    const char* name;
    Expression* value;
};

class Load : public Expression {
public:
    int bytes;
    int offset;
    Expression* ptr;
    int type;
    bool isAtomic;
    bool signed_;
    int align;
};

class Store : public Expression {
public:
    int bytes;
    int offset;
    Expression* ptr;
    Expression* value;
    bool isAtomic;
    int align;
    int valueType;
};

class AtomicRMW : public Expression {
public:
    int op;
    int bytes;
    int offset;
    Expression* ptr;
    Expression* value;
    int type;
};

class AtomicCmpxchg : public Expression {
public:
    int bytes;
    int offset;
    Expression* ptr;
    Expression* expected;
    Expression* replacement;
    int type;
};

class AtomicWait : public Expression {
public:
    Expression* ptr;
    Expression* expected;
    Expression* timeout;
    int expectedType;
    int offset;
};

class AtomicNotify : public Expression {
public:
    Expression* ptr;
    Expression* notifyCount;
    int offset;
};

class SIMDExtract : public Expression {
public:
    int op;
    Expression* vec;
    int index;
};

class SIMDReplace : public Expression {
public:
    int op;
    Expression* vec;
    int index;
    Expression* value;
};

class SIMDShuffle : public Expression {
public:
    Expression* left;
    Expression* right;
    std::vector<int> mask;
};

class SIMDBitselect : public Expression {
public:
    Expression* left;
    Expression* right;
    Expression* cond;
};

class SIMDShift : public Expression {
public:
    int op;
    Expression* vec;
    Expression* shift;
};

class Const : public Expression {
public:
    int value;
};

class MemoryInit : public Expression {
public:
    int segment;
    Expression* dest;
    Expression* offset;
    Expression* size;
};

class DataDrop : public Expression {
public:
    int segment;
};

class MemoryCopy : public Expression {
public:
    Expression* dest;
    Expression* source;
    Expression* size;
};

class MemoryFill : public Expression {
public:
    Expression* dest;
    Expression* value;
    Expression* size;
};

class Unary : public Expression {
public:
    int op;
    Expression* value;
};

class Binary : public Expression {
public:
    int op;
    Expression* left;
    Expression* right;
};

class Select : public Expression {
public:
    Expression* condition;
    Expression* ifTrue;
    Expression* ifFalse;
};

class Drop : public Expression {
public:
    Expression* value;
};

class Return : public Expression {
public:
    Expression* value;
};

class Host : public Expression {
public:
    int op;
    const char* nameOperand;
    std::vector<Expression*> operands;
};

class Nop : public Expression {};

class Unreachable : public Expression {};

class Push : public Expression {
public:
    Expression* value;
};

class Pop : public Expression {
public:
    int type;
};

namespace LoadUtils {
    bool isSignRelevant(Load* load);
};

template<typename SubType, typename RetType> class Visitor {
public:
    RetType visit(Expression* curr);
};

template<typename SubType, typename RetType> class OverriddenVisitor : public Visitor<SubType, RetType> {
public:
    RetType visit(Expression* curr);
};

using Index = size_t;
using CustomCopier = Expression*(*)(Expression*);
using ExpressionList = std::vector<Expression*>;