#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint32_t vcount_t;

struct TR_ResolvedMethod;
struct TR_OpaqueClassBlock;
struct TR_PersistentClassInfo;
struct TR_PersistentMethodInfo;
struct TR_PrexArgInfo;
struct TR_PrexArgument;
struct TR_PersistentCHTable;
struct TR_ResolvedMethodSymbol;
struct TR_SymbolReference;
struct TR_MethodSymbol;
struct TR_Symbol;
struct TR_YesNoMaybe;
struct TR_ClassTableCriticalSection;
struct TR_KnownObjectTable;
struct TR_Recompilation;
struct TR_ResolvedMethodSymbol;
struct TR_Method;
struct TR_ClassQueries;

template<typename T>
struct TR_ScratchList {
    TR_ScratchList(void*);
};

struct TR {
    struct Node;
    struct TreeTop;
    struct Symbol;
    struct MethodSymbol;
    struct Compiler;
};

struct ParmInfo {
    void clear();
    void setKnownObjectIndex(int32_t);
    void setClassIsFixed();
    bool hasKnownObjectIndex();
    TR_OpaqueClassBlock* getClass();
    bool classIsFixed();
    bool classIsCurrentlyFinal();
    void setClass(TR_OpaqueClassBlock*);
};

struct TR_InvariantArgumentPreexistence {
    bool trace();
    void* comp();
    ParmInfo* getSuitableParmInfo(TR::Node*);
    bool classIsCompatibleWithMethod(TR_OpaqueClassBlock*, TR_ResolvedMethod*);
    bool devirtualizeVirtualCall(TR::Node*, TR::TreeTop*, TR_OpaqueClassBlock*);
    void specializeInvokeExactSymbol(TR::Node*, int32_t, void*, TR_InvariantArgumentPreexistence*);
    void processIndirectCall(TR::Node*, TR::TreeTop*, vcount_t);
    bool _isOutermostMethod;
    bool _success;
};

struct TR_Compiler {
    static TR_Compiler* cls;
    TR_OpaqueClassBlock* objectClass(void*, void*);
    bool isInterfaceClass(void*, TR_OpaqueClassBlock*);
};

struct TR_YesNoMaybe {};

struct TR_ClassQueries {
    static void collectAllSubClasses(TR_PersistentClassInfo*, TR_ScratchList<TR_PersistentClassInfo>*, void*);
};

struct TR_ClassTableCriticalSection {
    TR_ClassTableCriticalSection(void*);
};