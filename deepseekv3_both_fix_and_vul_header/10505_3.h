#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned long OMX_U32;
typedef int32_t INT;
typedef unsigned char UCHAR;

#define AACENC_OK 0
#define AACENC_BITRATE 0
#define IN_AUDIO_DATA 0
#define OUT_BITSTREAM_DATA 0
#define OMX_BUFFERFLAG_CODECCONFIG 0
#define OMX_BUFFERFLAG_ENDOFFRAME 0
#define OMX_BUFFERFLAG_EOS 0

struct OMX_BUFFERHEADERTYPE {
    OMX_U32 nOffset;
    OMX_U32 nFilledLen;
    OMX_U32 nAllocLen;
    OMX_U32 nFlags;
    OMX_U32 nTimeStamp;
    uint8_t* pBuffer;
};

struct BufferInfo {
    OMX_BUFFERHEADERTYPE* mHeader;
    bool mOwnedByUs;
};

template <typename T>
class List {
public:
    bool empty() const { return true; }
    T* begin() { return nullptr; }
    void erase(T*) {}
};

struct AACENC_InfoStruct {
    uint8_t* confBuf;
    OMX_U32 confSize;
};

struct AACENC_InArgs {
    OMX_U32 numInSamples;
};

struct AACENC_OutArgs {
    OMX_U32 numOutBytes;
    OMX_U32 numInSamples;
};

struct AACENC_BufDesc {
    OMX_U32 numBufs;
    void** bufs;
    INT* bufferIdentifiers;
    INT* bufSizes;
    INT* bufElSizes;
};

enum OMX_AUDIO_AACOBJECTTYPE {
    OMX_AUDIO_AACObjectELD
};

enum OMX_EVENTTYPE {
    OMX_EventError
};

enum OMX_ERRORTYPE {
    OMX_ErrorUndefined
};

typedef int AACENC_ERROR;

#define ALOGE(...)
#define ALOGW(...)
#define android_errorWriteLog(...)

class SoftAACEncoder2 {
private:
    bool mSignalledError;
    bool mSentCodecSpecificData;
    void* mAACEncoder;
    OMX_U32 mBitRate;
    OMX_U32 mNumChannels;
    OMX_U32 mSampleRate;
    OMX_AUDIO_AACOBJECTTYPE mAACProfile;
    size_t mInputSize;
    int16_t* mInputFrame;
    int64_t mInputTimeUs;
    bool mSawInputEOS;
    static const OMX_U32 kNumSamplesPerFrame = 1024;

public:
    void onQueueFilled(OMX_U32 portIndex);
    void notify(OMX_EVENTTYPE eEvent, OMX_ERRORTYPE eError, OMX_U32 nData1, OMX_U32 nData2);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE* buffer);
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE* buffer);
    List<BufferInfo*>& getPortQueue(OMX_U32 portIndex);
    AACENC_ERROR aacEncEncode(void* enc, AACENC_BufDesc* in, AACENC_BufDesc* out, AACENC_InArgs* inargs, AACENC_OutArgs* outargs);
    OMX_U32 aacEncoder_GetParam(void* enc, OMX_U32 param);
    AACENC_ERROR aacEncInfo(void* enc, AACENC_InfoStruct* info);
};