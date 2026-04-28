#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define OMX_BUFFERFLAG_EOS 0x00000001
#define OMX_BUFFERFLAG_SYNCFRAME 0x00000002
#define OMX_EventError 0
#define OMX_ErrorUndefined 0
#define VPX_IMG_FMT_I420 1
#define VPX_DL_REALTIME 1
#define VPX_CODEC_OK 0
#define VPX_CODEC_CX_FRAME_PKT 0
#define VPX_FRAME_IS_KEY 0x1
#define VPX_EFLAG_FORCE_KF 0x01
#define kInputPortIndex 0
#define kOutputPortIndex 1
#define kInputBufferAlignment 16
#define OMX_COLOR_FormatYUV420SemiPlanar 0x7FA30C00

#define ALOGE(fmt, ...) fprintf(stderr, "E: " fmt "\n", ##__VA_ARGS__)
#define ALOGW(fmt, ...) fprintf(stderr, "W: " fmt "\n", ##__VA_ARGS__)
#define android_errorWriteLog(tag, msg) fprintf(stderr, "E: %s %s\n", tag, msg)

typedef uint32_t OMX_U32;
typedef int32_t status_t;
#define OK 0

struct OMX_BUFFERHEADERTYPE {
    uint8_t* pBuffer;
    uint32_t nAllocLen;
    uint32_t nFilledLen;
    uint32_t nOffset;
    uint32_t nFlags;
    uint64_t nTimeStamp;
};

struct vpx_image_t {
    int fmt;
    unsigned int w;
    unsigned int h;
    unsigned int d_w;
    unsigned int d_h;
    unsigned int x_chroma_shift;
    unsigned int y_chroma_shift;
    unsigned char* planes[3];
    int stride[3];
};

struct vpx_codec_cx_pkt_t {
    int kind;
    union {
        struct {
            uint64_t pts;
            size_t sz;
            uint8_t* buf;
            uint32_t flags;
        } frame;
    } data;
};

typedef int vpx_codec_err_t;
typedef void* vpx_codec_iter_t;
typedef unsigned int vpx_enc_frame_flags_t;

struct vpx_codec_enc_cfg {
    uint32_t rc_target_bitrate;
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

class SoftVPXEncoder {
public:
    void* mCodecContext;
    vpx_codec_enc_cfg* mCodecConfiguration;
    bool mInputDataIsMeta;
    bool mKeyFrameRequested;
    bool mBitrateUpdated;
    uint32_t mWidth;
    uint32_t mHeight;
    uint32_t mBitrate;
    uint32_t mFramerate;
    uint32_t mTemporalPatternLength;
    uint8_t* mConversionBuffer;
    uint32_t mColorFormat;
    uint64_t mLastTimestamp;

    status_t initEncoder();
    void notify(OMX_U32, OMX_U32, OMX_U32, void*);
    List<BufferInfo*>& getPortQueue(OMX_U32);
    void notifyEmptyBufferDone(OMX_BUFFERHEADERTYPE*);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE*);
    const uint8_t* extractGraphicBuffer(uint8_t*, size_t, const uint8_t*, size_t, uint32_t, uint32_t);
    void ConvertYUV420SemiPlanarToYUV420Planar(const uint8_t*, uint8_t*, uint32_t, uint32_t);
    vpx_enc_frame_flags_t getEncodeFlags();
    void onQueueFilled(OMX_U32);
};

static inline int vpx_img_wrap(vpx_image_t* img, int fmt, unsigned int w, unsigned int h, 
                              unsigned int align, unsigned char* data) {
    return 0;
}

static inline vpx_codec_err_t vpx_codec_enc_config_set(void* ctx, vpx_codec_enc_cfg* cfg) {
    return 0;
}

static inline const char* vpx_codec_err_to_string(vpx_codec_err_t err) {
    return "";
}

static inline vpx_codec_err_t vpx_codec_encode(void* ctx, vpx_image_t* img, 
                                              uint64_t pts, uint32_t duration, 
                                              vpx_enc_frame_flags_t flags, int deadline) {
    return 0;
}

static inline const vpx_codec_cx_pkt_t* vpx_codec_get_cx_data(void* ctx, vpx_codec_iter_t* iter) {
    return nullptr;
}