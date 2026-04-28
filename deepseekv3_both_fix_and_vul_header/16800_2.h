#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int OPJ_BOOL;
#define OPJ_FALSE 0
#define OPJ_TRUE 1

typedef size_t OPJ_SIZE_T;
typedef unsigned int OPJ_UINT32;
typedef double OPJ_FLOAT64;
typedef unsigned char OPJ_BYTE;

#define OPJ_PATH_LEN 4096
#define OPJ_IS_IMF(x) (0)
#define OPJ_GET_IMF_MAINLEVEL(x) (0)
#define OPJ_IMF_MAINLEVEL_MAX 11
#define OPJ_IMF_MAINLEVEL_1_MSAMPLESEC 0
#define OPJ_IMF_MAINLEVEL_2_MSAMPLESEC 0
#define OPJ_IMF_MAINLEVEL_3_MSAMPLESEC 0
#define OPJ_IMF_MAINLEVEL_4_MSAMPLESEC 0
#define OPJ_IMF_MAINLEVEL_5_MSAMPLESEC 0
#define OPJ_IMF_MAINLEVEL_6_MSAMPLESEC 0
#define OPJ_IMF_MAINLEVEL_7_MSAMPLESEC 0
#define OPJ_IMF_MAINLEVEL_8_MSAMPLESEC 0
#define OPJ_IMF_MAINLEVEL_9_MSAMPLESEC 0
#define OPJ_IMF_MAINLEVEL_10_MSAMPLESEC 0
#define OPJ_IMF_MAINLEVEL_11_MSAMPLESEC 0

enum {
    PGX_DFMT,
    PXM_DFMT,
    BMP_DFMT,
    TIF_DFMT,
    RAW_DFMT,
    RAWL_DFMT,
    TGA_DFMT,
    PNG_DFMT,
    J2K_CFMT,
    JP2_CFMT
};

enum {
    OPJ_CODEC_J2K,
    OPJ_CODEC_JP2
};

typedef struct {
    char tcp_mct;
    char* cp_comment;
    void* cp_matrice;
    char* infile;
    char* outfile;
    int decod_format;
    int cod_format;
    int rsiz;
    int cp_tx0;
    int cp_ty0;
    int cp_tdx;
    int cp_tdy;
    OPJ_BOOL tile_size_on;
    void* mct_data;
} opj_cparameters_t;

typedef struct {
    int numcomps;
    int x1;
    int y1;
    struct {
        int dx;
        int dy;
    } comps[3];
} opj_image_t;

typedef struct opj_stream opj_stream_t;
typedef struct opj_codec opj_codec_t;

typedef struct {
    int rawWidth;
    int rawHeight;
    int rawComp;
    int rawBitDepth;
    int rawSigned;
    int* rawComps;
} raw_cparameters_t;

typedef struct {
    char* imgdirpath;
    int set_imgdir;
} img_fol_t;

typedef struct {
    char** filename;
    char* filename_buf;
} dircnt_t;

double opj_clock(void);
void opj_set_default_encoder_parameters(opj_cparameters_t* parameters);
opj_codec_t* opj_create_compress(int format);
void opj_set_info_handler(opj_codec_t* codec, void (*callback)(const char* msg, void* client_data), void* client_data);
void opj_set_warning_handler(opj_codec_t* codec, void (*callback)(const char* msg, void* client_data), void* client_data);
void opj_set_error_handler(opj_codec_t* codec, void (*callback)(const char* msg, void* client_data), void* client_data);
int opj_setup_encoder(opj_codec_t* codec, opj_cparameters_t* parameters, opj_image_t* image);
int opj_encoder_set_extra_options(opj_codec_t* codec, const char* const* options);
int opj_codec_set_threads(opj_codec_t* codec, int num_threads);
opj_stream_t* opj_stream_create_default_file_stream(const char* filename, OPJ_BOOL is_read_stream);
OPJ_BOOL opj_start_compress(opj_codec_t* codec, opj_image_t* image, opj_stream_t* stream);
OPJ_BOOL opj_write_tile(opj_codec_t* codec, OPJ_UINT32 tile_index, OPJ_BYTE* data, OPJ_UINT32 data_size, opj_stream_t* stream);
OPJ_BOOL opj_encode(opj_codec_t* codec, opj_stream_t* stream);
OPJ_BOOL opj_end_compress(opj_codec_t* codec, opj_stream_t* stream);
void opj_stream_destroy(opj_stream_t* stream);
void opj_destroy_codec(opj_codec_t* codec);
void opj_image_destroy(opj_image_t* image);

int parse_cmdline_encoder(int argc, char** argv, opj_cparameters_t* parameters, img_fol_t* img_fol, raw_cparameters_t* raw_cp, char* indexfilename, size_t indexfilename_size, int* framerate, OPJ_BOOL* PLT, OPJ_BOOL* TLM, int* num_threads, unsigned int* target_bitdepth);
unsigned int get_num_images(const char* imgdirpath);
int load_images(dircnt_t* dirptr, const char* imgdirpath);
int get_next_file(int imageno, dircnt_t* dirptr, img_fol_t* img_fol, opj_cparameters_t* parameters);
opj_image_t* pgxtoimage(const char* filename, opj_cparameters_t* parameters);
opj_image_t* pnmtoimage(const char* filename, opj_cparameters_t* parameters);
opj_image_t* bmptoimage(const char* filename, opj_cparameters_t* parameters);
opj_image_t* rawtoimage(const char* filename, opj_cparameters_t* parameters, raw_cparameters_t* raw_cp);
opj_image_t* rawltoimage(const char* filename, opj_cparameters_t* parameters, raw_cparameters_t* raw_cp);
opj_image_t* tgatoimage(const char* filename, opj_cparameters_t* parameters);

void info_callback(const char* msg, void* client_data);
void warning_callback(const char* msg, void* client_data);
void error_callback(const char* msg, void* client_data);