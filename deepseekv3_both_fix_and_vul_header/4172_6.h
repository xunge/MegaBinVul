#include <stdint.h>
#include <string>

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
    SET_CONSUMER_USAGE_BITS,
    SET_TRANSFORM_HINT,
    DUMP
};

typedef int32_t status_t;
#define NO_ERROR 0
#define EGL_NO_DISPLAY 0
#define EGL_NO_SYNC_KHR 0

class String8 {
public:
    String8() {}
    explicit String8(const char* str) {}
};

class BufferItem {
public:
    BufferItem() {}
};

class GraphicBuffer {
public:
    GraphicBuffer() {}
};

class Fence {
public:
    Fence() {}
};

class IConsumerListener {
public:
    static IConsumerListener* asInterface(void*) { return nullptr; }
};

template<typename T> class sp {
public:
    sp(T* ptr) : m_ptr(ptr) {}
    T* get() { return m_ptr; }
    T& operator*() { return *m_ptr; }
private:
    T* m_ptr;
};

class Parcel {
public:
    int32_t readInt32() const { return 0; }
    int64_t readInt64() const { return 0; }
    uint32_t readUint32() const { return 0; }
    uint64_t readUint64() const { return 0; }
    String8 readString8() const { return String8(); }
    void* readStrongBinder() const { return nullptr; }
    status_t read(GraphicBuffer&) const { return NO_ERROR; }
    status_t read(Fence&) const { return NO_ERROR; }
    status_t writeInt32(int32_t) { return NO_ERROR; }
    status_t writeInt64(int64_t) { return NO_ERROR; }
    status_t writeUint32(uint32_t) { return NO_ERROR; }
    status_t writeUint64(uint64_t) { return NO_ERROR; }
    status_t writeString8(const String8&) { return NO_ERROR; }
    status_t write(const BufferItem&) { return NO_ERROR; }
};

class BBinder {
public:
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags) = 0;
};

#define CHECK_INTERFACE(interface, data, reply)

class IGraphicBufferConsumer {
public:
    virtual status_t acquireBuffer(BufferItem* item, int64_t presentWhen) = 0;
    virtual status_t detachBuffer(int slot) = 0;
    virtual status_t attachBuffer(int* slot, const sp<GraphicBuffer>& buffer) = 0;
    virtual status_t releaseBuffer(int buf, uint64_t frameNumber, void* display, void* fence, const sp<Fence>& releaseFence) = 0;
    virtual status_t consumerConnect(const sp<IConsumerListener>& consumer, bool controlledByApp) = 0;
    virtual status_t consumerDisconnect() = 0;
    virtual status_t getReleasedBuffers(uint64_t* slotMask) = 0;
    virtual status_t setDefaultBufferSize(uint32_t w, uint32_t h) = 0;
    virtual status_t setDefaultMaxBufferCount(uint32_t bufferCount) = 0;
    virtual status_t disableAsyncBuffer() = 0;
    virtual status_t setMaxAcquiredBufferCount(uint32_t maxAcquiredBuffers) = 0;
    virtual void setConsumerName(const String8& name) = 0;
    virtual status_t setDefaultBufferFormat(uint32_t defaultFormat) = 0;
    virtual status_t setConsumerUsageBits(uint32_t usage) = 0;
    virtual status_t setTransformHint(uint32_t hint) = 0;
    virtual void dump(String8& result, const String8& prefix) = 0;
};

class BnGraphicBufferConsumer : public BBinder, public IGraphicBufferConsumer {
public:
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags);
};