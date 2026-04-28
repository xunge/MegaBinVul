#include <stdint.h>
#include <cstddef>

typedef int32_t status_t;
typedef int32_t OMX_ERRORTYPE;
typedef void* OMX_HANDLETYPE;

#define BAD_VALUE (-1)
#define OK (0)
#define OMX_ErrorNone (0)

enum {
    kPortIndexOutput
};

struct OMX_BUFFERHEADERTYPE {
    uint32_t nFilledLen;
    uint32_t nOffset;
    uint32_t nFlags;
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

class List {
public:
    void add(void*) {}
    void remove(void*) {}
};

namespace OMX {
    typedef void* buffer_id;
    OMX_ERRORTYPE FillThisBuffer(OMX_HANDLETYPE, OMX_BUFFERHEADERTYPE*);
}

inline OMX_ERRORTYPE OMX_FillThisBuffer(OMX_HANDLETYPE hComponent, OMX_BUFFERHEADERTYPE* pBuffer) {
    return OMX::FillThisBuffer(hComponent, pBuffer);
}

class OMXNodeInstance {
private:
    Mutex mLock;
    Mutex mDebugLock;
    List mOutputBuffersWithCodec;
    OMX_HANDLETYPE mHandle;

    OMX_BUFFERHEADERTYPE* findBufferHeader(OMX::buffer_id, int) { return nullptr; }
    OMX_BUFFERHEADERTYPE* findBufferHeader(OMX::buffer_id) { return nullptr; }
    status_t storeFenceInMeta_l(OMX_BUFFERHEADERTYPE*, int, int) { return OK; }
    status_t StatusFromOMXError(OMX_ERRORTYPE) { return OK; }
public:
    status_t fillBuffer(OMX::buffer_id buffer, int fenceFd);
};

#define CLOG_ERROR(...)
#define CLOG_BUMPED_BUFFER(...)
#define EMPTY_BUFFER(...) 0
#define WITH_STATS(...) 0