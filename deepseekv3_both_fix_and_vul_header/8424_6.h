#include <string.h>

typedef char XML_Char;

/* Forward declarations */
typedef struct _HashTable HashTable;
typedef struct _zend_class_entry zend_class_entry;
typedef struct _zend_string zend_string;

typedef union _zend_value {
    long lval;
    double dval;
    struct {
        char *val;
        size_t len;
    } str;
    struct {
        HashTable *ptr;
    } arr;
    struct {
        void *ptr;
        zend_class_entry *ce;
        HashTable *properties;
    } obj;
} zend_value;

typedef struct _zval_struct {
    zend_value value;
    union {
        struct {
            unsigned char type;
        } v;
    } u1;
} zval;

struct _zend_string {
    size_t len;
    char val[1];
};

struct _zend_class_entry {
    char *name;
};

struct _HashTable {
    unsigned int nTableSize;
    void *pInternalPointer;
    void *pListHead;
    void *pListTail;
    unsigned int nNumOfElements;
    unsigned int nTableMask;
    unsigned int nNextFreeElement;
    void *pDestructor;
    void *arBuckets;
};

typedef struct _st_entry {
    int type;
    zval data;
    char *varname;
} st_entry;

typedef struct _wddx_stack {
    int top;
    int done;
    char *varname;
    st_entry *elements;
} wddx_stack;

typedef unsigned char zend_bool;

struct _zend_executor_globals {
    HashTable *class_table;
    zend_class_entry *scope;
};

static struct _zend_executor_globals executor_globals;
#define EG(v) (executor_globals.v)

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

#define PHP_CLASS_NAME_VAR "php_class_name"
#define PHP_IC_ENTRY ((zend_class_entry *)0)

#define IS_UNDEF 0
#define IS_NULL 1
#define IS_FALSE 2
#define IS_TRUE 3
#define IS_LONG 4
#define IS_DOUBLE 5
#define IS_STRING 6
#define IS_ARRAY 7
#define IS_OBJECT 8
#define IS_RESOURCE 9
#define IS_REFERENCE 10

#define Z_TYPE(zval) ((zval).u1.v.type)
#define Z_STRVAL(zval) ((zval).value.str.val)
#define Z_STRLEN(zval) ((zval).value.str.len)
#define Z_STR(zval) ((zend_string*)&(zval).value.str)
#define Z_ARRVAL(zval) ((zval).value.arr.ptr)
#define Z_OBJPROP(zval) ((zval).value.obj.properties)
#define Z_OBJCE(zval) ((zval).value.obj.ce)
#define Z_ISUNDEF(zval) (Z_TYPE(zval) == IS_UNDEF)
#define Z_REFCOUNTED(zval) (0)
#define Z_DELREF(zval) (void)(0)

#define HASH_OF(zval) (Z_TYPE(*(zval)) == IS_ARRAY ? Z_ARRVAL(*(zval)) : Z_OBJPROP(*(zval)))

static void (*zval_add_ref)(void*) = NULL;

static void wddx_stack_top(wddx_stack *stack, void **ent) {}
static void efree(void *ptr) {}
static void zval_ptr_dtor(zval *zval_ptr) {}
static void ZVAL_STR(zval *zval_ptr, zend_string *str) {}
static void ZVAL_STRING(zval *zval_ptr, const char *str) {}
static void call_user_function_ex(void *a, zval *b, zval *c, zval *d, int e, int f, int g, void *h) {}
static zend_string *php_base64_decode(const unsigned char *str, size_t len) { return NULL; }
static void zend_str_tolower(char *str, size_t len) {}
static void zend_string_forget_hash_val(zend_string *str) {}
static zend_class_entry *zend_hash_find_ptr(HashTable *ht, zend_string *key) { return NULL; }
static void object_init_ex(zval *obj, zend_class_entry *ce) {}
static void zend_hash_merge(HashTable *target, HashTable *source, void (*pCopyConstructor)(void *), int overwrite) {}
static void php_store_class_name(zval *obj, const char *name, size_t len) {}
static void ZVAL_COPY_VALUE(zval *dst, zval *src) {}
static void add_property_zval(zval *obj, const char *name, zval *value) {}
static void zend_symtable_str_update(HashTable *ht, const char *key, size_t len, zval *pData) {}
static void zend_hash_next_index_insert(HashTable *ht, zval *pData) {}