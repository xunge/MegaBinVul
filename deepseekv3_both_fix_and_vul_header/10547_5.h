#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

#define IW_IMPL(x) x

typedef struct jpeg_common_struct *j_common_ptr;
typedef struct jpeg_decompress_struct *j_decompress_ptr;
typedef int boolean;

struct jpeg_error_mgr {
    void (*error_exit)(j_common_ptr);
    void (*output_message)(j_common_ptr);
    void (*format_message)(j_common_ptr, char *buffer);
};

struct jpeg_source_mgr {
    void (*init_source)(j_decompress_ptr);
    boolean (*fill_input_buffer)(j_decompress_ptr);
    void (*skip_input_data)(j_decompress_ptr, long);
    void (*resync_to_restart)(j_decompress_ptr, int);
    void (*term_source)(j_decompress_ptr);
};

struct jpeg_decompress_struct {
    struct jpeg_error_mgr *err;
    struct jpeg_source_mgr *src;
    int output_width;
    int output_height;
    int out_color_space;
    int output_components;
    unsigned int output_scanline;
    int saw_JFIF_marker;
};

struct my_error_mgr {
    struct jpeg_error_mgr pub;
    jmp_buf setjmp_buffer;
};

struct iw_context;
struct iw_iodescr;

struct iw_image {
    int imgtype;
    int native_grayscale;
    int width;
    int height;
    int bit_depth;
    size_t bpr;
    unsigned char *pixels;
};

struct iwjpegrcontext {
    struct jpeg_source_mgr pub;
    struct iw_context *ctx;
    struct iw_iodescr *iodescr;
    unsigned char *buffer;
    size_t buffer_len;
    double exif_density_x;
    double exif_density_y;
    int is_jfif;
    int exif_orientation;
};

typedef unsigned char iw_byte;
typedef unsigned char JSAMPLE;
typedef unsigned int JDIMENSION;

#define IW_IMGTYPE_GRAY 0
#define IW_IMGTYPE_RGB 1
#define JMSG_LENGTH_MAX 200
#define JPEG_HEADER_OK 1
#define TRUE 1

#define JCS_GRAYSCALE 1
#define JCS_RGB 2
#define JCS_CMYK 3

void iw_zeromem(void *ptr, size_t size);
void *iw_malloc(struct iw_context *ctx, size_t size);
void *iw_malloc_large(struct iw_context *ctx, size_t bpr, size_t height);
void iw_free(struct iw_context *ctx, void *ptr);
void iw_set_error(struct iw_context *ctx, const char *msg);
void iw_set_errorf(struct iw_context *ctx, const char *fmt, ...);
void iw_warning(struct iw_context *ctx, const char *msg);
int iw_check_image_dimensions(struct iw_context *ctx, int width, int height);
size_t iw_calc_bytesperrow(int width, int bits);
void iw_set_input_image(struct iw_context *ctx, struct iw_image *img);
void iw_reorient_image(struct iw_context *ctx, unsigned int transform);

void my_error_exit(j_common_ptr cinfo);
void my_output_message(j_common_ptr cinfo);
void my_init_source_fn(j_decompress_ptr cinfo);
boolean my_fill_input_buffer_fn(j_decompress_ptr cinfo);
void my_skip_input_data_fn(j_decompress_ptr cinfo, long num_bytes);
void my_term_source_fn(j_decompress_ptr cinfo);
void iwjpeg_read_density(struct iw_context *ctx, struct iw_image *img, struct jpeg_decompress_struct *cinfo);
void iwjpeg_read_saved_markers(struct iwjpegrcontext *rctx, struct jpeg_decompress_struct *cinfo);
void convert_cmyk_to_rbg(struct iw_context *ctx, JSAMPLE *src, JSAMPLE *dst, int width);
void handle_exif_density(struct iwjpegrcontext *rctx, struct iw_image *img);

struct jpeg_error_mgr *jpeg_std_error(struct jpeg_error_mgr *err);
void jpeg_create_decompress(struct jpeg_decompress_struct *cinfo);
int jpeg_read_header(struct jpeg_decompress_struct *cinfo, boolean require_image);
void jpeg_start_decompress(struct jpeg_decompress_struct *cinfo);
JDIMENSION jpeg_read_scanlines(struct jpeg_decompress_struct *cinfo, JSAMPLE **scanlines, JDIMENSION max_lines);
void jpeg_finish_decompress(struct jpeg_decompress_struct *cinfo);
void jpeg_destroy_decompress(struct jpeg_decompress_struct *cinfo);
void jpeg_save_markers(struct jpeg_decompress_struct *cinfo, int marker_code, unsigned int length);
int jpeg_resync_to_restart(j_decompress_ptr cinfo, int desired);