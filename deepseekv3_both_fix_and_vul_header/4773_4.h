#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef uint32_t OMX_U32;
typedef int32_t OMX_ERRORTYPE;
typedef int32_t OMX_EVENTTYPE;
typedef int32_t OMX_COMMANDTYPE;
typedef int32_t int32;

#define OMX_BUFFERFLAG_EOS 0x00000001
#define OMX_EventError 1
#define OMX_ErrorUndefined 0
#define OMX_EventPortSettingsChanged 2
#define OUTPUT_BUFFER_TOO_SMALL 0x80001001

#define ALOGE(...)
#define ALOGV(...) 
#define ALOGV_IF(...)
#define android_errorWriteLog(...)
#define CHECK_GE(a, b) ((void)0)

struct OMX_BUFFERHEADERTYPE {
    uint8_t* pBuffer;
    uint32_t nAllocLen;
    uint32_t nFilledLen;
    uint32_t nOffset;
    uint32_t nFlags;
    int64_t nTimeStamp;
};

enum {
    NONE,
    AWAITING_DISABLED
};

enum ERROR_CODE {
    NO_DECODING_ERROR,
    NO_ENOUGH_MAIN_DATA_ERROR,
    SIDE_INFO_ERROR
};

struct tPVMP3DecoderExternal {
    int16_t* pOutputBuffer;
    uint8_t* pInputBuffer;
    uint32_t inputBufferCurrentLength;
    uint32_t inputBufferMaxLength;
    uint32_t inputBufferUsedLength;
    uint32_t outputFrameSize;
    uint32_t samplingRate;
    uint32_t num_channels;
};

struct BufferInfo {
    OMX_BUFFERHEADERTYPE* mHeader;
    bool mOwnedByUs;
};

template <typename T> class List {
public:
    bool empty() const { return false; }
    T* begin() { return nullptr; }
    void erase(T*) {}
};

ERROR_CODE pvmp3_framedecoder(tPVMP3DecoderExternal*, uint8_t*) {
    return NO_DECODING_ERROR;
}

class SoftMP3 {
private:
    bool mSignalledError;
    bool mSawInputEos;
    bool mSignalledOutputEos;
    bool mIsFirst;
    int32_t mOutputPortSettingsChange;
    int64_t mAnchorTimeUs;
    uint32_t mNumFramesOutput;
    uint32_t mSamplingRate;
    uint32_t mNumChannels;
    tPVMP3DecoderExternal* mConfig;
    uint8_t* mDecoderBuf;
    static const uint32_t kOutputBufferSize = 8192;
    static const uint32_t kPVMP3DecoderDelay = 529;

    List<BufferInfo*>& getPortQueue(int) { static List<BufferInfo*> q; return q; }
    void notify(OMX_EVENTTYPE, OMX_ERRORTYPE, int, void*) {}
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE*) {}
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE*) {}
    
public:
    void onQueueFilled(OMX_U32 portIndex);
};