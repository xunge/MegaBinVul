#include <stdint.h>
#include <errno.h>
#include <memory>

typedef uint32_t OMX_U32;
typedef uint8_t OMX_U8;
typedef void* OMX_PTR;
typedef void* OMX_HANDLETYPE;
typedef int64_t OMX_TICKS;
typedef int status_t;

enum OMX_ERRORTYPE {
    OMX_ErrorNone = 0
};

struct OMX_BUFFERHEADERTYPE {
    OMX_U8* pBuffer;
    OMX_U32 nAllocLen;
    OMX_U32 nFilledLen;
    OMX_U32 nOffset;
    OMX_PTR pAppPrivate;
    OMX_PTR pPlatformPrivate;
    OMX_PTR pInputPortPrivate;
    OMX_PTR pOutputPortPrivate;
    OMX_HANDLETYPE hMarkTargetComponent;
    OMX_PTR pMarkData;
    OMX_U32 nTickCount;
    OMX_TICKS nTimeStamp;
    OMX_U32 nFlags;
    OMX_U32 nOutputPortIndex;
    OMX_U32 nInputPortIndex;
};

namespace OMX {
    typedef uint32_t buffer_id;
}

class IMemory {
public:
    virtual size_t size() const = 0;
    virtual void* pointer() = 0;
    virtual ~IMemory() {}
};

template<typename T>
class sp {
public:
    sp(T* ptr = nullptr) : mPtr(ptr) {}
    T* operator->() const { return mPtr; }
    operator bool() const { return mPtr != nullptr; }
    bool operator!=(std::nullptr_t) const { return mPtr != nullptr; }
private:
    T* mPtr;
};

struct BufferMeta {
    BufferMeta(const sp<IMemory>& params, OMX_U32 portIndex) {}
    BufferMeta(const sp<IMemory>& params) {}
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

class GraphicBufferSource {
public:
    void addCodecBuffer(OMX_BUFFERHEADERTYPE*) {}
};

class OMXNodeInstance {
public:
    OMX_HANDLETYPE mHandle;
    Mutex mLock;
    sp<GraphicBufferSource> getGraphicBufferSource() { return nullptr; }
    void addActiveBuffer(OMX_U32, OMX::buffer_id) {}
    OMX::buffer_id makeBufferID(OMX_BUFFERHEADERTYPE*) { return 0; }
    status_t StatusFromOMXError(OMX_ERRORTYPE) { return 0; }
    status_t useBuffer(OMX_U32 portIndex, const sp<IMemory>& params,
                      OMX::buffer_id* buffer, OMX_U32 allottedSize);
};

enum {
    kPortIndexInput = 0,
    kPortIndexOutput = 1
};

#define OK 0
#define BAD_VALUE (-EINVAL)
#define CLOG_ERROR(...)
#define CLOG_BUFFER(...)
#define SIMPLE_BUFFER(...) 0
#define NEW_BUFFER_FMT(...) 0
#define CHECK_EQ(a, b)
#define OMX_UseBuffer(...) OMX_ErrorNone