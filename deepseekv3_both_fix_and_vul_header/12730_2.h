#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define INT64 int64_t
#define LIM(a,b,c) ((a) < (b) ? (b) : ((a) > (c) ? (c) : (a)))

struct dng_color {
    int parsedfields;
    double colormatrix[4][3];
    double calibration[4][4];
    double forwardmatrix[4][3];
    int illuminant;
};

struct dng_levels {
    int parsedfields;
    float analogbalance[4];
    float baseline_exposure;
    unsigned dng_whitelevel[4];
    float asshotneutral[4];
    float dng_fblack;
    unsigned dng_black;
    unsigned dng_cblack[4106];
    float dng_fcblack[4106];
    unsigned default_crop[4];
    float LinearResponseLimit;
    int preview_colorspace;
    int64_t opcode2_offset;
    int64_t lineartable_offset;
    int lineartable_len;
};

struct tiff_ifd {
    struct dng_color dng_color[2];
    struct dng_levels dng_levels;
    int sample_format;
    int bps;
    int64_t opcode2_offset;
    int64_t lineartable_offset;
    int lineartable_len;
};

struct imgdata_params {
    int raw_processing_options;
};

struct imgdata_color {
    struct dng_color dng_color[2];
    struct dng_levels dng_levels;
    unsigned linear_max[4];
    float cmatrix[4][3];
};

struct imgdata {
    struct imgdata_params params;
    struct imgdata_color color;
};

class LibRaw {
public:
    void identify_process_dng_fields();
    void lossy_dng_load_raw();
};

#define FORCC for (c = 0; c < colors && c < 4; c++)
#define FORC4 for (c = 0; c < 4; c++)
#define FC(row, col) (filters >> ((((row) << 1 & 14) + ((col) & 1)) << 1) & 3)
#define LIBRAW_CBLACK_SIZE 4106
#define LIBRAW_WBI_D65 21
#define LIBRAW_WBI_Daylight 1
#define LIBRAW_WBI_D55 17
#define LIBRAW_WBI_D75 18
#define LIBRAW_WBI_D50 2
#define LIBRAW_WBI_Flash 3
#define LIBRAW_DNGFM_ILLUMINANT 1
#define LIBRAW_DNGFM_COLORMATRIX 2
#define LIBRAW_DNGFM_CALIBRATION 4
#define LIBRAW_DNGFM_ANALOGBALANCE 1
#define LIBRAW_DNGFM_CROPORIGIN 2
#define LIBRAW_DNGFM_CROPSIZE 4
#define LIBRAW_DNGFM_FORWARDMATRIX 8
#define LIBRAW_DNGFM_BASELINEEXPOSURE 8
#define LIBRAW_DNGFM_WHITE 16
#define LIBRAW_DNGFM_ASSHOTNEUTRAL 32
#define LIBRAW_DNGFM_BLACK 64
#define LIBRAW_DNGFM_PREVIEWCS 128
#define LIBRAW_DNGFM_OPCODE2 256
#define LIBRAW_DNGFM_LINTABLE 512
#define LIBRAW_DNGFM_LINEARRESPONSELIMIT 1024
#define LIBRAW_PROCESSING_DONT_CHECK_DNG_ILLUMINANT 1
#define LIBRAW_PROCESSING_USE_DNG_DEFAULT_CROP 2
#define LIBRAW_CAMERAMAKER_Fujifilm 1

extern int dng_version;
extern int data_offset;
extern int thumb_offset;
extern struct tiff_ifd *tiff_ifd;
extern unsigned tiff_nifds;
extern struct imgdata imgdata;
extern int colors;
extern unsigned filters;
extern char *normalized_model;
extern float cam_mul[4];
extern unsigned cblack[4106];
extern unsigned black;
extern unsigned maximum;
extern unsigned raw_width;
extern unsigned raw_height;
extern unsigned width;
extern unsigned height;
extern unsigned left_margin;
extern unsigned top_margin;
extern int tiff_samples;
extern int shot_select;
extern FILE *ifp;
extern int64_t meta_offset;
extern void (LibRaw::*load_raw)();
extern float cmatrix[4][3];

int find_ifd_by_offset(int offset);
void cam_xyz_coeff(float cmatrix[4][3], double cam_xyz[4][3]);
void linear_table(int len);
int makeIs(int maker);