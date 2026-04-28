#include <stdint.h>

#define AV_LOG_ERROR 0
#define FRAMETYPE_INTRA 0
#define FRAMETYPE_NULL 0
#define IVI_MB_HUFF 0

typedef struct GetBitContext {
    int dummy;
} GetBitContext;

typedef struct VLC {
    int dummy;
} VLC;

typedef struct AVCodecContext {
    int dummy;
} AVCodecContext;

typedef struct IVI5DecContext {
    GetBitContext gb;
    int frame_type;
    int prev_frame_type;
    int frame_num;
    int gop_invalid;
    int frame_flags;
    int pic_hdr_size;
    int checksum;
    VLC mb_vlc;
} IVI5DecContext;

static int get_bits(GetBitContext *gb, int n);
static int get_bits_long(GetBitContext *gb, int n);
static void skip_bits(GetBitContext *gb, int n);
static void align_get_bits(GetBitContext *gb);
static void skip_hdr_extension(GetBitContext *gb);
static int ff_ivi_dec_huff_desc(GetBitContext *gb, int flag, int huff_type, VLC *vlc, AVCodecContext *avctx);
static int decode_gop_header(IVI5DecContext *ctx, AVCodecContext *avctx);
static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);