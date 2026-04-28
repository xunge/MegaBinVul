#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define VPX_BITS_8 8
#define LEVEL_MAX 0
#define PROFILE_1 1
#define MIN_GF_INTERVAL 4
#define MAX_GF_INTERVAL 16
#define FIXED_GF_INTERVAL 8
#define MAX_SEGMENTS 8
#define CONFIG_VP9_HIGHBITDEPTH 1
#define VPX_CODEC_MEM_ERROR 1
#define VPX_Q 0
#define CYCLIC_REFRESH_AQ 1

struct vpx_internal_error_info {
    int error_code;
    const char *detail;
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

struct SEGMENTATION {
    int seg;
};

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
    int mi_stride;
    int mi_rows;
    int mi_cols;
    int mi_alloc_size;
    int interp_filter;
    struct SEGMENTATION seg;
    struct vpx_internal_error_info error;
};

struct RATE_CONTROL {
    int baseline_gf_interval;
    int worst_quality;
    int best_quality;
    int rc_1_frame;
    int rc_2_frame;
    int is_src_frame_alt_ref;
};

struct VP9_COMP {
    struct VP9_COMMON common;
    struct RATE_CONTROL rc;
    struct VP9EncoderConfig oxcf;
    int target_level;
    int keep_level_stats;
    int level_constraint;
    int external_resize;
    int initial_width;
    int initial_height;
    int framerate;
    int encode_breakout;
    int segment_encode_breakout[MAX_SEGMENTS];
    int *consec_zero_mv;
    int *skin_map;
    int *mbmi_ext_base;
    struct {
        struct {
            struct {
                int bd;
            } e_mbd;
        } mb;
    } td;
    struct {
        int number_temporal_layers;
        int number_spatial_layers;
    } svc;
    void *alt_ref_source;
    int ext_refresh_frame_flags_pending;
    int ext_refresh_frame_context_pending;
    struct {
        int default_interp_filter;
    } sf;
    int refresh_golden_frame;
    int refresh_last_frame;
};

void vpx_internal_error(struct vpx_internal_error_info *info, int error, const char *message);
void *vpx_calloc(size_t num, size_t size);
void vpx_free(void *memblk);
void vp9_init_quantizer(struct VP9_COMP *cpi);
void vp9_reset_segment_features(struct VP9_COMMON *cm);
void vp9_set_high_precision_mv(struct VP9_COMP *cpi, int flag);
void vp9_set_rc_buffer_sizes(struct VP9_COMP *cpi);
void vp9_new_framerate(struct VP9_COMP *cpi, int framerate);
void vp9_free_context_buffers(struct VP9_COMMON *cm);
void alloc_compressor_data(struct VP9_COMP *cpi);
void realloc_segmentation_maps(struct VP9_COMP *cpi);
int vp9_alloc_loop_filter(struct VP9_COMMON *cm);
void update_frame_size(struct VP9_COMP *cpi);
void vp9_cyclic_refresh_reset_resize(struct VP9_COMP *cpi);
void free_copy_partition_data(struct VP9_COMP *cpi);
void alloc_copy_partition_data(struct VP9_COMP *cpi);
void vp9_update_layer_context_change_config(struct VP9_COMP *cpi, int bandwidth);
void vp9_check_reset_rc_flag(struct VP9_COMP *cpi);
void set_tile_limits(struct VP9_COMP *cpi);
void vp9_set_row_mt(struct VP9_COMP *cpi);
void vp9_free_pc_tree(struct VP9_COMP *cpi);
void highbd_set_var_fns(struct VP9_COMP *cpi);
void set_level_constraint(int *constraint, int level);
int get_level_index(int level);
int calc_mi_size(int rows);
void vp9_set_mb_mi(struct VP9_COMMON *cm, int width, int height);

#define CHECK_MEM_ERROR(cm, ptr, alloc) \
    do { \
        if (!(ptr)) \
            vpx_internal_error(&(cm)->error, VPX_CODEC_MEM_ERROR, "Failed to allocate memory"); \
    } while (0)

typedef struct VP9_COMP VP9_COMP;
typedef struct VP9_COMMON VP9_COMMON;
typedef struct RATE_CONTROL RATE_CONTROL;
typedef struct VP9EncoderConfig VP9EncoderConfig;