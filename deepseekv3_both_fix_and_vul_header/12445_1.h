#include <stddef.h>

typedef unsigned short U_16;
typedef unsigned long UDATA;

struct J9VMThread;
struct J9ConstantPool;
struct J9Method;
struct J9RAMStaticMethodRef;
struct J9JavaVM;
struct J9ROMClass;

struct J9Class {
    UDATA initializeStatus;
    struct J9Method *ramMethods;
};

struct J9VMThread {
    void *floatTemp1;
    struct J9JavaVM *javaVM;
};

struct J9ConstantPool {
    struct {
        struct J9ROMClass *romClass;
        struct J9Method **staticSplitMethodTable;
    } *ramClass;
};

struct J9JavaVM {
    struct {
        struct J9Method *initialStaticMethod;
    } initialMethods;
};

struct J9ROMClass {
    U_16 staticSplitMethodRefIndexes[1];
};

#define J9ROMCLASS_STATICSPLITMETHODREFINDEXES(romClass) ((romClass)->staticSplitMethodRefIndexes)
#define J9_CLASS_FROM_METHOD(method) ((struct J9Class*)((char*)(method) - offsetof(struct J9Class, ramMethods)))
#define J9_RESOLVE_FLAG_CHECK_CLINIT 0x1
#define J9_RESOLVE_FLAG_NO_CP_UPDATE 0x2
#define J9_ARE_NO_BITS_SET(value, bits) (((value) & (bits)) == 0)

extern struct J9Method *resolveStaticMethodRefInto(struct J9VMThread *, struct J9ConstantPool *, U_16, UDATA, struct J9RAMStaticMethodRef *);