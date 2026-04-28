#include <stdint.h>
#include <stdlib.h>

typedef struct _zval_struct {
    int type;
    union {
        char *strval;
        long lval;
        double dval;
    } value;
    size_t len;
} zval;

typedef struct _HashTable {
    unsigned int nApplyCount;
} HashTable;

typedef struct _spl_array_object {
    HashTable *ht;
} spl_array_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define EG(x) (x)
#define BP_VAR_R 0
#define BP_VAR_W 1
#define BP_VAR_RW 2
#define BP_VAR_UNSET 3
#define BP_VAR_IS 4
#define IS_STRING 0
#define IS_NULL 1
#define IS_RESOURCE 2
#define IS_DOUBLE 3
#define IS_BOOL 4
#define IS_LONG 5
#define FAILURE (-1)
#define E_WARNING 0
#define E_NOTICE 0
#define E_STRICT 0

#define Z_TYPE_P(x) (x)->type
#define Z_STRVAL_P(x) (x)->value.strval
#define Z_STRLEN_P(x) (x)->len
#define Z_LVAL_P(x) (x)->value.lval
#define Z_DVAL_P(x) (x)->value.dval

static zval *uninitialized_zval_ptr;
static zval *error_zval_ptr;

#define ALLOC_INIT_ZVAL(z) do { \
    z = malloc(sizeof(zval)); \
    if (z) { \
        z->type = IS_NULL; \
    } \
} while (0)