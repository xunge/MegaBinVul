#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef uintptr_t UDATA;
typedef uint32_t U_32;
typedef struct J9VMThread J9VMThread;
typedef struct J9ConstantPool {
    UDATA cpEntries[1];
} J9ConstantPool;
typedef struct J9RAMMethodHandleRef J9RAMMethodHandleRef;
typedef struct J9ROMMethodHandleRef J9ROMMethodHandleRef;
typedef struct J9ROMMethodRef J9ROMMethodRef;
typedef struct J9Class J9Class;
typedef struct J9ROMNameAndSignature J9ROMNameAndSignature;
typedef struct J9UTF8 J9UTF8;
typedef struct J9RAMSpecialMethodRef J9RAMSpecialMethodRef;
typedef struct J9RAMClassRef J9RAMClassRef;
typedef struct J9JavaVM J9JavaVM;
typedef void* j9object_t;

struct J9ROMMethodHandleRef {
    U_32 methodOrFieldRefIndex;
    U_32 handleTypeAndCpType;
};

struct J9ROMMethodRef {
    U_32 classRefCPIndex;
};

struct J9RAMClassRef {
    J9Class* value;
};

struct J9RAMSpecialMethodRef {
    char data[64];
};

struct J9VMThread {
    void* returnValue;
    J9JavaVM* javaVM;
};

struct J9JavaVM {
    struct MemoryManagerFunctions {
        j9object_t (*j9gc_objaccess_asConstantPoolObject)(J9VMThread*, j9object_t, UDATA);
    } *memoryManagerFunctions;
    J9Class* (*J9VMJAVALANGINVOKEMETHODHANDLE)(J9JavaVM*);
};

#define J9DescriptionCpTypeShift 0
#define MH_REF_GETFIELD 0
#define MH_REF_PUTFIELD 1
#define MH_REF_GETSTATIC 2
#define MH_REF_PUTSTATIC 3
#define MH_REF_INVOKEVIRTUAL 4
#define MH_REF_INVOKESTATIC 5
#define MH_REF_INVOKESPECIAL 6
#define MH_REF_NEWINVOKESPECIAL 7
#define MH_REF_INVOKEINTERFACE 8

#define J9_RESOLVE_FLAG_JIT_COMPILE_TIME 0x01
#define J9_RESOLVE_FLAG_REDEFINE_CLASS 0x02
#define J9_RESOLVE_FLAG_NO_THROW_ON_FAIL 0x04
#define J9_RESOLVE_FLAG_NO_CP_UPDATE 0x08

#define J9_ARE_ANY_BITS_SET(flags, bits) ((flags) & (bits))
#define J9_ARE_NO_BITS_SET(flags, bits) (!((flags) & (bits)))
#define J9_ROM_CP_FROM_CP(cp) ((J9ROMMethodRef*)((cp)->cpEntries))
#define J9ROMMETHODREF_NAMEANDSIGNATURE(ref) ((J9ROMNameAndSignature*)(ref))
#define J9ROMNAMEANDSIGNATURE_NAME(nas) ((J9UTF8*)(nas))
#define J9UTF8_DATA(utf) ((char*)(utf))
#define J9UTF8_LENGTH(utf) (0)
#define J9UTF8_LITERAL_EQUALS(data, length, str) (0)
#define J9VMCONSTANTPOOL_JAVALANGNULLPOINTEREXCEPTION 0
#define J9_CLASS_FROM_CP(cp) ((J9Class*)(cp))
#define J9STATIC_OBJECT_STORE(vmThread, clazz, addr, value) (*(addr) = (value))
#define J9_GC_ALLOCATE_OBJECT_TENURED 0x01
#define J9_GC_ALLOCATE_OBJECT_NON_INSTRUMENTABLE 0x02
#define J9_GC_ALLOCATE_OBJECT_HASHED 0x04
#define J9VMJAVALANGINVOKEMETHODHANDLE(vm) ((vm)->J9VMJAVALANGINVOKEMETHODHANDLE(vm))

struct J9RAMMethodHandleRef {
    j9object_t methodHandle;
};

int resolveInstanceFieldRef(J9VMThread*, void*, J9ConstantPool*, UDATA, UDATA, void*);
void* resolveStaticFieldRefInto(J9VMThread*, void*, J9ConstantPool*, UDATA, UDATA, void*, void*);
void* resolveStaticFieldRef(J9VMThread*, void*, J9ConstantPool*, UDATA, UDATA, void*);
J9Class* resolveClassRef(J9VMThread*, J9ConstantPool*, UDATA, UDATA);
int resolveVirtualMethodRef(J9VMThread*, J9ConstantPool*, UDATA, UDATA, void*);
void* resolveSpecialMethodRefInto(J9VMThread*, J9ConstantPool*, UDATA, UDATA, J9RAMSpecialMethodRef*);
void* resolveSpecialMethodRef(J9VMThread*, J9ConstantPool*, UDATA, UDATA);
void* resolveStaticMethodRefInto(J9VMThread*, J9ConstantPool*, UDATA, UDATA, void*);
void* resolveStaticMethodRef(J9VMThread*, J9ConstantPool*, UDATA, UDATA);
void* resolveInterfaceMethodRef(J9VMThread*, J9ConstantPool*, UDATA, UDATA);
void setCurrentExceptionUTF(J9VMThread*, int, void*);
void setHeapOutOfMemoryError(J9VMThread*);
bool threadEventsPending(J9VMThread*);
void sendResolveMethodHandle(J9VMThread*, UDATA, J9ConstantPool*, J9Class*, J9ROMNameAndSignature*);
void clearException(J9VMThread*);

namespace VM_VMHelpers {
    static inline void clearException(J9VMThread* vmThread) {
        ::clearException(vmThread);
    }
}