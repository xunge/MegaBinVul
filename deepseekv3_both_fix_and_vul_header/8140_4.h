#include <stdint.h>
#include <stddef.h>

typedef int32_t status_t;
typedef uint32_t OMX_U32;
typedef uint8_t OMX_U8;
typedef int32_t OMX_ERRORTYPE;
typedef uint32_t OMX_INDEXTYPE;

namespace OMX {
    typedef void* buffer_id;
    constexpr OMX_INDEXTYPE OMX_IndexParamPortDefinition = 0;
    constexpr OMX_ERRORTYPE OMX_ErrorNone = 0;
}

using OMX::OMX_IndexParamPortDefinition;
using OMX::OMX_ErrorNone;

struct OMX_PARAM_PORTDEFINITIONTYPE {
    OMX_U32 nSize;
    OMX_U32 nVersion;
    OMX_U32 nPortIndex;
    OMX_U32 nBufferSize;
};

struct OMX_BUFFERHEADERTYPE {
    OMX_U8* pBuffer;
    void* pAppPrivate;
};

class GraphicBuffer {
public:
    void* handle;
};

template<typename T> class sp {
public:
    T* operator->() const;
};

class BufferMeta {
public:
    BufferMeta(const sp<GraphicBuffer>&, OMX_U32);
    BufferMeta(const sp<GraphicBuffer>&);
};

class OMXNodeInstance {
protected:
    void* mHandle;
public:
    status_t useGraphicBuffer2_l(OMX_U32 portIndex, const sp<GraphicBuffer>& graphicBuffer,
                               OMX::buffer_id* buffer);
};

#define CLOG_ERROR(type, err, fmt, ...)
#define CLOG_BUFFER(type, fmt)
#define CHECK_EQ(a, b)
#define UNKNOWN_ERROR (-1)
#define OK (0)
#define BUFFER_FMT(portIndex, fmt, size, ptr)
#define NEW_BUFFER_FMT(buffer, portIndex, fmt, size, ptr)

OMX_ERRORTYPE OMX_GetParameter(void* handle, OMX_INDEXTYPE index, void* params);
OMX_ERRORTYPE OMX_UseBuffer(void* handle, OMX_BUFFERHEADERTYPE** header,
                           OMX_U32 portIndex, void* appPrivate,
                           OMX_U32 size, OMX_U8* buffer);

status_t StatusFromOMXError(OMX_ERRORTYPE err);
void InitOMXParams(OMX_PARAM_PORTDEFINITIONTYPE* params);
OMX::buffer_id makeBufferID(OMX_BUFFERHEADERTYPE* header);
void addActiveBuffer(OMX_U32 portIndex, OMX::buffer_id buffer);
const char* asString(OMX_INDEXTYPE index);
const char* portString(OMX_U32 portIndex);