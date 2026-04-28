#include <stdbool.h>
#include <stddef.h>

typedef unsigned char U_8;
typedef unsigned short U_16;
typedef unsigned int U_32;
typedef unsigned long UDATA;
typedef long IDATA;

typedef struct J9UTF8 {
    U_8* data;
    U_16 length;
} J9UTF8;

typedef struct J9Class J9Class;
typedef struct J9ArrayClass J9ArrayClass;
typedef struct J9VMThread J9VMThread;
typedef struct J9ConstantPool J9ConstantPool;
typedef struct J9RAMMethodTypeRef J9RAMMethodTypeRef;
typedef struct J9ROMMethodTypeRef J9ROMMethodTypeRef;
typedef struct J9ROMClass J9ROMClass;
typedef struct J9JavaVM J9JavaVM;
typedef struct J9MemoryManagerFunctions J9MemoryManagerFunctions;

typedef void* j9object_t;

#define J9_ARE_ANY_BITS_SET(value, bits) ((value) & (bits))
#define J9_ARE_NO_BITS_SET(value, bits) (!((value) & (bits)))
#define J9_RESOLVE_FLAG_JIT_COMPILE_TIME 0x01
#define J9_RESOLVE_FLAG_REDEFINE_CLASS 0x02
#define J9_RESOLVE_FLAG_NO_THROW_ON_FAIL 0x04
#define J9_RESOLVE_FLAG_NO_CP_UPDATE 0x08
#define J9_LOOK_NO_THROW 0x10
#define J9_LOOK_NO_JAVA 0x20
#define J9_VISIBILITY_ALLOWED 0
#define J9VMCONSTANTPOOL_JAVALANGNULLPOINTEREXCEPTION 0
#define J9VMCONSTANTPOOL_JAVALANGILLEGALACCESSERROR 0

#define J9_ROM_CP_FROM_CP(cp) ((J9ROMMethodTypeRef*)(cp))
#define J9_CLASS_FROM_CP(cp) ((J9Class*)(cp))
#define J9ROMMETHODTYPEREF_SIGNATURE(ref) ((J9UTF8*)(ref))
#define J9UTF8_DATA(utf8) ((utf8)->data)
#define J9UTF8_LENGTH(utf8) ((utf8)->length)
#define J9VMJAVALANGINVOKEMETHODTYPE_RTYPE(vmThread, obj) (obj)
#define J9VMJAVALANGINVOKEMETHODTYPE_PTYPES(vmThread, obj) (obj)
#define J9INDEXABLEOBJECT_SIZE(vmThread, obj) (0)
#define J9JAVAARRAYOFOBJECT_LOAD(vmThread, array, index) (array)
#define J9ROMCLASS_IS_ARRAY(romClass) (0)
#define J9STATIC_OBJECT_STORE(vmThread, clazz, addr, value) (*(addr) = (value))
#define J9VM_J9CLASS_FROM_HEAPCLASS(vmThread, obj) ((J9Class*)(obj))

struct J9RAMMethodTypeRef {
    j9object_t type;
};

struct J9VMThread {
    j9object_t returnValue;
    j9object_t currentException;
    J9JavaVM* javaVM;
};

struct J9JavaVM {
    J9MemoryManagerFunctions* memoryManagerFunctions;
};

struct J9MemoryManagerFunctions {
    j9object_t (*j9gc_createJavaLangString)(J9VMThread*, U_8*, U_16, U_32);
};

struct J9Class {
    J9ROMClass* romClass;
    void* classLoader;
    J9Class* ramClass;
};

struct J9ArrayClass {
    J9Class* leafComponentType;
};

struct J9ROMClass {
    U_32 modifiers;
};

struct J9ConstantPool {
    J9Class* ramClass;
};

struct J9ROMMethodTypeRef {
    J9UTF8* signature;
};

void Trc_VM_sendResolveMethodTypeRefInto_Entry(J9VMThread*, J9ConstantPool*, UDATA, UDATA);
void Trc_VM_sendResolveMethodTypeRefInto_Exit(J9VMThread*, j9object_t);
void Trc_VM_sendResolveMethodTypeRefInto_Exception(J9VMThread*, J9Class*, J9Class*, IDATA);
void sendFromMethodDescriptorString(J9VMThread*, J9UTF8*, void*, void*);
bool threadEventsPending(J9VMThread*);
void setCurrentException(J9VMThread*, UDATA, UDATA*);
void setCurrentExceptionUTF(J9VMThread*, UDATA, char*);
void setNativeOutOfMemoryError(J9VMThread*, UDATA, UDATA);
IDATA checkVisibility(J9VMThread*, J9Class*, J9Class*, U_32, UDATA);
char* illegalAccessMessage(J9VMThread*, U_32, J9Class*, J9Class*, IDATA);

namespace VM_VMHelpers {
    void clearException(J9VMThread*);
}