#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef int64_t OMX_TICKS;

typedef struct OMX_BUFFERHEADERTYPE {
    uint8_t *pBuffer;
    uint32_t nAllocLen;
    uint32_t nFilledLen;
    uint32_t nOffset;
    uint32_t nFlags;
    OMX_TICKS nTimeStamp;
} OMX_BUFFERHEADERTYPE;

typedef struct BufferInfo {
    OMX_BUFFERHEADERTYPE *mHeader;
    bool mOwnedByUs;
} BufferInfo;

typedef void* vpx_codec_iter_t;
typedef void* vpx_codec_ctx_t;

struct vpx_image {
    unsigned int d_w;
    unsigned int d_h;
    int fmt;
    void* user_priv;
    unsigned char* planes[3];
    int stride[3];
};

template<typename T>
class List {
public:
    bool empty() const { return false; }
    T* begin() { return nullptr; }
    void erase(T*) {}
};

class SoftVPX {
public:
    bool mFrameParallelMode;
    vpx_codec_ctx_t* mCtx;
    vpx_image* mImg;
    int mEOSStatus;

    List<BufferInfo*>& getPortQueue(int);
    void handlePortSettingsChange(bool*, uint32_t, uint32_t);
    uint32_t outputBufferWidth();
    uint32_t outputBufferHeight();
    void copyYV12FrameToOutputBuffer(uint8_t*, const uint8_t*, const uint8_t*, const uint8_t*, size_t, size_t, size_t);
    void notifyFillBufferDone(OMX_BUFFERHEADERTYPE*);
    bool outputBuffers(bool flushDecoder, bool display, bool eos, bool *portWillReset);
};

enum {
    VPX_IMG_FMT_I420,
    VPX_PLANE_Y,
    VPX_PLANE_U, 
    VPX_PLANE_V,
    OMX_BUFFERFLAG_EOS,
    OUTPUT_FRAMES_FLUSHED
};

#define ALOGE(...)
#define CHECK_EQ(a, b)
#define android_errorWriteLog(...)

// Mock VPX functions
static inline int vpx_codec_decode(vpx_codec_ctx_t*, const void*, unsigned int, void*, long) { return 0; }
static inline vpx_image* vpx_codec_get_frame(vpx_codec_ctx_t*, vpx_codec_iter_t*) { return nullptr; }