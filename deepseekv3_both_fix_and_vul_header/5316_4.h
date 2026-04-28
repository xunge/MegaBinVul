#include <stdint.h>
#include <limits.h>
#include <stddef.h>

#define HEVC_MAX_PPS_COUNT 64
#define HEVC_MAX_REFS 16
#define HEVC_NAL_CRA_NUT 21
#define HEVC_NAL_TRAIL_N 0
#define HEVC_NAL_TSA_N 2
#define HEVC_NAL_STSA_N 3
#define HEVC_NAL_RADL_N 4
#define HEVC_NAL_RADL_R 5
#define HEVC_NAL_RASL_N 6
#define HEVC_NAL_RASL_R 7
#define HEVC_SLICE_I 2
#define HEVC_SLICE_P 1
#define HEVC_SLICE_B 0
#define AV_LOG_ERROR 16
#define AV_LOG_WARNING 24
#define AV_EF_EXPLODE (1 << 9)
#define AVERROR_INVALIDDATA (-1)
#define AVERROR(ENOMEM) (-12)
#define L0 0
#define L1 1

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct HEVCLocalContext {
    GetBitContext gb;
    int first_qp_group;
    struct {
        int cu_qp_offset_cb;
        int cu_qp_offset_cr;
    } tu;
    int qp_y;
} HEVCLocalContext;

typedef struct ShortTermRPS {
    int num_negative_pics;
    int num_positive_pics;
} ShortTermRPS;

typedef struct LongTermRPS {
    int num_long_term_pics;
} LongTermRPS;

typedef struct HEVCPPS {
    int pic_init_qp_minus26;
    int num_ref_idx_l0_default_active;
    int num_ref_idx_l1_default_active;
    int dependent_slice_segments_enabled_flag;
    int output_flag_present_flag;
    int num_extra_slice_header_bits;
    int separate_colour_plane_flag;
    int sps_id;
    int disable_dbf;
    int beta_offset;
    int tc_offset;
    int lists_modification_present_flag;
    int cabac_init_present_flag;
    int weighted_pred_flag;
    int weighted_bipred_flag;
    int slice_header_extension_present_flag;
    int tiles_enabled_flag;
    int entropy_coding_sync_enabled_flag;
    int num_tile_rows;
    int num_tile_columns;
    int pic_slice_level_chroma_qp_offsets_present_flag;
    int chroma_qp_offset_list_enabled_flag;
    int deblocking_filter_control_present_flag;
    int deblocking_filter_override_enabled_flag;
    int seq_loop_filter_across_slices_enabled_flag;
    int cu_qp_delta_enabled_flag;
} HEVCPPS;

typedef struct HEVCSPS {
    int width;
    int height;
    int chroma_format_idc;
    int log2_max_poc_lsb;
    int max_sub_layers;
    int qp_bd_offset;
    int sao_enabled;
    int sps_temporal_mvp_enabled_flag;
    int nb_st_rps;
    int separate_colour_plane_flag;
    struct {
        int max_dec_pic_buffering;
    } temporal_layer[7];
    int ctb_width;
    int ctb_height;
    ShortTermRPS *st_rps;
} HEVCSPS;

typedef struct SliceHeader {
    int first_slice_in_pic_flag;
    int no_output_of_prior_pics_flag;
    int pps_id;
    int dependent_slice_segment_flag;
    int slice_segment_addr;
    int slice_addr;
    int slice_type;
    int pic_output_flag;
    int colour_plane_id;
    int pic_order_cnt_lsb;
    int short_term_ref_pic_set_sps_flag;
    ShortTermRPS slice_rps;
    ShortTermRPS *short_term_rps;
    LongTermRPS long_term_rps;
    int slice_temporal_mvp_enabled_flag;
    int slice_sample_adaptive_offset_flag[3];
    int nb_refs[2];
    int rpl_modification_flag[2];
    int list_entry_lx[2][16];
    int mvd_l1_zero_flag;
    int cabac_init_flag;
    int collocated_list;
    int collocated_ref_idx;
    int max_num_merge_cand;
    int slice_qp_delta;
    int slice_cb_qp_offset;
    int slice_cr_qp_offset;
    int cu_chroma_qp_offset_enabled_flag;
    int disable_deblocking_filter_flag;
    int beta_offset;
    int tc_offset;
    int slice_loop_filter_across_slices_enabled_flag;
    int num_entry_point_offsets;
    unsigned *entry_point_offset;
    int *offset;
    int *size;
    int slice_qp;
    int slice_ctb_addr_rs;
    int short_term_ref_pic_set_size;
    int long_term_ref_pic_set_size;
} SliceHeader;

typedef struct HEVCParamSets {
    HEVCPPS *pps;
    HEVCSPS *sps;
    struct {
        void *data;
    } *pps_list[HEVC_MAX_PPS_COUNT];
    struct {
        void *data;
    } *sps_list[32];
} HEVCParamSets;

typedef struct AVCodecContext {
    int err_recognition;
    void *priv_data;
    int threads_number;
} AVCodecContext;

typedef struct HEVCContext {
    HEVCLocalContext *HEVClc;
    SliceHeader sh;
    HEVCParamSets ps;
    AVCodecContext *avctx;
    int ref;
    int seq_decode;
    int max_ra;
    int nal_unit_type;
    int last_eos;
    int temporal_id;
    int poc;
    int pocTid0;
    int slice_idx;
    int slice_initialized;
    int enable_parallel_tiles;
    int threads_number;
} HEVCContext;

enum AVPixelFormat {
    AV_PIX_FMT_NONE = -1
};

static inline int get_bits1(GetBitContext *gb) { return 0; }
static inline int get_ue_golomb_long(GetBitContext *gb) { return 0; }
static inline int get_se_golomb(GetBitContext *gb) { return 0; }
static inline int get_bits(GetBitContext *gb, int n) { return 0; }
static inline int get_bitsz(GetBitContext *gb, int n) { return 0; }
static inline int get_bits_left(GetBitContext *gb) { return 0; }
static inline void skip_bits(GetBitContext *gb, int n) {}
static inline int av_ceil_log2(int v) { return 0; }
static inline void *av_malloc_array(size_t nmemb, size_t size) { return NULL; }
static inline void av_freep(void *ptr) {}
static inline void av_log(void *avctx, int level, const char *fmt, ...) {}
static inline unsigned get_bits_long(GetBitContext *gb, int n) { return 0; }

static inline int IS_IDR(HEVCContext *s) { return 0; }
static inline int IS_BLA(HEVCContext *s) { return 0; }
static inline int IS_IRAP(HEVCContext *s) { return 0; }
static inline void ff_hevc_clear_refs(HEVCContext *s) {}
static inline int ff_hevc_compute_poc(HEVCSPS *sps, int pocTid0, int poc_lsb, int nal_type) { return 0; }
static inline int ff_hevc_decode_short_term_rps(GetBitContext *gb, void *avctx, ShortTermRPS *rps, HEVCSPS *sps, int is_slice_header) { return 0; }
static inline int decode_lt_rps(HEVCContext *s, LongTermRPS *rps, GetBitContext *gb) { return 0; }
static inline int ff_hevc_frame_nb_refs(HEVCContext *s) { return 0; }
static inline int pred_weight_table(HEVCContext *s, GetBitContext *gb) { return 0; }
static inline enum AVPixelFormat get_format(HEVCContext *s, const HEVCSPS *sps) { return AV_PIX_FMT_NONE; }
static inline int set_sps(HEVCContext *s, const HEVCSPS *sps, enum AVPixelFormat pix_fmt) { return 0; }