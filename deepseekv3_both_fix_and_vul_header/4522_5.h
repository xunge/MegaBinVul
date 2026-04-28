#include <stdint.h>
#include <memory>

enum status_t {
    NO_ERROR = 0
};

class String8 {
public:
    String8() {}
    String8(const char*) {}
};

class BufferItem {};

class GraphicBuffer {
public:
    operator void*() { return nullptr; }
};

class Fence {
public:
    operator void*() { return nullptr; }
};

class NativeHandle {
public:
    void* handle() const { return nullptr; }
};

class IConsumerListener {
public:
    static IConsumerListener* asInterface(void*) { return nullptr; }
};

template<typename T> class sp {
public:
    sp(T* ptr = nullptr) : m_ptr(ptr) {}
    T* get() const { return m_ptr; }
    T* operator->() const { return m_ptr; }
    operator bool() const { return m_ptr != nullptr; }
    bool operator!=(std::nullptr_t) const { return m_ptr != nullptr; }
    T& operator*() const { return *m_ptr; }
private:
    T* m_ptr;
};

class Parcel {
public:
    int64_t readInt64() const { return 0; }
    uint64_t readUint64() const { return 0; }
    int32_t readInt32() const { return 0; }
    uint32_t readUint32() const { return 0; }
    String8 readString8() const { return String8(); }
    status_t write(const BufferItem&) const { return NO_ERROR; }
    status_t writeInt32(int32_t) const { return NO_ERROR; }
    status_t writeInt64(int64_t) const { return NO_ERROR; }
    status_t writeString8(const String8&) const { return NO_ERROR; }
    status_t writeNativeHandle(void*) const { return NO_ERROR; }
    status_t read(void* buffer) const { return NO_ERROR; }
    void* readStrongBinder() const { return nullptr; }
};

class BBinder {
public:
    virtual status_t onTransact(uint32_t, const Parcel&, Parcel*, uint32_t);
};

class IGraphicBufferConsumer {
public:
    virtual status_t acquireBuffer(BufferItem*, int64_t, uint64_t) = 0;
    virtual status_t detachBuffer(int) = 0;
    virtual status_t attachBuffer(int*, const sp<GraphicBuffer>&) = 0;
    virtual status_t releaseBuffer(int, uint64_t, void*, void*, const sp<Fence>&) = 0;
    virtual status_t consumerConnect(const sp<IConsumerListener>&, bool) = 0;
    virtual status_t consumerDisconnect() = 0;
    virtual status_t getReleasedBuffers(uint64_t*) = 0;
    virtual status_t setDefaultBufferSize(uint32_t, uint32_t) = 0;
    virtual status_t setDefaultMaxBufferCount(int) = 0;
    virtual status_t disableAsyncBuffer() = 0;
    virtual status_t setMaxAcquiredBufferCount(int) = 0;
    virtual void setConsumerName(const String8&) = 0;
    virtual status_t setDefaultBufferFormat(int32_t) = 0;
    virtual status_t setDefaultBufferDataSpace(int32_t) = 0;
    virtual status_t setConsumerUsageBits(uint32_t) = 0;
    virtual status_t setTransformHint(uint32_t) = 0;
    virtual sp<NativeHandle> getSidebandStream() = 0;
    virtual void dump(String8&, const String8&) = 0;
};

#define CHECK_INTERFACE(interface, data, reply)
#define EGL_NO_DISPLAY nullptr
#define EGL_NO_SYNC_KHR nullptr

enum {
    ACQUIRE_BUFFER,
    DETACH_BUFFER,
    ATTACH_BUFFER,
    RELEASE_BUFFER,
    CONSUMER_CONNECT,
    CONSUMER_DISCONNECT,
    GET_RELEASED_BUFFERS,
    SET_DEFAULT_BUFFER_SIZE,
    SET_DEFAULT_MAX_BUFFER_COUNT,
    DISABLE_ASYNC_BUFFER,
    SET_MAX_ACQUIRED_BUFFER_COUNT,
    SET_CONSUMER_NAME,
    SET_DEFAULT_BUFFER_FORMAT,
    SET_DEFAULT_BUFFER_DATA_SPACE,
    SET_CONSUMER_USAGE_BITS,
    SET_TRANSFORM_HINT,
    GET_SIDEBAND_STREAM,
    DUMP
};

typedef int32_t PixelFormat;
typedef int32_t android_dataspace;

class BnGraphicBufferConsumer : public BBinder, public IGraphicBufferConsumer {
public:
    virtual status_t onTransact(uint32_t, const Parcel&, Parcel*, uint32_t);
};