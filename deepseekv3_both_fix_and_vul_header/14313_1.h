#include <set>
#include <vector>
#include <map>
#include <stdexcept>
#include <string>
#include <cstdint>
#include <cassert>

struct Expression {
    virtual ~Expression() = default;
    template<typename T> T* cast() { return dynamic_cast<T*>(this); }
};

struct Block : Expression {};
struct If : Expression {};
struct Loop : Expression {};
struct Break : Expression {};
struct Switch : Expression {};
struct Call : Expression { bool isReturn = false; };
struct CallIndirect : Expression { bool isReturn = false; };
struct LocalGet : Expression {};
struct LocalSet : Expression {};
struct GlobalGet : Expression {};
struct GlobalSet : Expression {};
struct Select : Expression {};
struct Return : Expression {};
struct Nop : Expression {};
struct Unreachable : Expression {};
struct Drop : Expression {};
struct RefNull : Expression {};
struct RefIs : Expression {};
struct RefFunc : Expression {};
struct RefEq : Expression {};
struct RefAs : Expression {};
struct TableGet : Expression {};
struct TableSet : Expression {};
struct Throw : Expression {};
struct Rethrow : Expression {};
struct MemorySize : Expression { void make64() {} };
struct MemoryGrow : Expression { void make64() {} };
struct CallRef : Expression { bool isReturn = false; };

struct ControlFlow {
    template<typename T> bool is() { return false; }
};

struct BinaryLocation {
    BinaryLocation(size_t = 0) {}
    bool operator<(const BinaryLocation&) const { return false; }
};

struct BinaryLocations {
    struct Span {
        BinaryLocation start;
        BinaryLocation end;
    };
    static const BinaryLocation Else;
};

const BinaryLocation BinaryLocations::Else = BinaryLocation(0);

struct Function {
    struct DebugLocation {
        bool operator<(const DebugLocation&) const { return false; }
    };
    std::map<Expression*, DebugLocation> debugLocations;
    std::map<Expression*, BinaryLocations::Span> expressionLocations;
    std::map<ControlFlow*, std::map<BinaryLocation, BinaryLocation>> delimiterLocations;
};

struct BinaryConsts {
    enum {
        Block, If, Loop, Br, BrIf, BrTable, CallFunction, CallIndirect,
        RetCallFunction, RetCallIndirect, LocalGet, LocalTee, LocalSet,
        GlobalGet, GlobalSet, Select, SelectWithType, Return, Nop, Unreachable, 
        Drop, End, Else, Catch, CatchAll, Delegate, RefNull, RefIsNull, RefFunc,
        RefEq, RefAsNonNull, BrOnNull, BrOnNonNull, TableGet, TableSet,
        Try, Throw, Rethrow, MemorySize, MemoryGrow, CallRef, RetCallRef,
        Let, AtomicPrefix, MiscPrefix, SIMDPrefix, GCPrefix, RefIsFunc,
        RefIsData, RefIsI31, RefAsFunc, RefAsData, RefAsI31
    };
    typedef int ASTNodes;
    static ASTNodes toASTNodes(uint8_t code) { return Block; }
};

struct Wasm {
    struct Memory {
        bool is64() { return false; }
        void make64() {}
    } memory;
};

struct Allocator {
    template<typename T> T* alloc() { return new T(); }
    template<typename T> T* cast() { return static_cast<T*>(this); }
};

struct WasmBinaryBuilder {
    size_t pos = 0;
    size_t endOfFunction = 0;
    size_t depth = 0;
    size_t codeSectionLocation = 0;
    std::vector<ControlFlow*> controlFlowStack;
    Function* currFunction = nullptr;
    std::set<Function::DebugLocation> debugLocation;
    Allocator allocator;
    Wasm wasm;
    
