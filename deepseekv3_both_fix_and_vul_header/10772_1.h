#include <stdint.h>
#include <string.h>
#include <inttypes.h>

typedef struct _post_var_data_t {
    struct {
        char *c;
        size_t len;
    } str;
    char *ptr;
    char *end;
    uint64_t cnt;
} post_var_data_t;

#define TSRMLS_DC
#define TSRMLS_CC
#define PG(x) (0)
#define SUCCESS 0
#define FAILURE (-1)
#define E_WARNING (0)
#define zend_bool int
#define zval void

static void php_error_docref(const char *docref TSRMLS_DC, int type, const char *format, ...);
static int add_post_var(zval *arr, post_var_data_t *vars, zend_bool eof TSRMLS_DC);