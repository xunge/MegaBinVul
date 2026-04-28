#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define UNEXPECTED(condition) (condition)
#define SW_HTTP_HEADER_KEY_SIZE 1024
#define SW_USE_HTTP2
#define E_WARNING 2

typedef struct _zval_struct zval;

typedef struct http_context {
    struct {
        zval *zobject;
        zval *zheader;
    } response;
    bool http2;
} http_context;

extern void php_swoole_error(int level, const char *message);
extern zval *swoole_http_init_and_read_property(void *ce, zval *zobject, zval **property, const char *str, size_t len);
extern void swoole_strtolower(char *str, size_t len);
extern void http_header_key_format(char *str, size_t len);
extern void add_assoc_null_ex(zval *arg, const char *key, size_t key_len);
extern void add_assoc_stringl_ex(zval *arg, const char *key, size_t key_len, char *str, size_t str_len);

#define ZEND_STRL(str) (str), (sizeof(str)-1)

extern void *swoole_http_response_ce;