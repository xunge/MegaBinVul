#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef char XML_Char;

typedef struct _zval {
    int type;
    char *strval;
    size_t strlen;
    long lval;
} zval;

typedef struct _st_entry {
    int type;
    zval *data;
    char *varname;
} st_entry;

typedef struct _wddx_stack {
    int top;
    int done;
    st_entry *entries;
} wddx_stack;

#define ST_STRING 1
#define ST_BINARY 2
#define ST_NUMBER 3
#define ST_BOOLEAN 4
#define ST_DATETIME 5
#define IS_STRING 6

#define Z_TYPE_P(pzval) ((pzval)->type)
#define Z_STRLEN_P(pzval) ((pzval)->strlen)
#define Z_STRVAL_P(pzval) ((pzval)->strval)
#define Z_LVAL_P(pzval) ((pzval)->lval)

#define TSRMLS_FETCH()
#define TSRMLS_CC

#define STR_FREE(p) free(p)
#define estrndup(s, len) strndup((const char *)s, len)
#define erealloc(p, size) realloc(p, size)
#define efree(p) free(p)
#define emalloc(size) malloc(size)

int wddx_stack_is_empty(wddx_stack *stack);
void wddx_stack_top(wddx_stack *stack, void **ent);
void convert_scalar_to_number(zval *data);
void zval_ptr_dtor(zval **pzval);
time_t php_parse_date(const char *date, char **error);