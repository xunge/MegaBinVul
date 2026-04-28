#include <stdint.h>
#include <string.h>
#include <cstddef>

#define ALOGV(...)
#define ALOGE(...)

struct VideoFrame {
    int mWidth;
    int mHeight;
    int mDisplayWidth;
    int mDisplayHeight;
    size_t mSize;
    int mRotationAngle;
    uint8_t* mData;
};

template<typename T> class sp {
public:
    sp() : m_ptr(nullptr) {}
    sp(T* ptr) : m_ptr(ptr) {}
    T* operator->() { return m_ptr; }
    void clear() { m_ptr = nullptr; }
    bool operator==(const sp<T>& other) const { return m_ptr == other.m_ptr; }
    bool operator==(const T* ptr) const { return m_ptr == ptr; }
private:
    T* m_ptr;
};

class IMemory {
public:
    virtual ~IMemory() {}
    virtual void* pointer() = 0;
};

class MemoryHeapBase {
public:
    MemoryHeapBase(size_t, int, const char*);
};

class MemoryBase : public IMemory {
public:
    MemoryBase(const sp<MemoryHeapBase>&, size_t, size_t);
    void* pointer() override;
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&);
        ~Autolock();
    };
};

class IMediaRetriever {
public:
    virtual VideoFrame* getFrameAtTime(int64_t timeUs, int option) = 0;
    virtual ~IMediaRetriever() {}
};

class MetadataRetrieverClient {
private:
    Mutex mLock;
    static Mutex sLock;
    sp<IMemory> mThumbnail;
    IMediaRetriever* mRetriever;
public:
    sp<IMemory> getFrameAtTime(int64_t timeUs, int option);
};