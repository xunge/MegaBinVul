#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sx;
    int sy;
    int colorsTotal;
    int *red;
    int *green;
    int *blue;
} gdImage;
typedef gdImage *gdImagePtr;

#define PHP_GDIMG_TYPE_GIF 1
#define PHP_GDIMG_TYPE_JPG 2
#define PHP_GDIMG_TYPE_PNG 3

#define INTERNAL_FUNCTION_PARAMETERS int ht, void *return_value, void **return_value_ptr, void *this_ptr, int return_value_used
#define ZEND_NUM_ARGS() ht
#define TSRMLS_CC
#define TSRMLS_DC
#define FAILURE -1
#define RETURN_FALSE return
#define RETURN_TRUE return
#define E_WARNING 2
#define INI_INT(name) 0
#define VCWD_FOPEN(path, mode) fopen(path, mode)
#define PHP_GD_CHECK_OPEN_BASEDIR(fn, msg)

#define HAVE_GD_JPG
#define HAVE_GD_PNG

gdImagePtr gdImageCreateFromGif(FILE *fp);
gdImagePtr gdImageCreateFromJpegEx(FILE *fp, long ignore_warning);
gdImagePtr gdImageCreateFromPng(FILE *fp);
gdImagePtr gdImageCreate(int sx, int sy);
void gdImageDestroy(gdImagePtr im);
void gdImageCopyResized(gdImagePtr dst, gdImagePtr src, int dstX, int dstY, int srcX, int srcY, int dstW, int dstH, int srcW, int srcH);
int gdImageColorAllocate(gdImagePtr im, int r, int g, int b);
int gdImageGetPixel(gdImagePtr im, int x, int y);
void gdImageSetPixel(gdImagePtr im, int x, int y, int color);
void gdImageWBMP(gdImagePtr im, int fg, FILE *out);
void php_error_docref(const char *docref, int type, const char *format, ...);