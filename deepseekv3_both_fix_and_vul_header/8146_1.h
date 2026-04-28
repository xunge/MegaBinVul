#include <stdint.h>

typedef int32_t status_t;
typedef uint32_t OMX_U32;

namespace OMX {
    typedef int buffer_id;
}

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

template<typename T>
class sp {
public:
    sp() {}
    sp(T*) {}
};

class GraphicBuffer {};

struct OMX_BUFFERHEADERTYPE {};

class OMXNodeInstance {
public:
    status_t updateGraphicBufferInMeta(OMX_U32, const sp<GraphicBuffer>&, OMX::buffer_id);
    status_t updateGraphicBufferInMeta(OMX_U32, const sp<GraphicBuffer>&, OMX::buffer_id, OMX_BUFFERHEADERTYPE*);
private:
    Mutex mLock;
    OMX_BUFFERHEADERTYPE* findBufferHeader(OMX::buffer_id);
    OMX_BUFFERHEADERTYPE* findBufferHeader(OMX::buffer_id, OMX_U32);
    status_t updateGraphicBufferInMeta_l(OMX_U32, const sp<GraphicBuffer>&, OMX::buffer_id, OMX_BUFFERHEADERTYPE*);
};