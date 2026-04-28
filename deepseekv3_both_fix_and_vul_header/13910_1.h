#include <stdint.h>
#include <stdlib.h>

#define AV_LOG_ERROR 0
#define AV_LOG_WARNING 1
#define AV_LOG_DEBUG 2
#define AV_LOG_VERBOSE 3
#define AVERROR_INVALIDDATA (-1)
#define DNXHD_HEADER_HR2 0x000002800100
#define DNXHD_VARIABLE 0
#define AV_PIX_FMT_YUV422P 0
#define AV_PIX_FMT_YUV422P10 1
#define AV_PIX_FMT_YUV422P12 2
#define AV_PIX_FMT_YUV444P10 3
#define AV_PIX_FMT_YUV444P12 4
#define AV_PIX_FMT_GBRP10 5
#define AV_PIX_FMT_GBRP12 6
#define FF_ARRAY_ELEMS(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef struct AVFrame {
    int interlaced_frame;
    int top_field_first;
} AVFrame;

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVCodecContext {
    int bits_per_raw_sample;
    AVRational sample_aspect_ratio;
} AVCodecContext;

typedef struct BlockDSPContext {
} BlockDSPContext;

typedef struct IDCTDSPContext {
    int idct_permutation;
} IDCTDSPContext;

typedef struct ScanTable {
} ScanTable;

typedef struct DNXHDContext {
    int bit_depth;
    AVCodecContext *avctx;
    int cur_field;
    int mbaff;
    int height;
    int width;
    int act;
    int is_444;
    int pix_fmt;
    int mb_width;
    int mb_height;
    int data_offset;
    uint32_t mb_scan_index[68];
    struct {
        int cid;
        int width;
        int coding_unit_size;
    } *cid_table;
    void (*decode_dct_block)(void);
    BlockDSPContext bdsp;
    IDCTDSPContext idsp;
    ScanTable scantable;
} DNXHDContext;

static inline uint16_t AV_RB16(const uint8_t *p) { return (p[0] << 8) | p[1]; }
static inline uint32_t AV_RB32(const uint8_t *p) { return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3]; }
static inline uint64_t avpriv_dnxhd_parse_header_prefix(const uint8_t *buf) { return 0; }
static void av_log(void *avctx, int level, const char *fmt, ...) {}
static void ff_dlog(void *avctx, const char *fmt, ...) {}
static void avpriv_request_sample(void *avctx, const char *fmt) {}
static void av_assert0(int expr) {}
static void ff_blockdsp_init(BlockDSPContext *c, void *avctx) {}
static void ff_idctdsp_init(IDCTDSPContext *c, void *avctx) {}
static void ff_init_scantable(int perm, ScanTable *scantable, const uint8_t *zigzag) {}
static const uint8_t ff_zigzag_direct[64] = {0};
static int dnxhd_init_vlc(DNXHDContext *ctx, int cid, int bitdepth) { return 0; }
static void dnxhd_decode_dct_block_10_444(void) {}
static void dnxhd_decode_dct_block_12_444(void) {}
static void dnxhd_decode_dct_block_12(void) {}
static void dnxhd_decode_dct_block_10(void) {}
static void dnxhd_decode_dct_block_8(void) {}
static void av_reduce(int *dst_num, int *dst_den, int64_t num, int64_t den, int64_t max) {}