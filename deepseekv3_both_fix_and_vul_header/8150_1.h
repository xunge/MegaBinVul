#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define UNUSED(x) (void)(x)
#define OK 0
#define NONE 0
#define ALOGE(...)
#define ALOGV(...)
#define MAX_TIME_STAMPS 16
#define IVD_STREAM_WIDTH_HEIGHT_NOT_SUPPORTED 0x0
#define IVD_MEM_ALLOC_FAILED 0x0
#define IVD_RES_CHANGED 0x0
#define OMX_EventError 0
#define OMX_ErrorUnsupportedSetting 0
#define OMX_ErrorUndefined 0
#define OMX_BUFFERFLAG_EOS 0x1

typedef uint32_t OMX_U32;
typedef int32_t WORD32;
typedef uint32_t UWORD32;
typedef int32_t IV_API_CALL_STATUS_T;

struct OMX_BUFFERHEADERTYPE {
    OMX_U32 nFlags;
    OMX_U32 nTimeStamp;
    OMX_U32 nOffset;
    OMX_U32 nFilledLen;
};

struct BufferInfo {
    OMX_BUFFERHEADERTYPE* mHeader;
    bool mOwnedByUs;
};

struct ivd_video_decode_ip_t {
    UWORD32 u4_error_code;
};

struct ivd_video_decode_op_t {
    UWORD32 u4_error_code;
    UWORD32 u4_frame_decoded_flag;
    UWORD32 u4_num_bytes_consumed;
    UWORD32 u4_pic_wd;
    UWORD32 u4_pic_ht;
    UWORD32 u4_output_present;
    UWORD32 u4_ts;
};

#define GETTIME(a, b) gettimeofday(a, b)
#define TIME_DIFF(a, b, c) \
    do { \
        (c) = ((a).tv_sec - (b).tv_sec) * 1000000 + ((a).tv_usec - (b).tv_usec); \
    } while (0)

template <typename T>
class List {
public:
    T* begin();
    void erase(T*);
    bool empty();
};

class SoftHEVC {
public:
    void onQueueFilled(OMX_U32 portIndex);
    bool mSignalledError;
    int mOutputPortSettingsChange;
    void* mCodecCtx;
    uint32_t mStride;
    bool mReceivedEOS;
    bool mIsInFlush;
    bool mTimeStampsValid[MAX_TIME_STAMPS];
    uint64_t mTimeStamps[MAX_TIME_STAMPS];
    struct timeval mTimeStart;
    struct timeval mTimeEnd;
    bool mFlushNeeded;
    bool mChangingResolution;
    uint32_t mWidth;
    uint32_t mHeight;

    int initDecoder();
    uint32_t outputBufferWidth();
    uint32_t outputBufferHeight();
    void setParams(uint32_t stride);
    List<BufferInfo*>& getPortQueue(uint32_t portIndex);
    void notify(OMX_U32 event, OMX_U32 data1, OMX_U32 data2, void* info);
    void setFlushMode();
    bool setDecodeArgs(ivd_video_decode_ip_t* ip, ivd_video_decode_op_t* op, 
                      OMX_BUFFERHEADERTYPE* inHeader, OMX_BUFFERHEADERTYPE* outHeader, 
                      size_t timeStampIx);
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE* header);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE* header);
    void resetDecoder();
    void resetPlugin();
    void handlePortSettingsChange(bool* portWillReset, uint32_t width, uint32_t height);
};

IV_API_CALL_STATUS_T ivdec_api_function(void* codec_ctx, void* ip, void* op);

static const uint32_t kInputPortIndex = 0;
static const uint32_t kOutputPortIndex = 1;