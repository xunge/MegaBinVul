#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct AVFrame {
    int key_frame;
    void *owner2;
} AVFrame;

typedef struct AVCodecContext {
    int active_thread_type;
    int skip_frame;
    int debug;
    int has_b_frames;
    int bits_per_raw_sample;
    struct {
        int (*start_frame)(struct AVCodecContext *, void *, int);
        int (*decode_slice)(struct AVCodecContext *, const uint8_t *, int);
    } *hwaccel;
    struct {
        int capabilities;
    } *codec;
} AVCodecContext;

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct MpegEncContext {
    AVCodecContext *avctx;
    int flags2;
    int first_field;
    struct {
        AVFrame f;
        void *owner2;
    } *current_picture_ptr;
    int workaround_bugs;
    int flags;
    int low_delay;
    int codec_id;
    int slice_context_count;
    int droppable;
    int picture_structure;
    struct {
        GetBitContext gb;
    } s;
    struct {
        int dct_bits;
    } dsp;
    GetBitContext gb;
    int context_initialized;
    int data_partitioning;
} MpegEncContext;

typedef struct H264Context {
    MpegEncContext s;
    int is_avc;
    int nal_length_size;
    int max_contexts;
    int current_slice;
    int nal_unit_type;
    int nal_ref_idc;
    struct H264Context *thread_context[16];
    struct {
        int bit_depth_luma;
        int chroma_format_idc;
        int bitstream_restriction_flag;
        int num_reorder_frames;
    } sps;
    int cur_chroma_format_idc;
    int pixel_shift;
    int sei_recovery_frame_cnt;
    int delayed_pic[1];
    void *h264dsp;
    void *hpc;
    GetBitContext intra_gb;
    GetBitContext inter_gb;
    GetBitContext *intra_gb_ptr;
    GetBitContext *inter_gb_ptr;
    int redundant_pic_count;
    int slice_type_nos;
} H264Context;

#define FF_THREAD_FRAME 1
#define CODEC_FLAG2_CHUNKS 1
#define FF_BUG_AUTODETECT 1
#define FF_BUG_TRUNCATED 1
#define FF_DEBUG_STARTCODE 1
#define AVDISCARD_NONREF 1
#define AVDISCARD_BIDIR 1
#define AVDISCARD_NONKEY 1
#define AVDISCARD_ALL 1
#define CODEC_CAP_HWACCEL_VDPAU 1
#define CODEC_FLAG_LOW_DELAY 1
#define PICT_BOTTOM_FIELD 1
#define AV_LOG_ERROR 1
#define AV_LOG_DEBUG 1
#define AV_LOG_WARNING 1
#define CONFIG_H264_VDPAU_DECODER 1

#define NAL_SPS 7
#define NAL_PPS 8
#define NAL_IDR_SLICE 5
#define NAL_SLICE 1
#define NAL_DPA 2
#define NAL_DPB 3
#define NAL_DPC 4
#define NAL_SEI 6
#define NAL_AUD 9
#define NAL_END_SEQUENCE 10
#define NAL_END_STREAM 11
#define NAL_FILLER_DATA 12
#define NAL_SPS_EXT 13
#define NAL_AUXILIARY_SLICE 19

enum AV_PICTURE_TYPE {
    AV_PICTURE_TYPE_NONE = 0,
    AV_PICTURE_TYPE_I,
    AV_PICTURE_TYPE_P,
    AV_PICTURE_TYPE_B,
    AV_PICTURE_TYPE_S,
    AV_PICTURE_TYPE_SI,
    AV_PICTURE_TYPE_SP,
    AV_PICTURE_TYPE_BI
};

static void av_log(void *avctx, int level, const char *fmt, ...);
static int decode_rbsp_trailing(H264Context *h, const uint8_t *src);
static void idr(H264Context *h);
static void ff_h264_reset_sei(H264Context *h);
static const uint8_t *ff_h264_decode_nal(H264Context *h, const uint8_t *src, int *dst_length, int *consumed, int length);
static int decode_slice_header(H264Context *h, H264Context *h0);
static void decode_postinit(H264Context *h, int setup_finished);
static void execute_decode_slices(H264Context *h, int context_count);
static int ff_h264_decode_seq_parameter_set(H264Context *h);
static void ff_h264_decode_picture_parameter_set(H264Context *h, int bit_length);
static void ff_h264_decode_sei(H264Context *h);
static void ff_h264dsp_init(void *h264dsp, int bit_depth, int chroma_format_idc);
static void ff_h264_pred_init(void *hpc, int codec_id, int bit_depth, int chroma_format_idc);
static void ff_dsputil_init(void *dsp, AVCodecContext *avctx);
static void ff_vdpau_h264_picture_start(MpegEncContext *s);
static void ff_vdpau_add_data_chunk(MpegEncContext *s, const uint8_t *buf, int buf_size);
static void ff_thread_report_progress(AVFrame *f, int max, int is_bottom_field);
static void init_get_bits(GetBitContext *gb, const uint8_t *buffer, int bit_size);
static int get_ue_golomb(GetBitContext *gb);