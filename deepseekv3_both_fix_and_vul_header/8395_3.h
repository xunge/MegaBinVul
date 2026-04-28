#include <cstddef>
#include <cstdint>
#include <cstdbool>

typedef uint32_t OMX_U32;
typedef int32_t OMX_ERRORTYPE;
typedef uint32_t OMX_EVENTTYPE;
typedef uint32_t OMX_DIRTYPE;
typedef void* OMX_PTR;

#define OMX_DirInput 0
#define OMX_DirOutput 1
#define OMX_FALSE 0
#define OMX_EventError 0
#define OMX_ErrorUndefined 0
#define CHECK_LT(a,b) 
#define CHECK_EQ(a,b) 
#define CHECK(a) 
#define ALOGE(...)

struct OMX_BUFFERHEADERTYPE;

template <typename T>
class Vector {
public:
    size_t size() const { return 0; }
    T& editItemAt(size_t index) { static T t; return t; }
    void clear() {}
};

struct BufferInfo {
    OMX_BUFFERHEADERTYPE* mHeader;
    bool mOwnedByUs;
};

struct PortInfo {
    enum Transition {
        NONE,
        DISABLING,
        ENABLING
    };

    struct {
        bool bEnabled;
        OMX_DIRTYPE eDir;
    } mDef;
    
    Vector<BufferInfo> mBuffers;
    Transition mTransition;
    Vector<OMX_BUFFERHEADERTYPE*> mQueue;
};

class SimpleSoftOMXComponent {
protected:
    Vector<PortInfo> mPorts;
    void notify(OMX_EVENTTYPE eEvent, OMX_ERRORTYPE eError, OMX_U32 nData1, OMX_PTR pEventData) {}
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE* buffer) {}
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE* buffer) {}
    void android_errorWriteLog(uint32_t tag, const char* msg) {}
    void checkTransitions() {}
    virtual void onPortEnable(OMX_U32 portIndex, bool enable);
};