#include <stdio.h>
#include <stdlib.h>

typedef unsigned char U_CHAR;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

struct jpeg_compress_struct {
    JDIMENSION image_width;
};

typedef struct jpeg_compress_struct *j_compress_ptr;
typedef struct cjpeg_source_struct *cjpeg_source_ptr;
typedef struct ppm_source_struct *ppm_source_ptr;

struct cjpeg_source_struct {
    JSAMPROW buffer[1];
    FILE *input_file;
};

struct ppm_source_struct {
    struct cjpeg_source_struct pub;
    JSAMPLE *rescale;
    U_CHAR *iobuffer;
    unsigned int buffer_width;
    unsigned int maxval;
};

#define METHODDEF(type) static type
#define ERREXIT(cinfo,code) exit(1)
#define JERR_INPUT_EOF 1
#define JERR_PPM_OUTOFRANGE 2
#define JERR_PPM_TOOLARGE 2
#define UCH(x) ((unsigned char)(x))

static int ReadOK(FILE *file, U_CHAR *buf, size_t len) {
    return fread(buf, 1, len, file) == len;
}