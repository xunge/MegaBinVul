#include <stddef.h>
#include <assert.h>

typedef struct _php_stream php_stream;
typedef struct _php_stream_temp_data php_stream_temp_data;

struct _php_stream {
    void *abstract;
    int eof;
};

struct _php_stream_temp_data {
    php_stream *innerstream;
};

#define TSRMLS_DC

size_t php_stream_read(php_stream *stream, char *buf, size_t count);