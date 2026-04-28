#include <stdio.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;

#define METHODDEF(type) static type
#define FALSE 0
#define JCS_GRAYSCALE 1
#define JCS_CMYK 2
#define JERR_INPUT_EOF 1
#define JERR_BMP_OUTOFRANGE 2
#define GETJSAMPLE(value) ((int)(value))

struct jpeg_common_struct;
typedef struct jpeg_common_struct *j_common_ptr;

struct jpeg_compress_struct {
    struct {
        JSAMPARRAY (*access_virt_sarray)(j_common_ptr, JSAMPARRAY, JDIMENSION, JDIMENSION, int);
    } *mem;
    int in_color_space;
    JDIMENSION image_width;
};
typedef struct jpeg_compress_struct *j_compress_ptr;

struct cjpeg_source_struct {
    FILE *input_file;
    JSAMPARRAY buffer;
};
typedef struct cjpeg_source_struct *cjpeg_source_ptr;

struct bmp_source_struct {
    struct cjpeg_source_struct pub;
    JSAMPARRAY colormap;
    int cmap_length;
    int use_inversion_array;
    JDIMENSION source_row;
    JSAMPARRAY whole_image;
    JSAMPROW iobuffer;
    size_t row_width;
};
typedef struct bmp_source_struct *bmp_source_ptr;

void ERREXIT(j_compress_ptr cinfo, int code);
int ReadOK(FILE *file, JSAMPROW buf, size_t len);
void rgb_to_cmyk(JSAMPLE r, JSAMPLE g, JSAMPLE b, 
                JSAMPLE *c, JSAMPLE *m, JSAMPLE *y, JSAMPLE *k);
extern int rgb_red[];
extern int rgb_green[];
extern int rgb_blue[];
extern int alpha_index[];
extern int rgb_pixelsize[];