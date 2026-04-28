#include <stdio.h>
#include <stdlib.h>

typedef unsigned char U_CHAR;
typedef unsigned short UINT16;
typedef unsigned int JDIMENSION;
typedef int boolean;

#define METHODDEF(type) static type
#define LOCAL(type) static type
#define UCH(x) ((int)(x))

#define ERREXIT(cinfo,code) exit(1)
#define TRACEMS2(cinfo,level,code,p1,p2)
#define JERR_INPUT_EOF 1
#define JERR_BMP_NOT 2
#define JERR_BMP_BADHEADER 3
#define JERR_BMP_BADDEPTH 4
#define JERR_BMP_COMPRESSED 5
#define JERR_BMP_EMPTY 6
#define JERR_BMP_BADPLANES 7
#define JERR_BMP_BADCMAP 8
#define JERR_BAD_IN_COLORSPACE 9
#define JERR_WIDTH_OVERFLOW 10
#define JTRC_BMP_OS2_MAPPED 11
#define JTRC_BMP_OS2 12
#define JTRC_BMP_MAPPED 13
#define JTRC_BMP 14

#define JPOOL_IMAGE 1
#define JCS_UNKNOWN 0
#define JCS_EXT_RGB 1
#define JCS_GRAYSCALE 2
#define JCS_CMYK 3
#define JCS_EXT_BGR 4
#define JCS_EXT_BGRA 5
#define FALSE 0

typedef struct jpeg_compress_struct *j_compress_ptr;
typedef struct jpeg_common_struct *j_common_ptr;
typedef struct jpeg_progress_mgr *cd_progress_ptr;

typedef struct cjpeg_source_struct *cjpeg_source_ptr;
typedef struct bmp_source_struct *bmp_source_ptr;

struct jpeg_compress_struct {
    struct jpeg_memory_mgr *mem;
    JDIMENSION image_width;
    JDIMENSION image_height;
    int in_color_space;
    int input_components;
    int data_precision;
    UINT16 X_density;
    UINT16 Y_density;
    int density_unit;
    struct jpeg_progress_mgr *progress;
};

struct jpeg_memory_mgr {
    void * (*alloc_small) (j_common_ptr cinfo, int pool_id, size_t sizeofobject);
    void * (*alloc_sarray) (j_common_ptr cinfo, int pool_id,
                           JDIMENSION samplesperrow, JDIMENSION numrows);
    void * (*request_virt_sarray) (j_common_ptr cinfo, int pool_id,
                                  boolean pre_zero,
                                  JDIMENSION samplesperrow, JDIMENSION numrows,
                                  JDIMENSION maxaccess);
};

struct jpeg_progress_mgr {
    long total_extra_passes;
};

struct cjpeg_source_struct {
    int (*get_pixel_rows) (j_compress_ptr cinfo, cjpeg_source_ptr sinfo);
    FILE *input_file;
    void *buffer;
    JDIMENSION buffer_height;
};

struct bmp_source_struct {
    struct cjpeg_source_struct pub;
    int bits_per_pixel;
    JDIMENSION row_width;
    U_CHAR *iobuffer;
    void *colormap;
    void *whole_image;
    int use_inversion_array;
};

int ReadOK(FILE *file, U_CHAR *buf, size_t len) { return 1; }
int read_byte(bmp_source_ptr source) { return 0; }
void read_colormap(bmp_source_ptr source, int colors, int entrysize) {}
int preload_image(j_compress_ptr cinfo, cjpeg_source_ptr sinfo) { return 0; }
int get_8bit_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo) { return 0; }
int get_24bit_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo) { return 0; }
int get_32bit_row(j_compress_ptr cinfo, cjpeg_source_ptr sinfo) { return 0; }
int IsExtRGB(int colorspace) { return 1; }

static const int rgb_pixelsize[] = {0, 3, 1, 4, 3, 4};