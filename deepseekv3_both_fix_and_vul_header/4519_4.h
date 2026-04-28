#include <stdint.h>
#include <string.h>

template <typename T>
class List {
public:
    bool empty() const;
    T* begin();
    void erase(T*);
};

typedef uint32_t OMX_U32;
typedef void* OMX_PTR;

struct OMX_BUFFERHEADERTYPE {
    uint8_t* pBuffer;
    uint32_t nAllocLen;
    uint32_t nFilledLen;
    uint32_t nOffset;
    uint32_t nFlags;
    uint64_t nTimeStamp;
};

#define OMX_BUFFERFLAG_EOS 0x00000001

enum OMX_EVENTTYPE {
    OMX_EventError
};

enum {
    OMX_ErrorNone = 0,
    OMX_ErrorOverflow,
    OMX_ErrorStreamCorrupt,
    OMX_ErrorUndefined
};

struct BufferInfo {
    OMX_BUFFERHEADERTYPE* mHeader;
    bool mOwnedByUs;
};

enum {
    MODE_NARROW,
    MODE_WIDE
};

enum {
    NONE
};

typedef uint8_t UWord8;
typedef int16_t int16;

struct RX_State_wb {
    // RX_State_wb members
};

class SoftAMR {
protected:
    bool mSignalledError;
    int mOutputPortSettingsChange;
    uint64_t mAnchorTimeUs;
    uint32_t mNumSamplesOutput;
    int mMode;
    void* mState;
    int16_t mInputSampleBuffer[320];
    void* mDecoderBuf;
    void* mDecoderCookie;
    uint32_t mInputBufferCount;

    virtual List<BufferInfo*>& getPortQueue(uint32_t portIndex) = 0;
    virtual void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE* header) = 0;
    virtual void notifyFillBufferDone(OMX_BUFFERHEADERTYPE* header) = 0;
    virtual void notify(OMX_EVENTTYPE eEvent, OMX_U32 nData1, OMX_U32 nData2, OMX_PTR pEventData) = 0;
    
public:
    void onQueueFilled(OMX_U32 portIndex);
    size_t getFrameSize(int16_t mode);
};

static const size_t kNumSamplesPerFrameNB = 160;
static const size_t kNumSamplesPerFrameWB = 320;
static const int kSampleRateNB = 8000;
static const int kSampleRateWB = 16000;

extern const size_t WmfDecBytesPerFrame[];

typedef enum {
    MIME_IETF
} Frame_Type_3GPP;

typedef void* AMRDecodeState;
extern int AMRDecode(AMRDecodeState state, Frame_Type_3GPP frameType, UWord8* input, int16_t* output, int mimeType);

extern void mime_unsorting(uint8_t* input, int16_t* output, int16_t* frameType, int16_t* mode, int16_t numFrames, RX_State_wb* state);

extern void pvDecoder_AmrWb(int16_t mode, int16_t* input, int16_t* output, int16_t* numSamplesOutput, void* decoderBuf, int16_t frameType, void* decoderCookie);

#define CHECK_EQ(a, b)
#define ALOGE(...)
#define android_errorWriteLog(...)