#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int OPJ_INT32;
typedef unsigned int OPJ_UINT32;
typedef double OPJ_FLOAT64;

#define OPJ_PATH_LEN 4096
#define OPJ_CODEC_J2K 0
#define OPJ_CODEC_JP2 1
#define OPJ_CODEC_JPT 2
#define OPJ_CLRSPC_SYCC 1
#define OPJ_CLRSPC_GRAY 2
#define OPJ_CLRSPC_SRGB 3
#define OPJ_CLRSPC_CMYK 4
#define OPJ_CLRSPC_EYCC 5
#define OPJ_PREC_MODE_CLIP 0
#define OPJ_PREC_MODE_SCALE 1
#define OPJ_FALSE 0

typedef enum {
    J2K_CFMT = 0,
    JP2_CFMT = 1,
    JPT_CFMT = 2
} COD_FORMAT;

typedef enum {
    PXM_DFMT = 0,
    PGX_DFMT = 1,
    BMP_DFMT = 2,
    TIF_DFMT = 3,
    RAW_DFMT = 4,
    RAWL_DFMT = 5,
    TGA_DFMT = 6,
    PNG_DFMT = 7
} DECOD_FORMAT;

typedef struct {
    OPJ_UINT32 cp_reduce;
} opj_core_parameters;

typedef struct {
    opj_core_parameters core;
    char* infile;
    char* outfile;
    COD_FORMAT decod_format;
    DECOD_FORMAT cod_format;
    int quiet;
    OPJ_UINT32 numcomps;
    OPJ_UINT32* comps_indices;
    OPJ_UINT32 DA_x0;
    OPJ_UINT32 DA_y0;
    OPJ_UINT32 DA_x1;
    OPJ_UINT32 DA_y1;
    OPJ_UINT32 nb_tile_to_decode;
    OPJ_UINT32 tile_index;
    int force_rgb;
    int upsample;
    int split_pnm;
    OPJ_UINT32 nb_precision;
    struct {
        OPJ_UINT32 prec;
        OPJ_UINT32 mode;
    } *precision;
    int num_threads;
} opj_decompress_parameters;

typedef struct {
    OPJ_UINT32 prec;
    OPJ_INT32 dx;
    OPJ_INT32 dy;
} opj_image_comp;

typedef struct {
    OPJ_UINT32 numcomps;
    OPJ_UINT32 color_space;
    opj_image_comp* comps;
    unsigned char* icc_profile_buf;
    OPJ_UINT32 icc_profile_len;
} opj_image_t;

typedef struct {
    char** filename;
    char* filename_buf;
} dircnt_t;

typedef struct {
    char* imgdirpath;
    int set_imgdir;
} img_fol_t;

typedef void* opj_stream_t;
typedef void* opj_codec_t;
typedef void* opj_codestream_index_t;

void set_default_parameters(opj_decompress_parameters* parameters);
int parse_cmdline_decoder(int argc, char** argv, opj_decompress_parameters* parameters, img_fol_t* img_fol);
void destroy_parameters(opj_decompress_parameters* parameters);
int get_num_images(const char* imgdirpath);
int load_images(dircnt_t* dirptr, const char* imgdirpath);
int get_next_file(OPJ_INT32 imageno, dircnt_t* dirptr, img_fol_t* img_fol, opj_decompress_parameters* parameters);
opj_stream_t* opj_stream_create_default_file_stream(const char* filename, int is_read_stream);
opj_codec_t* opj_create_decompress(OPJ_UINT32 format);
void opj_set_info_handler(opj_codec_t* codec, void (*callback)(const char* msg, void* client_data), void* client_data);
void opj_set_warning_handler(opj_codec_t* codec, void (*callback)(const char* msg, void* client_data), void* client_data);
void opj_set_error_handler(opj_codec_t* codec, void (*callback)(const char* msg, void* client_data), void* client_data);
OPJ_FLOAT64 opj_clock();
int opj_setup_decoder(opj_codec_t* codec, opj_core_parameters* parameters);
int opj_codec_set_threads(opj_codec_t* codec, int num_threads);
int opj_read_header(opj_stream_t* stream, opj_codec_t* codec, opj_image_t** image);
int opj_set_decoded_components(opj_codec_t* codec, OPJ_UINT32 numcomps, OPJ_UINT32* comps_indices, OPJ_UINT32 apply_color_transforms);
int opj_set_decoded_resolution_factor(opj_codec_t* codec, OPJ_UINT32 factor);
int opj_set_decode_area(opj_codec_t* codec, opj_image_t* image, OPJ_INT32 DA_x0, OPJ_INT32 DA_y0, OPJ_INT32 DA_x1, OPJ_INT32 DA_y1);
int opj_decode(opj_codec_t* codec, opj_stream_t* stream, opj_image_t* image);
int opj_end_decompress(opj_codec_t* codec, opj_stream_t* stream);
int opj_get_decoded_tile(opj_codec_t* codec, opj_stream_t* stream, opj_image_t* image, OPJ_UINT32 tile_index);
void opj_stream_destroy(opj_stream_t* stream);
void opj_destroy_codec(opj_codec_t* codec);
void opj_image_destroy(opj_image_t* image);
void opj_destroy_cstr_index(opj_codestream_index_t** cstr_index);
void color_sycc_to_rgb(opj_image_t* image);
void color_cmyk_to_rgb(opj_image_t* image);
void color_esycc_to_rgb(opj_image_t* image);
void color_apply_icc_profile(opj_image_t* image);
void color_cielab_to_rgb(opj_image_t* image);
void clip_component(opj_image_comp* comp, OPJ_UINT32 prec);
void scale_component(opj_image_comp* comp, OPJ_UINT32 prec);
opj_image_t* upsample_image_components(opj_image_t* image);
opj_image_t* convert_gray_to_rgb(opj_image_t* image);
int imagetopnm(opj_image_t* image, const char* outfile, int split_pnm);
int imagetopgx(opj_image_t* image, const char* outfile);
int imagetobmp(opj_image_t* image, const char* outfile);
int imagetotif(opj_image_t* image, const char* outfile);
int imagetoraw(opj_image_t* image, const char* outfile);
int imagetorawl(opj_image_t* image, const char* outfile);
int imagetotga(opj_image_t* image, const char* outfile);
int imagetopng(opj_image_t* image, const char* outfile);
void quiet_callback(const char* msg, void* client_data);
void info_callback(const char* msg, void* client_data);
void warning_callback(const char* msg, void* client_data);
void error_callback(const char* msg, void* client_data);