#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVStereo3D {
    int type;
    int flags;
} AVStereo3D;

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVCodecContext {
    int debug;
    AVRational sample_aspect_ratio;
    void *log_ctx;
} AVCodecContext;

typedef struct MJpegDecodeContext {
    GetBitContext gb;
    AVCodecContext *avctx;
    int buggy_avid;
    int adobe_transform;
    int rgb;
    int pegasus_rct;
    int got_picture;
    int colr;
    int xfrm;
    int start_code;
    AVStereo3D *stereo3d;
    void *exif_metadata;
} MJpegDecodeContext;

typedef struct GetByteContext {
    const uint8_t *buffer;
    int index;
    int size;
} GetByteContext;

#define AVERROR_INVALIDDATA (-1)
#define FF_DEBUG_STARTCODE (1 << 0)
#define FF_DEBUG_PICT_INFO (1 << 1)
#define AV_LOG_DEBUG 0
#define AV_LOG_INFO 0
#define AV_LOG_ERROR 0
#define AV_LOG_WARNING 0
#define APP1 0xE1
#define APP3 0xE3
#define SEEK_SET 0
#define AV_RB32(x) (0)
#define AV_RL32(x) (0)
#define AV_STEREO3D_2D 0
#define AV_STEREO3D_LINES 1
#define AV_STEREO3D_SIDEBYSIDE 2
#define AV_STEREO3D_TOPBOTTOM 3
#define AV_STEREO3D_FLAG_INVERT (1 << 0)

static inline int get_bits(GetBitContext *s, int n) { return 0; }
static inline int get_bits_left(GetBitContext *s) { return 0; }
static inline int get_bits_long(GetBitContext *s, int n) { return 0; }
static inline void skip_bits(GetBitContext *s, int n) {}
static inline const uint8_t *align_get_bits(GetBitContext *s) { return NULL; }
static void av_log(void *avctx, int level, const char *fmt, ...) {}
static void av_get_codec_tag_string(char *buf, size_t buf_size, unsigned int codec_tag) {}
static unsigned int av_bswap32(unsigned int x) { return 0; }
static void ff_set_sar(AVCodecContext *avctx, AVRational sar) {}
static AVStereo3D *av_stereo3d_alloc(void) { return NULL; }
static int ff_tdecode_header(GetByteContext *gbytes, int *le, int *ifd_offset) { return 0; }
static int avpriv_exif_decode_ifd(void *avctx, GetByteContext *gbytes, int le, int ifd, void **exif_metadata) { return 0; }

static void bytestream2_init(GetByteContext *gbytes, const uint8_t *buf, int size) {}
static int bytestream2_tell(GetByteContext *gbytes) { return 0; }
static void bytestream2_seek(GetByteContext *gbytes, int offset, int whence) {}