#include <cstdint>
#include <string>

#define NEVER_INLINE __attribute__((noinline))
#define UNLIKELY(x) __builtin_expect((x), 0)
#define LIKELY(x) __builtin_expect((x), 1)

class String {
public:
    const char* get() const;
};

class Class;
class ObjectData;

struct tv_lval {
    int type() const;
    int operator*() const;
};

class ObjectData {
public:
    Class* getVMClass();
    void reserveDynProps(int nProp);
    tv_lval makeDynProp(const char* key);
    tv_lval getPropLval(Class* ctx, const char* key);
};

class Class {
public:
    struct DeclPropLookup {
        int slot;
        bool accessible;
    };
    DeclPropLookup getDeclPropSlot(Class* ctx, const char* key);
    const char* declPropRepoAuthType(int slot);
    struct DeclProperty {
        int attrs;
    };
    const DeclProperty* declProperties();
};

class VariableUnserializer {
public:
    void unserializeProp(ObjectData* obj,
                         const String& key,
                         Class* ctx,
                         const String& realKey,
                         int nProp);
};

enum KindOf {
    KindOfUninit
};

namespace RuntimeOption {
    extern bool RepoAuthoritative;
}

namespace Repo {
    struct RepoGlobal {
        bool HardPrivatePropInference;
    };
    struct RepoImpl {
        RepoGlobal global();
    };
    RepoImpl get();
};

void unserializePropertyValue(tv_lval t, int nProp);
void throwUnexpectedType(const String& key, ObjectData* obj, int t);

constexpr int kInvalidSlot = -1;
constexpr int AttrLateInit = 1;

bool tvMatchesRepoAuthType(int t, const char* repoTy);