#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int OPJ_INT32;
typedef unsigned int OPJ_UINT32;
typedef double OPJ_FLOAT64;
typedef int OPJ_BOOL;
#define OPJ_FALSE 0
#define OPJ_TRUE 1

typedef enum {
    OPJ_CLRSPC_UNKNOWN = -1,
    OPJ_CLRSPC_UNSPECIFIED = 0,
    OPJ_CLRSPC_SRGB = 1,
    OPJ_CLRSPC_GRAY = 2,
    OPJ_CLRSPC_SYCC = 3,
    OPJ_CLRSPC_EYCC = 4,
    OPJ_CLRSPC_CMYK = 5
} OPJ_CLRSPC;

typedef enum {
    OPJ_PREC_MODE_CLIP = 0,
    OPJ_PREC_MODE_SCALE = 1
} OPJ_PREC_MODE;

typedef enum {
    J2K_CFMT = 0,
    JP2_CFMT = 1,
    JPT_CFMT = 2
} OPJ_CODEC_FORMAT;

typedef enum {
    PXM_DFMT = 0,
    PGX_DFMT = 1,
    BMP_DFMT = 2,
    TIF_DFMT = 3,
    RAW_DFMT = 4,
    RAWL_DFMT = 5,
    TGA_DFMT = 6,
    PNG_DFMT = 7
} OPJ_DFMT;

#define OPJ_PATH_LEN 4096
#define OPJ_CODEC_J2K 0
#define OPJ_CODEC_JP2 1
#define OPJ_CODEC_JPT 2

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
    int nb_tile_to_decode;
    int tile_index;
    OPJ_UINT32 DA_x0;
    OPJ_UINT32 DA_y0;
    OPJ_UINT32 DA_x1;
    OPJ_UINT32 DA_y1;
    int force_rgb;
    int upsample;
    int split_pnm;
    struct {
        OPJ_UINT32 prec;
        OPJ_PREC_MODE mode;
    } *precision;
    int nb_precision;
    int num_threads;
} opj_decompress_parameters;

typedef struct {
    char *imgdirpath;
    int set_imgdir;
} img_fol_t;

typedef struct {
    char **filename;
    char *filename_buf;
} dircnt_t;

typedef struct opj_image_comp {
    OPJ_INT32 dx;
    OPJ_INT32 dy;
    OPJ_UINT32 prec;
} opj_image_comp_t;

typedef struct opj_image {
    OPJ_UINT32 numcomps;
    opj_image_comp_t *comps;
    OPJ_CLRSPC color_space;
    void *icc_profile_buf;
    OPJ_UINT32 icc_profile_len;
} opj_image_t;

typedef void opj_stream_t;
typedef void opj_codec_t;
typedef void opj_codestream_index_t;
typedef opj_decompress_parameters opj_dparameters_t;

void set_default_parameters(opj_decompress_parameters *parameters);
int parse_cmdline_decoder(int argc, char **argv, opj_decompress_parameters *parameters, img_fol_t *img_fol);
void destroy_parameters(opj_decompress_parameters *parameters);
int get_num_images(char *imgdirpath);
int load_images(dircnt_t *dirptr, char *imgdirpath);
int get_next_file(OPJ_INT32 imageno, dircnt_t *dirptr, img_fol_t *img_fol, opj_decompress_parameters *parameters);
opj_stream_t* opj_stream_create_default_file_stream(const char *fname, OPJ_BOOL p_is_read);
opj_codec_t* opj_create_decompress(OPJ_CODEC_FORMAT format);
void opj_set_info_handler(opj_codec_t *codec, void (*callback)(const char *msg, void *client_data), void *client_data);
void opj_set_warning_handler(opj_codec_t *codec, void (*callback)(const char *msg, void *client_data), void *client_data);
void opj_set_error_handler(opj_codec_t *codec, void (*callback)(const char *msg, void *client_data), void *client_data);
OPJ_BOOL opj_setup_decoder(opj_codec_t *codec, opj_dparameters_t *parameters);
OPJ_BOOL opj_codec_set_threads(opj_codec_t *codec, int num_threads);
OPJ_BOOL opj_read_header(opj_stream_t *stream, opj_codec_t *codec, opj_image_t **image);
OPJ_BOOL opj_set_decoded_components(opj_codec_t *codec, int numcomps, const OPJ_UINT32 *comps_indices, OPJ_BOOL apply_color_transforms);
OPJ_BOOL opj_set_decoded_resolution_factor(opj_codec_t *codec, OPJ_UINT32 res_factor);
OPJ_BOOL opj_set_decode_area(opj_codec_t *codec, opj_image_t *image, OPJ_INT32 DA_x0, OPJ_INT32 DA_y0, OPJ_INT32 DA_x1, OPJ_INT32 DA_y1);
OPJ_BOOL opj_decode(opj_codec_t *codec, opj_stream_t *stream, opj_image_t *image);
OPJ_BOOL opj_end_decompress(opj_codec_t *codec, opj_stream_t *stream);
OPJ_BOOL opj_get_decoded_tile(opj_codec_t *codec, opj_stream_t *stream, opj_image_t *image, OPJ_UINT32 tile_index);
void opj_stream_destroy(opj_stream_t *stream);
void opj_destroy_codec(opj_codec_t *codec);
void opj_image_destroy(opj_image_t *image);
void opj_destroy_cstr_index(opj_codestream_index_t **p_cstr_index);
void color_sycc_to_rgb(opj_image_t *image);
void color_cmyk_to_rgb(opj_image_t *image);
void color_esycc_to_rgb(opj_image_t *image);
void color_apply_icc_profile(opj_image_t *image);
void color_cielab_to_rgb(opj_image_t *image);
void clip_component(opj_image_comp_t *comp, OPJ_UINT32 prec);
void scale_component(opj_image_comp_t *comp, OPJ_UINT32 prec);
opj_image_t* upsample_image_components(opj_image_t *image);
opj_image_t* convert_gray_to_rgb(opj_image_t *image);
int imagetopnm(opj_image_t *image, const char *outfile, int split_pnm);
int imagetopgx(opj_image_t *image, const char *outfile);
int imagetobmp(opj_image_t *image, const char *outfile);
int imagetotif(opj_image_t *image, const char *outfile);
int imagetoraw(opj_image_t *image, const char *outfile);
int imagetorawl(opj_image_t *image, const char *outfile);
int imagetotga(opj_image_t *image, const char *outfile);
int imagetopng(opj_image_t *image, const char *outfile);
OPJ_FLOAT64 opj_clock(void);
void quiet_callback(const char *msg, void *client_data);
void info_callback(const char *msg, void *client_data);
void warning_callback(const char *msg, void *client_data);
void error_callback(const char *msg, void *client_data);

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1