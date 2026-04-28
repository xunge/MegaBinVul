#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_VPS_COUNT 16
#define MAX_SUB_LAYERS 7
#define MAX_SPS_COUNT 32
#define MAX_DPB_SIZE 16
#define MAX_SHORT_TERM_RPS_COUNT 64
#define MAX_LOG2_CTB_SIZE 15

#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24
#define AV_LOG_DEBUG 48
#define AVERROR_INVALIDDATA (-1)
#define AV_CODEC_FLAG2_IGNORE_CROP (1 << 15)
#define AV_CODEC_FLAG_UNALIGNED (1 << 0)
#define AV_EF_EXPLODE (1 << 9)

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVBufferRef {
    void *data;
} AVBufferRef;

typedef struct AVCodecContext {
    int flags;
    int flags2;
    int err_recognition;
    void (*av_log)(void *, int, const char *, ...);
} AVCodecContext;

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct HEVCWindow {
    int left_offset;
    int right_offset;
    int top_offset;
    int bottom_offset;
} HEVCWindow;

typedef struct HEVCSPS {
    int vps_id;
    int max_sub_layers;
    int chroma_format_idc;
    int separate_colour_plane_flag;
    int width;
    int height;
    HEVCWindow pic_conf_win;
    HEVCWindow output_window;
    int bit_depth;
    int log2_max_poc_lsb;
    struct {
        int max_dec_pic_buffering;
        int num_reorder_pics;
        int max_latency_increase;
    } temporal_layer[MAX_SUB_LAYERS];
    int log2_min_cb_size;
    int log2_diff_max_min_coding_block_size;
    int log2_min_tb_size;
    int log2_max_trafo_size;
    int max_transform_hierarchy_depth_inter;
    int max_transform_hierarchy_depth_intra;
    int scaling_list_enable_flag;
    struct {
    } scaling_list;
    int amp_enabled_flag;
    int sao_enabled;
    int pcm_enabled_flag;
    struct {
        int bit_depth;
        int bit_depth_chroma;
        int log2_min_pcm_cb_size;
        int log2_max_pcm_cb_size;
        int loop_filter_disable_flag;
    } pcm;
    int nb_st_rps;
    struct {
    } st_rps[MAX_SHORT_TERM_RPS_COUNT];
    int long_term_ref_pics_present_flag;
    int num_long_term_ref_pics_sps;
    int lt_ref_pic_poc_lsb_sps[32];
    int used_by_curr_pic_lt_sps_flag[32];
    int sps_temporal_mvp_enabled_flag;
    int sps_strong_intra_smoothing_enable_flag;
    struct {
        AVRational sar;
        HEVCWindow def_disp_win;
    } vui;
    int pixel_shift;
    int output_width;
    int output_height;
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
    int qp_bd_offset;
    int transform_skip_rotation_enabled_flag;
    int transform_skip_context_enabled_flag;
    int implicit_rdpcm_enabled_flag;
    int explicit_rdpcm_enabled_flag;
    int intra_smoothing_disabled_flag;
    int persistent_rice_adaptation_enabled_flag;
    struct {
    } ptl;
} HEVCSPS;

static inline int get_bits(GetBitContext *gb, int n) { return 0; }
static inline int get_bits1(GetBitContext *gb) { return 0; }
static inline void skip_bits(GetBitContext *gb, int n) {}
static inline void skip_bits1(GetBitContext *gb) {}
static inline int get_ue_golomb_long(GetBitContext *gb) { return 0; }
static inline int get_bits_left(GetBitContext *gb) { return 0; }
static inline int parse_ptl(GetBitContext *gb, AVCodecContext *avctx, void *ptl, int max_sub_layers) { return 0; }
static inline int ff_hevc_decode_short_term_rps(GetBitContext *gb, AVCodecContext *avctx, void *st_rps, HEVCSPS *sps, int flag) { return 0; }
static inline void decode_vui(GetBitContext *gb, AVCodecContext *avctx, int apply_defdispwin, HEVCSPS *sps) {}
static inline void set_default_scaling_list_data(void *scaling_list) {}
static inline int scaling_list_data(GetBitContext *gb, AVCodecContext *avctx, void *scaling_list, HEVCSPS *sps) { return 0; }
static inline int map_pixel_format(AVCodecContext *avctx, HEVCSPS *sps) { return 0; }
static inline int av_image_check_size(int width, int height, int flag, AVCodecContext *avctx) { return 0; }
static inline unsigned av_mod_uintp2(unsigned a, unsigned p) { return 0; }
static inline void avpriv_request_sample(AVCodecContext *avctx, const char *msg, ...) {}
static inline int FFMIN(int a, int b) { return a < b ? a : b; }