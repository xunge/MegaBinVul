#include <string.h>
#include <stdlib.h>

typedef char XML_Char;

typedef struct _zval {
    int type;
    char *value;
    int len;
} zval;

typedef struct _st_entry {
    zval *data;
    char *varname;
    int type;
} st_entry;

typedef struct _wddx_stack {
    st_entry *elements;
    int top;
    int done;
    char *varname;
} wddx_stack;

typedef struct _zend_class_entry {
    void *serialize;
    void *unserialize;
} zend_class_entry;

typedef struct _zend_executor_globals {
    void *class_table;
    zend_class_entry *scope;
} zend_executor_globals;

extern zend_executor_globals executor_globals;
#define EG(v) (executor_globals.v)

static zend_class_entry PHP_IC_ENTRY;
static zend_class_entry *PHP_IC_ENTRY_PTR = &PHP_IC_ENTRY;

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

#define PHP_CLASS_NAME_VAR "PHP_CLASS_NAME_VAR"
#define ST_STRUCT 1
#define E_WARNING 2

#define TSRMLS_FETCH()
#define TSRMLS_CC

#define STR_FREE(x) free(x)
#define MAKE_STD_ZVAL(zv) do { zv = malloc(sizeof(zval)); } while(0)
#define FREE_ZVAL(zv) free(zv)
#define ZVAL_STRING(z, s, dup) do { Z_STRVAL_P(z) = (dup ? strdup(s) : (s)); Z_STRLEN_P(z) = strlen(s); } while(0)
#define ZVAL_EMPTY_STRING(z) do { Z_STRVAL_P(z) = strdup(""); Z_STRLEN_P(z) = 0; } while(0)

#define Z_STRVAL_P(z) (z)->value
#define Z_STRLEN_P(z) (z)->len
#define Z_TYPE_P(z) (z)->type
#define Z_DELREF_P(z)
#define Z_OBJCE_P(z) NULL
#define Z_OBJPROP_P(z) NULL
#define Z_ARRVAL_P(z) NULL

#define IS_OBJECT 1
#define IS_ARRAY 2
#define IS_STRING 3

typedef struct _HashTable {
    // Hash table implementation
} HashTable;

#define HASH_OF(z) NULL

#define FAILURE -1
#define SUCCESS 0

typedef int zend_bool;

unsigned char *php_base64_decode(const char *input, int input_len, int *output_len);
void zend_str_tolower(char *str, size_t len);
int zend_hash_find(void *ht, const char *key, int key_len, void **result);
void zend_hash_merge(void *target, void *source, void (*copy)(void *), void *tmp, size_t size, int overwrite);
void zval_add_ref(zval **zv);
void php_store_class_name(zval *obj, const char *name, size_t name_len);
void add_property_zval(zval *obj, const char *name, zval *value);
void zend_hash_next_index_insert(void *ht, void *data, size_t size, void *dest);
void zend_symtable_update(void *ht, const char *key, int key_len, void *data, size_t size, void *dest);
void zval_ptr_dtor(zval **zv);
void zval_dtor(zval *zv);
void call_user_function_ex(void *a, void *b, void *c, void *d, int e, int f, int g, void *h);
void php_error_docref(void *ref, int type, const char *format, ...);
void object_init_ex(zval *obj, zend_class_entry *ce);
void efree(void *ptr);
void wddx_stack_top(wddx_stack *stack, void **entry);