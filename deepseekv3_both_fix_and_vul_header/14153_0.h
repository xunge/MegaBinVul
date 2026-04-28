#include <stdint.h>

typedef struct J9Class J9Class;
typedef struct J9ITable J9ITable;
typedef struct J9Method J9Method;
typedef struct J9ROMMethod J9ROMMethod;

struct J9ITable {
    J9Class *interfaceClass;
    J9ITable *next;
};

struct J9Class {
    void *iTable;
};

struct J9Method {
    J9ROMMethod *romMethod;
};

struct J9ROMMethod {
    uint32_t modifiers;
};

#define J9_ROM_METHOD_FROM_RAM_METHOD(method) ((method)->romMethod)
#define J9AccPublic 0x0001
#define TR_ASSERT(condition, message) ((void)0)
#define UDATA uintptr_t
#define JNIEXPORT
#define JNICALL
typedef void* JNIEnv;
typedef void* jclass;
typedef long long jlong;
typedef int jint;