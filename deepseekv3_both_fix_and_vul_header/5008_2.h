#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int SIXELSTATUS;
#define SIXEL_OK 0
#define SIXEL_JPEG_ERROR -1
#define SIXEL_BAD_INPUT -2
#define SIXEL_BAD_ALLOCATION -3
#define SIXEL_PIXELFORMAT_RGB888 3

typedef unsigned int JDIMENSION;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;

#define TRUE 1
#define FALSE 0
#define JCS_RGB 2
#define JPOOL_IMAGE 0

struct jpeg_error_mgr {
    int num_warnings;
    struct jpeg_error_mgr *(*jpeg_std_error)(struct jpeg_error_mgr *err);
};

struct jpeg_common_struct;
typedef struct jpeg_common_struct *j_common_ptr;

struct jpeg_decompress_struct {
    struct jpeg_error_mgr *err;
    unsigned int output_width;
    unsigned int output_height;
    int output_components;
    unsigned int output_scanline;
    int out_color_space;
    int quantize_colors;
    struct {
        JSAMPARRAY (*alloc_sarray)(j_common_ptr, int, JDIMENSION, JDIMENSION);
    } *mem;
};

typedef struct sixel_allocator_t sixel_allocator_t;
void *sixel_allocator_malloc(sixel_allocator_t *allocator, size_t size);
void sixel_helper_set_additional_message(const char *message);

struct jpeg_error_mgr *jpeg_std_error(struct jpeg_error_mgr *err);
void jpeg_create_decompress(struct jpeg_decompress_struct *cinfo);
void jpeg_mem_src(struct jpeg_decompress_struct *cinfo, unsigned char *data, size_t datasize);
int jpeg_read_header(struct jpeg_decompress_struct *cinfo, int require_image);
void jpeg_start_decompress(struct jpeg_decompress_struct *cinfo);
int jpeg_read_scanlines(struct jpeg_decompress_struct *cinfo, JSAMPARRAY scanlines, int max_lines);
void jpeg_finish_decompress(struct jpeg_decompress_struct *cinfo);
void jpeg_destroy_decompress(struct jpeg_decompress_struct *cinfo);