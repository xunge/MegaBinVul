#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int OPJ_INT32;
typedef unsigned int OPJ_UINT32;
typedef double OPJ_FLOAT64;

#define OPJ_PATH_LEN 256
#define OPJ_CODEC_J2K 0
#define OPJ_CODEC_JP2 1
#define OPJ_CODEC_JPT 2
#define OPJ_CLRSPC_SYCC 0
#define OPJ_CLRSPC_GRAY 1
#define OPJ_CLRSPC_SRGB 2
#define OPJ_CLRSPC_CMYK 3
#define OPJ_CLRSPC_EYCC 4
#define OPJ_PREC_MODE_CLIP 0
#define OPJ_PREC_MODE_SCALE 1
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
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

typedef struct {
    int prec;
    int mode;
} opj_precision_t;

typedef struct {
    int core;
    char *infile;
    char *outfile;
    int decod_format;
    int cod_format;
    int DA_x0;
    int DA_y0;
    int DA_x1;
    int DA_y1;
    int nb_tile_to_decode;
    int tile_index;
    int num_threads;
    int split_pnm;
    int force_rgb;
    int upsample;
    opj_precision_t *precision;
    OPJ_UINT32 nb_precision;
} opj_decompress_parameters;

typedef struct {
    OPJ_UINT32 numcomps;
    OPJ_UINT32 color_space;
    struct {
        int dx;
        int dy;
        int prec;
    } *comps;
    OPJ_UINT32 icc_profile_len;
    char *icc_profile_buf;
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

typedef struct {
    int set_imgdir;
    char *imgdirpath;
} img_fol_t;

typedef struct {
    char **filename;
    char *filename_buf;
} dircnt_t;

void info_callback(const char *msg, void *client_data);
void warning_callback(const char *msg, void *client_data);
void error_callback(const char *msg, void *client_data);