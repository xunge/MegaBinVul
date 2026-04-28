#include <stdio.h>
#include <stdlib.h>

#define METHODDEF(type) static type
#define LOCAL(type) static type
#define GLOBAL(type) type
#define EXTERN(type) extern type
#define boolean int
#define TRUE 1
#define FALSE 0
#define JDIMENSION unsigned int
#define JSAMPLE unsigned char
#define JSAMPROW JSAMPLE*
#define MAXJSAMPLE 255
#define BITS_IN_JSAMPLE 8
#define JPOOL_IMAGE 0
#define JCS_UNKNOWN 0
#define JCS_GRAYSCALE 1
#define JCS_RGB 2
#define JCS_EXT_RGB 3
#define JCS_CMYK 4
#define JTRC_PGM_TEXT 0
#define JTRC_PPM_TEXT 0
#define JTRC_PGM 0
#define JTRC_PPM 0
#define JERR_PPM_NOT 0
#define JERR_BAD_IN_COLORSPACE 0

typedef unsigned char U_CHAR;
typedef struct jpeg_common_struct *j_common_ptr;
typedef struct jpeg_compress_struct *j_compress_ptr;
typedef struct cjpeg_source_struct *cjpeg_source_ptr;
typedef struct ppm_source_struct *ppm_source_ptr;

struct jpeg_error_mgr;
struct jpeg_memory_mgr;

struct jpeg_common_struct {
    struct jpeg_error_mgr *err;
    struct jpeg_memory_mgr *mem;
};

struct jpeg_compress_struct {
    struct jpeg_common_struct common;
    JDIMENSION image_width;
    JDIMENSION image_height;
    int in_color_space;
    int input_components;
    int data_precision;
    struct jpeg_memory_mgr *mem;
};

struct jpeg_memory_mgr {
    void* (*alloc_small) (j_common_ptr cinfo, int pool_id, size_t sizeofobject);
    JSAMPROW* (*alloc_sarray) (j_common_ptr cinfo, int pool_id,
                              JDIMENSION samplesperrow, JDIMENSION numrows);
};

struct cjpeg_source_struct {
    FILE *input_file;
    JSAMPROW *buffer;
    JDIMENSION buffer_height;
    void (*get_pixel_rows)(j_compress_ptr, cjpeg_source_ptr);
};

struct ppm_source_struct {
    struct cjpeg_source_struct pub;
    unsigned int maxval;
    size_t buffer_width;
    U_CHAR *iobuffer;
    JSAMPROW pixrow;
    JSAMPLE *rescale;
};

int rgb_pixelsize[] = {0, 1, 3, 3, 4};

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ERREXIT(cinfo,code) exit(code)
#define TRACEMS2(cinfo,level,code,w,h)

int read_pbm_integer(j_compress_ptr cinfo, FILE *file, int maxval);
int IsExtRGB(int color_space);

void get_text_gray_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
void get_text_gray_rgb_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
void get_text_gray_cmyk_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
void get_text_rgb_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
void get_text_rgb_cmyk_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
void get_word_gray_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
void get_raw_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
void get_scaled_gray_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
void get_gray_rgb_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
void get_gray_cmyk_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
void get_word_rgb_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
void get_rgb_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
void get_rgb_cmyk_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);