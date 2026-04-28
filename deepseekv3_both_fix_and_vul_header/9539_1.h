#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VPS_COUNT 16
#define MAX_SPS_COUNT 32
#define MAX_SUB_LAYERS 7
#define MAX_DPB_SIZE 16
#define MAX_SHORT_TERM_RPS_COUNT 64
#define MAX_LOG2_CTB_SIZE 6
#define CODEC_FLAG2_IGNORE_CROP (1 << 16)
#define CODEC_FLAG_UNALIGNED (1 << 0)
#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24
#define AV_LOG_DEBUG 48
#define AV_EF_EXPLODE (1 << 9)
#define FF_DEBUG_BITSTREAM (1 << 0)
#define FF_ARRAY_ELEMS(a) (sizeof(a) / sizeof((a)[0]))
#define AVERROR(e) (-(e))
#define ENOMEM 12
#define EINVAL 22
#define AVERROR_INVALIDDATA (-0x3ebbb1b2)
#define AVERROR_PATCHWELCOME (-0x3ebbb1b1)

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVBufferRef {
    uint8_t *data;
    size_t size;
} AVBufferRef;

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVPixFmtDescriptor {
    int log2_chroma_w;
    int log2_chroma_h;
} AVPixFmtDescriptor;

typedef struct AVCodecContext {
    int flags;
    int flags2;
    int err_recognition;
    int debug;
    void *priv_data;
} AVCodecContext;

typedef struct HEVCPTL {
    // Profile tier level structure
    int dummy;
} HEVCPTL;

typedef struct HEVCSPS {
    int vps_id;
    int max_sub_layers;
    HEVCPTL ptl;
    int chroma_format_idc;
    int separate_colour_plane_flag;
    int width;
    int height;
    int bit_depth;
    int pix_fmt;
    int log2_max_poc_lsb;
    int log2_min_cb_size;
    int log2_diff_max_min_coding_block_size;
    int log2_min_tb_size;
    int log2_max_trafo_size;
    int max_transform_hierarchy_depth_inter;
    int max_transform_hierarchy_depth_intra;
    int scaling_list_enable_flag;
    int amp_enabled_flag;
    int sao_enabled;
    int pcm_enabled_flag;
    int nb_st_rps;
    int long_term_ref_pics_present_flag;
    int num_long_term_ref_pics_sps;
    int sps_temporal_mvp_enabled_flag;
    int sps_strong_intra_smoothing_enable_flag;
    int transform_skip_rotation_enabled_flag;
    int transform_skip_context_enabled_flag;
    int implicit_rdpcm_enabled_flag;
    int explicit_rdpcm_enabled_flag;
    int intra_smoothing_disabled_flag;
    int persistent_rice_adaptation_enabled_flag;
    int pixel_shift;
    int qp_bd_offset;
    int log2_ctb_size;
    int log2_min_pu_size;
    int ctb_width;
    int ctb_height;
    int ctb_size;
    int min_cb_width;
    int min_cb_height;
    int min_tb_width;
    int min_tb_height;
    int min_pu_width;
    int min_pu_height;
    int tb_mask;
    int output_width;
    int output_height;
    int hshift[3];
    int vshift[3];
    struct {
        int left_offset;
        int right_offset;
        int top_offset;
        int bottom_offset;
    } pic_conf_win, output_window;
    struct {
        int bit_depth;
        int bit_depth_chroma;
        int log2_min_pcm_cb_size;
        int log2_max_pcm_cb_size;
        int loop_filter_disable_flag;
    } pcm;
    struct {
        AVRational sar;
        struct {
            int left_offset;
            int right_offset;
            int top_offset;
            int bottom_offset;
        } def_disp_win;
    } vui;
    struct {
        int max_dec_pic_buffering;
        int num_reorder_pics;
        int max_latency_increase;
    } temporal_layer[MAX_SUB_LAYERS];
    struct {
        int data[6][4][4];
    } scaling_list;
    int lt_ref_pic_poc_lsb_sps[MAX_SHORT_TERM_RPS_COUNT];
    int used_by_curr_pic_lt_sps_flag[MAX_SHORT_TERM_RPS_COUNT];
    struct {
        int num_delta_pocs;
        int num_negative_pics;
        int num_positive_pics;
        int delta_poc[32];
        int used[32];
    } st_rps[MAX_SHORT_TERM_RPS_COUNT];
} HEVCSPS;

typedef struct HEVCPPS {
    int sps_id;
} HEVCPPS;

typedef struct HEVCLocalContext {
    GetBitContext gb;
} HEVCLocalContext;

typedef struct HEVCContext {
    AVCodecContext *avctx;
    HEVCLocalContext *HEVClc;
    AVBufferRef *vps_list[MAX_VPS_COUNT];
    AVBufferRef *sps_list[MAX_SPS_COUNT];
    AVBufferRef *pps_list[MAX_SPS_COUNT];
    AVBufferRef *current_sps;
    HEVCSPS *sps;
    int apply_defdispwin;
} HEVCContext;

static const AVPixFmtDescriptor *av_pix_fmt_desc_get(int fmt);
static int av_image_check_size(int w, int h, int log_offset, void *log_ctx);
static void av_log(void *avcl, int level, const char *fmt, ...);
static void avpriv_report_missing_feature(void *avctx, const char *msg);
static int get_bits(GetBitContext *gb, int n);
static int get_bits1(GetBitContext *gb);
static void skip_bits(GetBitContext *gb, int n);
static void skip_bits1(GetBitContext *gb);
static int get_ue_golomb_long(GetBitContext *gb);
static AVBufferRef *av_buffer_allocz(size_t size);
static void av_buffer_unref(AVBufferRef **buf);
static int parse_ptl(HEVCContext *s, HEVCPTL *ptl, int max_sub_layers);
static int ff_hevc_decode_short_term_rps(HEVCContext *s, void *rps, HEVCSPS *sps, int flag);
static int decode_vui(HEVCContext *s, HEVCSPS *sps);
static void set_default_scaling_list_data(void *scaling_list);
static int scaling_list_data(HEVCContext *s, void *scaling_list, HEVCSPS *sps);
static const char *av_get_pix_fmt_name(int pix_fmt);
static int get_bits_left(GetBitContext *gb);
static AVBufferRef *av_buffer_ref(AVBufferRef *buf);
static int FFMIN(int a, int b);

enum AVPixelFormat {
    AV_PIX_FMT_YUV420P,
    AV_PIX_FMT_YUV422P,
    AV_PIX_FMT_YUV444P,
    AV_PIX_FMT_YUV420P9,
    AV_PIX_FMT_YUV422P9,
    AV_PIX_FMT_YUV444P9,
    AV_PIX_FMT_YUV420P10,
    AV_PIX_FMT_YUV422P10,
    AV_PIX_FMT_YUV444P10,
    AV_PIX_FMT_YUV420P12,
    AV_PIX_FMT_YUV422P12,
    AV_PIX_FMT_YUV444P12,
};