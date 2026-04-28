#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <string.h>

typedef enum {
    JCS_UNKNOWN,
    JCS_GRAYSCALE,
    JCS_RGB,
    JCS_YCbCr,
    JCS_CMYK,
    JCS_YCCK
} J_COLOR_SPACE;

typedef struct jpeg_error_mgr {
    struct jpeg_error_mgr *pub;
    jmp_buf setjmp_buffer;
} jpeg_error_mgr;

typedef struct jpeg_memory_mgr {
    void (*realize_virt_arrays)(void *cinfo);
} jpeg_memory_mgr;

typedef struct jpeg_compress_struct {
    J_COLOR_SPACE in_color_space;
    int image_width;
    int image_height;
    int next_scanline;
    jpeg_memory_mgr *mem;
    jpeg_error_mgr err;
} jpeg_compress_struct;

typedef struct cjpeg_source_struct {
    FILE *input_file;
    void (*start_input)(jpeg_compress_struct *cinfo, struct cjpeg_source_struct *si);
    int (*get_pixel_rows)(jpeg_compress_struct *cinfo, struct cjpeg_source_struct *si);
    void (*finish_input)(jpeg_compress_struct *cinfo, struct cjpeg_source_struct *si);
    unsigned char *buffer[1];
} cjpeg_source_struct;

typedef struct tjinstance {
    jpeg_compress_struct cinfo;
    jpeg_error_mgr jerr;
} tjinstance;

typedef void *tjhandle;
typedef enum { FALSE, TRUE } boolean;
typedef jpeg_compress_struct *j_compress_ptr;
typedef cjpeg_source_struct *cjpeg_source_ptr;
typedef struct jpeg_common_struct *j_common_ptr;

#define TJPF_UNKNOWN 0
#define TJ_NUMPF 12
#define TJFLAG_BOTTOMUP 2

extern int pf2cs[];
extern int cs2pf[];
extern int tjPixelSize[];

#define _throwg(msg) { retval = -1; goto bailout; }
#define _throwunix(msg) { retval = -1; goto bailout; }
#define PAD(width, align) (((width) + (align) - 1) & (~((align) - 1)))

extern tjhandle tjInitCompress(void);
extern void tjDestroy(tjhandle handle);
extern cjpeg_source_ptr jinit_read_bmp(j_compress_ptr cinfo, boolean is_os2);
extern cjpeg_source_ptr jinit_read_ppm(j_compress_ptr cinfo);