#include <stdlib.h>

#define LIBRAW_PROGRESS_LOAD_RAW 0
#define LIBRAW_PROGRESS_REMOVE_ZEROES 1
#define LIBRAW_PROGRESS_BAD_PIXELS 2
#define LIBRAW_PROGRESS_DARK_FRAME 3
#define LIBRAW_PROGRESS_FOVEON_INTERPOLATE 4
#define LIBRAW_PROGRESS_SCALE_COLORS 5
#define LIBRAW_PROGRESS_PRE_INTERPOLATE 6
#define LIBRAW_PROGRESS_INTERPOLATE 7
#define LIBRAW_PROGRESS_MIX_GREEN 8
#define LIBRAW_PROGRESS_MEDIAN_FILTER 9
#define LIBRAW_PROGRESS_HIGHLIGHTS 10
#define LIBRAW_PROGRESS_FUJI_ROTATE 11
#define LIBRAW_PROGRESS_APPLY_PROFILE 12
#define LIBRAW_PROGRESS_CONVERT_RGB 13
#define LIBRAW_PROGRESS_STRETCH 14
#define LIBRAW_HISTOGRAM_SIZE 0x2000
#define LIBRAW_DECODER_LEGACY 0x1
#define NO_LCMS

struct libraw_decoder_info_t {
    unsigned int decoder_flags;
};

struct img_data {
    short (*image)[4];
};

struct libraw_internal_data_t {
    struct {
        int (*histogram)[LIBRAW_HISTOGRAM_SIZE];
    } output_data;
};

struct libraw_imgother_t {
    int fuji_width;
    int zero_is_bad;
    int mix_green;
    float maximum;
};

struct libraw_iparams_t {
    int is_foveon;
    int colors;
    int filters;
    int height;
    int width;
};

struct libraw_output_params_t {
    int cropbox[4];
    const char* bad_pixels;
    const char* dark_frame;
    int wf_debanding;
    int half_size;
    int four_color_rgb;
    int user_qual;
    int user_sat;
    int green_matching;
    int dcb_iterations;
    int dcb_enhance_fl;
    int fbdd_noiserd;
    int eeci_refine;
    int es_med_passes;
    int cfa_green;
    float green_thresh;
    int exp_correc;
    float exp_shift;
    float exp_preser;
    int ca_correc;
    float cablue;
    float cared;
    int cfaline;
    float linenoise;
    int cfa_clean;
    float lclean;
    float cclean;
    int highlight;
    int use_fuji_rotate;
    int med_passes;
    const char* camera_profile;
    const char* output_profile;
};

struct libraw_colordata_t {
    float data_maximum;
    float maximum;
};

struct libraw_data_t {
    int height;
    int width;
};

class LibRaw_exceptions {};

class LibRaw {
public:
    struct libraw_iparams_t P1;
    struct libraw_imgother_t IO;
    struct libraw_output_params_t O;
    struct libraw_colordata_t C;
    struct libraw_data_t S;
    struct img_data imgdata;
    struct libraw_internal_data_t libraw_internal_data;
    
    void (LibRaw::*load_raw)();
    
    int dcraw_process(void);
    void CHECK_ORDER_LOW(int);
    void SET_PROC_FLAG(int);
    void get_decoder_info(libraw_decoder_info_t*);
    void raw2image_ex(int);
    void remove_zeroes();
    void bad_pixels(const char*);
    void subtract(const char*);
    void wf_remove_banding();
    void adjust_bl();
    void subtract_black();
    void adjust_maximum();
    void foveon_interpolate();
    void green_matching();
    void scale_colors();
    void pre_interpolate();
    void fbdd(int);
    void lin_interpolate();
    void vng_interpolate();
    void ppg_interpolate();
    void ahd_interpolate();
    void dcb(int, int);
    void ahd_interpolate_mod();
    void afd_interpolate_pl(int, int);
    void vcd_interpolate(int);
    void lmmse_interpolate(int);
    void amaze_demosaic_RT();
    void dht_interpolate();
    void aahd_interpolate();
    void refinement();
    void median_filter_new();
    void es_median_filter();
    void median_filter();
    void blend_highlights();
    void recover_highlights();
    void fuji_rotate();
    void apply_profile(const char*, const char*);
    void convert_to_rgb();
    void stretch();
    void green_equilibrate(float);
    void exp_bef(float, float);
    void CA_correct_RT(float, float);
    void cfa_linedn(float);
    void cfa_impulse_gauss(float, float);
    void merror(void*, const char*);
    void foveon_dp_load_raw();
    void EXCEPTION_HANDLER(LibRaw_exceptions&);
};