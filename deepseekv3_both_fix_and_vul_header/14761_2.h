#include <stddef.h>
#include <stdint.h>

typedef int64_t jlong;
typedef void* JNIEnv;
typedef void* jobject;

class SkRegion {
public:
    size_t readFromMemory(const void* buffer, size_t length);
};

namespace android {
    class Parcel {
    public:
        int32_t readInt32();
        const void* readInplace(size_t len);
    };
    Parcel* parcelForJavaObject(JNIEnv* env, jobject obj);
};