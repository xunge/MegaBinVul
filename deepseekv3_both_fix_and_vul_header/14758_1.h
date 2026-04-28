#include <stdint.h>

typedef int32_t status_t;
#define BAD_VALUE (-1)

namespace OMX {
    typedef int buffer_id;
}

typedef uint32_t OMX_U32;
typedef int64_t OMX_TICKS;

struct OMX_BUFFERHEADERTYPE {
    OMX_U32 nAllocLen;
    OMX_U32 nFilledLen;
    OMX_U32 nOffset;
    void* pAppPrivate;
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

class BufferMeta {
public:
    void CopyToOMX(OMX_BUFFERHEADERTYPE*) {}
};

class OMXNodeInstance {
private:
    Mutex mLock;
    OMX_BUFFERHEADERTYPE* findBufferHeader(OMX::buffer_id);
    status_t emptyBuffer_l(OMX_BUFFERHEADERTYPE*, OMX_U32, OMX_TICKS, intptr_t);
public:
    status_t emptyBuffer(OMX::buffer_id, OMX_U32, OMX_U32, OMX_U32, OMX_TICKS);
};