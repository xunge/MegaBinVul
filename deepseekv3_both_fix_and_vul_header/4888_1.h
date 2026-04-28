#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _gdIOCtx {
    int (*putC)(struct _gdIOCtx *, int);
    int (*putBuf)(struct _gdIOCtx *, const void *, int);
    void (*gd_free)(struct _gdIOCtx *);
    void *data;
} gdIOCtx;

typedef struct _gdImage {
    int colorsTotal;
    int (*red)(struct _gdImage *, int);
    int (*green)(struct _gdImage *, int);
    int (*blue)(struct _gdImage *, int);
} *gdImagePtr;

typedef struct _zval {
    int type;
    char *strval;
} zval;

typedef struct _php_stream {
    // dummy stream structure
} php_stream;

#define PHP_GDIMG_TYPE_XBM 1
#define PHP_GDIMG_TYPE_GIF 2
#define PHP_GDIMG_TYPE_PNG 3
#define PHP_GDIMG_TYPE_JPG 4
#define PHP_GDIMG_TYPE_WBM 5
#define PHP_GDIMG_TYPE_WEBP 6
#define PHP_GDIMG_CONVERT_WBM 7

#define TSRMLS_CC
#define ZEND_NUM_ARGS() 0
#define FAILURE -1
#define RETURN_FALSE return
#define RETURN_TRUE return
#define IS_RESOURCE 1
#define IS_STRING 2
#define E_WARNING 1
#define REPORT_ERRORS 0
#define IGNORE_PATH 0
#define IGNORE_URL_WIN 0

static int _php_image_output_putc(gdIOCtx *ctx, int c) { return 0; }
static int _php_image_output_putbuf(gdIOCtx *ctx, const void *buf, int len) { return 0; }
static void _php_image_output_ctxfree(gdIOCtx *ctx) {}
static int _php_image_stream_putc(gdIOCtx *ctx, int c) { return 0; }
static int _php_image_stream_putbuf(gdIOCtx *ctx, const void *buf, int len) { return 0; }
static void _php_image_stream_ctxfree(gdIOCtx *ctx) {}

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define Z_TYPE_P(zval) ((zval)->type)
#define Z_STRVAL_P(zval) ((zval)->strval)
#define ZEND_FETCH_RESOURCE(ptr, type, zval, id, name, le) ptr = *(type*)(zval)
#define php_error_docref(a,b,c,...)
#define php_stream_from_zval_no_verify(stream, zval) stream = NULL
#define php_stream_open_wrapper(a,b,c,d) NULL
#define emalloc malloc