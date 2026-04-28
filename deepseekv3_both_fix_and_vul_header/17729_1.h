#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

typedef unsigned char U_CHAR;
typedef unsigned char JSAMPLE;
typedef unsigned short JDIMENSION;

#define BITS_IN_JSAMPLE 8
#define MAXJSAMPLE 255
#define JPOOL_IMAGE 0
#define JCS_UNKNOWN 0
#define JCS_GRAYSCALE 1
#define JCS_EXT_RGB 2
#define JCS_RGB 3
#define JCS_CMYK 4
#define JERR_PPM_NOT 0
#define JERR_BAD_IN_COLORSPACE 0
#define JTRC_PGM_TEXT 0
#define JTRC_PPM_TEXT 0
#define JTRC_PGM 0
#define JTRC_PPM 0

#define METHODDEF(type) static type
#define LOCAL(type) static type
#define GLOBAL(type) type
#define EXTERN(type) extern type

typedef bool boolean;
#define TRUE true
#define FALSE false

typedef struct jpeg_compress_struct *j_compress_ptr;
typedef struct jpeg_error_mgr *j_common_ptr;
typedef struct jpeg_memory_mgr *j_memory_mgr;

typedef struct cjpeg_source_struct *cjpeg_source_ptr;
typedef struct ppm_source_struct *ppm_source_ptr;

typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;

struct jpeg_error_mgr {
    void (*error_exit) (j_common_ptr cinfo);
};

struct jpeg_memory_mgr {
    void * (*alloc_small) (j_common_ptr cinfo, int pool_id, size_t sizeofobject);
    JSAMPARRAY (*alloc_sarray) (j_common_ptr cinfo, int pool_id,
                               JDIMENSION samplesperrow, JDIMENSION numrows);
};

struct jpeg_compress_struct {
    struct jpeg_error_mgr *err;
    struct jpeg_memory_mgr *mem;
    int image_width;
    int image_height;
    int in_color_space;
    int input_components;
    int data_precision;
};

struct cjpeg_source_struct {
    FILE *input_file;
    JSAMPARRAY buffer;
    JDIMENSION buffer_height;
    void (*get_pixel_rows) (j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
};

struct ppm_source_struct {
    struct cjpeg_source_struct pub;
    unsigned int maxval;
    size_t buffer_width;
    U_CHAR *iobuffer;
    JSAMPLE *rescale;
    JSAMPROW pixrow;
};

#define ERREXIT(cinfo,code)  \
  ((cinfo)->err->error_exit ((j_common_ptr) (cinfo)))
#define TRACEMS2(cinfo,l,code,m1,m2)

#define IsExtRGB(cs) ((cs) == JCS_EXT_RGB || (cs) == JCS_RGB)

#define RGB_RED 0
#define RGB_GREEN 1
#define RGB_BLUE 2
#define RGB_PIXELSIZE 3

extern int rgb_pixelsize[];
extern int read_pbm_integer(j_compress_ptr cinfo, FILE *infile, int maxval);

/* Function prototypes for row readers */
extern void get_text_gray_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
extern void get_text_gray_rgb_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
extern void get_text_gray_cmyk_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
extern void get_text_rgb_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
extern void get_text_rgb_cmyk_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
extern void get_word_gray_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
extern void get_raw_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
extern void get_scaled_gray_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
extern void get_gray_rgb_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
extern void get_gray_cmyk_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
extern void get_word_rgb_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
extern void get_rgb_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
extern void get_rgb_cmyk_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);