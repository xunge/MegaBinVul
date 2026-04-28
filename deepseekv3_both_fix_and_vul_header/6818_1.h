#include <assert.h>
#include <stdlib.h>

typedef struct _php_stream {
    void *abstract;
} php_stream;

typedef struct _php_stream_temp_data {
    php_stream *innerstream;
    void *meta;
} php_stream_temp_data;

#define TSRMLS_DC
#define PHP_STREAM_FREE_CLOSE 0
#define PHP_STREAM_FREE_PRESERVE_HANDLE 0

int php_stream_free_enclosed(php_stream *stream, int options);
void efree(void *ptr);
void zval_ptr_dtor(void *zval_ptr);