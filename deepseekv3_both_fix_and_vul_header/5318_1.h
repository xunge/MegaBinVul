#include <stdint.h>
#include <string.h>

#define STUDIO_INTRA_BITS 9
#define AV_LOG_ERROR 16
#define AVERROR_INVALIDDATA (-1)

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct VLC {
    int16_t (*table)[2];
    int table_allocated;
    int table_size;
    int bits;
} VLC;

typedef struct AVCodecContext {
    void *priv_data;
    int bits_per_raw_sample;
} AVCodecContext;

typedef struct Mpeg4DecContext {
    VLC studio_intra_tab[22];
    VLC studio_luma_dc;
    VLC studio_chroma_dc;
    int rgb;
} Mpeg4DecContext;

typedef struct MpegEncContext {
    AVCodecContext *avctx;
    GetBitContext gb;
    int intra_dc_precision;
    int dct_precision;
    int qscale;
    int mpeg_quant;
    int bits_per_raw_sample;
    int last_dc[3];
    struct {
        uint8_t permutated[64];
    } intra_scantable;
    uint16_t intra_matrix[64];
    uint16_t chroma_intra_matrix[64];
} MpegEncContext;

static const uint8_t ac_state_tab[22][2] = {
    {0,0}, {1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6},
    {1,7}, {2,8}, {3,9}, {4,10}, {5,11}, {6,12},
    {3,13}, {4,14}, {5,15}, {6,16}, {7,17}, {8,18}, {9,19}, {10,20},
    {0,21}
};

static int get_vlc2(GetBitContext *gb, int16_t (*table)[2], int bits, int max_depth);
static int get_bits(GetBitContext *gb, int n);
static int get_xbits(GetBitContext *gb, int n);
static int check_marker(AVCodecContext *avctx, GetBitContext *gb, const char *msg);
static int av_clip(int a, int amin, int amax);
static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);