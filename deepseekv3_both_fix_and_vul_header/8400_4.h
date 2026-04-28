#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef int64_t OMX_TICKS;

typedef struct OMX_BUFFERHEADERTYPE {
    uint8_t* pBuffer;
    uint32_t nAllocLen;
    uint32_t nFilledLen;
    uint32_t nOffset;
    uint32_t nFlags;
    OMX_TICKS nTimeStamp;
} OMX_BUFFERHEADERTYPE;

typedef struct BufferInfo {
    OMX_BUFFERHEADERTYPE* mHeader;
    bool mOwnedByUs;
} BufferInfo;

typedef void* vpx_codec_iter_t;
typedef void* vpx_codec_ctx_t;

struct vpx_image {
    unsigned int d_w;
    unsigned int d_h;
    unsigned int fmt;
    void* user_priv;
    unsigned char* planes[3];
    int stride[3];
};

enum {
    VPX_PLANE_Y,
    VPX_PLANE_U,
    VPX_PLANE_V
};

enum {
    VPX_IMG_FMT_I420
};

enum {
    OUTPUT_FRAMES_FLUSHED,
    OMX_BUFFERFLAG_EOS
};

template <typename T>
class List {
public:
    bool empty() const;
    T* begin();
    void erase(T* position);
};

class SoftVPX {
public:
    bool mFrameParallelMode;
    vpx_codec_ctx_t* mCtx;
    vpx_image* mImg;
    int mEOSStatus;

    bool outputBuffers(bool flushDecoder, bool display, bool eos, bool* portWillReset);
    List<BufferInfo*>& getPortQueue(int port);
    void handlePortSettingsChange(bool* portWillReset, uint32_t width, uint32_t height);
    uint32_t outputBufferWidth();
    uint32_t outputBufferHeight();
    bool outputBufferSafe(OMX_BUFFERHEADERTYPE* outHeader);
    void copyYV12FrameToOutputBuffer(uint8_t* dst, const uint8_t* srcY, const uint8_t* srcU, const uint8_t* srcV, size_t srcYStride, size_t srcUStride, size_t srcVStride);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE* outHeader);
};

#define CHECK_EQ(a, b) ((void)0)
#define ALOGE(...) ((void)0)
#define android_errorWriteLog(...) ((void)0)

int vpx_codec_decode(vpx_codec_ctx_t* ctx, const void* data, unsigned int data_sz, void* user_priv, long deadline);
vpx_image* vpx_codec_get_frame(vpx_codec_ctx_t* ctx, vpx_codec_iter_t* iter);