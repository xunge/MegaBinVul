#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sx;
    int sy;
    unsigned char *red;
    unsigned char *green;
    unsigned char *blue;
} gdImage;
typedef gdImage *gdImagePtr;

#define INTERNAL_FUNCTION_PARAMETERS int ht, void *return_value, void **return_value_ptr, void *this_ptr, int return_value_used
#define ZEND_NUM_ARGS() ht
#define TSRMLS_CC
#define FAILURE -1
#define RETURN_FALSE do { return; } while (0)
#define RETURN_TRUE do { return; } while (0)
#define PHP_GD_CHECK_OPEN_BASEDIR(filename, message)
#define VCWD_FOPEN(filename, mode) fopen(filename, mode)
#define INI_INT(name) 0
#define E_WARNING 2
#define php_error_docref(reference, severity, ...)

enum {
    PHP_GDIMG_TYPE_GIF,
    PHP_GDIMG_TYPE_JPG,
    PHP_GDIMG_TYPE_PNG
};

#define HAVE_GD_JPG
#define HAVE_GD_PNG

gdImagePtr gdImageCreateFromGif(FILE *fd) { return NULL; }
gdImagePtr gdImageCreateFromJpegEx(FILE *fd, long ignore_warning) { return NULL; }
gdImagePtr gdImageCreateFromPng(FILE *fd) { return NULL; }
gdImagePtr gdImageCreate(int width, int height) { return NULL; }
void gdImageDestroy(gdImagePtr im) {}
int gdImageColorAllocate(gdImagePtr im, int r, int g, int b) { return -1; }
int gdImageGetPixel(gdImagePtr im, int x, int y) { return 0; }
void gdImageSetPixel(gdImagePtr im, int x, int y, int color) {}
void gdImageCopyResized(gdImagePtr dst, gdImagePtr src, int dstX, int dstY, int srcX, int srcY, int dstW, int dstH, int srcW, int srcH) {}
void gdImageWBMP(gdImagePtr im, int fg, FILE *out) {}