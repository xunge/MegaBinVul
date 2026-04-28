#include <stdint.h>
#include <string.h>
#include <stddef.h>

enum status_t {
    NO_ERROR = 0
};

enum PixelFormat {
};

class Parcel {
public:
    int readInt32() const;
    uint32_t readUint32() const;
    void writeInt32(int);
    void writeUint32(uint32_t);
    void* writeInplace(size_t);
    void write(const void*, size_t);
    template<typename T> void write(const T&);
    template<typename T> void read(T&) const;
    int readStrongBinder() const;
    int readNativeHandle() const;
    void writeString8(const char*);
};

template<typename T>
class sp {
public:
    sp();
    sp(T*);
    T* get() const;
    T* operator->() const;
    operator bool() const;
    T& operator*() const;
};

class GraphicBuffer {
public:
    GraphicBuffer();
};

class Fence {
public:
    Fence();
};

class IProducerListener {
public:
    static IProducerListener* asInterface(int);
};

class NativeHandle {
public:
    static NativeHandle* create(int, bool);
};

class BBinder {
public:
    virtual status_t onTransact(uint32_t, const Parcel&, Parcel*, uint32_t);
};

class QueueBufferInput {
public:
    QueueBufferInput(const Parcel&);
};

class QueueBufferOutput {
};

class IGraphicBufferProducer {
public:
    virtual int requestBuffer(int, sp<GraphicBuffer>*);
    virtual int setBufferCount(int);
    virtual int dequeueBuffer(int*, sp<Fence>*, bool, uint32_t, uint32_t, PixelFormat, uint32_t);
    virtual int detachBuffer(int);
    virtual int detachNextBuffer(sp<GraphicBuffer>*, sp<Fence>*);
    virtual int attachBuffer(int*, const sp<GraphicBuffer>&);
    virtual status_t queueBuffer(int, const QueueBufferInput&, QueueBufferOutput*);
    virtual void cancelBuffer(int, const sp<Fence>&);
    virtual int query(int, int*);
    virtual status_t connect(const sp<IProducerListener>&, int, bool, QueueBufferOutput*);
    virtual status_t disconnect(int);
    virtual status_t setSidebandStream(const sp<NativeHandle>&);
    virtual void allocateBuffers(bool, uint32_t, uint32_t, PixelFormat, uint32_t);
    virtual status_t allowAllocation(bool);
    virtual status_t setGenerationNumber(uint32_t);
    virtual const char* getConsumerName();
};

class BnGraphicBufferProducer : public BBinder, public IGraphicBufferProducer {
public:
    virtual status_t onTransact(uint32_t, const Parcel&, Parcel*, uint32_t);
};

enum {
    REQUEST_BUFFER,
    SET_BUFFER_COUNT,
    DEQUEUE_BUFFER,
    DETACH_BUFFER,
    DETACH_NEXT_BUFFER,
    ATTACH_BUFFER,
    QUEUE_BUFFER,
    CANCEL_BUFFER,
    QUERY,
    CONNECT,
    DISCONNECT,
    SET_SIDEBAND_STREAM,
    ALLOCATE_BUFFERS,
    ALLOW_ALLOCATION,
    SET_GENERATION_NUMBER,
    GET_CONSUMER_NAME
};

#define CHECK_INTERFACE(INTERFACE, data, reply)
#define NULL 0