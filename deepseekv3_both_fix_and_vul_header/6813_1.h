#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <assert.h>

typedef struct _php_stream {
    char mode[16];
    const struct _php_stream_ops *ops;
    void *abstract;
} php_stream;

typedef struct _php_stream_temp_data {
    int mode;
    void *meta;
} php_stream_temp_data;

typedef struct _php_stream_wrapper php_stream_wrapper;
typedef struct _php_stream_context php_stream_context;
typedef struct _zval {
    // Minimal zval structure
    int type;
    void *value;
} zval;

#define STREAMS_DC
#define TSRMLS_DC
#define TSRMLS_CC

#define MAKE_STD_ZVAL(zv) do { \
    zv = malloc(sizeof(zval)); \
    zv->type = 0; \
    zv->value = NULL; \
} while (0)

#define array_init(zv) do { \
    zv->type = 1; \
    zv->value = malloc(16); \
} while (0)

#define add_assoc_stringl(zv, key, str, len, dup) do { \
    /* Implementation stub */ \
} while (0)

#define add_assoc_stringl_ex(zv, key, key_len, str, len, dup) do { \
    /* Implementation stub */ \
} while (0)

#define add_assoc_bool(zv, key, val) do { \
    /* Implementation stub */ \
} while (0)

#define zval_ptr_dtor(zv) do { \
    free(zv->value); \
    free(zv); \
} while (0)

#define estrndup(str, len) strndup(str, len)
#define efree(ptr) free(ptr)

#define php_stream_wrapper_log_error(wrapper, options, ...)
#define php_base64_decode(str, len, outlen) NULL
#define php_url_decode(str, len) len
#define php_stream_temp_create_rel(mode, max_memory) NULL
#define php_stream_temp_write(stream, buf, len)
#define php_stream_temp_seek(stream, offset, whence, newoffs)
#define TEMP_STREAM_READONLY 0

struct _php_stream_ops {
    // Minimal ops structure
};
const struct _php_stream_ops php_stream_rfc2397_ops;