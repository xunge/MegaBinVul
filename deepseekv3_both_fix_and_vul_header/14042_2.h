#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct AVFrame;

typedef struct AVCodecContext {
    void *priv_data;
    int frame_number;
    int skip_loop_filter;
    int skip_frame;
    int debug;
    int active_thread_type;
    int height;
    void (*release_buffer)(struct AVCodecContext *, struct AVFrame *);
} AVCodecContext;

typedef struct AVPacket {
    const uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    int reference;
    int pict_type;
    int key_frame;
    int linesize[3];
    uint8_t *data[4];
    int type;
} AVFrame;

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct Vp3Fragment {
    int dummy;
} Vp3Fragment;

typedef struct Vp3DecodeContext {
    AVCodecContext *avctx;
    int theora;
    int keyframe;
    Vp3Fragment *all_fragments;
    int fragment_count;
    int qps[3];
    int last_qps[3];
    int nqps;
    int *filter_limit_values;
    int version;
    int chroma_y_shift;
    int height;
    int flipped_image;
    int data_offset[3];
    int c_superblock_height;
    AVFrame current_frame;
    AVFrame golden_frame;
    AVFrame last_frame;
    uint8_t *edge_emu_buffer;
    int skip_loop_filter;
    int last_slice_end;
} Vp3DecodeContext;

#define CONFIG_THEORA_DECODER 0
#define FF_THREAD_FRAME 1
#define AVERROR_PATCHWELCOME (-1)
#define AV_LOG_ERROR 0
#define AV_LOG_INFO 1
#define AV_LOG_WARNING 2
#define AV_LOG_DEBUG 3
#define FF_DEBUG_PICT_INFO 0x0001
#define AVDISCARD_ALL 48
#define AVDISCARD_NONKEY 32
#define AV_PICTURE_TYPE_I 1
#define AV_PICTURE_TYPE_P 2
#define FF_BUFFER_TYPE_COPY 1
#define HAVE_THREADS 1

static inline int FFABS(int x) { return x >= 0 ? x : -x; }

static void init_get_bits(GetBitContext *gb, const uint8_t *buf, int size);
static int get_bits1(GetBitContext *gb);
static int get_bits(GetBitContext *gb, int n);
static void skip_bits(GetBitContext *gb, int n);
static void skip_bits_long(GetBitContext *gb, int n);
static void av_log(void *avctx, int level, const char *fmt, ...);
static void init_loop_filter(Vp3DecodeContext *s);
static void init_dequantizer(Vp3DecodeContext *s, int i);
static int ff_thread_get_buffer(AVCodecContext *avctx, AVFrame *frame);
static void *av_malloc(size_t size);
static void ff_thread_report_progress(AVFrame *frame, int progress, int field);
static void ff_thread_finish_setup(AVCodecContext *avctx);
static int unpack_superblocks(Vp3DecodeContext *s, GetBitContext *gb);
static int unpack_modes(Vp3DecodeContext *s, GetBitContext *gb);
static int unpack_vectors(Vp3DecodeContext *s, GetBitContext *gb);
static int unpack_block_qpis(Vp3DecodeContext *s, GetBitContext *gb);
static int unpack_dct_coeffs(Vp3DecodeContext *s, GetBitContext *gb);
static void render_slice(Vp3DecodeContext *s, int i);
static void apply_loop_filter(Vp3DecodeContext *s, int i, int row, int row_end);
static void vp3_draw_horiz_band(Vp3DecodeContext *s, int height);
static void update_frames(AVCodecContext *avctx);