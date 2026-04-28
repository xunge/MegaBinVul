#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>

#define ALOGE printf
#define android_errorWriteLog(uid, tag) 
#define CHECK_GE(a, b) if ((a) < (b)) { return; }
#define CHECK_EQ(a, b) if ((a) != (b)) { return; }

typedef int32_t OMX_U32;
typedef int32_t OMX_ERRORTYPE;
typedef int32_t OMX_EVENTTYPE;

enum {
    OMX_EventError,
    OMX_ErrorOverflow,
    OMX_ErrorUndefined,
    NONE,
    OMX_BUFFERFLAG_EOS
};

enum {
    MODE_NARROW,
    MODE_WIDE
};

enum Frame_Type_3GPP {
    MIME_IETF
};

typedef uint8_t UWord8;
typedef int16_t int16;

typedef struct {
    uint8_t *pBuffer;
    OMX_U32 nAllocLen;
    OMX_U32 nFilledLen;
    OMX_U32 nOffset;
    OMX_U32 nFlags;
    OMX_U32 nTimeStamp;
} OMX_BUFFERHEADERTYPE;

typedef struct BufferInfo {
    OMX_BUFFERHEADERTYPE *mHeader;
    bool mOwnedByUs;
} BufferInfo;

typedef struct RX_State_wb {
    // Placeholder for RX state
} RX_State_wb;

template <typename T>
class List {
public:
    bool empty() const;
    T* begin();
    void erase(T*);
};

class SoftAMR {
private:
    bool mSignalledError;
    int mOutputPortSettingsChange;
    int mMode;
    void* mState;
    int64_t mAnchorTimeUs;
    int64_t mNumSamplesOutput;
    int mInputBufferCount;
    uint8_t mInputSampleBuffer[1024];
    void* mDecoderBuf;
    void* mDecoderCookie;
    
    static const int kNumSamplesPerFrameNB = 160;
    static const int kNumSamplesPerFrameWB = 320;
    static const int kSampleRateNB = 8000;
    static const int kSampleRateWB = 16000;
    
    List<BufferInfo*>& getPortQueue(int portIndex);
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE* header);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE* header);
    void notify(OMX_EVENTTYPE event, OMX_ERRORTYPE error, OMX_U32 data, void* info);
    size_t getFrameSize(int mode);
    
public:
    void onQueueFilled(OMX_U32 portIndex);
};

int AMRDecode(void* state, Frame_Type_3GPP frameType, UWord8* input, int16_t* output, int mimeType);
void mime_unsorting(uint8_t* input, uint8_t* output, int16_t* frameType, int16_t* mode, int numFrames, RX_State_wb* rx_state);
void pvDecoder_AmrWb(int16_t mode, uint8_t* input, int16_t* output, int16_t* numSamplesOutput, void* decoderBuf, int16_t frameType, void* decoderCookie);