#include <stddef.h>

typedef unsigned long UDATA;

struct J9RAMStaticFieldRef {
    UDATA valueOffset;
    UDATA flagsAndClass;
};

struct J9Class {
    UDATA initializeStatus;
};

struct J9VMThread {
    UDATA floatTemp1;
};

struct J9ConstantPool {
    UDATA data[1];
};

typedef struct J9VMThread J9VMThread;
typedef struct J9Method J9Method;
typedef struct J9ConstantPool J9ConstantPool;
typedef struct J9ROMFieldShape J9ROMFieldShape;
typedef struct J9RAMStaticFieldRef J9RAMStaticFieldRef;
typedef struct J9Class J9Class;

#define J9RAMSTATICFIELDREF_CLASS(ref) ((J9Class *)((ref)->flagsAndClass & ~1))
#define J9_RESOLVE_FLAG_CHECK_CLINIT 1
#define J9_RESOLVE_FLAG_NO_CP_UPDATE 2
#define J9_ARE_NO_BITS_SET(value, bits) (((value) & (bits)) == 0)

extern void *resolveStaticFieldRefInto(J9VMThread *, J9Method *, J9ConstantPool *, UDATA, UDATA, J9ROMFieldShape **, J9RAMStaticFieldRef *);