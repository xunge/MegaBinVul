#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;
typedef double OPJ_FLOAT64;
typedef unsigned char OPJ_BYTE;
typedef int OPJ_BOOL;

typedef enum {
    OPJ_CLRSPC_UNKNOWN = -1,
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

typedef struct {
    OPJ_UINT32 cp_reduce;
    OPJ_UINT32 num_threads;
} opj_core_parameters;

typedef struct {
    OPJ_UINT32 prec;
    OPJ_PREC_MODE mode;
} opj_precision;

typedef struct opj_decompress_parameters {
    opj_core_parameters core;
    char *infile;
    char *outfile;
    int decod_format;
    int cod_format;
    int quiet;
    int numcomps;
    int *comps_indices;
    int nb_tile_to_decode;
    int tile_index;
    int DA_x0;
    int DA_y0;
    int DA_x1;
    int DA_y1;
    int split_pnm;
    int force_rgb;
    int upsample;
    opj_precision *precision;
    OPJ_UINT32 nb_precision;
    int num_threads;  // Added missing member
} opj_decompress_parameters;

typedef struct opj_image_component {
    OPJ_INT32 dx;
    OPJ_INT32 dy;
    OPJ_UINT32 prec;
} opj_image_component;

typedef struct opj_image {
    OPJ_CLRSPC color_space;
    OPJ_UINT32 numcomps;
    opj_image_component *comps;
    OPJ_BYTE *icc_profile_buf;
    OPJ_UINT32 icc_profile_len;
} opj_image_t;

typedef struct opj_stream {
    // Stream implementation details
} opj_stream_t;

typedef struct opj_codec {
    // Codec implementation details
} opj_codec_t;

typedef struct opj_codestream_index {
    // Codestream index implementation details
} opj_codestream_index_t;

typedef struct img_fol_t {
    int set_imgdir;
    char *imgdirpath;
} img_fol_t;

typedef struct dircnt_t {
    char **filename;
    char *filename_buf;
} dircnt_t;

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
#define OPJ_FALSE 0
#define OPJ_TRUE 1

void set_default_parameters(opj_decompress_parameters*);
int parse_cmdline_decoder(int, char**, opj_decompress_parameters*, img_fol_t*);
void destroy_parameters(opj_decompress_parameters*);
OPJ_INT32 get_num_images(char*);
int load_images(dircnt_t*, char*);
int get_next_file(OPJ_INT32, dircnt_t*, img_fol_t*, opj_decompress_parameters*);
opj_stream_t* opj_stream_create_default_file_stream(const char*, OPJ_BOOL);
opj_codec_t* opj_create_decompress(OPJ_UINT32);
void opj_set_info_handler(opj_codec_t*, void (*)(const char*, void*), void*);
void opj_set_warning_handler(opj_codec_t*, void (*)(const char*, void*), void*);
void opj_set_error_handler(opj_codec_t*, void (*)(const char*, void*), void*);
OPJ_FLOAT64 opj_clock(void);
OPJ_BOOL opj_setup_decoder(opj_codec_t*, opj_core_parameters*);
OPJ_BOOL opj_codec_set_threads(opj_codec_t*, int);
OPJ_BOOL opj_read_header(opj_stream_t*, opj_codec_t*, opj_image_t**);
OPJ_BOOL opj_set_decoded_components(opj_codec_t*, int, int*, OPJ_BOOL);
OPJ_BOOL opj_set_decoded_resolution_factor(opj_codec_t*, OPJ_UINT32);
OPJ_BOOL opj_set_decode_area(opj_codec_t*, opj_image_t*, OPJ_INT32, OPJ_INT32, OPJ_INT32, OPJ_INT32);
OPJ_BOOL opj_decode(opj_codec_t*, opj_stream_t*, opj_image_t*);
OPJ_BOOL opj_end_decompress(opj_codec_t*, opj_stream_t*);
OPJ_BOOL opj_get_decoded_tile(opj_codec_t*, opj_stream_t*, opj_image_t*, int);
void opj_stream_destroy(opj_stream_t*);
void opj_destroy_codec(opj_codec_t*);
void opj_image_destroy(opj_image_t*);
void opj_destroy_cstr_index(opj_codestream_index_t**);
void color_sycc_to_rgb(opj_image_t*);
void color_cmyk_to_rgb(opj_image_t*);
void color_esycc_to_rgb(opj_image_t*);
void color_apply_icc_profile(opj_image_t*);
void color_cielab_to_rgb(opj_image_t*);
void clip_component(opj_image_component*, OPJ_UINT32);
void scale_component(opj_image_component*, OPJ_UINT32);
opj_image_t* upsample_image_components(opj_image_t*);
opj_image_t* convert_gray_to_rgb(opj_image_t*);
int imagetopnm(opj_image_t*, const char*, int);
int imagetopgx(opj_image_t*, const char*);
int imagetobmp(opj_image_t*, const char*);
int imagetotif(opj_image_t*, const char*);
int imagetoraw(opj_image_t*, const char*);
int imagetorawl(opj_image_t*, const char*);
int imagetotga(opj_image_t*, const char*);
int imagetopng(opj_image_t*, const char*);
void quiet_callback(const char*, void*);
void info_callback(const char*, void*);
void warning_callback(const char*, void*);
void error_callback(const char*, void*);