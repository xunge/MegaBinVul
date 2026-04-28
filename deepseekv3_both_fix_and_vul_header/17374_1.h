#include <stdint.h>
#include <stdlib.h>

#define AV_CODEC_FLAG_LOW_DELAY (1 << 0)

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVCodecContext {
    int debug;
    int flags;
    int profile;
    int level;
    int has_b_frames;
    int bits_per_raw_sample;
} AVCodecContext;

typedef struct MpegEncContext {
    AVCodecContext *avctx;
    int codec_tag;
    int low_delay;
    int studio_profile;
} MpegEncContext;

typedef struct Mpeg4DecContext {
    MpegEncContext m;
    int divx_version;
    int xvid_build;
} Mpeg4DecContext;

#define AV_RL32(x) (*(const uint32_t*)(x))
#define FF_DEBUG_STARTCODE 0x0001
#define AV_LOG_VERBOSE 0
#define AV_LOG_DEBUG 0
#define AV_LOG_WARNING 0
#define AV_LOG_ERROR 0
#define FRAME_SKIPPED 0
#define AVERROR_INVALIDDATA (-1)
#define USER_DATA_STARTCODE 0x1B2
#define GOP_STARTCODE 0x1B3
#define VOS_STARTCODE 0x1B0
#define VISUAL_OBJ_STARTCODE 0x1B5
#define VOP_STARTCODE 0x1B6
#define FF_PROFILE_MPEG4_SIMPLE_STUDIO 0

static inline void align_get_bits(GetBitContext *gb) {}
static inline unsigned show_bits(GetBitContext *gb, int n) { return 0; }
static inline void skip_bits(GetBitContext *gb, int n) {}
static inline unsigned get_bits(GetBitContext *gb, int n) { return 0; }
static inline int get_bits_count(GetBitContext *gb) { return 0; }
static inline void av_log(void *avctx, int level, const char *fmt, ...) {}
static inline int decode_vol_header(Mpeg4DecContext *ctx, GetBitContext *gb) { return 0; }
static inline void decode_user_data(Mpeg4DecContext *ctx, GetBitContext *gb) {}
static inline void mpeg4_decode_gop_header(MpegEncContext *s, GetBitContext *gb) {}
static inline void mpeg4_decode_profile_level(MpegEncContext *s, GetBitContext *gb) {}
static inline void next_start_code_studio(GetBitContext *gb) {}
static inline void extension_and_user_data(MpegEncContext *s, GetBitContext *gb, int n) {}
static inline void mpeg4_decode_visual_object(MpegEncContext *s, GetBitContext *gb) {}
static inline int decode_studiovisualobject(Mpeg4DecContext *ctx, GetBitContext *gb) { return 0; }
static inline int decode_studio_vop_header(Mpeg4DecContext *ctx, GetBitContext *gb) { return 0; }
static inline int decode_vop_header(Mpeg4DecContext *ctx, GetBitContext *gb) { return 0; }