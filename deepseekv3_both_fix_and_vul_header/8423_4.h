#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char XML_Char;

typedef struct _zval {
    int type;
    char *value;
    int len;
} zval;

typedef struct _HashTable {
    void *dummy;
} HashTable;

typedef struct _zend_class_entry {
    void *dummy;
} zend_class_entry;

typedef struct _st_entry {
    int type;
    char *varname;
    zval *data;
} st_entry;

typedef struct _wddx_stack {
    int top;
    int done;
    char *varname;
} wddx_stack;

typedef struct _zend_executor_globals {
    zend_class_entry *scope;
    HashTable *class_table;
} zend_executor_globals;

static zend_executor_globals executor_globals;
#define EG(v) (executor_globals.v)

typedef bool zend_bool;

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

#define ST_FIELD 1
#define ST_STRUCT 2

#define PHP_CLASS_NAME_VAR "PHP_CLASS_NAME"
static zend_class_entry *PHP_IC_ENTRY = NULL;

#define IS_OBJECT 7
#define IS_ARRAY 6
#define IS_STRING 3
#define FAILURE -1

#define TSRMLS_FETCH()
#define TSRMLS_CC
#define MAKE_STD_ZVAL(zv) ((zv) = malloc(sizeof(zval)))
#define FREE_ZVAL(zv) free(zv)
#define STR_FREE(s) free(s)
#define ZVAL_EMPTY_STRING(zv) do { (zv)->value = NULL; (zv)->len = 0; } while(0)
#define ZVAL_STRING(zv, s, dup) do { (zv)->value = strdup(s); (zv)->len = strlen(s); } while(0)
#define Z_STRLEN_P(zv) ((zv)->len)
#define Z_STRVAL_P(zv) ((zv)->value)
#define Z_TYPE_P(zv) ((zv)->type)
#define Z_OBJPROP_P(zv) NULL
#define Z_OBJCE_P(zv) NULL
#define Z_DELREF_P(zv)
#define Z_ARRVAL_P(zv) NULL
#define HASH_OF(zv) NULL

static void wddx_stack_top(wddx_stack *stack, void **ent) {}
static void efree(void *ptr) { free(ptr); }
static void zval_ptr_dtor(zval **zv) {}
static void zval_dtor(zval *zv) {}
static void zval_add_ref(zval *zv) {}
static unsigned char *php_base64_decode(const char *s, int l, int *nl) { return NULL; }
static void zend_str_tolower(char *s, int l) {}
static void php_store_class_name(zval *o, const char *s, int l) {}
static void object_init_ex(zval *o, zend_class_entry *ce) {}
static void call_user_function_ex(void *a, void *b, void *c, void *d, int e, int f, int g, void *h) {}
static void zend_hash_merge(HashTable *ht1, HashTable *ht2, void (*cp)(void*), void *tmp, size_t sz, int f) {}
static void zend_hash_next_index_insert(HashTable *ht, void *d, size_t s, void *p) {}
static void zend_symtable_update(HashTable *ht, const char *k, size_t kl, void *d, size_t s, void *p) {}
static void add_property_zval(zval *o, const char *k, zval *v) {}
static int zend_hash_find(HashTable *ht, const char *k, size_t kl, void **p) { return FAILURE; }