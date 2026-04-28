#include <stddef.h>
#include <stdint.h>

typedef struct JNIEnv JNIEnv;
typedef struct _jobject* jobject;
typedef int64_t jlong;

class SkRegion {
public:
    SkRegion();
    void readFromMemory(const void* buffer, size_t size);
};

namespace android {
    class Parcel {
    public:
        int32_t readInt32();
        const void* readInplace(size_t len);
    };
    Parcel* parcelForJavaObject(JNIEnv* env, jobject parcel);
}