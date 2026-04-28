#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define VPX_BITS_8 8
#define LEVEL_MAX 0
#define PROFILE_1 1
#define MAX_SEGMENTS 8
#define MIN_GF_INTERVAL 4
#define MAX_GF_INTERVAL 16
#define FIXED_GF_INTERVAL 8
#define VPX_Q 0
#define CYCLIC_REFRESH_AQ 1
#define VPX_CODEC_MEM_ERROR 1

struct vpx_internal_error_info {
    int error_code;
    const char *detail;
};

typedef struct VP9_COMMON VP9_COMMON;
typedef struct RATE_CONTROL RATE_CONTROL;
typedef struct VP9EncoderConfig VP9EncoderConfig;
typedef struct VP9_COMP VP9_COMP;

struct VP9_COMMON {
    int profile;
    int bit_depth;
    int color_space;
    int color_range;
    int width;
    int height;
    int render_width;
    int render_height;
    int refresh_frame_context;
    int reset_frame_context;
    int current_video_frame;
    int interp_filter;
    int mi_stride;
    int mi_rows;
    int mi_cols;
    int mi_alloc_size;
    struct {
        int mi_stride;
        int mi_rows;
    } seg;
    struct vpx_internal_error_info error;
};

struct RATE_CONTROL {
    int baseline_gf_interval;
    int worst_quality;
    int best_quality;
    int is_src_frame_alt_ref;
    int rc_1_frame;
    int rc_2_frame;
};

struct VP9EncoderConfig {
    int width;
    int height;
    int render_width;
    int render_height;
    int profile;
    int bit_depth;
    int color_space;
    int color_range;
    int target_level;
    int pass;
    int rc_mode;
    int worst_allowed_q;
    int best_allowed_q;
    int encode_breakout;
    int aq_mode;
    int target_bandwidth;
};

struct VP9_COMP {
    VP9_COMMON common;
    RATE_CONTROL rc;
    VP9EncoderConfig oxcf;
    int target_level;
    int keep_level_stats;
    int level_constraint;
    int framerate;
    int external_resize;
    int initial_width;
    int initial_height;
    int encode_breakout;
    int segment_encode_breakout[MAX_SEGMENTS];
    int *consec_zero_mv;
    int *skin_map;
    int refresh_golden_frame;
    int refresh_last_frame;
    void *alt_ref_source;
    int ext_refresh_frame_flags_pending;
    int ext_refresh_frame_context_pending;
    struct {
        int number_temporal_layers;
        int number_spatial_layers;
    } svc;
    struct {
        int default_interp_filter;
    } sf;
    struct {
        struct {
            struct {
                int bd;
            } e_mbd;
        } mb;
    } td;
    void *mbmi_ext_base;
};

void vp9_init_quantizer(VP9_COMP *cpi);
void set_level_constraint(int *constraint, int index);
int get_level_index(int level);
void vp9_reset_segment_features(VP9_COMMON *cm);
void vp9_set_high_precision_mv(VP9_COMP *cpi, int flag);
void vp9_set_rc_buffer_sizes(VP9_COMP *cpi);
void vp9_new_framerate(VP9_COMP *cpi, int framerate);
void vp9_set_mb_mi(VP9_COMMON *cm, int width, int height);
int calc_mi_size(int mi_rows);
void vp9_free_context_buffers(VP9_COMMON *cm);
void alloc_compressor_data(VP9_COMP *cpi);
void realloc_segmentation_maps(VP9_COMP *cpi);
int vp9_alloc_loop_filter(VP9_COMMON *cm);
void update_frame_size(VP9_COMP *cpi);
void vp9_cyclic_refresh_reset_resize(VP9_COMP *cpi);
void vp9_update_layer_context_change_config(VP9_COMP *cpi, int bandwidth);
void vp9_check_reset_rc_flag(VP9_COMP *cpi);
void set_tile_limits(VP9_COMP *cpi);
void vp9_set_row_mt(VP9_COMP *cpi);
void free_copy_partition_data(VP9_COMP *cpi);
void alloc_copy_partition_data(VP9_COMP *cpi);
void highbd_set_var_fns(VP9_COMP *cpi);
void *vpx_calloc(size_t nmemb, size_t size);
void vpx_free(void *memblk);
void vp9_free_pc_tree(void *td);
void vpx_internal_error(struct vpx_internal_error_info *info, int error, const char *fmt);