#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPATHLEN 4096
#define TSRMLS_DC
#define TSRMLS_CC
#define SUCCESS 0

typedef struct _zval {
    int type;
    long lval;
    char *strval;
    int strlen;
} zval;

#define Z_TYPE_PP(ppzval) ((*ppzval)->type)
#define Z_LVAL_PP(ppzval) ((*ppzval)->lval)
#define Z_LVAL(zval) (zval.lval)
#define Z_STRVAL_PP(ppzval) ((*ppzval)->strval)
#define Z_STRLEN_PP(ppzval) ((*ppzval)->strlen)

#define IS_LONG 1
#define IS_STRING 2

#define HASH_OF(arr) arr
#define php_error_docref(ref, level, ...) fprintf(stderr, __VA_ARGS__)
#define E_WARNING 1
#define E_NOTICE 2

static void zval_copy_ctor(zval *z) {
    if (z->type == IS_STRING) {
        z->strval = strdup(z->strval);
    }
}

static void convert_to_long(zval *z) {
    if (z->type == IS_STRING) {
        z->lval = atol(z->strval);
        z->type = IS_LONG;
    }
}

static int zend_hash_find(void *ht, const char *key, size_t key_len, void **result) {
    return SUCCESS;
}