#include <stdint.h>
#include <string.h>
#include <sys/types.h>

template<typename T> class sp {
public:
    T* operator->() const { return nullptr; }
    operator bool() const { return false; }
};

class IMemory {
public:
    sp<class IMemoryHeap> getMemory(ssize_t* offset, size_t* size) const;
    void* getBase() const;
    int getHeapID() const;
};

class IMemoryHeap {
public:
    int getHeapID() const;
    void* getBase() const;
};

class ANativeWindowBuffer {};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

class ICameraRecordingProxy {
public:
    static int getCommonBaseAddress();
};

class BufferItemConsumer {
public:
    static const int INVALID_BUFFER_SLOT;
};

enum status_t {
    OK = 0
};

struct BufferItem {
    int mBuf;
    class {
    public:
        ANativeWindowBuffer* getNativeBuffer() const;
    }* mGraphicBuffer;
};

struct VideoNativeMetadata {
    uint32_t eType;
    ANativeWindowBuffer* pBuffer;
};

enum {
    kMetadataBufferTypeANWBuffer = 1
};

class StreamingProcessor {
public:
    void releaseRecordingFrame(const sp<IMemory>& mem);
private:
    struct RecordingHeap {
        sp<IMemoryHeap> mHeap;
    }* mRecordingHeap;
    int mId;
    Mutex mMutex;
    class {
    public:
        size_t size() const { return 0; }
        const BufferItem& operator[](size_t) const;
        void replaceAt(size_t);
    } mRecordingBuffers;
    class {
    public:
        status_t releaseBuffer(const BufferItem&);
    }* mRecordingConsumer;
    int mRecordingHeapFree;
    int mRecordingHeapCount;
};

#define ATRACE_CALL()
#define ALOGW(...)
#define ALOGE(...)
#define ALOGVV(...)
#define ALOGV_IF(...)
#define __FUNCTION__ ""