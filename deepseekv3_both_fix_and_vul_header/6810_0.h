#include <stdio.h>
#include <assert.h>
#include <sys/types.h>

typedef struct _php_stream php_stream;
typedef struct _php_stream_temp_data php_stream_temp_data;

#define TSRMLS_DC
#define FAILURE -1
#define SUCCESS 0
#define PHP_STREAM_IS_STDIO 1
#define PHP_STREAM_AS_STDIO 2
#define PHP_STREAM_FREE_CLOSE 1

struct _php_stream {
    void *abstract;
    php_stream *innerstream;
};

struct _php_stream_temp_data {
    php_stream *innerstream;
};

size_t php_stream_memory_get_buffer(php_stream *stream, size_t *memsize);
php_stream *php_stream_fopen_tmpfile(void);
int php_stream_write(php_stream *stream, const char *buf, size_t count);
off_t php_stream_tell(php_stream *stream);
void php_stream_free_enclosed(php_stream *stream, int options);
void php_stream_encloses(php_stream *outer, php_stream *inner);
int php_stream_seek(php_stream *stream, off_t offset, int whence);
int php_stream_cast(php_stream *stream, int castas, void **ret, int options);
int php_stream_is(php_stream *stream, int type);