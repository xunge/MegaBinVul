#define J9_RESOLVE_FLAG_NO_CLASS_LOAD 0x0001
#define J9_RESOLVE_FLAG_JIT_COMPILE_TIME 0x0002
#define J9_RESOLVE_FLAG_NO_THROW_ON_FAIL 0x0004

typedef struct JNIEnv_ JNIEnv;
typedef void* jobject;
typedef int jint;

#define JNICALL

jobject getMethodAt(JNIEnv *env, jobject constantPoolOop, jint cpIndex, int flags);