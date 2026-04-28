#include <vector>
#include <string>
#include <memory>

class Expression {
public:
    std::vector<Expression*> operands;
};

class Module {
public:
    std::allocator<Expression*> allocator;
};

class CustomCopier {
public:
    Expression* operator()(Expression* curr) { return nullptr; }
};

class Builder;
class Block {
public:
    std::vector<Expression*> list;
    std::string name;
    int type;
};

class If {
public:
    Expression* condition;
    Expression* ifTrue;
    Expression* ifFalse;
    int type;
};

class Loop {
public:
    std::string name;
    Expression* body;
};

class Break {
public:
    std::string name;
    Expression* value;
    Expression* condition;
};

class Switch {
public:
    std::vector<std::string> targets;
    std::string default_;
    Expression* condition;
    Expression* value;
};

class Call {
public:
    std::string target;
    std::vector<Expression*> operands;
    int type;
    bool isReturn;
};

class CallIndirect {
public:
    std::string fullType;
    Expression* target;
    std::vector<Expression*> operands;
    int type;
    bool isReturn;
};

class LocalGet {
public:
    unsigned index;
    int type;
};

class LocalSet {
public:
    unsigned index;
    Expression* value;
    bool isTee() { return false; }
};

class GlobalGet {
public:
    std::string name;
    int type;
};

class GlobalSet {
public:
    std::string name;
    Expression* value;
};

class Load {
public:
    bool isAtomic;
    unsigned bytes;
    unsigned offset;
    bool signed_;
    unsigned align;
    Expression* ptr;
    int type;
};

class Store {
public:
    bool isAtomic;
    unsigned bytes;
    unsigned offset;
    unsigned align;
    Expression* ptr;
    Expression* value;
    int valueType;
};

class AtomicRMW {
public:
    int op;
    unsigned bytes;
    unsigned offset;
    Expression* ptr;
    Expression* value;
    int type;
};

class AtomicCmpxchg {
public:
    unsigned bytes;
    unsigned offset;
    Expression* ptr;
    Expression* expected;
    Expression* replacement;
    int type;
};

class AtomicWait {
public:
    Expression* ptr;
    Expression* expected;
    Expression* timeout;
    int expectedType;
    unsigned offset;
};

class AtomicNotify {
public:
    Expression* ptr;
    Expression* notifyCount;
    unsigned offset;
};

class SIMDExtract {
public:
    int op;
    Expression* vec;
    unsigned index;
};

class SIMDReplace {
public:
    int op;
    Expression* vec;
    unsigned index;
    Expression* value;
};

class SIMDShuffle {
public:
    Expression* left;
    Expression* right;
    std::vector<uint8_t> mask;
};

class SIMDBitselect {
public:
    Expression* left;
    Expression* right;
    Expression* cond;
};

class SIMDShift {
public:
    int op;
    Expression* vec;
    Expression* shift;
};

class Const {
public:
    int value;
};

class MemoryInit {
public:
    std::string segment;
    Expression* dest;
    Expression* offset;
    Expression* size;
};

class DataDrop {
public:
    std::string segment;
};

class MemoryCopy {
public:
    Expression* dest;
    Expression* source;
    Expression* size;
};

class MemoryFill {
public:
    Expression* dest;
    Expression* value;
    Expression* size;
};

class Unary {
public:
    int op;
    Expression* value;
};

class Binary {
public:
    int op;
    Expression* left;
    Expression* right;
};

class Select {
public:
    Expression* condition;
    Expression* ifTrue;
    Expression* ifFalse;
};

class Drop {
public:
    Expression* value;
};

class Return {
public:
    Expression* value;
};

class Host {
public:
    int op;
    std::string nameOperand;
    std::vector<Expression*> operands;
};

class Nop {};
class Unreachable {};

class Push {
public:
    int value;
};

class Pop {
public:
    int type;
};

using Index = unsigned int;
using Name = std::string;
using Type = int;
using Value = int;

template<typename Derived, typename Result>
class OverriddenVisitor {
public:
    Result visit(Expression* curr) { return static_cast<Derived*>(this)->visit(curr); }
};

class ExpressionList {
public:
    ExpressionList(std::allocator<Expression*> allocator) {}
    void push_back(Expression* expr) {}
};

