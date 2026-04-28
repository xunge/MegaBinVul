#include <stdio.h>

typedef unsigned char U_CHAR;
typedef unsigned short JDIMENSION;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;

typedef struct jpeg_compress_struct *j_compress_ptr;
typedef struct cjpeg_source_struct *cjpeg_source_ptr;
typedef struct ppm_source_struct *ppm_source_ptr;

#define METHODDEF(type) static type
#define ERREXIT(cinfo,code) ((void)0)
#define ReadOK(file,buffer,len) (fread(buffer, 1, len, file) == ((size_t) (len)))
#define UCH(x) ((int)(x) & 0xFF)
#define JERR_INPUT_EOF 1
#define JERR_PPM_TOOLARGE 2

struct cjpeg_source_struct {
    JSAMPROW buffer[1];
    FILE *input_file;
};

struct ppm_source_struct {
    struct cjpeg_source_struct pub;
    JSAMPLE *rescale;
    unsigned int maxval;
    U_CHAR *iobuffer;
    size_t buffer_width;
};

struct jpeg_compress_struct {
    JDIMENSION image_width;
    struct jpeg_error_mgr *err;
};

struct jpeg_error_mgr {
    int msg_code;
    void (*error_exit)(void *);
};