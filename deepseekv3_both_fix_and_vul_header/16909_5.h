#include <vector>
#include <map>
#include <cstdlib>
#include <cstdint>

using Index = uint32_t;

class Type {
public:
    bool operator!=(const Type& other) const { return false; }
};

class Name {
public:
    bool is() const { return false; }
    bool operator==(const Name& other) const { return false; }
    bool operator!=(const Name& other) const { return false; }
    bool operator<(const Name& other) const { return false; }
};

class Expression {
public:
    enum class Id {
        BlockId, LoopId, BreakId, SwitchId, CallId, CallIndirectId,
        GetLocalId, SetLocalId, GetGlobalId, SetGlobalId, LoadId,
        StoreId, AtomicCmpxchgId, AtomicRMWId, AtomicWaitId, AtomicWakeId,
        SIMDExtractId, SIMDReplaceId, SIMDShuffleId, SIMDBitselectId,
        SIMDShiftId, MemoryInitId, DataDropId, MemoryCopyId, MemoryFillId,
        ConstId, UnaryId, BinaryId, HostId, NopId, UnreachableId,
        InvalidId, NumExpressionIds, IfId, SelectId, DropId, ReturnId
    };
    Id _id;
    
    template<typename T> T* cast() { return static_cast<T*>(this); }
};

class Nop : public Expression {};

class Block : public Expression {
public:
    Name name;
    std::vector<Expression*> list;
};

class Loop : public Expression {
public:
    Name name;
};

class Break : public Expression {
public:
    Name name;
};

class Switch : public Expression {
public:
    std::vector<Name> targets;
    Name default_;
};

class Call : public Expression {
public:
    Name target;
    std::vector<Expression*> operands;
};

class CallIndirect : public Expression {
public:
    Type fullType;
    std::vector<Expression*> operands;
};

class GetLocal : public Expression {
public:
    Index index;
};

class SetLocal : public Expression {
public:
    Index index;
    Type type;
};

class GetGlobal : public Expression {
public:
    Name name;
};

class SetGlobal : public Expression {
public:
    Name name;
};

class Load : public Expression {
public:
    uint32_t bytes;
    bool signed_;
    uint32_t offset;
    uint32_t align;
    bool isAtomic;
};

class Store : public Expression {
public:
    uint32_t bytes;
    uint32_t offset;
    uint32_t align;
    Type valueType;
    bool isAtomic;
};

class AtomicCmpxchg : public Expression {
public:
    uint32_t bytes;
    uint32_t offset;
};

class AtomicRMW : public Expression {
public:
    uint32_t op;
    uint32_t bytes;
    uint32_t offset;
};

class AtomicWait : public Expression {
public:
    Type expectedType;
};

class SIMDExtract : public Expression {
public:
    uint32_t op;
    uint32_t index;
};

class SIMDReplace : public Expression {
public:
    uint32_t op;
    uint32_t index;
};

class SIMDShuffle : public Expression {
public:
    uint8_t mask[16];
};

class SIMDShift : public Expression {
public:
    uint32_t op;
};

class MemoryInit : public Expression {
public:
    uint32_t segment;
    Expression* dest;
    Expression* offset;
    Expression* size;
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

class DataDrop : public Expression {
public:
    uint32_t segment;
};

class Const : public Expression {
public:
    uint64_t value;
};

class Unary : public Expression {
public:
    uint32_t op;
};

class Binary : public Expression {
public:
    uint32_t op;
};

class Host : public Expression {
public:
    uint32_t op;
    Name nameOperand;
    std::vector<Expression*> operands;
};

namespace LoadUtils {
    bool isSignRelevant(Load* load) { return false; }
}

class ChildIterator {
public:
    ChildIterator(Expression* expr) {}
    Expression** begin() { return nullptr; }
    Expression** end() { return nullptr; }
};

struct ExpressionAnalyzer {
    using ExprComparer = bool(*)(Expression*, Expression*);
    bool flexibleEqual(Expression* left, Expression* right, ExprComparer comparer);
};

#define WASM_UNREACHABLE() abort()
#define PUSH(clazz, what) \
    leftStack.push_back(left->cast<clazz>()->what); \
    rightStack.push_back(right->cast<clazz>()->what);