#include <string.h>
#include <stdlib.h>

typedef char XML_Char;

typedef struct _zval {
    int type;
    char *str_val;
    long long_val;
    size_t str_len;
} zval;

typedef struct _st_entry {
    int type;
    zval *data;
    char *varname;
} st_entry;

typedef struct _wddx_stack {
    int done;
} wddx_stack;

#define ST_STRING 0
#define ST_BINARY 1
#define ST_NUMBER 2
#define ST_BOOLEAN 3
#define ST_DATETIME 4

#define IS_STRING 1

#define TSRMLS_FETCH()
#define TSRMLS_CC

#define Z_STRLEN_P(z) ((z)->str_len)
#define Z_STRVAL_P(z) ((z)->str_val)
#define Z_TYPE_P(z) ((z)->type)
#define Z_LVAL_P(z) ((z)->long_val)

#define STR_FREE(ptr) free(ptr)

static char *estrndup(const char *s, size_t len) { return NULL; }
static void *erealloc(void *ptr, size_t size) { return NULL; }
static void zval_ptr_dtor(zval **zval_ptr) {}
static long php_parse_date(const char *date, void *timeptr) { return 0; }
static void convert_scalar_to_number(zval *data) {}
static void *emalloc(size_t size) { return NULL; }
static void efree(void *ptr) {}

static int wddx_stack_is_empty(wddx_stack *stack) { return 0; }
static void wddx_stack_top(wddx_stack *stack, void **entry) {}