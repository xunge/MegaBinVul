#include <stdio.h>
#include <stdlib.h>

typedef unsigned char U_CHAR;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned short UINT16;
typedef unsigned int JDIMENSION;

typedef struct jpeg_compress_struct *j_compress_ptr;
typedef struct cjpeg_source_struct *cjpeg_source_ptr;
typedef struct bmp_source_struct *bmp_source_ptr;
typedef struct jpeg_common_struct *j_common_ptr;
typedef struct jpeg_progress_mgr *cd_progress_ptr;

#define METHODDEF(type) static type
#define LOCAL(type) static type

#define ERREXIT(cinfo,code) 
#define TRACEMS2(cinfo,level,code,arg1,arg2) 

#define JPOOL_IMAGE 0
#define JCS_UNKNOWN 0
#define JCS_GRAYSCALE 1
#define JCS_EXT_RGB 2
#define JCS_EXT_BGR 3
#define JCS_EXT_BGRA 4
#define JCS_CMYK 5

#define JERR_INPUT_EOF 0
#define JERR_BMP_NOT 0
#define JERR_BMP_BADHEADER 0
#define JERR_BMP_BADDEPTH 0
#define JERR_BMP_COMPRESSED 0
#define JERR_BMP_EMPTY 0
#define JERR_BMP_BADPLANES 0
#define JERR_BMP_BADCMAP 0
#define JERR_BAD_IN_COLORSPACE 0
#define JERR_WIDTH_OVERFLOW 0
#define JTRC_BMP_OS2_MAPPED 0
#define JTRC_BMP_OS2 0
#define JTRC_BMP_MAPPED 0
#define JTRC_BMP 0

#define UCH(x) ((unsigned char)(x))
#define ReadOK(file,buffer,len) (fread(buffer, 1, len, file) == (size_t)(len))

struct jpeg_compress_struct {
    UINT16 X_density;
    UINT16 Y_density;
    int density_unit;
    int in_color_space;
    int input_components;
    int data_precision;
    JDIMENSION image_width;
    JDIMENSION image_height;
    struct jpeg_progress_mgr *progress;
    struct jpeg_memory_mgr *mem;
};

struct cjpeg_source_struct {
    FILE *input_file;
    JDIMENSION buffer_height;
    JSAMPARRAY buffer;
    void (*get_pixel_rows)(j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
};

struct bmp_source_struct {
    struct cjpeg_source_struct pub;
    int bits_per_pixel;
    JSAMPARRAY colormap;
    int cmap_length;
    JDIMENSION row_width;
    int use_inversion_array;
    JSAMPARRAY whole_image;
    U_CHAR *iobuffer;
};

struct jpeg_memory_mgr {
    JSAMPARRAY (*alloc_sarray)(j_common_ptr cinfo, int pool_id, JDIMENSION samplesperrow, JDIMENSION numrows);
    JSAMPARRAY (*request_virt_sarray)(j_common_ptr cinfo, int pool_id, int pre_zero, JDIMENSION samplesperrow, JDIMENSION numrows, JDIMENSION maxaccess);
    void *(*alloc_small)(j_common_ptr cinfo, int pool_id, size_t sizeofobject);
};

struct jpeg_progress_mgr {
    int total_extra_passes;
};

#define FALSE 0
#define TRUE 1

static const int rgb_pixelsize[] = {0, 0, 3, 3, 4, 0};

LOCAL(int) IsExtRGB(int colorspace) { return 0; }
LOCAL(void) read_colormap(bmp_source_ptr source, int num_colors, int mapentrysize) {}
LOCAL(int) read_byte(bmp_source_ptr source) { return 0; }
LOCAL(void) get_8bit_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo) {}
LOCAL(void) get_24bit_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo) {}
LOCAL(void) get_32bit_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo) {}
LOCAL(void) preload_image(j_compress_ptr cinfo, cjpeg_source_ptr sinfo) {}