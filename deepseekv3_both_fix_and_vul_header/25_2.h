#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#define FF_THREAD_FRAME 1
#define CODEC_FLAG2_CHUNKS 1
#define FF_BUG_AUTODETECT 1
#define FF_BUG_TRUNCATED 1
#define FF_DEBUG_STARTCODE 1
#define AVDISCARD_NONREF 1
#define AVDISCARD_BIDIR 1
#define AVDISCARD_NONKEY 1
#define AVDISCARD_ALL 1
#define NAL_SPS 7
#define NAL_PPS 8
#define NAL_DPA 2
#define NAL_IDR_SLICE 5
#define NAL_SLICE 1
#define NAL_SEI 6
#define NAL_DPB 3
#define NAL_DPC 4
#define NAL_AUD 9
#define NAL_END_SEQUENCE 10
#define NAL_END_STREAM 11
#define NAL_FILLER_DATA 12
#define NAL_SPS_EXT 13
#define NAL_AUXILIARY_SLICE 19
#define NAL_FF_IGNORE 0
#define AV_PICTURE_TYPE_B 3
#define AV_PICTURE_TYPE_I 1
#define PICT_BOTTOM_FIELD 1
#define FRAME_RECOVERED_IDR 1
#define AV_LOG_ERROR 1
#define AV_LOG_DEBUG 2
#define AV_LOG_INFO 3
#define HAVE_THREADS 1
#define ENOSYS 38

typedef struct AVFrame {
    int key_frame;
} AVFrame;

typedef struct ThreadFrame {
    int dummy;
} ThreadFrame;

typedef struct H264Picture {
    AVFrame f;
    int recovered;
    ThreadFrame tf;
} H264Picture;

typedef struct AVHWAccel {
    int (*start_frame)(void *avctx, const uint8_t *buf, uint32_t buf_size);
    int (*decode_slice)(void *avctx, const uint8_t *buf, uint32_t buf_size);
} AVHWAccel;

typedef struct AVCodecContext {
    int active_thread_type;
    int flags;
    int flags2;
    int skip_frame;
    int debug;
    AVHWAccel *hwaccel;
} AVCodecContext;

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct SPS {
    int log2_max_frame_num;
} SPS;

typedef struct H264Context {
    AVCodecContext *avctx;
    int slice_context_count;
    int current_slice;
    int first_field;
    H264Picture *cur_pic_ptr;
    int is_avc;
    int nal_length_size;
    int workaround_bugs;
    int nal_unit_type;
    int nal_ref_idc;
    int max_contexts;
    int frame_num;
    int recovery_frame;
    int sei_recovery_frame_cnt;
    int frame_recovered;
    int droppable;
    int picture_structure;
    GetBitContext gb;
    void *thread_context[16];
    int data_partitioning;
    int redundant_pic_count;
    int slice_type_nos;
    int context_initialized;
    int list_count;
    int ref_count[2];
    GetBitContext intra_gb;
    GetBitContext inter_gb;
    GetBitContext *intra_gb_ptr;
    GetBitContext *inter_gb_ptr;
    SPS sps;
} H264Context;

static void av_log(void *avctx, int level, const char *fmt, ...) {}
static void init_get_bits(GetBitContext *s, const uint8_t *buffer, int bit_size) {}
static unsigned get_ue_golomb(GetBitContext *gb) { return 0; }
static void ff_h264_reset_sei(H264Context *h) {}
static const uint8_t *ff_h264_decode_nal(H264Context *h, const uint8_t *buf, int *dst_length, int *consumed, int length) { return NULL; }
static int decode_rbsp_trailing(H264Context *h, const uint8_t *ptr) { return 0; }
static void idr(H264Context *h) {}
static int decode_slice_header(H264Context *hx, H264Context *h) { return 0; }
static void decode_postinit(H264Context *h, int b) {}
static void ff_h264_decode_sei(H264Context *h) {}
static int ff_h264_decode_seq_parameter_set(H264Context *h) { return 0; }
static int h264_set_parameter_from_sps(H264Context *h) { return 0; }
static void ff_h264_decode_picture_parameter_set(H264Context *h, int bit_length) {}
static void execute_decode_slices(H264Context *h, int context_count) {}
static void ff_thread_report_progress(ThreadFrame *tf, int max, int b) {}
static int AVERROR(int err) { return -err; }