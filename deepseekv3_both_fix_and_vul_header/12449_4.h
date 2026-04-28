#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef unsigned char U_8;
typedef unsigned short U_16;
typedef unsigned long UDATA;
typedef long IDATA;
typedef void* j9object_t;

struct J9Class {
    struct J9ROMClass* romClass;
    struct J9ClassLoader* classLoader;
    j9object_t classObject;
    UDATA initializeStatus;
    void* module;
};

struct J9VMThread {
    struct J9JavaVM* javaVM;
    j9object_t currentException;
    UDATA publicFlags;
};

struct J9JavaVM {
    struct J9ClassLoader* systemClassLoader;
    struct {
        j9object_t (*j9gc_createJavaLangString)(struct J9VMThread*, U_8*, U_16, U_8);
    }* memoryManagerFunctions;
    UDATA hotSwapCount;
    struct J9Class* (*J9VMJAVALANGLINKAGEERROR_OR_NULL)(struct J9JavaVM*);
};

struct J9ConstantPool {
    struct J9Class* ramClass;
    struct J9ROMStringRef* romConstantPool;
};

struct J9ClassLoader {
    // empty struct
};

struct J9RAMClassRef {
    struct J9Class* value;
    UDATA modifiers;
};

struct J9ROMStringRef {
    struct J9UTF8* utf8Data;
};

struct J9UTF8 {
    U_16 length;
    U_8 data[1];
};

struct J9ArrayClass {
    struct J9Class* leafComponentType;
};

struct J9ROMClass {
    UDATA modifiers;
};

#define J9_ARE_ANY_BITS_SET(value, bits) ((value) & (bits))
#define J9_ARE_NO_BITS_SET(value, bits) (!((value) & (bits)))
#define J9_RESOLVE_FLAG_JIT_COMPILE_TIME 0x01
#define J9_RESOLVE_FLAG_REDEFINE_CLASS 0x02
#define J9_RESOLVE_FLAG_NO_THROW_ON_FAIL 0x04
#define J9_RESOLVE_FLAG_NO_CLASS_LOAD 0x08
#define J9_RESOLVE_FLAG_INSTANTIABLE 0x10
#define J9_RESOLVE_FLAG_INIT_CLASS 0x20
#define J9_RESOLVE_FLAG_NO_CP_UPDATE 0x40
#define J9_LOOK_NO_THROW 0x01
#define J9_LOOK_NO_JAVA 0x02
#define J9_FINDCLASS_FLAG_THROW_ON_FAIL 0x01
#define J9_FINDCLASS_FLAG_EXISTING_ONLY 0x02
#define J9_PUBLIC_FLAGS_POP_FRAMES_INTERRUPT 0x01
#define J9AccInterface 0x0200
#define J9ClassInitSucceeded 0
#define J9_VISIBILITY_ALLOWED 0
#define J9_VISIBILITY_NON_MODULE_ACCESS_ERROR -1
#define J9VMCONSTANTPOOL_JAVALANGNOCLASSDEFFOUNDERROR 1
#define J9VMCONSTANTPOOL_JAVALANGILLEGALACCESSERROR 2
#define J9VMCONSTANTPOOL_JAVALANGINSTANTIATIONERROR 3
#define J9_EX_CTOR_CLASS 0

#define J9ROMSTRINGREF_UTF8DATA(ref) ((ref)->utf8Data)
#define J9UTF8_LENGTH(utf8) ((utf8)->length)
#define J9UTF8_DATA(utf8) ((utf8)->data)
#define J9_CLASS_FROM_CP(cp) ((cp)->ramClass)
#define J9ROMCLASS_ALLOCATES_VIA_NEW(romClass) (1)
#define J9ROMCLASS_IS_ARRAY(romClass) (0)
#define J9VM_J9CLASS_TO_HEAPCLASS(clazz) ((clazz)->classObject)
#define J9VMJAVALANGCLASS_PROTECTIONDOMAIN(vmThread, classObject) (NULL)
#define J9OBJECT_CLAZZ(vmThread, obj) ((struct J9Class*)(obj))
#define J9VMJAVALANGLINKAGEERROR_OR_NULL(vm) ((vm)->J9VMJAVALANGLINKAGEERROR_OR_NULL(vm))
#define j9mem_free_memory(ptr) free(ptr)

static inline void issueReadBarrier() {}
static inline void setCurrentException(struct J9VMThread* vmThread, UDATA exceptionIndex, UDATA* detailMessage) {}
static inline void setCurrentExceptionUTF(struct J9VMThread* vmThread, UDATA exceptionIndex, const char* message) {}
static inline bool instanceOfOrCheckCast(struct J9Class* instanceClass, struct J9Class* castClass) { return false; }
static inline bool requirePackageAccessCheck(struct J9JavaVM* vm, struct J9ClassLoader* classLoader, void* module, struct J9Class* resolvedClass) { return false; }
static inline bool packageAccessIsLegal(struct J9VMThread* vmThread, struct J9Class* resolvedClass, j9object_t protectionDomain, bool canRunJavaCode) { return false; }
static inline IDATA checkVisibility(struct J9VMThread* vmThread, struct J9Class* fromClass, struct J9Class* toClass, UDATA modifiers, UDATA lookupOptions) { return 0; }
static inline char* illegalAccessMessage(struct J9VMThread* vmThread, UDATA modifiers, struct J9Class* fromClass, struct J9Class* toClass, IDATA errorCode) { return NULL; }
static inline void initializeClass(struct J9VMThread* vmThread, struct J9Class* clazz) {}
static inline struct J9Class* internalFindClassUTF8(struct J9VMThread* vmThread, U_8* className, U_16 classNameLength, struct J9ClassLoader* classLoader, UDATA flags) { return NULL; }

namespace VM_VMHelpers {
    static inline void clearException(struct J9VMThread* vmThread) {}
    static inline bool exceptionPending(struct J9VMThread* vmThread) { return false; }
};

#define PORT_ACCESS_FROM_VMC(vmThread)
#define Assert_VM_notNull(expr)
#define Trc_VM_resolveClassRef_Entry(vmThread, ramCP, cpIndex, resolveFlags)
#define Trc_VM_resolveClassRef_lookup(vmThread, length, data)
#define Trc_VM_resolveClassRef_Exit(vmThread, resolvedClass)