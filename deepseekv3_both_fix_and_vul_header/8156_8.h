#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>

typedef int32_t status_t;
typedef int64_t nsecs_t;
typedef int64_t ssize_t;

#define OK 0
#define INVALID_OPERATION (-1)
#define NO_MEMORY (-2)
#define CAMERA_MSG_VIDEO_FRAME 0
#define kMetadataBufferTypeANWBuffer 0

#define ATRACE_CALL()
#define ALOGE(...)
#define ALOGV(...)
#define ALOGVV(...)
#define ALOGW(...)

template<typename T>
class sp {
public:
    sp() : ptr(nullptr) {}
    sp(T* p) : ptr(p) {}
    T* operator->() { return ptr; }
    bool operator==(int) { return ptr == nullptr; }
    T* ptr;
    T* promote() { return ptr; }
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

template<typename T>
class Vector {
public:
    void clear() {}
    void setCapacity(size_t) {}
    void insertAt(size_t, size_t) {}
    size_t size() const { return 0; }
    void replaceAt(const T&, size_t) {}
    T& operator[](size_t) { static T t; return t; }
};

struct IMemoryHeap {
    void* getBase() { return nullptr; }
    IMemoryHeap* getMemory(ssize_t*, size_t*) { return this; }
};

struct ANativeWindowBuffer {};

struct ICameraRecordingProxy {
    static uint8_t* getCommonBaseAddress() { return nullptr; }
};

struct BufferItem {
    nsecs_t mTimestamp;
    struct GraphicBuffer {
        ANativeWindowBuffer* getNativeBuffer() { return nullptr; }
    } *mGraphicBuffer;
    int mBuf;
};

struct BufferItemConsumer {
    static const int INVALID_BUFFER_SLOT = -1;
    static const int NO_BUFFER_AVAILABLE = -3;
    status_t acquireBuffer(BufferItem*, int) { return OK; }
    void releaseBuffer(const BufferItem&) {}
};

struct VideoNativeMetadata {
    int eType;
    ANativeWindowBuffer* pBuffer;
    int nFenceFd;
};

class Camera2Heap {
public:
    Camera2Heap(size_t, size_t, const char*) {}
    struct mHeap {
        size_t getSize() { return 0; }
    } *mHeap;
    sp<IMemoryHeap>* mBuffers;
};

class Parameters {
public:
    enum State { RECORD, VIDEO_SNAPSHOT };
    State state;
};

class SharedParameters {
public:
    class Lock {
    public:
        Lock(SharedParameters&) {}
        Parameters mParameters;
    };
    SharedParameters& getParameters() { static SharedParameters params; return params; }
};

class Camera2Client {
public:
    struct SharedCameraCallbacks {
        class Lock {
        public:
            Lock(SharedCameraCallbacks&) {}
            struct RemoteCallback {
                void dataCallbackTimestamp(nsecs_t, int, sp<IMemoryHeap>) {}
            } *mRemoteCallback;
        };
    };
    sp<Camera2Client> promote() { return sp<Camera2Client>(); }
    SharedParameters& getParameters() { static SharedParameters params; return params; }
    SharedCameraCallbacks mSharedCameraCallbacks;
};

class StreamingProcessor {
public:
    status_t processRecordingFrame();
    int mId;
    size_t mRecordingFrameCount;
    size_t mRecordingHeapCount;
    size_t mRecordingHeapHead;
    size_t mRecordingHeapFree;
    sp<Camera2Heap> mRecordingHeap;
    Vector<BufferItem> mRecordingBuffers;
    sp<BufferItemConsumer> mRecordingConsumer;
    Mutex mMutex;
    sp<Camera2Client> mClient;
};