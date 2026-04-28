#include <string.h>
#include <stdlib.h>

typedef struct _zend_string {
    char *val;
    size_t len;
} zend_string;

typedef struct _zval_struct {
    zend_string *str;
} zval;

static const char hexchars[] = "0123456789ABCDEF";

#define Z_STRLEN_P(zval_p) ((zval_p)->str->len)
#define Z_STRVAL_P(zval_p) ((zval_p)->str->val)
#define ZSTR_VAL(str) ((str)->val)
#define ZSTR_LEN(str) ((str)->len)
#define ZVAL_NEW_STR(zval_p, str) do { (zval_p)->str = str; } while (0)
#define zval_ptr_dtor(zval_p) free((zval_p)->str)

zend_string *zend_string_alloc(size_t len, int persistent) {
    zend_string *str = malloc(sizeof(zend_string) + len + 1);
    str->val = (char*)(str + 1);
    str->len = len;
    return str;
}