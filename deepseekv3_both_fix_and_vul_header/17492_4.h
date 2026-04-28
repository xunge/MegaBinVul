#include <stdbool.h>
#include <vector>
#include <cstddef>

#define MEMBER_MAX_COUNT 0

typedef int SQInteger;
struct SQSharedState;
typedef SQSharedState* SQSharedStatePtr;
typedef void* SQObjectPtr;

enum SQObjectType {
    OT_CLOSURE,
    OT_NATIVECLOSURE,
    OT_NULL
};

struct SQClassMember {
    SQObjectPtr val;
};

struct SQTable {
    bool Get(const SQObjectPtr&, SQObjectPtr&);
    bool NewSlot(const SQObjectPtr&, const SQObjectPtr&);
    size_t CountUsed();
};

struct SQClosure {
    SQObjectPtr _base;
    SQClosure* Clone();
};

struct SQSharedState {
    SQInteger GetMetaMethodIdxByName(const SQObjectPtr&);
    SQInteger _constructoridx;
};

struct SQVM {
    static void IsEqual(SQInteger, const SQObjectPtr&, bool&);
};

struct SQClass {
    bool _locked;
    SQTable* _members;
    SQObjectPtr* _metamethods;
    SQObjectPtr _base;
    SQInteger _constructoridx;
    std::vector<SQClassMember> _defaultvalues;
    std::vector<SQClassMember> _methods;

    bool NewSlot(SQSharedStatePtr ss, const SQObjectPtr& key, const SQObjectPtr& val, bool bstatic);
    SQObjectPtr _make_method_idx(size_t idx);
    SQObjectPtr _make_field_idx(size_t idx);
    bool _isfield(const SQObjectPtr& obj);
    size_t _member_idx(const SQObjectPtr& obj);
};

inline SQObjectType sq_type(const SQObjectPtr&) { return OT_NULL; }
inline SQClosure* _closure(const SQObjectPtr&) { return nullptr; }
inline void __ObjAddRef(SQObjectPtr) {}