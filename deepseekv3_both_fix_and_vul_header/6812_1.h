#include <stddef.h>
#include <assert.h>

struct _php_stream {
    void *abstract;
};

struct _php_stream_memory_data {
    char *data;
    size_t fsize;
};

typedef struct _php_stream php_stream;
typedef struct _php_stream_memory_data php_stream_memory_data;

#define PHPAPI
#define STREAMS_DC
#define TSRMLS_DC
#define TEMP_STREAM_READONLY 0
#define TEMP_STREAM_TAKE_BUFFER 1

php_stream *php_stream_memory_create_rel(int mode);
size_t php_stream_write(php_stream *stream, char *buf, size_t length);