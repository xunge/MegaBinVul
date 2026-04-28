#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

#define HD_ERROR_BAD_FORMAT 1
#define JCS_GRAYSCALE 1
#define JCS_RGB 2
#define JMSG_LENGTH_MAX 200
#define FALSE 0
#define TRUE 1

typedef unsigned char uchar;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef int boolean;

struct jpeg_error_mgr {
    void (*error_exit)(void *);
    char msg_code;
    char msg_parm[8];
    int trace_level;
    long num_warnings;
    const char **jpeg_message_table;
    int last_jpeg_message;
    const char **addon_message_table;
    int first_addon_message;
    int last_addon_message;
};

struct jpeg_decompress_struct {
    struct jpeg_error_mgr *err;
    int image_width;
    int image_height;
    int num_components;
    int jpeg_color_space;
    int out_color_space;
    int scale_num, scale_denom;
    int output_components;
    int out_color_components;
    int output_width;
    int output_height;
    JDIMENSION output_scanline;
    int quantize_colors;
};

typedef struct {
    struct jpeg_error_mgr jerr;
    char message[JMSG_LENGTH_MAX];
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
void jpeg_stdio_src(struct jpeg_decompress_struct *cinfo, FILE *infile);
int jpeg_read_header(struct jpeg_decompress_struct *cinfo, boolean require_image);
void jpeg_calc_output_dimensions(struct jpeg_decompress_struct *cinfo);
void jpeg_start_decompress(struct jpeg_decompress_struct *cinfo);
int jpeg_read_scanlines(struct jpeg_decompress_struct *cinfo, JSAMPARRAY scanlines, JDIMENSION max_lines);
void jpeg_finish_decompress(struct jpeg_decompress_struct *cinfo);
void jpeg_destroy_decompress(struct jpeg_decompress_struct *cinfo);
void jpeg_error_handler(void *cinfo);
void progress_error(int code, const char *format, ...);
const char *file_rlookup(const char *filename);