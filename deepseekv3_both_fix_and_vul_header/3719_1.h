#include <stdlib.h>
#include <stdint.h>

typedef union _zvalue_value {
    long lval;
    void *ptr;
    struct {
        void *val;
        uint32_t len;
    } str;
    struct _hashtable *ht;
} zvalue_value;

typedef struct _zval_struct {
    zvalue_value value;
    uint8_t type;
    uint8_t is_ref;
    uint16_t refcount;
} zval;

typedef struct _hashtable {
    uint32_t nTableSize;
    uint32_t nTableMask;
    uint32_t nNumOfElements;
    uint32_t nNextFreeElement;
    void *pInternalPointer;
    void *pListHead;
    void *pListTail;
    void **arBuckets;
} HashTable;

typedef void (*copy_ctor_func_t)(void *);

typedef struct _zend_object_value {
    void *handle;
    void *handlers;
} zend_object_value;

typedef struct _zend_object_handlers {
    void *dummy;
} zend_object_handlers;

typedef struct _zend_property_info {
    void *dummy;
} zend_property_info;

typedef struct _zend_class_entry {
    void *dummy;
} zend_class_entry;

typedef struct _php_unserialize_data_t {
    void *dummy;
} php_unserialize_data_t;

typedef struct _spl_array_object {
    zval *array;
    long ar_flags;
    struct {
        zend_object_value value;
        zend_object_handlers *handlers;
        HashTable *properties;
        zval **properties_table;
        zend_property_info **property_info;
    } std;
} spl_array_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define ALLOC_INIT_ZVAL(z) do { \
    (z) = (zval *)malloc(sizeof(zval)); \
    (z)->type = 0; \
    (z)->is_ref = 0; \
    (z)->refcount = 1; \
} while (0)

#define Z_TYPE_P(z) ((z)->type)
#define Z_LVAL_P(z) ((z)->value.lval)
#define Z_ARRVAL_P(z) ((z)->value.ht)
#define IS_NULL 0
#define IS_LONG 1
#define IS_ARRAY 7

#define SPL_ARRAY_CLONE_MASK 0x00000001

extern void zval_ptr_dtor(zval **zval_ptr);
extern int php_var_unserialize(zval **rval, const unsigned char **p, const unsigned char *max, php_unserialize_data_t *var_hash TSRMLS_DC);
extern void zend_hash_copy(HashTable *target, HashTable *source, copy_ctor_func_t pCopyConstructor, void *tmp, uint32_t size);
extern void zval_add_ref(zval *z);
extern void zend_throw_exception_ex(zend_class_entry *exception_ce, long code TSRMLS_DC, const char *format, ...);

extern zend_class_entry *spl_ce_UnexpectedValueException;