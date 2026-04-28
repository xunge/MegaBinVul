#include <cstddef>
#include <stdint.h>
#include <sys/types.h>

typedef uint32_t OMX_U32;

namespace OMX {
    typedef uint32_t buffer_id;
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

template<typename K, typename V>
class KeyedVector {
public:
    ssize_t indexOfKey(const K& key) const;
    V valueAt(size_t index) const;
};

class BufferMeta {
public:
    OMX_U32 getPortIndex() const;
};

class OMXNodeInstance {
private:
    Mutex mBufferIDLock;
    KeyedVector<OMX::buffer_id, OMX_BUFFERHEADERTYPE*> mBufferIDToBufferHeader;
public:
    OMX_BUFFERHEADERTYPE* findBufferHeader(OMX::buffer_id buffer, OMX_U32 portIndex);
    OMX_BUFFERHEADERTYPE* findBufferHeader(OMX::buffer_id buffer);
};

void CLOGW(const char*, ...);
void android_errorWriteLog(uint32_t, const char*);