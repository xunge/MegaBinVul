#include <stdint.h>
#include <stdlib.h>
#include <sys/time.h>
#include <cstdio>

#define UNUSED(x) (void)(x)
#define OK 0
#define ALOGE(...)
#define OMX_EventError 0
#define OMX_ErrorUnsupportedSetting 0
#define OMX_ErrorUndefined 0
#define OMX_BUFFERFLAG_EOS 0x00000001
#define IVD_STREAM_WIDTH_HEIGHT_NOT_SUPPORTED 0
#define IVD_MEM_ALLOC_FAILED 0
#define IVD_RES_CHANGED 0
#define MAX_TIME_STAMPS 10
#define DUMP_TO_FILE(file, buf, size)
#define GETTIME(tv, tz) gettimeofday(tv, tz)
#define TIME_DIFF(start, end, diff)
#define PRINT_TIME(fmt, timeTaken, timeDelay, bytes)
#define IV_API_CALL_STATUS_T int

typedef uint32_t OMX_U32;
typedef int32_t WORD32;

struct OMX_BUFFERHEADERTYPE {
    uint32_t nFlags;
    uint32_t nTimeStamp;
    uint32_t nOffset;
    uint32_t nFilledLen;
    void* pv_stream_buffer;
};

struct BufferInfo {
    OMX_BUFFERHEADERTYPE* mHeader;
    bool mOwnedByUs;
};

struct ivd_video_decode_ip_t {
    void* pv_stream_buffer;
    uint32_t u4_num_Bytes;
};

struct ivd_video_decode_op_t {
    uint32_t u4_error_code;
    uint32_t u4_frame_decoded_flag;
    uint32_t u4_num_bytes_consumed;
    uint32_t u4_output_present;
    uint32_t u4_pic_wd;
    uint32_t u4_pic_ht;
    uint32_t u4_ts;
};

template<typename T>
class List {
public:
    typedef T* iterator;
    iterator begin() { return nullptr; }
    bool empty() { return false; }
    void erase(iterator) {}
};

enum {
    NONE,
    kInputPortIndex,
    kOutputPortIndex
};

class SoftAVC {
public:
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
    struct timeval mTimeStart;
    struct timeval mTimeEnd;
    FILE* mInFile;
    uint32_t mWidth;
    uint32_t mHeight;

    int initDecoder();
    uint32_t outputBufferWidth();
    uint32_t outputBufferHeight();
    void setParams(uint32_t stride);
    List<BufferInfo*>& getPortQueue(uint32_t portIndex);
    void notify(uint32_t event, uint32_t error, uint32_t data, void* info);
    void setFlushMode();
    bool setDecodeArgs(ivd_video_decode_ip_t* dec_ip, ivd_video_decode_op_t* dec_op, 
                      OMX_BUFFERHEADERTYPE* inHeader, OMX_BUFFERHEADERTYPE* outHeader, 
                      size_t timeStampIx);
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE* header);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE* header);
    void resetDecoder();
    void resetPlugin();
    void handlePortSettingsChange(bool* portWillReset, uint32_t width, uint32_t height);
    IV_API_CALL_STATUS_T ivdec_api_function(void* codec_ctx, void* dec_ip, void* dec_op);
    void onQueueFilled(OMX_U32 portIndex);
};