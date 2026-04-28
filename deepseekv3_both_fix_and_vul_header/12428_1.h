typedef void* JNIEnv;
typedef void* jobject;
typedef int jint;
typedef void* jclass;

#define JNICALL

#define J9_RESOLVE_FLAG_NO_CLASS_LOAD 0x0001
#define J9_RESOLVE_FLAG_JIT_COMPILE_TIME 0x0002
#define J9_RESOLVE_FLAG_NO_THROW_ON_FAIL 0x0004

jclass getClassAt(JNIEnv *env, jobject constantPoolOop, jint cpIndex, int flags);