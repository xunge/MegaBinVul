#include <stdbool.h>
#include <stddef.h>

typedef unsigned char UDATA;
typedef void* j9object_t;
typedef struct J9VMThread J9VMThread;
typedef struct J9ConstantPool J9ConstantPool;
typedef struct J9RAMMethodRef J9RAMMethodRef;
typedef struct J9Class J9Class;
typedef struct J9ROMMethodRef J9ROMMethodRef;
typedef struct J9ROMNameAndSignature J9ROMNameAndSignature;
typedef struct J9MemoryManagerFunctions J9MemoryManagerFunctions;

#define J9_ARE_NO_BITS_SET(flags, bits) ((flags & bits) == 0)
#define J9_RESOLVE_FLAG_JIT_COMPILE_TIME (1 << 0)
#define J9_RESOLVE_FLAG_REDEFINE_CLASS (1 << 1)
#define J9_CLASS_FROM_CP(cp) ((J9Class*)(cp))
#define J9ROMMETHODREF_NAMEANDSIGNATURE(ref) ((J9ROMNameAndSignature*)(ref))
#define J9VMCONSTANTPOOL_JAVALANGNULLPOINTEREXCEPTION 0
#define MH_REF_INVOKEVIRTUAL 0

struct J9RAMMethodRef {
    UDATA methodIndexAndArgCount;
};

struct J9Class {
    j9object_t* invokeCache;
};

struct J9VMThread {
    j9object_t returnValue;
    j9object_t currentException;
    struct J9JavaVM* javaVM;
};

struct J9JavaVM {
    J9MemoryManagerFunctions* memoryManagerFunctions;
};

struct J9ConstantPool {
    void* romConstantPool;
};

struct J9MemoryManagerFunctions {
    int (*j9gc_objaccess_staticCompareAndSwapObject)(J9VMThread*, J9Class*, j9object_t*, j9object_t, j9object_t);
};

void VM_AtomicSupport_writeBarrier(void);
void Trc_VM_resolveInvokeHandle_Entry(J9VMThread*, J9ConstantPool*, UDATA, UDATA);
void Trc_VM_resolveInvokeHandle_Exit(J9VMThread*, j9object_t);
void Trc_VM_Assert_ShouldNeverHappen();
J9Class* resolveClassRef(J9VMThread*, J9ConstantPool*, UDATA, UDATA);
void sendResolveOpenJDKInvokeHandle(J9VMThread*, J9ConstantPool*, UDATA, int, J9Class*, J9ROMNameAndSignature*);
void setCurrentExceptionUTF(J9VMThread*, int, const char*);