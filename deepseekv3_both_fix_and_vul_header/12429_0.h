#include <stddef.h>

#define J9_RESOLVE_FLAG_NO_THROW_ON_FAIL 0
#define J9_RESOLVE_FLAG_NO_CLASS_INIT 0
#define J9_RESOLVE_FLAG_NO_CP_UPDATE 0

typedef enum {
    OK,
    NULL_POINTER_EXCEPTION,
    WRONG_CP_ENTRY_TYPE_EXCEPTION
} SunReflectCPResult;

typedef enum {
    J9CPTYPE_UNUSED,
    J9CPTYPE_HANDLE_METHOD,
    J9CPTYPE_INSTANCE_METHOD,
    J9CPTYPE_INTERFACE_INSTANCE_METHOD,
    J9CPTYPE_STATIC_METHOD,
    J9CPTYPE_INTERFACE_STATIC_METHOD,
    J9CPTYPE_INTERFACE_METHOD
} UDATA;

typedef int jint;
typedef int jboolean;

typedef struct J9JavaVM {
    struct J9InternalVMFunctions* internalVMFunctions;
} J9JavaVM;

typedef struct J9VMThread {
    J9JavaVM* javaVM;
} J9VMThread;

typedef struct J9Method {
    void* constantPool;
} J9Method;

typedef struct J9Class {
    void* classObject;
} J9Class;

typedef struct J9ConstantPool {
} J9ConstantPool;

typedef struct J9RAMConstantRef {
} J9RAMConstantRef;

typedef struct J9RAMMethodRef {
    J9Method* method;
} J9RAMMethodRef;

typedef struct J9RAMStaticMethodRef {
    J9Method* method;
} J9RAMStaticMethodRef;

typedef struct J9InternalVMFunctions {
    void (*internalEnterVMFromJNI)(struct J9VMThread*);
    void (*internalExitVMToJNI)(struct J9VMThread*);
    int (*resolveVirtualMethodRef)(struct J9VMThread*, struct J9ConstantPool*, jint, UDATA, struct J9Method**);
    struct J9Method* (*resolveSpecialMethodRef)(struct J9VMThread*, struct J9ConstantPool*, jint, UDATA);
    struct J9Method* (*resolveStaticMethodRefInto)(struct J9VMThread*, struct J9ConstantPool*, jint, UDATA, void*);
    struct J9Method* (*resolveStaticMethodRef)(struct J9VMThread*, struct J9ConstantPool*, jint, UDATA);
    struct J9Method* (*resolveInterfaceMethodRef)(struct J9VMThread*, struct J9ConstantPool*, jint, UDATA);
    void* (*getJNIMethodID)(struct J9VMThread*, struct J9Method*);
    void* (*j9jni_createLocalRef)(void*, void*);
    void (*throwNativeOOMError)(void*, int, int);
} J9InternalVMFunctions;

typedef void* jobject;
typedef void* jclass;
typedef void* jmethodID;

typedef struct JNINativeInterface_ {
    jobject (*ToReflectedMethod)(void*, jclass, jmethodID, jboolean);
} JNINativeInterface;

typedef const struct JNINativeInterface_* JNIEnv;

#define J9CLASS_FROMCPINTERNALRAMCLASS(vmThread, constantPoolOop) ((struct J9Class*)0)
#define J9_CP_FROM_CLASS(cpClass) ((struct J9ConstantPool*)0)

static void clearException(struct J9VMThread* vmThread) {}
static void checkResult(JNIEnv env, SunReflectCPResult result) {}
static SunReflectCPResult getRAMConstantRefAndType(struct J9VMThread* vmThread, jobject constantPoolOop, jint cpIndex, UDATA* cpType, struct J9RAMConstantRef** ramConstantRef) { return OK; }