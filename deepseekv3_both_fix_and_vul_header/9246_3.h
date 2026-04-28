#include <stddef.h>

typedef union _zvalue_value {
    long lval;
    double dval;
    struct {
        struct _zend_object *obj;
        struct _zend_object_handlers *handlers;
        struct _zend_class_entry *ce;
    } obj;
} zvalue_value;

typedef struct _zval_struct {
    zvalue_value value;
    unsigned char type;
} zval;

typedef struct _zend_class_entry {
    char *name;
} zend_class_entry;

typedef struct _HashTable HashTable;

typedef struct _zend_object {
    zend_class_entry *ce;
} zend_object;

typedef struct _zend_object_handlers {
    HashTable* (*get_properties)(zval *object);
} zend_object_handlers;

typedef struct _spl_array_object {
    zend_object std;
    zval *array;
    long ar_flags;
} spl_array_object;

typedef HashTable* (*zend_object_get_properties_t)(zval *object);

#define TSRMLS_DC
#define TSRMLS_CC
#define SEPARATE_ZVAL_IF_NOT_REF(zv)
#define Z_ADDREF_P(zv)
#define Z_TYPE_PP(ppzv) ((*(ppzv))->type)
#define Z_OBJ_HT_PP(ppzv) ((*(ppzv))->value.obj.handlers)
#define Z_OBJ_HANDLER_PP(ppzv, h) (Z_OBJ_HT_PP(ppzv)->h)
#define Z_OBJCE_PP(ppzv) ((*(ppzv))->value.obj.ce)

#define IS_ARRAY 7
#define IS_OBJECT 8
#define SPL_ARRAY_INT_MASK 0x0000ffff
#define SPL_ARRAY_USE_OTHER 0x00010000
#define SPL_ARRAY_IS_SELF 0x00020000

extern zend_object_handlers std_object_handlers;
extern zend_class_entry *spl_ce_InvalidArgumentException;
extern zend_object_handlers spl_handler_ArrayObject;
extern zend_object_handlers spl_handler_ArrayIterator;
extern zend_object *(*zend_object_store_get_object)(zval *object);
extern HashTable* (*spl_array_get_properties)(zval *object);
extern HashTable *(*spl_array_get_hash_table)(spl_array_object *intern, int check);
extern void spl_array_rewind(spl_array_object *intern);
extern void zend_throw_exception(zend_class_entry *exception_ce, const char *message, int code);
extern void zend_throw_exception_ex(zend_class_entry *exception_ce, int code, const char *format, ...);
extern void zval_ptr_dtor(zval **zval_ptr);