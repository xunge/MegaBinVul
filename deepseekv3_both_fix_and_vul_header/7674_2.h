#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

typedef unsigned char uchar;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef int boolean;
typedef unsigned int JDIMENSION;

#define IMAGE_MAX_DIM 65535
#define HD_ERROR_BAD_FORMAT 1
#define FALSE 0
#define JCS_GRAYSCALE 1
#define JCS_RGB 2

struct jpeg_error_mgr {
    void (*error_exit)(void *);
};

struct jpeg_decompress_struct {
    struct jpeg_error_mgr *err;
    JDIMENSION output_width;
    JDIMENSION output_height;
    int output_components;
    int out_color_components;
    int out_color_space;
    JDIMENSION output_scanline;
    int num_components;
    boolean quantize_colors;
};

typedef struct {
    struct jpeg_error_mgr jerr;
    char message[256];
    jmp_buf retbuf;
} hd_jpeg_err_t;

typedef struct {
    int width;
    int height;
    int depth;
    uchar *pixels;
    char *filename;
} image_t;

void jpeg_std_error(struct jpeg_error_mgr *err);
void jpeg_create_decompress(struct jpeg_decompress_struct *cinfo);
void jpeg_stdio_src(struct jpeg_decompress_struct *cinfo, FILE *fp);
int jpeg_read_header(struct jpeg_decompress_struct *cinfo, boolean require_image);
void jpeg_calc_output_dimensions(struct jpeg_decompress_struct *cinfo);
void jpeg_start_decompress(struct jpeg_decompress_struct *cinfo);
int jpeg_read_scanlines(struct jpeg_decompress_struct *cinfo, JSAMPROW *row, JDIMENSION lines);
void jpeg_finish_decompress(struct jpeg_decompress_struct *cinfo);
void jpeg_destroy_decompress(struct jpeg_decompress_struct *cinfo);
void jpeg_error_handler(void *cinfo);

const char *file_rlookup(const char *filename);
void progress_error(int error, const char *format, ...);