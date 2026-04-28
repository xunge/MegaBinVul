#include <stdlib.h>
#include <string.h>

typedef double iw_tmpsample;
typedef float iw_float32;

#define IW_CHANNELTYPE_NONALPHA 0
#define IW_CHANNELTYPE_ALPHA 1
#define IW_DITHERFAMILY_NONE 0
#define IW_DITHERFAMILY_RANDOM 1
#define IW_DITHERFAMILY_ERRDIFF 2
#define IW_DITHERSUBTYPE_SAMEPATTERN 0
#define IW_DIMENSION_H 0
#define IW_DIMENSION_V 1
#define IW_DITHER_MAXROWS 4
#define IW_BKGD_STRATEGY_LATE 0
#define IW_SAMPLETYPE_FLOATINGPOINT 0

struct iw_csdescr;

struct iw_img2 {
    int width;
    int sampletype;
};

struct iw_channelinfo_out {
    int channeltype;
    int ditherfamily;
    int dithersubtype;
    int color_count;
    int use_nearest_color_table;
    double bkgd1_color_lin;
    double bkgd2_color_lin;
};

struct iw_channelinfo_intermed {
    int corresponding_output_channel;
    int channeltype;
    int need_unassoc_alpha_processing;
};

struct iw_resize_settings {
    void *rrctx;
    int disable_rrctx_cache;
};

struct iw_context {
    int intermed_canvas_width;
    int intermed_canvas_height;
    struct iw_img2 img2;
    struct iw_channelinfo_intermed *intermed_ci;
    struct iw_channelinfo_out *img2_ci;
    iw_float32 *intermediate32;
    iw_float32 *intermediate_alpha32;
    iw_float32 *final_alpha32;
    int nearest_color_table;
    void *prng;
    unsigned int random_seed;
    double dither_errors[IW_DITHER_MAXROWS][1];
    int bkgd_checkerboard;
    int bkgd_check_origin[2];
    int bkgd_check_size;
    double bkgd1alpha;
    double bkgd2alpha;
    int apply_bkgd;
    int apply_bkgd_strategy;
    int intclamp;
    struct iw_resize_settings resize_settings[2];
};

void iw_zeromem(void *ptr, size_t size);
void* iw_malloc(struct iw_context *ctx, size_t size);
void iw_free(struct iw_context *ctx, void *ptr);
int iw_bkgd_has_transparency(struct iw_context *ctx);
void iwpvt_prng_set_random_seed(void *prng, unsigned int seed);
void* iwpvt_resize_rows_init(struct iw_context *ctx, struct iw_resize_settings *rs, int channeltype, int num_in_pix, int num_out_pix);
void iwpvt_resize_row_main(void *rrctx, iw_tmpsample *in_pix, iw_tmpsample *out_pix);
void iwpvt_resize_rows_done(void *rrctx);
void clamp_output_samples(struct iw_context *ctx, iw_tmpsample *out_pix, int num_out_pix);
void put_sample_convert_from_linear_flt(struct iw_context *ctx, iw_tmpsample tmpsamp, int i, int j, int output_channel, const struct iw_csdescr *out_csdescr);
void put_sample_convert_from_linear(struct iw_context *ctx, iw_tmpsample tmpsamp, int i, int j, int output_channel, const struct iw_csdescr *out_csdescr);