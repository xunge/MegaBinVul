#include <stdint.h>
#include <string.h>

typedef int32_t status_t;
typedef uint32_t OMX_U32;
typedef int32_t OMX_ERRORTYPE;
typedef uint32_t OMX_INDEXTYPE;
typedef char* OMX_STRING;
typedef void* OMX_HANDLETYPE;

namespace OMX {
    typedef uint32_t buffer_id;
}

class GraphicBuffer;

template<typename T>
class sp {
public:
    sp() {}
    sp(T*) {}
    T* operator->() const { return nullptr; }
    operator T*() const { return nullptr; }
};

struct BufferMeta {
    BufferMeta(GraphicBuffer*, OMX_U32) {}
    BufferMeta(GraphicBuffer*) {}
};

struct OMX_VERSIONTYPE {
    struct {
        OMX_U32 nVersionMajor;
        OMX_U32 nVersionMinor;
        OMX_U32 nRevision;
        OMX_U32 nStep;
    } s;
};

struct OMX_BUFFERHEADERTYPE {
    BufferMeta* pAppPrivate;
};

struct UseAndroidNativeBufferParams {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    BufferMeta* pAppPrivate;
    OMX_BUFFERHEADERTYPE** ppBufferHdr;
    GraphicBuffer* buffer;
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

class GraphicBuffer {
public:
    void* handle;
};

class OMXNodeInstance {
public:
    OMX_HANDLETYPE mHandle;
    Mutex mLock;
    status_t useGraphicBuffer(OMX_U32, const sp<GraphicBuffer>&, OMX::buffer_id*);
    status_t useGraphicBuffer2_l(OMX_U32, const sp<GraphicBuffer>&, OMX::buffer_id*);
    status_t StatusFromOMXError(OMX_ERRORTYPE);
    void addActiveBuffer(OMX_U32, OMX::buffer_id);
    OMX::buffer_id makeBufferID(OMX_BUFFERHEADERTYPE*);
    const char* portString(OMX_U32);
};

OMX_ERRORTYPE OMX_GetExtensionIndex(OMX_HANDLETYPE, OMX_STRING, OMX_INDEXTYPE*);
OMX_ERRORTYPE OMX_SetParameter(OMX_HANDLETYPE, OMX_INDEXTYPE, const UseAndroidNativeBufferParams*);

#define OK 0
#define OMX_ErrorNone 0
#define CHECK_EQ(a, b)
#define CLOG_ERROR(a, b, ...)
#define CLOG_BUFFER(a, ...)