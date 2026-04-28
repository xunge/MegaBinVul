#include <stdint.h>

#define AV_RL32(x) (*(const uint32_t*)(x))
#define FF_DEBUG_STARTCODE 0x0001
#define USER_DATA_STARTCODE 0x1B2
#define GOP_STARTCODE 0x1B3
#define VOS_STARTCODE 0x1B0
#define VISUAL_OBJ_STARTCODE 0x1B5
#define VOP_STARTCODE 0x1B6
#define FF_PROFILE_MPEG4_SIMPLE_STUDIO 0x2000
#define AV_CODEC_FLAG_LOW_DELAY (1 << 0)
#define FRAME_SKIPPED (-1)
#define AVERROR_INVALIDDATA (-2)
#define AVERROR_PATCHWELCOME (-3)

#define AV_LOG_VERBOSE 1
#define AV_LOG_DEBUG 2
#define AV_LOG_WARNING 3
#define AV_LOG_ERROR 4

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVCodecContext {
    int flags;
    int bits_per_raw_sample;
    int profile;
    int level;
    int has_b_frames;
    int debug;
} AVCodecContext;

typedef struct MpegEncContext {
    AVCodecContext *avctx;
    int studio_profile;
    int low_delay;
    uint32_t codec_tag;
} MpegEncContext;

typedef struct Mpeg4DecContext {
    MpegEncContext m;
    int divx_version;
    int xvid_build;
} Mpeg4DecContext;

static inline void align_get_bits(GetBitContext *gb) {}
static inline unsigned int get_bits(GetBitContext *gb, int n) { return 0; }
static inline unsigned int show_bits(GetBitContext *gb, int n) { return 0; }
static inline void skip_bits(GetBitContext *gb, int n) {}
static inline int get_bits_count(GetBitContext *gb) { return 0; }
static void av_log(void *avctx, int level, const char *fmt, ...) {}
static int decode_vol_header(Mpeg4DecContext *ctx, GetBitContext *gb) { return 0; }
static void decode_user_data(Mpeg4DecContext *ctx, GetBitContext *gb) {}
static void mpeg4_decode_gop_header(MpegEncContext *s, GetBitContext *gb) {}
static void mpeg4_decode_profile_level(MpegEncContext *s, GetBitContext *gb, int *profile, int *level) {}
static void next_start_code_studio(GetBitContext *gb) {}
static void extension_and_user_data(MpegEncContext *s, GetBitContext *gb, int n) {}
static int decode_studiovisualobject(Mpeg4DecContext *ctx, GetBitContext *gb) { return 0; }
static void mpeg4_decode_visual_object(MpegEncContext *s, GetBitContext *gb) {}
static int decode_studio_vop_header(Mpeg4DecContext *ctx, GetBitContext *gb) { return 0; }
static int decode_vop_header(Mpeg4DecContext *ctx, GetBitContext *gb) { return 0; }
static void avpriv_request_sample(void *avctx, const char *msg) {}
static void av_assert0(int expr) {}