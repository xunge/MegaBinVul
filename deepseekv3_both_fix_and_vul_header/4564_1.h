#include <stdio.h>
#include <stdlib.h>

#define INTERNAL_FUNCTION_PARAMETERS int ht, void *return_value, void **return_value_ptr, void *this_ptr, int return_value_used
#define ZEND_NUM_ARGS() ht
#define TSRMLS_CC
#define TSRMLS_DC
#define FAILURE (-1)
#define RETURN_TRUE do { RETVAL_TRUE; return; } while (0)
#define RETURN_FALSE do { RETVAL_FALSE; return; } while (0)
#define RETVAL_TRUE ZVAL_TRUE(return_value)
#define RETVAL_FALSE ZVAL_FALSE(return_value)
#define ZVAL_TRUE(z) do { *(int*)(z) = 1; } while (0)
#define ZVAL_FALSE(z) do { *(int*)(z) = 0; } while (0)

#define HAVE_GD_JPG 1
#define HAVE_GD_GIF_READ 1
#define HAVE_GD_PNG 1
#define HAVE_GD_BUNDLED 1

#define PHP_GDIMG_TYPE_GIF 1
#define PHP_GDIMG_TYPE_JPG 2
#define PHP_GDIMG_TYPE_PNG 3

#define INI_INT(name) 0

#define PHP_GD_CHECK_OPEN_BASEDIR(path, message)
#define VCWD_FOPEN(path, mode) fopen(path, mode)
#define E_WARNING 2

typedef struct {
    unsigned char *red;
    unsigned char *green;
    unsigned char *blue;
    int sx;
    int sy;
} *gdImagePtr;

void php_error_docref(const char *docref, int type, const char *format, ...);
int zend_parse_parameters(int num_args, const char *type_spec, ...);

gdImagePtr gdImageCreate(int width, int height);
void gdImageDestroy(gdImagePtr im);
int gdImageColorAllocate(gdImagePtr im, int r, int g, int b);
void gdImageCopyResized(gdImagePtr dst, gdImagePtr src, int dstX, int dstY, int srcX, int srcY, int dstW, int dstH, int srcW, int srcH);
int gdImageGetPixel(gdImagePtr im, int x, int y);
void gdImageSetPixel(gdImagePtr im, int x, int y, int color);
void gdImageWBMP(gdImagePtr im, int fg, FILE *out);
int gdImageSX(gdImagePtr im);
int gdImageSY(gdImagePtr im);