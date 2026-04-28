#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int OPJ_INT32;
typedef unsigned int OPJ_UINT32;
typedef double OPJ_FLOAT64;

#define OPJ_PATH_LEN 4096
#define OPJ_CODEC_J2K 0
#define OPJ_CODEC_JP2 1
#define OPJ_CODEC_JPT 2

#define J2K_CFMT 0
#define JP2_CFMT 1
#define JPT_CFMT 2

#define PXM_DFMT 0
#define PGX_DFMT 1
#define BMP_DFMT 2
#define TIF_DFMT 3
#define RAW_DFMT 4
#define RAWL_DFMT 5
#define TGA_DFMT 6
#define PNG_DFMT 7

#define OPJ_CLRSPC_SRGB 0
#define OPJ_CLRSPC_GRAY 1
#define OPJ_CLRSPC_SYCC 2
#define OPJ_CLRSPC_CMYK 3
#define OPJ_CLRSPC_EYCC 4

#define OPJ_PREC_MODE_CLIP 0
#define OPJ_PREC_MODE_SCALE 1

#define OPJ_FALSE 0

typedef struct {
    int dx;
    int dy;
    int prec;
} opj_image_comp_t;

typedef struct {
    int numcomps;
    opj_image_comp_t *comps;
    OPJ_UINT32 color_space;
    unsigned char *icc_profile_buf;
    OPJ_UINT32 icc_profile_len;
} opj_image_t;

typedef struct {
    OPJ_UINT32 cp_reduce;
} opj_core_parameters;

typedef struct {
    opj_core_parameters core;
    char *infile;
    char *outfile;
    int quiet;
    int decod_format;
    int cod_format;
    int numcomps;
    int *comps_indices;
    int nb_precision;
    struct {
        int prec;
        int mode;
    } *precision;
    int upsample;
    int force_rgb;
    int split_pnm;
    OPJ_UINT32 DA_x0;
    OPJ_UINT32 DA_y0;
    OPJ_UINT32 DA_x1;
    OPJ_UINT32 DA_y1;
    int nb_tile_to_decode;
    int tile_index;
    int num_threads;
} opj_decompress_parameters;

typedef struct {
    char **filename;
    char *filename_buf;
} dircnt_t;

typedef struct {
    char *imgdirpath;
    int set_imgdir;
} img_fol_t;

typedef void *opj_stream_t;
typedef void *opj_codec_t;
typedef void *opj_codestream_index_t;

void set_default_parameters(opj_decompress_parameters *parameters);
int parse_cmdline_decoder(int argc, char **argv, opj_decompress_parameters *parameters, img_fol_t *img_fol);
int get_num_images(const char *imgdirpath);
void destroy_parameters(opj_decompress_parameters *parameters);
int load_images(dircnt_t *dirptr, const char *imgdirpath);
int get_next_file(int imageno, dircnt_t *dirptr, img_fol_t *img_fol, opj_decompress_parameters *parameters);
opj_stream_t* opj_stream_create_default_file_stream(const char *fname, int p_is_read);
opj_codec_t* opj_create_decompress(int format);
void opj_stream_destroy(opj_stream_t *stream);
void opj_set_info_handler(opj_codec_t *codec, void (*callback)(const char *msg, void *client_data), void *client_data);
void opj_set_warning_handler(opj_codec_t *codec, void (*callback)(const char *msg, void *client_data), void *client_data);
void opj_set_error_handler(opj_codec_t *codec, void (*callback)(const char *msg, void *client_data), void *client_data);
double opj_clock(void);
int opj_setup_decoder(opj_codec_t *codec, opj_core_parameters *parameters);
void opj_destroy_codec(opj_codec_t *codec);
int opj_codec_set_threads(opj_codec_t *codec, int num_threads);
int opj_read_header(opj_stream_t *stream, opj_codec_t *codec, opj_image_t **image);
void opj_image_destroy(opj_image_t *image);
int opj_set_decoded_components(opj_codec_t *codec, int numcomps, int *comps_indices, int apply_color_transforms);
int opj_set_decoded_resolution_factor(opj_codec_t *codec, OPJ_UINT32 factor);
int opj_set_decode_area(opj_codec_t *codec, opj_image_t *image, OPJ_INT32 DA_x0, OPJ_INT32 DA_y0, OPJ_INT32 DA_x1, OPJ_INT32 DA_y1);
int opj_decode(opj_codec_t *codec, opj_stream_t *stream, opj_image_t *image);
int opj_end_decompress(opj_codec_t *codec, opj_stream_t *stream);
int opj_get_decoded_tile(opj_codec_t *codec, opj_stream_t *stream, opj_image_t *image, int tile_index);
void color_sycc_to_rgb(opj_image_t *image);
void color_cmyk_to_rgb(opj_image_t *image);
void color_esycc_to_rgb(opj_image_t *image);
void clip_component(opj_image_comp_t *comp, int prec);
void scale_component(opj_image_comp_t *comp, int prec);
opj_image_t* upsample_image_components(opj_image_t *image);
opj_image_t* convert_gray_to_rgb(opj_image_t *image);
int imagetopnm(opj_image_t *image, const char *outfile, int split_pnm);
int imagetopgx(opj_image_t *image, const char *outfile);
int imagetobmp(opj_image_t *image, const char *outfile);
int imagetoraw(opj_image_t *image, const char *outfile);
int imagetorawl(opj_image_t *image, const char *outfile);
int imagetotga(opj_image_t *image, const char *outfile);
void opj_destroy_cstr_index(opj_codestream_index_t **index);

void quiet_callback(const char *msg, void *client_data);
void info_callback(const char *msg, void *client_data);
void warning_callback(const char *msg, void *client_data);
void error_callback(const char *msg, void *client_data);