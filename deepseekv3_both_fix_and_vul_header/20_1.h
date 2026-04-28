#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define METHODDEF(type) static type
#define JDIMENSION unsigned int
#define JSAMPROW unsigned char*
#define U_CHAR unsigned char
#define JSAMPLE unsigned char
#define ERREXIT(cinfo,code) exit(1)
#define JERR_INPUT_EOF 1
#define JERR_PPM_OUTOFRANGE 2
#define UCH(x) ((unsigned char)(x))

typedef struct jpeg_compress_struct {
    int in_color_space;
    JDIMENSION image_width;
} *j_compress_ptr;

typedef struct cjpeg_source_struct {
    struct jpeg_compress_struct *cinfo;
    FILE *input_file;
    JSAMPROW buffer[1];
} *cjpeg_source_ptr;

typedef struct ppm_source_struct {
    struct cjpeg_source_struct pub;
    unsigned int maxval;
    JSAMPLE *rescale;
    JDIMENSION buffer_width;
    U_CHAR *iobuffer;
} *ppm_source_ptr;

extern int rgb_red[];
extern int rgb_green[];
extern int rgb_blue[];
extern int alpha_index[];
extern int rgb_pixelsize[];

#define ReadOK(file,buffer,len) (fread(buffer, 1, len, file) == (size_t)(len))