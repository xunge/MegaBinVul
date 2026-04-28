#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct _http_context {
    struct {
        void *zobject;
        void *zcookie;
    } response;
} http_context;

#define INTERNAL_FUNCTION_PARAMETERS int ht, void *return_value, void **return_value_ptr, void *this_ptr, int return_value_used
#define ZEND_PARSE_PARAMETERS_START(min_num_args, max_num_args)
#define Z_PARAM_STRING(str, len)
#define Z_PARAM_OPTIONAL
#define Z_PARAM_LONG(l)
#define Z_PARAM_BOOL(b)
#define ZEND_PARSE_PARAMETERS_END_EX(ret)
#define UNEXPECTED(condition) (condition)
#define RETURN_FALSE
#define RETURN_TRUE
#define ZEND_THIS
#define ZEND_STRL(str) (str), sizeof(str)-1
#define E_WARNING 0
#define zend_long long
#define zend_bool bool
#define nullptr NULL
#define emalloc malloc
#define efree free
#define php_swoole_error(a, b)
#define php_swoole_url_encode(a, b, c) NULL
#define php_swoole_format_date(a, b, c) NULL
#define php_swoole_http_response_get_and_check_context(a) NULL
#define strlcat strncat
#define add_next_index_stringl(a, b, c)
#define swoole_http_init_and_read_property(a, b, c, d, e) NULL
#define swoole_http_response_ce NULL

static int http_has_crlf(const char *value, size_t len) { return 0; }
static void *zend_memrchr(const void *s, int c, size_t n) { return NULL; }