#include <stdint.h>
#include <cstddef>

typedef int32_t status_t;
typedef uint32_t OMX_U32;
typedef int32_t OMX_ERRORTYPE;

namespace OMX {
    typedef void* buffer_id;
}

struct OMX_BUFFERHEADERTYPE {
    void* pAppPrivate;
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

class BufferMeta {};

class OMXNodeInstance {
public:
    Mutex mLock;
    void* mHandle;
    OMX_ERRORTYPE (*OMX_FreeBuffer)(void*, OMX_U32, OMX_BUFFERHEADERTYPE*);
    
    status_t freeBuffer(OMX_U32 portIndex, OMX::buffer_id buffer);
    void removeActiveBuffer(OMX_U32, OMX::buffer_id);
    OMX_BUFFERHEADERTYPE* findBufferHeader(OMX::buffer_id, OMX_U32);
    OMX_BUFFERHEADERTYPE* findBufferHeader(OMX::buffer_id);
    void invalidateBufferID(OMX::buffer_id);
    const char* portString(OMX_U32);
    status_t StatusFromOMXError(OMX_ERRORTYPE);
};

#define BAD_VALUE (-1)
#define CLOG_BUFFER(func, format, ...)
#define CLOG_IF_ERROR(func, err, format, ...)