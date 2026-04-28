#include <stdint.h>
#include <assert.h>
#include <vector>

#define DE265_MAX_SPS_SETS 16
#define MAX_PICTURE_WIDTH 16384
#define MAX_PICTURE_HEIGHT 16384
#define MAX_NUM_REF_PICS 16
#define MAX_NUM_LT_REF_PICS_SPS 32
#define UVLC_ERROR (-1)

enum de265_error {
    DE265_OK,
    DE265_ERROR_CODED_PARAMETER_OUT_OF_RANGE,
    DE265_WARNING_INVALID_CHROMA_FORMAT,
    DE265_WARNING_SPS_HEADER_INVALID,
    DE265_WARNING_PCM_BITDEPTH_TOO_LARGE,
    DE265_WARNING_NUMBER_OF_SHORT_TERM_REF_PIC_SETS_OUT_OF_RANGE
};

struct error_queue {
    void add_warning(int, bool);
};

struct bitreader {
    int get_bits(int n);
    int get_uvlc();
};

struct profile_tier_level {
    void read(bitreader* br, int max_sub_layers);
};

struct vui_parameters {
    de265_error read(error_queue* errqueue, bitreader* br, struct seq_parameter_set* sps);
};

struct range_extension {
    de265_error read(error_queue* errqueue, bitreader* br);
};

struct scaling_list_data {
};

struct short_term_ref_pic_set {
};

struct seq_parameter_set {
    int video_parameter_set_id;
    int sps_max_sub_layers;
    int sps_temporal_id_nesting_flag;
    profile_tier_level profile_tier_level_;
    int seq_parameter_set_id;
    int chroma_format_idc;
    int separate_colour_plane_flag;
    int pic_width_in_luma_samples;
    int pic_height_in_luma_samples;
    int conformance_window_flag;
    int conf_win_left_offset;
    int conf_win_right_offset;
    int conf_win_top_offset;
    int conf_win_bottom_offset;
    int bit_depth_luma;
    int bit_depth_chroma;
    int log2_max_pic_order_cnt_lsb;
    int MaxPicOrderCntLsb;
    int sps_sub_layer_ordering_info_present_flag;
    int sps_max_dec_pic_buffering[7];
    int sps_max_num_reorder_pics[7];
    int sps_max_latency_increase_plus1[7];
    int SpsMaxLatencyPictures[7];
    int log2_min_luma_coding_block_size;
    int log2_diff_max_min_luma_coding_block_size;
    int log2_min_transform_block_size;
    int log2_diff_max_min_transform_block_size;
    int max_transform_hierarchy_depth_inter;
    int max_transform_hierarchy_depth_intra;
    int scaling_list_enable_flag;
    int sps_scaling_list_data_present_flag;
    scaling_list_data scaling_list;
    int amp_enabled_flag;
    int sample_adaptive_offset_enabled_flag;
    int pcm_enabled_flag;
    int pcm_sample_bit_depth_luma;
    int pcm_sample_bit_depth_chroma;
    int log2_min_pcm_luma_coding_block_size;
    int log2_diff_max_min_pcm_luma_coding_block_size;
    int pcm_loop_filter_disable_flag;
    int num_short_term_ref_pic_sets;
    int long_term_ref_pics_present_flag;
    int num_long_term_ref_pics_sps;
    int lt_ref_pic_poc_lsb_sps[MAX_NUM_LT_REF_PICS_SPS];
    int used_by_curr_pic_lt_sps_flag[MAX_NUM_LT_REF_PICS_SPS];
    int sps_temporal_mvp_enabled_flag;
    int strong_intra_smoothing_enable_flag;
    int vui_parameters_present_flag;
    vui_parameters vui;
    int sps_extension_present_flag;
    int sps_range_extension_flag;
    int sps_multilayer_extension_flag;
    int sps_extension_6bits;
    struct range_extension range_extension;
    bool sps_read;
    std::vector<short_term_ref_pic_set> ref_pic_sets;

    de265_error read(error_queue* errqueue, bitreader* br);
    de265_error compute_derived_values();
    void set_default_scaling_lists(scaling_list_data* sl);
    de265_error read_scaling_list(bitreader* br, seq_parameter_set* sps, scaling_list_data* sl, bool b);
    bool read_short_term_ref_pic_set(error_queue* errqueue, seq_parameter_set* sps, bitreader* br, 
                                   short_term_ref_pic_set* st, int idx, 
                                   std::vector<short_term_ref_pic_set>& ref_pic_sets, bool b);
};

inline int get_bits(bitreader* br, int n) { return br->get_bits(n); }
inline int get_uvlc(bitreader* br) { return br->get_uvlc(); }

#define READ_VLC(var, type) { int tmp = get_uvlc(br); if (tmp == UVLC_ERROR) { return DE265_ERROR_CODED_PARAMETER_OUT_OF_RANGE; } var = tmp; }
#define READ_VLC_OFFSET(var, type, offset) { int tmp = get_uvlc(br); if (tmp == UVLC_ERROR) { return DE265_ERROR_CODED_PARAMETER_OUT_OF_RANGE; } var = tmp + offset; }