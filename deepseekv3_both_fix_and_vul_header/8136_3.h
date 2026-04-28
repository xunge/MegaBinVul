#include <stddef.h>
#include <stdint.h>

typedef int32_t status_t;
typedef uint32_t OMX_U32;
typedef int32_t OMX_ERRORTYPE;
typedef void* OMX_HANDLETYPE;

enum {
    OMX_ErrorNone = 0
};

struct OMX_BUFFERHEADERTYPE {
    void* pBuffer;
    void* pAppPrivate;
};

namespace OMX {
    typedef uint32_t buffer_id;
}

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

class BufferMeta {
public:
    BufferMeta(size_t) {}
    BufferMeta(size_t, OMX_U32) {}
};

class GraphicBufferSource {
public:
    void addCodecBuffer(OMX_BUFFERHEADERTYPE*) {}
};

template<typename T>
class sp {
public:
    sp() : mPtr(nullptr) {}
    sp(T* ptr) : mPtr(ptr) {}
    T* get() const { return mPtr; }
    T* operator->() const { return mPtr; }
    operator bool() const { return mPtr != nullptr; }
    bool operator!=(const T* other) const { return mPtr != other; }
private:
    T* mPtr;
};

#define CHECK_EQ(a, b) ((void)0)
#define CLOG_ERROR(func, err, fmt) ((void)0)
#define CLOG_BUFFER(func, fmt) ((void)0)
#define BUFFER_FMT(port, fmt) ""
#define NEW_BUFFER_FMT(buffer, port, fmt) ""

static const OMX_U32 kPortIndexInput = 0;

class OMXNodeInstance {
public:
    status_t allocateBuffer(OMX_U32 portIndex, size_t size, OMX::buffer_id* buffer, void** buffer_data);
    status_t allocateBuffer(OMX_U32 portIndex, size_t size, OMX::buffer_id* buffer, void** buffer_data, bool);
private:
    Mutex mLock;
    OMX_HANDLETYPE mHandle;
};

status_t StatusFromOMXError(OMX_ERRORTYPE);
OMX::buffer_id makeBufferID(OMX_BUFFERHEADERTYPE*);
void addActiveBuffer(OMX_U32, OMX::buffer_id);
GraphicBufferSource* getGraphicBufferSource();
OMX_ERRORTYPE OMX_AllocateBuffer(OMX_HANDLETYPE, OMX_BUFFERHEADERTYPE**, OMX_U32, void*, size_t);

#define OK 0