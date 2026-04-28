#include <stdint.h>
#include <sys/types.h>
#include <cstddef>

typedef int32_t status_t;
typedef uint32_t OMX_U32;

#define BAD_VALUE (-1)
#define OK (0)

enum {
    kPortIndexInput,
    kPortIndexOutput
};

enum {
    kMetadataBufferTypeGrallocSource,
    kMetadataBufferTypeANWBuffer
};

struct VideoGrallocMetadata {
    int eType;
    void* pHandle;
};

struct VideoNativeMetadata {
    int eType;
    void* pBuffer;
    int nFenceFd;
};

class GraphicBuffer {
public:
    void* handle;
    void* getNativeBuffer();
};

template<typename T>
class sp {
public:
    sp();
    sp(T*);
    T* operator->() const;
    operator T*() const;
};

class BufferMeta {
public:
    void setGraphicBuffer(const sp<GraphicBuffer>&);
};

class OMX_BUFFERHEADERTYPE {
public:
    uint8_t* pBuffer;
    void* pAppPrivate;
    uint32_t nAllocLen;
};

namespace OMX {
    typedef void* buffer_id;
}

class OMXNodeInstance {
public:
    int mMetadataType[2];
    const char* portString(OMX_U32 portIndex);
    status_t updateGraphicBufferInMeta_l(OMX_U32 portIndex, const sp<GraphicBuffer>& graphicBuffer,
                                       OMX::buffer_id buffer, OMX_BUFFERHEADERTYPE *header);
};

#define CLOG_BUFFER(func, format, ...)