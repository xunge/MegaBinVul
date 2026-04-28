#include <sys/stat.h>
#include <time.h>
#include <assert.h>
#include <string.h>

typedef struct _php_stream php_stream;
typedef struct _php_stream_statbuf php_stream_statbuf;
typedef struct _php_stream_memory_data php_stream_memory_data;

#define TEMP_STREAM_READONLY 0x0001

struct _php_stream_statbuf {
    struct stat sb;
};

struct _php_stream {
    void *abstract;
};

struct _php_stream_memory_data {
    int mode;
    size_t fsize;
};

#define TSRMLS_DC