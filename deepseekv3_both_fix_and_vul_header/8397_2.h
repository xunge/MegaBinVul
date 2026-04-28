#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ALOGE(format, ...) fprintf(stderr, "E/%s: " format "\n", "SoftMP3", ##__VA_ARGS__)
#define ALOGV(format, ...) fprintf(stderr, "V/%s: " format "\n", "SoftMP3", ##__VA_ARGS__)
#define ALOGV_IF(cond, format, ...) do { if (cond) ALOGV(format, ##__VA_ARGS__); } while(0)
#define android_errorWriteLog(tag, subTag) ((void)0)
#define CHECK_GE(a, b) do { if ((a) < (b)) abort(); } while(0)

typedef uint32_t OMX_U32;
typedef int32_t int32;

#define NONE 0
#define AWAITING_DISABLED 1
#define OUTPUT_BUFFER_TOO_SMALL 2
#define OMX_BUFFERFLAG_EOS 0x00000001
#define OMX_EventError 0
#define OMX_ErrorUndefined 0
#define OMX_EventPortSettingsChanged 0

struct OMX_BUFFERHEADERTYPE {
    uint8_t* pBuffer;
    OMX_U32 nAllocLen;
    OMX_U32 nFilledLen;
    OMX_U32 nOffset;
    OMX_U32 nFlags;
    OMX_U32 nTimeStamp;
};

struct BufferInfo {
    OMX_BUFFERHEADERTYPE* mHeader;
    bool mOwnedByUs;
};

template <typename T>
class List {
public:
    bool empty() const;
    T* begin();
    void erase(T*);
};

enum ERROR_CODE {
    NO_DECODING_ERROR,
    NO_ENOUGH_MAIN_DATA_ERROR,
    SIDE_INFO_ERROR
};

class SoftMP3 {
private:
    bool mSignalledError;
    int mOutputPortSettingsChange;
    bool mSawInputEos;
    bool mSignalledOutputEos;
    int64_t mAnchorTimeUs;
    uint32_t mNumFramesOutput;
    struct {
        uint8_t* pInputBuffer;
        uint32_t inputBufferCurrentLength;
        uint32_t inputBufferMaxLength;
        uint32_t inputBufferUsedLength;
        uint32_t outputFrameSize;
        int16_t* pOutputBuffer;
        uint32_t samplingRate;
        uint32_t num_channels;
    } *mConfig;
    void* mDecoderBuf;
    uint32_t mSamplingRate;
    uint32_t mNumChannels;
    bool mIsFirst;
    static const uint32_t kOutputBufferSize;
    static const uint32_t kPVMP3DecoderDelay;

    List<BufferInfo*>& getPortQueue(int);
    void notify(OMX_U32, OMX_U32, OMX_U32, void*);
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE*);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE*);
    bool memsetSafe(OMX_BUFFERHEADERTYPE*, int, size_t);
    ERROR_CODE pvmp3_framedecoder(void*, void*);

public:
    void onQueueFilled(OMX_U32);
};