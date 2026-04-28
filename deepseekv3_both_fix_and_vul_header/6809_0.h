#include <stdlib.h>
#include <stdio.h>

typedef struct _php_stream_memory_data {
    void *data;
    size_t fpos;
    size_t fsize;
    size_t smax;
    int mode;
} php_stream_memory_data;

typedef struct _php_stream {
    int flags;
} php_stream;

#define PHPAPI
#define STREAMS_DC
#define TSRMLS_DC
#define TEMP_STREAM_READONLY 1
#define PHP_STREAM_FLAG_NO_BUFFER (1<<0)

extern php_stream *php_stream_alloc_rel(void *ops, void *data, int persistent, const char *mode);
extern void *emalloc(size_t size);

static const void *php_stream_memory_ops;