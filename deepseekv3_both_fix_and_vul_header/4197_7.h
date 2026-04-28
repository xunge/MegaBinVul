#include <string.h>
#include <stdlib.h>

typedef struct _st_entry {
    int type;
    struct _zval *data;
    char *varname;
} st_entry;

typedef struct _wddx_stack {
    int top;
    int done;
    char *varname;
} wddx_stack;

typedef struct _zval {
    int type;
    union {
        long lval;
        double dval;
        struct {
            char *val;
            int len;
        } str;
        struct _HashTable *ht;
        struct _zend_class_entry *ce;
    } value;
} zval;

typedef struct _HashTable {
    int dummy;
} HashTable;

typedef struct _zend_class_entry {
    int dummy;
} zend_class_entry;

typedef int zend_bool;

#define ST_FIELD 1
#define ST_STRUCT 2

#define EL_STRING "string"
#define EL_NUMBER "number"
#define EL_BOOLEAN "boolean"
#define EL_NULL "null"
#define EL_ARRAY "array"
#define EL_STRUCT "struct"
#define EL_RECORDSET "recordset"
#define EL_BINARY "binary"
#define EL_DATETIME "datetime"
#define EL_VAR "var"
#define EL_FIELD "field"

#define PHP_CLASS_NAME_VAR "PHP_CLASS_NAME"
static zend_class_entry *PHP_IC_ENTRY = NULL;

#define TSRMLS_FETCH()
#define TSRMLS_CC

#define IS_OBJECT 7
#define IS_ARRAY 8
#define IS_STRING 6
#define FAILURE -1

typedef char XML_Char;

#define Z_STRVAL_P(z) ((z)->value.str.val)
#define Z_STRLEN_P(z) ((z)->value.str.len)
#define Z_TYPE_P(z) ((z)->type)
#define Z_OBJPROP_P(z) ((z)->value.ht)
#define Z_ARRVAL_P(z) ((z)->value.ht)
#define Z_OBJCE_P(z) ((z)->value.ce)

static zend_class_entry **EG_scope = NULL;
#define EG(scope) (EG_scope)

static void wddx_stack_top(wddx_stack *stack, void **entry) {}
static unsigned char *php_base64_decode(const char *str, int length, int *ret_len) { return NULL; }
static void STR_FREE(void *ptr) {}
static void ZVAL_STRING(zval *z, const char *str, int dup) {}
static void MAKE_STD_ZVAL(zval *z) {}
static void call_user_function_ex(void *a, void *b, zval *c, zval **d, int e, int f, int g, void *h) {}
static void zval_dtor(zval *z) {}
static void FREE_ZVAL(zval *z) {}
static void zval_ptr_dtor(zval **z) {}
static void efree(void *ptr) {}
static void zend_str_tolower(char *str, int len) {}
static int zend_hash_find(void *ht, const char *key, int len, void **pData) { return 0; }
static void object_init_ex(zval *obj, zend_class_entry *ce) {}
static void zend_hash_merge(void *target, void *source, void (*pCopyConstructor)(void *), void *tmp, int size, int overwrite) {}
static void php_store_class_name(zval *obj, const char *name, int len) {}
static void Z_DELREF_P(zval *z) {}
static void add_property_zval(zval *obj, const char *name, zval *value) {}
static void zend_symtable_update(void *ht, const char *key, int len, void **pData, int size, void *pDest) {}
static void zend_hash_next_index_insert(void *ht, void **pData, int size, void *pDest) {}
static HashTable *HASH_OF(void *data) { return NULL; }
static void zval_add_ref(void *z) {}