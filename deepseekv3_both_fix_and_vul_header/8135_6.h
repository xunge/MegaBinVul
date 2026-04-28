#include <unistd.h>
#include <stdint.h>
#include <cstddef>

typedef int32_t status_t;
typedef int32_t OMX_ERRORTYPE;
typedef uint32_t OMX_U32;
typedef int64_t OMX_TICKS;
typedef intptr_t intptr_t;

namespace OMX {
    typedef uint32_t buffer_id;
}

enum {
    BAD_VALUE = -1,
    kPortIndexInput = 0,
    kMetadataBufferTypeGrallocSource = 1,
    kMetadataBufferTypeANWBuffer = 2,
    OMX_ErrorBadParameter = 0x80001005
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

class OMX_BUFFERHEADERTYPE {
public:
    OMX_U32 nAllocLen;
    OMX_U32 nFilledLen;
    OMX_U32 nOffset;
    void* pAppPrivate;
};

class ABuffer {
public:
    size_t capacity();
    void* base();
};

class BufferMeta {
public:
    void CopyToOMX(OMX_BUFFERHEADERTYPE*);
    ABuffer* getBuffer(OMX_BUFFERHEADERTYPE*, bool, bool);
};

template<typename T> class sp {
public:
    sp(T* ptr) : ptr_(ptr) {}
    T* operator->() { return ptr_; }
    T* get() { return ptr_; }
    operator T*() { return ptr_; }
private:
    T* ptr_;
};

class VideoNativeMetadata {
public:
    int eType;
    struct ANWBuffer {
        void* handle;
    } *pBuffer;
};

class VideoGrallocMetadata {
public:
    int eType;
    void* pHandle;
};

class OMXNodeInstance {
public:
    status_t emptyBuffer(OMX::buffer_id, OMX_U32, OMX_U32, OMX_U32, OMX_TICKS, int);
private:
    Mutex mLock;
    int mMetadataType[2];
    OMX_BUFFERHEADERTYPE* findBufferHeader(OMX::buffer_id);
    OMX_BUFFERHEADERTYPE* findBufferHeader(OMX::buffer_id, int);
    status_t emptyBuffer_l(OMX_BUFFERHEADERTYPE*, OMX_U32, OMX_TICKS, intptr_t, int);
};

#define CLOG_BUFFER(...)
#define CLOG_ERROR(...)
#define FULL_BUFFER(...) 0