class LoadUtils {
public:
    static bool isSignRelevant(Load* load) { return false; }
};

class Builder {
public:
    Builder(Module& wasm) {}
    Expression* makeBlock(Name name, ExpressionList list, Type type) { return nullptr; }
    Expression* makeIf(Expression* condition, Expression* ifTrue, Expression* ifFalse, Type type) { return nullptr; }
    Expression* makeLoop(Name name, Expression* body) { return nullptr; }
    Expression* makeBreak(Name name, Expression* value, Expression* condition) { return nullptr; }
    Expression* makeSwitch(std::vector<Name> targets, Name default_, Expression* condition, Expression* value) { return nullptr; }
    Expression* makeCall(Name target, std::vector<Expression*> operands, Type type, bool isReturn) { return nullptr; }
    Expression* makeCallIndirect(Name fullType, Expression* target, std::vector<Expression*> operands, Type type, bool isReturn) { return nullptr; }
    Expression* makeLocalGet(Index index, Type type) { return nullptr; }
    Expression* makeLocalSet(Index index, Expression* value) { return nullptr; }
    Expression* makeLocalTee(Index index, Expression* value) { return nullptr; }
    Expression* makeGlobalGet(Name name, Type type) { return nullptr; }
    Expression* makeGlobalSet(Name name, Expression* value) { return nullptr; }
    Expression* makeAtomicLoad(unsigned bytes, unsigned offset, Expression* ptr, Type type) { return nullptr; }
    Expression* makeLoad(unsigned bytes, bool signed_, unsigned offset, unsigned align, Expression* ptr, Type type) { return nullptr; }
    Expression* makeStore(unsigned bytes, unsigned offset, unsigned align, Expression* ptr, Expression* value, Type valueType) { return nullptr; }
    Expression* makeAtomicStore(unsigned bytes, unsigned offset, Expression* ptr, Expression* value, Type valueType) { return nullptr; }
    Expression* makeAtomicRMW(int op, unsigned bytes, unsigned offset, Expression* ptr, Expression* value, Type type) { return nullptr; }
    Expression* makeAtomicCmpxchg(unsigned bytes, unsigned offset, Expression* ptr, Expression* expected, Expression* replacement, Type type) { return nullptr; }
    Expression* makeAtomicWait(Expression* ptr, Expression* expected, Expression* timeout, Type expectedType, unsigned offset) { return nullptr; }
    Expression* makeAtomicNotify(Expression* ptr, Expression* notifyCount, unsigned offset) { return nullptr; }
    Expression* makeSIMDExtract(int op, Expression* vec, unsigned index) { return nullptr; }
    Expression* makeSIMDReplace(int op, Expression* vec, unsigned index, Expression* value) { return nullptr; }
    Expression* makeSIMDShuffle(Expression* left, Expression* right, std::vector<uint8_t> mask) { return nullptr; }
    Expression* makeSIMDBitselect(Expression* left, Expression* right, Expression* cond) { return nullptr; }
    Expression* makeSIMDShift(int op, Expression* vec, Expression* shift) { return nullptr; }
    Expression* makeConst(Value value) { return nullptr; }
    Expression* makeMemoryInit(Name segment, Expression* dest, Expression* offset, Expression* size) { return nullptr; }
    Expression* makeDataDrop(Name segment) { return nullptr; }
    Expression* makeMemoryCopy(Expression* dest, Expression* source, Expression* size) { return nullptr; }
    Expression* makeMemoryFill(Expression* dest, Expression* value, Expression* size) { return nullptr; }
    Expression* makeUnary(int op, Expression* value) { return nullptr; }
    Expression* makeBinary(int op, Expression* left, Expression* right) { return nullptr; }
    Expression* makeSelect(Expression* condition, Expression* ifTrue, Expression* ifFalse) { return nullptr; }
    Expression* makeDrop(Expression* value) { return nullptr; }
    Expression* makeReturn(Expression* value) { return nullptr; }
    Expression* makeHost(int op, Name nameOperand, std::vector<Expression*> operands) { return nullptr; }
    Expression* makeNop() { return nullptr; }
    Expression* makeUnreachable() { return nullptr; }
    Expression* makePush(Value value) { return nullptr; }
    Expression* makePop(Type type) { return nullptr; }
};