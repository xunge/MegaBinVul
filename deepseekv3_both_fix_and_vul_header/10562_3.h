#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <limits.h>

typedef enum {
    SUCCESS,
    PNG_OUT_OF_MEMORY_ERROR,
    LIBPNG_FATAL_ERROR,
    WRONG_INPUT_COLOR_TYPE
} pngquant_error;

typedef enum {
    RWPNG_NONE,
    RWPNG_SRGB,
    RWPNG_GAMA_ONLY,
    RWPNG_ICCP,
    RWPNG_ICCP_WARN_GRAY,
    RWPNG_GAMA_CHRM
} rwpng_color_profile;

typedef struct rwpng_read_data {
    FILE *infile;
    size_t bytes_read;
} rwpng_read_data;

typedef struct {
    int width;
    int height;
    unsigned char *rgba_data;
    unsigned char **row_pointers;
    size_t file_size;
    rwpng_color_profile input_color;
    rwpng_color_profile output_color;
    double gamma;
    jmp_buf jmpbuf;
    int retval;
    void *chunks;
} png24_image;

typedef void* png_structp;
typedef void* png_infop;
typedef size_t png_size_t;
typedef unsigned char* png_bytep;
typedef unsigned char** png_bytepp;
typedef const unsigned char* png_const_bytep;
typedef char* png_charp;
typedef unsigned int png_uint_32;

#define PNG_LIBPNG_VER_STRING "1.6.0"
#define PNG_LIBPNG_VER 10600
#define PNG_COLOR_MASK_ALPHA 0x10
#define PNG_COLOR_MASK_COLOR 0x08
#define PNG_INFO_sRGB 0x01
#define PNG_INFO_gAMA 0x02
#define PNG_INFO_cHRM 0x04
#define PNG_FILLER_AFTER 1
#define PNG_SKIP_sRGB_CHECK_PROFILE 1
#define PNG_SET_OPTION_SUPPORTED 1
#define PNG_UNKNOWN_CHUNKS_SUPPORTED 1
#define PNG_HANDLE_CHUNK_IF_SAFE 1
#define PNG_OPTION_ON 1

void rwpng_error_handler(png_structp png_ptr, const char* msg);
void rwpng_warning_stderr_handler(png_structp png_ptr, const char* msg);
void rwpng_warning_silent_handler(png_structp png_ptr, const char* msg);
int read_chunk_callback(png_structp png_ptr, void* chunk);
void user_read_data(png_structp png_ptr, png_bytep data, png_size_t length);
png_bytepp rwpng_create_row_pointers(png_infop info_ptr, png_structp png_ptr, unsigned char *rgba_data, int height, int interlaced);

/* Dummy libpng function declarations */
png_structp png_create_read_struct(const char*, void*, void*, void*);
png_infop png_create_info_struct(png_structp);
void png_destroy_read_struct(png_structp*, png_infop*, png_infop*);
void png_set_option(png_structp, int, int);
void png_set_keep_unknown_chunks(png_structp, int, png_const_bytep, int);
void png_set_read_user_chunk_fn(png_structp, void*, int (*)(png_structp, void*));
void png_set_read_fn(png_structp, void*, void (*)(png_structp, png_bytep, png_size_t));
void png_read_info(png_structp, png_infop);
void png_get_IHDR(png_structp, png_infop, int*, int*, int*, int*, int*, int*, int*);
void png_set_strip_16(png_structp);
void png_set_gray_to_rgb(png_structp);
int png_get_valid(png_structp, png_infop, int);
void png_get_gAMA(png_structp, png_infop, double*);
void png_set_interlace_handling(png_structp);
void png_read_update_info(png_structp, png_infop);
png_size_t png_get_rowbytes(png_structp, png_infop);
void png_read_image(png_structp, png_bytepp);
void png_read_end(png_structp, png_infop);