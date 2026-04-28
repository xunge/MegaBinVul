#include <stdint.h>
#include <assert.h>
#include <stddef.h>

#define DEFAULT_GF_INTERVAL 16
#define MAXQ 255
#define MAX_MB_SEGMENTS 4
#define MAX_LAG_BUFFERS 25
#define CONFIG_REALTIME_ONLY 0
#define CONFIG_ONTHEFLY_BITPACKING 0
#define CONFIG_TEMPORAL_DENOISING 0

typedef enum {
    MODE_REALTIME,
    MODE_GOODQUALITY,
    MODE_BESTQUALITY,
    MODE_FIRSTPASS,
    MODE_SECONDPASS,
    MODE_SECONDPASS_BEST
} MODE;

typedef enum {
    USAGE_STREAM_FROM_SERVER,
    USAGE_LOCAL_FILE_PLAYBACK
} USAGE;

typedef enum {
    VP8E_NORMAL
} VP8_SCALING;

typedef enum {
    TOKEN_PARTITION_0,
    TOKEN_PARTITION_1,
    TOKEN_PARTITION_2,
    TOKEN_PARTITION_3
} TOKEN_PARTITION;

typedef struct {
    int Width;
    int Height;
    int Version;
    int multi_threaded;
    MODE Mode;
    int cpu_used;
    int worst_allowed_q;
    int best_allowed_q;
    int cq_level;
    int fixed_q;
    int alt_q;
    int key_q;
    int gold_q;
    int alt_freq;
    int error_resilient_mode;
    int end_usage;
    int token_partitions;
    int Sharpness;
    int lag_in_frames;
    int allow_lag;
    int noise_sensitivity;
    int encode_breakout;
    int starting_buffer_level;
    int optimal_buffer_level;
    int maximum_buffer_size;
    int starting_buffer_level_in_ms;
    int optimal_buffer_level_in_ms;
    int maximum_buffer_size_in_ms;
    int target_bandwidth;
    int allow_df;
    unsigned int number_of_layers;
} VP8_CONFIG;

typedef struct {
    int y_width;
    int y_height;
    void* buffer_alloc;
} YV12_BUFFER_CONFIG;

typedef struct {
    int version;
    int Width;
    int Height;
    int horiz_scale;
    int vert_scale;
    int sharpness_level;
    int multi_token_partition;
    YV12_BUFFER_CONFIG yv12_fb[2];
    int lst_fb_idx;
    void* error;
} VP8_COMMON;

typedef struct {
    VP8_COMMON common;
    VP8_CONFIG oxcf;
    int initial_width;
    int initial_height;
    int pass;
    int compressor_speed;
    int auto_worst_q;
    int worst_quality;
    int best_quality;
    int active_worst_quality;
    int active_best_quality;
    int cq_target_quality;
    int buffered_mode;
    int drop_frames_allowed;
    int target_bandwidth;
    int temporal_layer_id;
    int temporal_pattern_counter;
    int Speed;
    int force_next_frame_intra;
    int last_q[2];
    int bits_off_target;
    int buffer_level;
    int gf_interval_onepass_cbr;
    int baseline_gf_interval;
    int use_roi_static_threshold;
    int segment_encode_breakout[MAX_MB_SEGMENTS];
    double framerate;
    void* alt_ref_source;
    int is_src_frame_alt_ref;
    int ext_refresh_frame_flags_pending;
#if CONFIG_TEMPORAL_DENOISING
    struct {
        YV12_BUFFER_CONFIG yv12_mc_running_avg;
        int mb_rows;
        int mb_cols;
    } denoiser;
#endif
} VP8_COMP;

extern const int q_trans[];
extern void vp8_setup_version(VP8_COMMON* cm);
extern void setup_features(VP8_COMP* cpi);
extern void vp8_new_framerate(VP8_COMP* cpi, double framerate);
extern void vp8_reset_temporal_layer_change(VP8_COMP* cpi, VP8_CONFIG* oxcf, unsigned int prev_number_of_layers);
extern void dealloc_raw_frame_buffers(VP8_COMP* cpi);
extern void alloc_raw_frame_buffers(VP8_COMP* cpi);
extern void vp8_alloc_compressor_data(VP8_COMP* cpi);
extern int vp8_denoiser_allocate(void* denoiser, int width, int height, int mb_rows, int mb_cols, int noise_sensitivity);
extern void vpx_internal_error(void* error, int code, const char* msg);
extern void Scale2Ratio(int scale, int* hr, int* hs);
extern int rescale(int value, int target_bandwidth, int scale);