    uint8_t getInt8() { return 0; }
    uint32_t getU32LEB() { return 0; }
    void readNextDebugLocation() {}
    void throwError(const std::string& msg) { throw std::runtime_error(msg); }
    BinaryConsts::ASTNodes readExpression(Expression*& curr);
    void visitBlock(Block*) {}
    void visitIf(If*) {}
    void visitLoop(Loop*) {}
    void visitBreak(Break*, uint8_t) {}
    void visitSwitch(Switch*) {}
    void visitCall(Call*) {}
    void visitCallIndirect(CallIndirect*) {}
    void visitLocalGet(LocalGet*) {}
    void visitLocalSet(LocalSet*, uint8_t) {}
    void visitGlobalGet(GlobalGet*) {}
    void visitGlobalSet(GlobalSet*) {}
    void visitSelect(Select*, uint8_t) {}
    void visitReturn(Return*) {}
    void visitNop(Nop*) {}
    void visitUnreachable(Unreachable*) {}
    void visitDrop(Drop*) {}
    void visitRefNull(RefNull*) {}
    void visitRefIs(RefIs*, uint8_t) {}
    void visitRefFunc(RefFunc*) {}
    void visitRefEq(RefEq*) {}
    void visitRefAs(RefAs*, uint8_t) {}
    bool maybeVisitBrOn(Expression*&, uint8_t) { return false; }
    void visitTableGet(TableGet*) {}
    void visitTableSet(TableSet*) {}
    void visitTryOrTryInBlock(Expression*&) {}
    void visitThrow(Throw*) {}
    void visitRethrow(Rethrow*) {}
    void visitMemorySize(MemorySize*) {}
    void visitMemoryGrow(MemoryGrow*) {}
    void visitCallRef(CallRef*) {}
    void visitLet(Block*) {}
    bool maybeVisitLoad(Expression*&, uint8_t, bool) { return false; }
    bool maybeVisitStore(Expression*&, uint8_t, bool) { return false; }
    bool maybeVisitAtomicRMW(Expression*&, uint8_t) { return false; }
    bool maybeVisitAtomicCmpxchg(Expression*&, uint8_t) { return false; }
    bool maybeVisitAtomicWait(Expression*&, uint8_t) { return false; }
    bool maybeVisitAtomicNotify(Expression*&, uint8_t) { return false; }
    bool maybeVisitAtomicFence(Expression*&, uint8_t) { return false; }
    bool maybeVisitTruncSat(Expression*&, uint32_t) { return false; }
    bool maybeVisitMemoryInit(Expression*&, uint32_t) { return false; }
    bool maybeVisitDataDrop(Expression*&, uint32_t) { return false; }
    bool maybeVisitMemoryCopy(Expression*&, uint32_t) { return false; }
    bool maybeVisitMemoryFill(Expression*&, uint32_t) { return false; }
    bool maybeVisitTableSize(Expression*&, uint32_t) { return false; }
    bool maybeVisitTableGrow(Expression*&, uint32_t) { return false; }
    bool maybeVisitSIMDBinary(Expression*&, uint32_t) { return false; }
    bool maybeVisitSIMDUnary(Expression*&, uint32_t) { return false; }
    bool maybeVisitSIMDConst(Expression*&, uint32_t) { return false; }
    bool maybeVisitSIMDStore(Expression*&, uint32_t) { return false; }
    bool maybeVisitSIMDExtract(Expression*&, uint32_t) { return false; }
    bool maybeVisitSIMDReplace(Expression*&, uint32_t) { return false; }
    bool maybeVisitSIMDShuffle(Expression*&, uint32_t) { return false; }
    bool maybeVisitSIMDTernary(Expression*&, uint32_t) { return false; }
    bool maybeVisitSIMDShift(Expression*&, uint32_t) { return false; }
    bool maybeVisitSIMDLoad(Expression*&, uint32_t) { return false; }
    bool maybeVisitSIMDLoadStoreLane(Expression*&, uint32_t) { return false; }
    bool maybeVisitI31New(Expression*&, uint32_t) { return false; }
    bool maybeVisitI31Get(Expression*&, uint32_t) { return false; }
    bool maybeVisitRefTest(Expression*&, uint32_t) { return false; }
    bool maybeVisitRefCast(Expression*&, uint32_t) { return false; }
    bool maybeVisitRttCanon(Expression*&, uint32_t) { return false; }
    bool maybeVisitRttSub(Expression*&, uint32_t) { return false; }
    bool maybeVisitStructNew(Expression*&, uint32_t) { return false; }
    bool maybeVisitStructGet(Expression*&, uint32_t) { return false; }
    bool maybeVisitStructSet(Expression*&, uint32_t) { return false; }
    bool maybeVisitArrayNew(Expression*&, uint32_t) { return false; }
    bool maybeVisitArrayInit(Expression*&, uint32_t) { return false; }
    bool maybeVisitArrayGet(Expression*&, uint32_t) { return false; }
    bool maybeVisitArraySet(Expression*&, uint32_t) { return false; }
    bool maybeVisitArrayLen(Expression*&, uint32_t) { return false; }
    bool maybeVisitArrayCopy(Expression*&, uint32_t) { return false; }
    bool maybeVisitBinary(Expression*&, uint8_t) { return false; }
    bool maybeVisitUnary(Expression*&, uint8_t) { return false; }
    bool maybeVisitConst(Expression*&, uint8_t) { return false; }
    void requireFunctionContext(const std::string&) {}
};

#define BYN_TRACE(x)
#define DWARF 1