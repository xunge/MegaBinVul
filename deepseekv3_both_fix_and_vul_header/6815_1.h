#include <sys/types.h>
#include <assert.h>
#include <stddef.h>

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

off_t php_stream_seek(php_stream *stream, off_t offset, int whence);
off_t php_stream_tell(php_stream *stream);