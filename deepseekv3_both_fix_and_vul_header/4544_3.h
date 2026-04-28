#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void zval;
typedef struct _gdImage gdImage;
typedef gdImage* gdImagePtr;

struct _gdIOCtx {
    void (*free)(struct _gdIOCtx*);
    void (*gd_free)(struct _gdIOCtx*);
};
typedef struct _gdIOCtx gdIOCtx;

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define TSRMLS_CC 
#define ZEND_NUM_ARGS() ht
#define FAILURE (-1)
#define SUCCESS 0
#define PHP_GDIMG_TYPE_GD2PART 1
#define PHP_GDIMG_TYPE_WEBP 2
#define PHP_GDIMG_TYPE_JPG 3
#define PHP_GDIMG_TYPE_XPM 4
#define REPORT_ERRORS 0
#define IGNORE_PATH 0
#define IGNORE_URL_WIN 0
#define PHP_STREAM_COPY_ALL 0
#define PHP_STREAM_IS_STDIO 0
#define PHP_STREAM_AS_STDIO 0
#define PHP_STREAM_CAST_TRY_HARD 0
#define USE_GD_IOCTX 1
#define HAVE_GD_JPG 1
#define HAVE_GD_BUNDLED 1
#define HAVE_LIBGD204 0
#define HAVE_GD_XPM 1
#define INI_INT(x) 0
#define E_WARNING 2
#define RETURN_FALSE return
#define ZEND_REGISTER_RESOURCE(return_value, im, le_gd) 

typedef struct _php_stream php_stream;

php_stream* php_stream_open_wrapper(const char *path, const char *mode, int options, char **opened_path);
int php_stream_is(php_stream *stream, int is_type);
int php_stream_cast(php_stream *stream, int castas, void **ret, int options);
size_t php_stream_copy_to_mem(php_stream *stream, char **buf, size_t maxlen, int persistent);
void php_stream_close(php_stream *stream);
void pefree(void *ptr, int persistent);
void php_error_docref(const char *docref, int type, const char *format, ...);
int zend_parse_parameters(int num_args, const char *type_spec, ...);

gdIOCtx* gdNewDynamicCtxEx(int size, void *data, int free_flag);
gdImagePtr gdImageCreateFromXpm(char *filename);
gdImagePtr gdImageCreateFromJpeg(FILE *fp, int ignore_warning);