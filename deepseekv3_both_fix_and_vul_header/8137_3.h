#include <stdint.h>
#include <stddef.h>
#include <cstddef>

typedef int32_t status_t;
typedef uint32_t OMX_U32;
typedef void* OMX_HANDLETYPE;
typedef int OMX_ERRORTYPE;

namespace OMX {
    typedef uint32_t buffer_id;
}

struct OMX_BUFFERHEADERTYPE {
    void* pAppPrivate;
    void* pBuffer;
};

class IMemory {
public:
    size_t size() const;
    void* pointer() const;
};

template<typename T>
class sp {
public:
    T* get() const;
    T* operator->() const;
    bool operator!=(std::nullptr_t) const;
};

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&);
    };
};

class GraphicBufferSource {
public:
    void addCodecBuffer(OMX_BUFFERHEADERTYPE*);
};

class OMXNodeInstance {
    OMX_HANDLETYPE mHandle;
    Mutex mLock;
public:
    status_t allocateBufferWithBackup(OMX_U32, const sp<IMemory>&, OMX::buffer_id*, OMX_U32);
    OMX::buffer_id makeBufferID(OMX_BUFFERHEADERTYPE*);
    void addActiveBuffer(OMX_U32, OMX::buffer_id);
    sp<GraphicBufferSource> getGraphicBufferSource();
    status_t StatusFromOMXError(OMX_ERRORTYPE);
};

struct BufferMeta {
    BufferMeta(const sp<IMemory>&, bool);
    BufferMeta(const sp<IMemory>&, OMX_U32, bool);
};

enum {
    BAD_VALUE = -1,
    OK = 0,
    kPortIndexInput = 1,
    OMX_ErrorNone = 0
};

#define SIMPLE_BUFFER(a,b,c) (a),(b),(c)
#define CLOG_ERROR(a,b,c) 
#define CHECK_EQ(a,b) 
#define NEW_BUFFER_FMT(a,b,c,d,e,f) 
#define CLOG_BUFFER(a,b) 

OMX_ERRORTYPE OMX_AllocateBuffer(OMX_HANDLETYPE, OMX_BUFFERHEADERTYPE**, OMX_U32, BufferMeta*, OMX_U32);