#include <stddef.h>

typedef unsigned char U_8;
typedef unsigned short U_16;
typedef unsigned int U_32;
typedef unsigned long long U_64;
typedef U_32 UDATA;
typedef void *j9object_t;
typedef void *J9UTF8;
typedef void *J9ROMStringRef;
typedef void *J9Class;

struct J9JavaVM {
    struct {
        j9object_t (*j9gc_createJavaLangString)(void *, U_8 *, UDATA, UDATA);
    } *memoryManagerFunctions;
};

struct J9VMThread {
    struct J9JavaVM *javaVM;
};

struct J9ROMConstantPool {
    J9ROMStringRef romStringRef;
};

struct J9ConstantPool {
    struct J9ROMConstantPool *romConstantPool;
    struct J9RAMStringRef *ramStringRef;
};

struct J9RAMStringRef {
    j9object_t stringObject;
};

#define J9_ARE_NO_BITS_SET(flags, bits) (((flags) & (bits)) == 0)
#define J9_RESOLVE_FLAG_NO_CP_UPDATE 0x1
#define J9_STR_TENURE 0x1
#define J9_STR_INTERN 0x2
#define J9ROMSTRINGREF_UTF8DATA(ref) ((J9UTF8 *)ref)
#define J9UTF8_LENGTH(utf8) (*(UDATA *)(utf8))
#define J9UTF8_DATA(utf8) ((U_8 *)((UDATA *)(utf8) + 1))
#define J9_CLASS_FROM_CP(cp) ((J9Class *)(cp))
#define J9STATIC_OBJECT_STORE(vmStruct, clazz, addr, value) (*(addr) = (value))

#define Trc_VM_resolveStringRef_Entry(vmStruct, cpIndex, ramCP)
#define Trc_VM_resolveStringRef_utf8(vmStruct, utf8Wrapper, length, data)
#define Trc_VM_resolveStringRef_Exit(vmStruct, stringRef)