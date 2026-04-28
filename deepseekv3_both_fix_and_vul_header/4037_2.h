#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

#define UNEXPECTED(x) (x)
#define SW_HTTP_HEADER_KEY_SIZE 1024
#define SW_USE_HTTP2
#define ZEND_STRL(str) (str), (sizeof(str)-1)
#define E_WARNING 2

typedef struct {
    void *zobject;
    void *zheader;
} http_response_property;

typedef struct {
    bool http2;
    http_response_property response;
} http_context;

typedef struct _zval_struct zval;

extern void php_swoole_error(int level, const char *message);
extern zval *swoole_http_init_and_read_property(void *ce, void *zobject, void **property, const char *name, size_t name_len);
extern void swoole_strtolower(char *str, size_t len);
extern void http_header_key_format(char *key, size_t length);
extern void add_assoc_null_ex(zval *arg, const char *key, size_t key_len);
extern void add_assoc_stringl_ex(zval *arg, const char *key, size_t key_len, char *str, size_t length);

extern void *swoole_http_response_ce;