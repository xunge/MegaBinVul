#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

typedef uint32_t OMX_U32;
typedef void* OMX_PTR;

#define OMX_BUFFERFLAG_EOS 0x00000001
#define ALOGE printf
#define android_errorWriteLog(uid, msg)

struct OMX_BUFFERHEADERTYPE {
    OMX_U32 nFlags;
    OMX_U32 nFilledLen;
    OMX_U32 nAllocLen;
    OMX_U32 nOffset;
    OMX_U32 nTimeStamp;
    uint8_t* pBuffer;
};

enum OMX_EVENTTYPE {
    OMX_EventError
};

enum OMX_ERRORTYPE {
    OMX_ErrorUndefined
};

struct BufferInfo {
    OMX_BUFFERHEADERTYPE *mHeader;
    bool mOwnedByUs;
};

template<typename T> class List {
public:
    bool empty() const;
    T* begin();
    void erase(T*);
};

class SoftGSM {
public:
    bool mSignalledError;
    void *mGsm;
    int DecodeGSM(void *mGsm, int16_t *outBuffer, uint8_t *inBuffer, size_t inSize);
    void notify(OMX_EVENTTYPE eEvent, OMX_U32 nData1, OMX_U32 nData2, OMX_PTR pEventData);
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE *buffer);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE *buffer);
    List<BufferInfo *>& getPortQueue(OMX_U32 portIndex);
    void onQueueFilled(OMX_U32 portIndex);
};

const int kMaxNumSamplesPerFrame = 1024;
const int kMSGSMFrameSize = 65;