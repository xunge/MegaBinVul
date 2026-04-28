#include <stddef.h>

typedef struct _zend_class_entry {
    const char *name;
    size_t name_length;
    struct _zend_function_entry *function_table;
    void (*get_iterator)(struct _zend_class_entry *ce, void *object, int by_ref);
    void *(*create_object)(struct _zend_class_entry *ce);
    int ce_flags;
    void (*serialize)(void *object, unsigned char **buffer, size_t *buf_len, void *data);
    void (*unserialize)(void *object, void *ce);
} zend_class_entry;

typedef struct _zend_object_handlers {
    void (*write_property)(void *object, void *member, void *value, void **cache_slot);
    void (*unset_property)(void *object, void *member, void **cache_slot);
    void *(*get_method)(void *object, void *method, const void *key);
    int (*compare_objects)(void *object1, void *object2);
    void *(*clone_obj)(void *object);
} zend_object_handlers;

typedef struct _zend_function_entry {
    const char *fname;
    void (*handler)(void);
} zend_function_entry;

typedef struct _zend_object {
    zend_class_entry *ce;
} zend_object;

typedef struct _zend_object_iterator {
    void *data;
} zend_object_iterator;

typedef struct _zval_struct {
    long lval;
} zval;

typedef struct _zend_string {
    char *val;
} zend_string;

#define TSRMLS_D void
#define TSRMLS_CC
#define ZEND_ACC_PUBLIC 0x100
#define ZEND_ACC_FINAL_CLASS 0x20

zend_class_entry *pdo_dbstmt_ce;
zend_class_entry *pdo_row_ce;
zend_class_entry *zend_ce_traversable;
zend_object_handlers pdo_dbstmt_object_handlers;
zend_object_handlers std_object_handlers;
zend_function_entry pdo_dbstmt_functions[1];
zend_function_entry pdo_row_functions[1];

zend_object *pdo_dbstmt_new(zend_class_entry *ce);
zend_object *pdo_row_new(zend_class_entry *ce);
zend_object_iterator *pdo_stmt_iter_get(zend_class_entry *ce, zval *object, int by_ref);
int dbstmt_prop_write(zval *object, zval *member, zval *value, void **cache_slot);
int dbstmt_prop_delete(zval *object, zval *member, void **cache_slot);
void *dbstmt_method_get(zval *object, zend_string *method, const zval *key);
int dbstmt_compare(zval *object1, zval *object2);
zend_object *dbstmt_clone_obj(zval *object);
void pdo_row_serialize(zval *object, unsigned char **buffer, size_t *buf_len, void *data);
void zend_class_unserialize_deny(zval *object, zend_class_entry *ce);

void INIT_CLASS_ENTRY(zend_class_entry ce, const char *name, zend_function_entry *functions);
zend_class_entry *zend_register_internal_class(zend_class_entry *ce);
void zend_class_implements(zend_class_entry *ce, int num_interfaces, ...);
void zend_declare_property_null(zend_class_entry *ce, const char *name, size_t name_length, int flags);