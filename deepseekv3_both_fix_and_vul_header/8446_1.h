#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _zval_struct {
    int type;
    union {
        long lval;
        double dval;
        struct {
            char *val;
            int len;
        } str;
    } value;
} zval;

typedef struct _spl_array_object {
    void *dummy;
} spl_array_object;

typedef struct _HashTable {
    unsigned int nApplyCount;
} HashTable;

#define TSRMLS_DC
#define TSRMLS_CC
#define EG(e) e
#define BP_VAR_R 0
#define BP_VAR_W 1
#define BP_VAR_RW 2
#define BP_VAR_UNSET 3
#define BP_VAR_IS 4
#define Z_TYPE_P(zval_p) (zval_p)->type
#define Z_STRVAL_P(zval_p) (zval_p)->value.str.val
#define Z_STRLEN_P(zval_p) (zval_p)->value.str.len
#define Z_LVAL_P(zval_p) (zval_p)->value.lval
#define Z_DVAL_P(zval_p) (zval_p)->value.dval
#define ALLOC_INIT_ZVAL(z) memset(&(z), 0, sizeof(zval))
#define IS_STRING 0
#define IS_NULL 1
#define IS_RESOURCE 2
#define IS_DOUBLE 3
#define IS_BOOL 4
#define IS_LONG 5
#define FAILURE -1
#define E_WARNING 0
#define E_NOTICE 0
#define E_STRICT 0

static zval *uninitialized_zval_ptr;
static zval *error_zval_ptr;

static void *zend_object_store_get_object(zval *obj TSRMLS_DC) {
    return NULL;
}

static HashTable *spl_array_get_hash_table(spl_array_object *intern, int dummy TSRMLS_DC) {
    return NULL;
}

static int zend_symtable_find(HashTable *ht, char *key, uint len, void **retval) {
    return FAILURE;
}

static void zend_symtable_update(HashTable *ht, char *key, uint len, void **value, size_t size, void **retval) {
}

static int zend_hash_index_find(HashTable *ht, long index, void **retval) {
    return FAILURE;
}

static void zend_hash_index_update(HashTable *ht, long index, void **value, size_t size, void **retval) {
}

static void zend_error(int type, const char *format, ...) {
}