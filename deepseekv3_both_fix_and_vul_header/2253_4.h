#include <stdint.h>
#include <cstddef>
#include <cassert>

#define CHECK(cond) assert(cond)
#define CHECK_LT(a, b) assert((a) < (b))
#define ALOGE(...)
#define android_errorWriteLog(...)

typedef int32_t OMX_ERRORTYPE;
typedef void* OMX_PTR;
typedef uint32_t OMX_U32;
typedef uint8_t OMX_U8;

typedef struct OMX_BUFFERHEADERTYPE {
    OMX_U32 nSize;
    struct {
        struct {
            OMX_U8 nVersionMajor;
            OMX_U8 nVersionMinor;
            OMX_U8 nRevision;
            OMX_U8 nStep;
        } s;
    } nVersion;
    OMX_U8* pBuffer;
    OMX_U32 nAllocLen;
    OMX_U32 nFilledLen;
    OMX_U32 nOffset;
    OMX_PTR pAppPrivate;
    OMX_PTR pPlatformPrivate;
    OMX_PTR pInputPortPrivate;
    OMX_PTR pOutputPortPrivate;
    void* hMarkTargetComponent;
    OMX_PTR pMarkData;
    OMX_U32 nTickCount;
    OMX_U32 nTimeStamp;
    OMX_U32 nFlags;
    OMX_U32 nOutputPortIndex;
    OMX_U32 nInputPortIndex;
} OMX_BUFFERHEADERTYPE;

#define OMX_ErrorNone 0
#define OMX_ErrorBadParameter 1
#define OMX_StateLoaded 2
#define OMX_FALSE 0
#define OMX_TRUE 1

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex&) {}
    };
};

struct PortDef {
    OMX_U32 nBufferSize;
    OMX_U32 nBufferCountActual;
    OMX_U8 bEnabled;
    OMX_U8 bPopulated;
};

struct BufferInfo {
    OMX_BUFFERHEADERTYPE* mHeader;
    bool mOwnedByUs;
};

template<typename T>
class Vector {
public:
    size_t size() const { return 0; }
    T& editItemAt(size_t) { static T t; return t; }
    void push() {}
};

struct PortInfo {
    PortDef mDef;
    Vector<BufferInfo> mBuffers;
};

class SimpleSoftOMXComponent {
public:
    OMX_ERRORTYPE useBuffer(OMX_BUFFERHEADERTYPE **header,
                           OMX_U32 portIndex,
                           OMX_PTR appPrivate,
                           OMX_U32 size,
                           OMX_U8 *ptr);
protected:
    Mutex mLock;
    Vector<PortInfo> mPorts;
    int mState;
    void checkTransitions() {}
};