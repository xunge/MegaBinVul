typedef void* JNIEnv;
typedef void* jobject;
typedef int jint;

#define JNICALL

#define J9_RESOLVE_FLAG_RUNTIME_RESOLVE 0x1000
#define J9_RESOLVE_FLAG_NO_THROW_ON_FAIL 0x2000

jobject getMethodAt(JNIEnv* env, jobject constantPoolOop, jint cpIndex, int flags);