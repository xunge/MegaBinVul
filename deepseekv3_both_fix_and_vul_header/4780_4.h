#include <stdint.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stddef.h>
#include <cstdio>

#define UNUSED(x) (void)(x)
#define MAX_TIME_STAMPS 32
#define TIME_DIFF(start, end, diff) \
    diff = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);
#define GETTIME(a, b) gettimeofday(a, b)
#define DUMP_TO_FILE(f, buf, size)
#define ALOGV(...)
#define ALOGE(...)
#define CHECK_EQ(a, b)
#define OMX_BUFFERFLAG_EOS 0x00000001
#define IV_I_FRAME 1
#define IMPEG2D_UNSUPPORTED_DIMENSIONS 1
#define IVD_RES_CHANGED 2
#define OK 0
#define OMX_EventError 0
#define OMX_ErrorUndefined 0

typedef uint32_t OMX_U32;
typedef int32_t status_t;

enum {
    NONE,
    AWAITING_DISABLED,
    OUTPUT_PORT_SETTINGS_CHANGE
};

enum {
    kInputPortIndex = 0,
    kOutputPortIndex = 1
};

struct OMX_BUFFERHEADERTYPE {
    uint32_t nFlags;
    uint64_t nTimeStamp;
    uint32_t nOffset;
    uint32_t nFilledLen;
    uint8_t* pBuffer;
};

struct BufferInfo {
    OMX_BUFFERHEADERTYPE* mHeader;
    bool mOwnedByUs;
};

typedef int32_t WORD32;
typedef int16_t WORD16;
typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef uint8_t UWORD8;
typedef int32_t IV_API_CALL_STATUS_T;

struct ivd_video_decode_ip_t {
    void* pv_stream_buffer;
    uint32_t u4_num_Bytes;
};

struct ivd_video_decode_op_t {
    uint32_t u4_error_code;
    uint32_t u4_frame_decoded_flag;
    uint32_t u4_num_bytes_consumed;
    uint32_t u4_pic_wd;
    uint32_t u4_pic_ht;
    uint32_t u4_output_present;
    int32_t e_pic_type;
};

template<typename T> class List {
public:
    T* begin();
    void erase(T*);
    bool empty();
};

typedef IV_API_CALL_STATUS_T (*ivdec_api_function_t)(void*, void*, void*);

class SoftMPEG2 {
protected:
    int mOutputPortSettingsChange;
    bool mReceivedEOS;
    bool mIsInFlush;
    bool mInitNeeded;
    bool mFlushNeeded;
    bool mChangingResolution;
    bool mWaitForI;
    uint32_t mNewWidth;
    uint32_t mNewHeight;
    uint32_t mWidth;
    uint32_t mHeight;
    bool mTimeStampsValid[MAX_TIME_STAMPS];
    uint64_t mTimeStamps[MAX_TIME_STAMPS];
    struct timeval mTimeStart;
    struct timeval mTimeEnd;
    void* mCodecCtx;
    FILE* mInFile;
    FILE* mOutFile;
    ivdec_api_function_t ivdec_api_function;

    void setFlushMode();
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE* header);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE* header);
    void resetDecoder();
    void resetPlugin();
    bool setDecodeArgs(ivd_video_decode_ip_t*, ivd_video_decode_op_t*, OMX_BUFFERHEADERTYPE*, OMX_BUFFERHEADERTYPE*, size_t);
    void handlePortSettingsChange(bool*, uint32_t, uint32_t);
    status_t reInitDecoder();
    List<BufferInfo*>& getPortQueue(uint32_t);
    size_t getMinTimestampIdx(uint64_t*, bool*);
    void onQueueFilled(OMX_U32 portIndex);
    void notify(uint32_t event, uint32_t data1, uint32_t data2, void* info);
};