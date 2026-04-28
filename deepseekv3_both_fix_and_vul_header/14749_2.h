#include <cstdint>
#include <stddef.h>
#include <string.h>
#include <memory>

typedef void* jobject;
typedef void* jbyteArray;
typedef struct JNIEnv JNIEnv;

namespace android {
    class Parcel {
    public:
        struct ReadableBlob {
            void* data();
            void release();
        };
        
        int readBlob(size_t len, ReadableBlob* outBlob);
        const void* readInplace(size_t len);
        int32_t readInt32();
    };

    Parcel* parcelForJavaObject(JNIEnv* env, jobject obj);
    typedef int status_t;
}

enum SkColorType {
    kUnknown_SkColorType,
    kAlpha_8_SkColorType,
    kRGB_565_SkColorType,
    kARGB_4444_SkColorType,
    kRGBA_8888_SkColorType,
    kBGRA_8888_SkColorType,
    kIndex_8_SkColorType,
    kGray_8_SkColorType,
    kN32_SkColorType
};

enum SkAlphaType {
    kUnknown_SkAlphaType,
    kOpaque_SkAlphaType,
    kPremul_SkAlphaType,
    kUnpremul_SkAlphaType
};

typedef uint32_t SkPMColor;

class SkImageInfo {
public:
    static SkImageInfo Make(int width, int height, SkColorType colorType, SkAlphaType alphaType);
};

class SkBitmap {
public:
    bool setInfo(const SkImageInfo& info, size_t rowBytes);
    size_t getSize();
    void* getPixels();
    void lockPixels();
    void unlockPixels();
};

class SkColorTable {
public:
    SkColorTable(const SkPMColor* colors, int count);
};

class GraphicsJNI {
public:
    static jbyteArray allocateJavaPixelRef(JNIEnv* env, SkBitmap* bitmap, SkColorTable* ctable);
    static jobject createBitmap(JNIEnv* env, SkBitmap* bitmap, jbyteArray buffer, int flags, void*, void*, int density);
};

template<typename T> class SkAutoTDelete {
public:
    explicit SkAutoTDelete(T* obj) : fObj(obj) {}
    ~SkAutoTDelete() { delete fObj; }
    T* get() const { return fObj; }
    T* detach() { T* obj = fObj; fObj = NULL; return obj; }
    T* operator->() const { return fObj; }
private:
    T* fObj;
};

void SkDebugf(const char* format, ...);
void doThrowRE(JNIEnv* env, const char* msg);
void SkSafeUnref(SkColorTable* ctable);
int getPremulBitmapCreateFlags(bool isMutable);