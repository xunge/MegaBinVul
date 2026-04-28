#include <stddef.h>

typedef void* JNIEnv;
typedef void* jobject;
typedef void* jclass;
typedef unsigned long UDATA;
typedef int jint;

typedef enum SunReflectCPResult {
    NULL_POINTER_EXCEPTION
} SunReflectCPResult;

struct J9JavaVM;
struct J9InternalVMFunctions;

typedef struct J9VMThread {
    struct J9JavaVM* javaVM;
} J9VMThread;

typedef struct J9JavaVM {
    struct J9InternalVMFunctions* internalVMFunctions;
} J9JavaVM;

typedef struct J9InternalVMFunctions {
    void (*internalEnterVMFromJNI)(J9VMThread*);
    void (*internalExitVMToJNI)(J9VMThread*);
    jclass (*j9jni_createLocalRef)(JNIEnv*, jobject);
} J9InternalVMFunctions;

typedef struct J9Class J9Class;

#define J9_RESOLVE_FLAG_NO_THROW_ON_FAIL 0x1
#define J9_RESOLVE_FLAG_NO_CLASS_INIT 0x2
#define J9_RESOLVE_FLAG_NO_CP_UPDATE 0x4
#define J9VM_J9CLASS_TO_HEAPCLASS(clazz) ((jobject)(clazz))

void checkResult(JNIEnv* env, SunReflectCPResult result);
SunReflectCPResult getJ9ClassAt(J9VMThread* vmThread, jobject constantPoolOop, jint cpIndex, UDATA resolveFlags, J9Class** clazz);