#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int OPJ_INT32;

typedef struct opj_dparameters {
    char outfile[4096];
    char infile[4096];
    int decod_format;
    int flags;
} opj_dparameters_t;

typedef struct opj_image {
    // Placeholder for image structure
} opj_image_t;

typedef struct opj_codec {
    // Placeholder for codec structure
} opj_codec_t;

typedef struct opj_stream {
    // Placeholder for stream structure
} opj_stream_t;

typedef struct opj_codestream_info_v2 {
    // Placeholder for codestream info structure
} opj_codestream_info_v2_t;

typedef struct opj_codestream_index {
    // Placeholder for codestream index structure
} opj_codestream_index_t;

typedef struct img_fol {
    int flag;
    char* imgdirpath;
    int set_imgdir;
} img_fol_t;

typedef struct dircnt {
    char** filename;
    char* filename_buf;
} dircnt_t;

#define OPJ_IMG_INFO 1
#define OPJ_J2K_MH_INFO 2
#define OPJ_J2K_MH_IND 4
#define OPJ_DPARAMETERS_DUMP_FLAG 8
#define OPJ_PATH_LEN 4096
#define OPJ_CODEC_J2K 0
#define OPJ_CODEC_JP2 1
#define OPJ_CODEC_JPT 2

#define J2K_CFMT 0
#define JP2_CFMT 1
#define JPT_CFMT 2

void opj_set_default_decoder_parameters(opj_dparameters_t* parameters);
opj_stream_t* opj_stream_create_default_file_stream(const char* filename, int is_read);
opj_codec_t* opj_create_decompress(int format);
void opj_set_info_handler(opj_codec_t* codec, void (*callback)(const char*, void*), void* data);
void opj_set_warning_handler(opj_codec_t* codec, void (*callback)(const char*, void*), void* data);
void opj_set_error_handler(opj_codec_t* codec, void (*callback)(const char*, void*), void* data);
int opj_setup_decoder(opj_codec_t* codec, opj_dparameters_t* parameters);
int opj_read_header(opj_stream_t* stream, opj_codec_t* codec, opj_image_t** image);
void opj_dump_codec(opj_codec_t* codec, int flag, FILE* fout);
opj_codestream_info_v2_t* opj_get_cstr_info(opj_codec_t* codec);
opj_codestream_index_t* opj_get_cstr_index(opj_codec_t* codec);
void opj_stream_destroy(opj_stream_t* stream);
void opj_destroy_codec(opj_codec_t* codec);
void opj_image_destroy(opj_image_t* image);
void opj_destroy_cstr_index(opj_codestream_index_t** index);
void opj_destroy_cstr_info(opj_codestream_info_v2_t** info);

int parse_cmdline_decoder(int argc, char* argv[], opj_dparameters_t* parameters, img_fol_t* img_fol);
int get_num_images(const char* path);
int load_images(dircnt_t* dirptr, const char* path);
int get_next_file(int imageno, dircnt_t* dirptr, img_fol_t* img_fol, opj_dparameters_t* parameters);

void info_callback(const char* msg, void* data);
void warning_callback(const char* msg, void* data);
void error_callback(const char* msg, void* data);