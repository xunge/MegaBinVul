#include <stdint.h>
#include <stddef.h>

typedef uintptr_t UDATA;

struct J9VMThread {
    uint64_t floatTemp1;
};

struct J9ConstantPool {
    uint8_t data[1];
};

struct J9Method;
typedef struct J9Method J9Method;

struct J9RAMStaticMethodRef {
    J9Method *method;
};

struct J9Class {
    UDATA initializeStatus;
};

#define J9_RESOLVE_FLAG_CHECK_CLINIT 0x1
#define J9_RESOLVE_FLAG_NO_CP_UPDATE 0x2

#define J9_ARE_NO_BITS_SET(value, bits) (((value) & (bits)) == 0)
#define J9_CLASS_FROM_METHOD(method) ((struct J9Class *)(method))

J9Method *resolveStaticMethodRefInto(J9VMThread *vmStruct, J9ConstantPool *ramCP, UDATA cpIndex, UDATA resolveFlags, J9RAMStaticMethodRef *ramStaticMethodRef);