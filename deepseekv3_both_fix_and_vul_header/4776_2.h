#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define UNUSED(x) (void)(x)
#define OK 0
#define NONE 0
#define OMX_BUFFERFLAG_EOS 0x00000001
#define OMX_EventError 0
#define OMX_ErrorUndefined 0
#define IVD_RES_CHANGED 0
#define MAX_TIME_STAMPS 32
#define kInputPortIndex 0
#define kOutputPortIndex 1

typedef uint32_t OMX_U32;
typedef int32_t WORD32;
typedef uint32_t UWORD32;
typedef int16_t WORD16;
typedef uint16_t UWORD16;
typedef int8_t WORD8;
typedef uint8_t UWORD8;

typedef struct OMX_BUFFERHEADERTYPE {
    OMX_U32 nFlags;
    OMX_U32 nTimeStamp;
    OMX_U32 nFilledLen;
    OMX_U32 nOffset;
} OMX_BUFFERHEADERTYPE;

typedef struct BufferInfo {
    OMX_BUFFERHEADERTYPE* mHeader;
    bool mOwnedByUs;
} BufferInfo;

template<typename T>
class List {
public:
    T* begin();
    void erase(T*);
    bool empty();
};

typedef struct ivd_video_decode_ip_t {
    UWORD32 u4_error_code;
    UWORD32 u4_num_bytes_consumed;
    UWORD32 u4_frame_decoded_flag;
    UWORD32 u4_output_present;
    UWORD32 u4_pic_wd;
    UWORD32 u4_pic_ht;
    UWORD32 u4_ts;
} ivd_video_decode_ip_t;

typedef struct ivd_video_decode_op_t {
    UWORD32 u4_error_code;
    UWORD32 u4_num_bytes_consumed;
    UWORD32 u4_frame_decoded_flag;
    UWORD32 u4_output_present;
    UWORD32 u4_pic_wd;
    UWORD32 u4_pic_ht;
    UWORD32 u4_ts;
} ivd_video_decode_op_t;

typedef enum {
    IV_SUCCESS = 0,
    IV_FAIL = -1
} IV_API_CALL_STATUS_T;

struct SoftHEVC {
    bool mSignalledError;
    int mOutputPortSettingsChange;
    void* mCodecCtx;
    uint32_t mStride;
    bool mReceivedEOS;
    bool mIsInFlush;
    bool mFlushNeeded;
    bool mChangingResolution;
    bool mTimeStampsValid[MAX_TIME_STAMPS];
    uint64_t mTimeStamps[MAX_TIME_STAMPS];
    uint64_t mTimeStart;
    uint64_t mTimeEnd;

    int initDecoder();
    uint32_t outputBufferWidth();
    uint32_t outputBufferHeight();
    void setParams(uint32_t stride);
    List<BufferInfo*>& getPortQueue(int portIndex);
    void setFlushMode();
    bool setDecodeArgs(ivd_video_decode_ip_t*, ivd_video_decode_op_t*, OMX_BUFFERHEADERTYPE*, OMX_BUFFERHEADERTYPE*, size_t);
    void notify(int event, int error, int data, void* info);
    void resetDecoder();
    void resetPlugin();
    void handlePortSettingsChange(bool*, uint32_t, uint32_t);
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE*);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE*);
    void onQueueFilled(OMX_U32 portIndex);
};

IV_API_CALL_STATUS_T ivdec_api_function(void*, void*, void*);

#define GETTIME(a, b)
#define TIME_DIFF(a, b, c)
#define ALOGE(...)
#define ALOGV(...)