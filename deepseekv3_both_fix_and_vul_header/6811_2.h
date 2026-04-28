#include <stdlib.h>
#include <string.h>

#define TEMP_STREAM_READONLY 0x01
#define PHP_STREAM_OPTION_TRUNCATE_API 0
#define PHP_STREAM_TRUNCATE_SUPPORTED 0
#define PHP_STREAM_TRUNCATE_SET_SIZE 1
#define PHP_STREAM_OPTION_RETURN_OK 0
#define PHP_STREAM_OPTION_RETURN_ERR -1
#define PHP_STREAM_OPTION_RETURN_NOTIMPL -2

typedef struct _php_stream_memory_data {
    void *data;
    size_t fsize;
    size_t fpos;
    int mode;
} php_stream_memory_data;

typedef struct _php_stream {
    void *abstract;
} php_stream;

#define TSRMLS_DC
void *erealloc(void *ptr, size_t size);