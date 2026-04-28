#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uintptr_t UDATA;

struct J9VMThread {
    struct J9JavaVM* javaVM;
};

struct J9JavaVM {
    UDATA j2seVersion;
};

struct J9ConstantPool {
    struct J9ROMMethodRef* romConstantPool;
};

struct J9RAMSpecialMethodRef {
    struct J9Method* method;
};

struct J9ROMMethodRef {
    UDATA classRefCPIndex;
    struct J9ROMNameAndSignature* nameAndSignature;
};

struct J9Class {
    struct J9ROMClass* romClass;
};

struct J9ROMNameAndSignature {
};

struct J9Method {
};

struct J9ROMClass {
    void* cpShapeDescription;
    UDATA modifiers;
};

#define J9_ARE_ANY_BITS_SET(flags, bits) ((flags) & (bits))
#define J9_ARE_NO_BITS_SET(flags, bits) (!((flags) & (bits)))
#define J9_RESOLVE_FLAG_JIT_COMPILE_TIME 0x1
#define J9_RESOLVE_FLAG_REDEFINE_CLASS 0x2
#define J9_RESOLVE_FLAG_NO_THROW_ON_FAIL 0x4
#define J9_RESOLVE_FLAG_JCL_CONSTANT_POOL 0x8
#define J9_RESOLVE_FLAG_NO_CP_UPDATE 0x10
#define J9_LOOK_NO_THROW 0x1
#define J9_LOOK_NO_JAVA 0x2
#define J9_LOOK_VIRTUAL 0x4
#define J9_LOOK_ALLOW_FWD 0x8
#define J9_LOOK_HANDLE_DEFAULT_METHOD_CONFLICTS 0x10
#define J9_LOOK_CLCONSTRAINTS 0x20
#define J9_LOOK_NO_VISIBILITY_CHECK 0x40
#define J9_LOOK_IGNORE_INCOMPATIBLE_METHODS 0x80
#define J9AccInterface 0x1
#define J9CPTYPE_INTERFACE_INSTANCE_METHOD 0x1
#define J9CPTYPE_INTERFACE_STATIC_METHOD 0x2
#define J9CPTYPE_INTERFACE_METHOD 0x3
#define J2SE_V11 0xB0000
#define J9VMCONSTANTPOOL_JAVALANGINCOMPATIBLECLASSCHANGEERROR 0x1

#define Trc_VM_resolveSpecialMethodRef_Entry(vmStruct, ramCP, cpIndex, resolveFlags)
#define Trc_VM_resolveSpecialMethodRef_lookupMethod(vmStruct, method)
#define Trc_VM_resolveSpecialMethodRef_Exit(vmStruct, method)

static inline J9Class* J9_CLASS_FROM_CP(J9ConstantPool* cp) { return NULL; }
static inline J9Class* J9_CURRENT_CLASS(J9Class* clazz) { return NULL; }
static inline J9ROMNameAndSignature* J9ROMFIELDREF_NAMEANDSIGNATURE(J9ROMMethodRef* ref) { return ref->nameAndSignature; }
static inline UDATA J9_CP_TYPE(void* desc, UDATA index) { return 0; }
static inline void* J9ROMCLASS_CPSHAPEDESCRIPTION(struct J9ROMClass* romClass) { return romClass->cpShapeDescription; }
static inline UDATA J2SE_VERSION(struct J9JavaVM* javaVM) { return javaVM->j2seVersion; }

void checkForDecompile(J9VMThread* vmStruct, J9ROMMethodRef* romMethodRef, bool jitCompileTimeResolve);
J9Class* resolveClassRef(J9VMThread* vmStruct, J9ConstantPool* ramCP, UDATA cpIndex, UDATA resolveFlags);
J9Method* javaLookupMethod(J9VMThread* vmStruct, J9Class* resolvedClass, J9ROMNameAndSignature* nameAndSig, J9Class* currentClass, UDATA lookupOptions);
bool isDirectSuperInterface(J9VMThread* vmStruct, J9Class* resolvedClass, J9Class* currentClass);
void setCurrentException(J9VMThread* vmStruct, UDATA exception, void* detail);
void setIncompatibleClassChangeErrorInvalidDefenderSupersend(J9VMThread* vmStruct, J9Class* resolvedClass, J9Class* currentClass);
J9Method* getMethodForSpecialSend(J9VMThread* vmStruct, J9Class* currentClass, J9Class* resolvedClass, J9Method* method, UDATA lookupOptions);