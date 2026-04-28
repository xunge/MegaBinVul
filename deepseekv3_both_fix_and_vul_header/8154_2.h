#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define FILEREAD_MAX_LAYERS 1
#define MAX_CHANNEL_COUNT 8
#define NONE 0
#define AWAITING_DISABLED 1
#define ERROR_MALFORMED 1
#define AACDEC_FLUSH 1
#define AAC_TPDEC_CLEAR_BUFFER 1
#define OMX_BUFFERFLAG_EOS 0x00000001
#define OMX_BUFFERFLAG_CODECCONFIG 0x00000002
#define OMX_EventError 1
#define OMX_ErrorUndefined 0
#define OMX_ErrorStreamCorrupt 1
#define OMX_EventPortSettingsChanged 2

#define ALOGE(fmt, ...) fprintf(stderr, "E/%s: " fmt "\n", "SoftAAC2", ##__VA_ARGS__)
#define ALOGW(fmt, ...) fprintf(stderr, "W/%s: " fmt "\n", "SoftAAC2", ##__VA_ARGS__)
#define ALOGI(fmt, ...) fprintf(stderr, "I/%s: " fmt "\n", "SoftAAC2", ##__VA_ARGS__)
#define ALOGV(fmt, ...) fprintf(stderr, "V/%s: " fmt "\n", "SoftAAC2", ##__VA_ARGS__)

static inline void hexdump(const void *data, size_t size) {
    const uint8_t *p = (const uint8_t *)data;
    for (size_t i = 0; i < size; i++) {
        fprintf(stderr, "%02x ", p[i]);
        if ((i + 1) % 16 == 0) fprintf(stderr, "\n");
    }
    fprintf(stderr, "\n");
}

typedef uint8_t UCHAR;
typedef uint32_t UINT;
typedef int32_t INT;
typedef int16_t INT_PCM;
typedef int32_t OMX_U32;
typedef int32_t OMX_ERRORTYPE;
typedef int32_t OMX_EVENTTYPE;

typedef enum {
    AAC_DEC_OK,
    AAC_DEC_NOT_ENOUGH_BITS,
    AAC_DEC_OUTPUT_BUFFER_TOO_SMALL,
    AAC_DEC_INVALID_HANDLE,
    AAC_DEC_UNSUPPORTED_AOT,
    AAC_DEC_UNSUPPORTED_FORMAT,
    AAC_DEC_UNSUPPORTED_ER_FORMAT,
    AAC_DEC_UNSUPPORTED_EPCONFIG,
    AAC_DEC_UNSUPPORTED_MULTILAYER,
    AAC_DEC_UNSUPPORTED_CHANNELCONFIG,
    AAC_DEC_UNSUPPORTED_SAMPLINGRATE,
    AAC_DEC_INVALID_BITSTREAM,
    AAC_DEC_DECODE_ERROR,
    AAC_DEC_CHANNEL_MAPPING_ERROR,
    AAC_DEC_TRANSPORT_SYNC_ERROR,
    AAC_DEC_UNSUPPORTED_EXTENSION_PAYLOAD,
    AAC_DEC_ANC_DATA_ERROR,
    AAC_DEC_TOO_SMALL_ANC_BUFFER,
    AAC_DEC_TOO_MANY_ANC_ELEMENTS,
    AAC_DEC_UNKNOWN_ERROR
} AAC_DECODER_ERROR;

typedef struct {
    int sampleRate;
    int numChannels;
    int frameSize;
    int aacSampleRate;
    int aacSamplesPerFrame;
    int outputDelay;
    int numTotalBytes;
} StreamInfo;

typedef struct {
    void submitStreamData(StreamInfo*);
    void update();
} DRCWrapper;

typedef struct {
    OMX_U32 nFlags;
    OMX_U32 nTimeStamp;
    OMX_U32 nOffset;
    OMX_U32 nFilledLen;
    OMX_U32 nAllocLen;
    uint8_t* pBuffer;
} OMX_BUFFERHEADERTYPE;

typedef struct {
    OMX_BUFFERHEADERTYPE* mHeader;
    bool mOwnedByUs;
} BufferInfo;

template<typename T>
class List {
public:
    bool empty();
    T* begin();
    void erase(T*);
};

template<typename T>
class Vector {
public:
    void add(T);
    T itemAt(int);
    void removeAt(int);
    int size();
    T& editItemAt(int);
    void clear();
    T top();
    void pop();
};

class SoftAAC2 {
private:
    bool mSignalledError;
    int mOutputPortSettingsChange;
    bool mEndOfInput;
    bool mEndOfOutput;
    bool mIsADTS;
    int mInputBufferCount;
    int mOutputBufferCount;
    int mOutputDelayCompensated;
    void* mAACDecoder;
    StreamInfo* mStreamInfo;
    DRCWrapper mDrcWrap;
    OMX_BUFFERHEADERTYPE* mLastInHeader;
    Vector<int32_t> mBufferSizes;
    Vector<int64_t> mBufferTimestamps;
    Vector<int32_t> mDecodedSizes;

    List<BufferInfo*>& getPortQueue(int);
    void notify(OMX_EVENTTYPE, OMX_U32, OMX_U32, void*);
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE*);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE*);
    void configureDownmix();
    bool outputDelayRingBufferPutSamples(INT_PCM*, int);
    int outputDelayRingBufferGetSamples(INT_PCM*, int);
    int outputDelayRingBufferSamplesAvailable();
    int outputDelayRingBufferSpaceLeft();

public:
    void onQueueFilled(OMX_U32 portIndex);
};

extern "C" {
    AAC_DECODER_ERROR aacDecoder_ConfigRaw(void*, UCHAR**, UINT*);
    AAC_DECODER_ERROR aacDecoder_Fill(void*, UCHAR**, UINT*, UINT*);
    AAC_DECODER_ERROR aacDecoder_DecodeFrame(void*, INT_PCM*, INT, INT);
    void aacDecoder_SetParam(void*, INT, INT);
}