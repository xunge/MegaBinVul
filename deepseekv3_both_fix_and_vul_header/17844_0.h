#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned char UINT8;
typedef size_t OPJ_SIZE_T;
typedef int OPJ_BOOL;
typedef unsigned char OPJ_BYTE;

#define BUFFER_SIZE 4096
#define OPJ_TRUE 1
#define OPJ_FALSE 0

#define IMAGING_CODEC_BROKEN 1
#define IMAGING_CODEC_MEMORY 2
#define IMAGING_CODEC_END 3

#define J2K_STATE_FAILED 0
#define J2K_STATE_DONE 1

typedef enum {
    OPJ_CLRSPC_UNKNOWN = -1,
    OPJ_CLRSPC_UNSPECIFIED = 0,
    OPJ_CLRSPC_SRGB = 1,
    OPJ_CLRSPC_GRAY = 2,
    OPJ_CLRSPC_YCC = 3
} OPJ_COLOR_SPACE;

typedef struct {
    int format;
    int reduce;
    int layers;
    long length;
    char *error_msg;
    FILE *pfile;
} JPEG2KDECODESTATE;

typedef struct {
    int tile_index;
    size_t data_size;
    int x0, y0, x1, y1;
    int nb_comps;
} JPEG2KTILEINFO;

typedef void (*j2k_unpacker_t)(void*, JPEG2KTILEINFO*, UINT8*, void*);

typedef struct {
    int color_space;
    int components;
    const char *mode;
    j2k_unpacker_t unpacker;
} j2k_unpacker_entry;

j2k_unpacker_entry j2k_unpackers[] = {};

typedef struct ImagingCodecState {
    void *context;
    int errcode;
    int state;
    UINT8 *buffer;
} *ImagingCodecState;

typedef struct Imaging {
    char *mode;
    int xsize;
    int ysize;
} *Imaging;

typedef struct {
    int numcomps;
    OPJ_COLOR_SPACE color_space;
    int x0, y0;
    struct {
        int dx, dy;
    } *comps;
} opj_image_t;

typedef struct {
    int cp_reduce;
    int cp_layer;
} opj_dparameters_t;

typedef void opj_stream_t;
typedef void opj_codec_t;

opj_stream_t* opj_stream_create(size_t buffer_size, OPJ_BOOL is_input);
void opj_stream_set_read_function(opj_stream_t* stream, void* func);
void opj_stream_set_skip_function(opj_stream_t* stream, void* func);
void opj_stream_set_user_data_v1(opj_stream_t* stream, void* data);
void opj_stream_set_user_data_v2(opj_stream_t* stream, void* data, void* func);
void opj_stream_set_user_data_length(opj_stream_t* stream, unsigned long length);
void opj_set_default_decoder_parameters(opj_dparameters_t* params);
opj_codec_t* opj_create_decompress(int format);
void opj_set_error_handler(opj_codec_t* codec, void* func, void* data);
void opj_setup_decoder(opj_codec_t* codec, opj_dparameters_t* params);
OPJ_BOOL opj_read_header(opj_stream_t* stream, opj_codec_t* codec, opj_image_t** image);
OPJ_BOOL opj_read_tile_header(opj_codec_t* codec, opj_stream_t* stream, int* tile_index, size_t* data_size, int* x0, int* y0, int* x1, int* y1, int* nb_comps, OPJ_BOOL* should_continue);
OPJ_BOOL opj_decode_tile_data(opj_codec_t* codec, int tile_index, OPJ_BYTE* buffer, size_t data_size, opj_stream_t* stream);
OPJ_BOOL opj_end_decompress(opj_codec_t* codec, opj_stream_t* stream);
void opj_destroy_codec(opj_codec_t* codec);
void opj_image_destroy(opj_image_t* image);
void opj_stream_destroy(opj_stream_t* stream);

void* j2k_read(void* buffer, size_t size, void* user_data);
OPJ_SIZE_T j2k_skip(OPJ_SIZE_T size, void* user_data);
void j2k_error(const char* msg, void* user_data);

#ifndef OPJ_VERSION_MAJOR
#define opj_stream_set_user_data opj_stream_set_user_data_v1
#else
#define opj_stream_set_user_data opj_stream_set_user_data_v2
#endif