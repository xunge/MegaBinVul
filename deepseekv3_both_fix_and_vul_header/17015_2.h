#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVCodecContext {
    void *priv_data;
    int width;
    int height;
    int coded_width;
    int coded_height;
    int skip_loop_filter;
    int skip_frame;
    int frame_number;
    int debug;
    void *avctx;
    int active_thread_type;
} AVCodecContext;

typedef struct AVFrame {
    int pict_type;
    int key_frame;
    int linesize[3];
    uint8_t *data[3];
    int crop_left;
    int crop_right;
    int crop_top;
    int crop_bottom;
} AVFrame;

typedef struct AVPacket {
    const uint8_t *data;
    int size;
} AVPacket;

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct Vp3Fragment {
    int dummy;
} Vp3Fragment;

typedef struct Vp3DecodeContext {
    int theora;
    int keyframe;
    int nqps;
    int qps[3];
    int last_qps[3];
    int version;
    int height;
    int chroma_y_shift;
    int flipped_image;
    int data_offset[3];
    int last_slice_end;
    int c_superblock_height;
    int offset_x;
    int offset_y;
    int *filter_limit_values;
    int skip_loop_filter;
    int macroblock_height;
    int macroblock_width;
    int fragment_count;
    Vp3Fragment *all_fragments;
    struct {
        AVFrame *f;
    } current_frame, golden_frame, last_frame;
    uint8_t *edge_emu_buffer;
    AVCodecContext *avctx;
} Vp3DecodeContext;

#define CONFIG_THEORA_DECODER 0
#define CONFIG_VP4_DECODER 0
#define FF_THREAD_FRAME 1
#define AVERROR_PATCHWELCOME (-1)
#define AVERROR_DECODER_NOT_FOUND (-1)
#define AVERROR(ENOMEM) (-1)
#define AV_LOG_ERROR 0
#define AV_LOG_WARNING 0
#define AV_LOG_INFO 0
#define AV_LOG_DEBUG 0
#define FF_DEBUG_PICT_INFO 0
#define AVDISCARD_ALL 0
#define AVDISCARD_NONKEY 0
#define AV_PICTURE_TYPE_I 1
#define AV_PICTURE_TYPE_P 2
#define AV_GET_BUFFER_FLAG_REF 0
#define INT_MAX 2147483647
#define FFABS(x) ((x) >= 0 ? (x) : -(x))
#define HAVE_THREADS 0

static int init_get_bits8(GetBitContext *gb, const uint8_t *buf, int buf_size) { return 0; }
static int get_bits1(GetBitContext *gb) { return 0; }
static int get_bits(GetBitContext *gb, int n) { return 0; }
static void skip_bits(GetBitContext *gb, int n) {}
static void skip_bits_long(GetBitContext *gb, int n) {}
static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}
static int vp3_decode_end(AVCodecContext *avctx) { return 0; }
static int theora_decode_header(AVCodecContext *avctx, GetBitContext *gb) { return 0; }
static int vp3_decode_init(AVCodecContext *avctx) { return 0; }
static int theora_decode_tables(AVCodecContext *avctx, GetBitContext *gb) { return 0; }
static void init_loop_filter(Vp3DecodeContext *s) {}
static void init_dequantizer(Vp3DecodeContext *s, int i) {}
static int ff_thread_get_ext_buffer(AVCodecContext *avctx, void *frame, int flags) { return 0; }
static void *av_malloc(size_t size) { return NULL; }
static int ff_thread_release_ext_buffer(AVCodecContext *avctx, void *frame) { return 0; }
static int ff_thread_ref_frame(void *dst, void *src) { return 0; }
static void ff_thread_report_progress(void *frame, int progress, int field) {}
static int unpack_superblocks(Vp3DecodeContext *s, GetBitContext *gb) { return 0; }
static int unpack_modes(Vp3DecodeContext *s, GetBitContext *gb) { return 0; }
static int unpack_vectors(Vp3DecodeContext *s, GetBitContext *gb) { return 0; }
static int unpack_block_qpis(Vp3DecodeContext *s, GetBitContext *gb) { return 0; }
static int unpack_dct_coeffs(Vp3DecodeContext *s, GetBitContext *gb) { return 0; }
static void render_slice(Vp3DecodeContext *s, int i) {}
static void apply_loop_filter(Vp3DecodeContext *s, int i, int row, int next_row) {}
static void vp3_draw_horiz_band(Vp3DecodeContext *s, int height) {}
static int av_frame_ref(void *dst, void *src) { return 0; }
static int update_frames(AVCodecContext *avctx) { return 0; }
static void av_frame_unref(void *frame) {}
static void avpriv_request_sample(void *avctx, const char *msg) {}
static int vp4_unpack_macroblocks(Vp3DecodeContext *s, GetBitContext *gb) { return 0; }
static int vp4_unpack_dct_coeffs(Vp3DecodeContext *s, GetBitContext *gb) { return 0; }
static void ff_thread_finish_setup(AVCodecContext *avctx) {}