#include <string.h>

typedef struct _zend_class_entry {
    char *name;
    struct _zend_function_entry *function_table;
    void *get_iterator;
    void *create_object;
    int ce_flags;
    void *serialize;
} zend_class_entry;

typedef struct _zend_object_handlers {
    void *write_property;
    void *unset_property;
    void *get_method;
    void *compare_objects;
    void *clone_obj;
} zend_object_handlers;

typedef struct _zend_function_entry {
    char *fname;
    void *handler;
} zend_function_entry;

typedef struct _zend_object {
    zend_class_entry *ce;
} zend_object;

typedef struct _zval_struct {
    long lval;
} zval;

typedef struct _zend_literal {
    long dummy;
} zend_literal;

typedef struct _zend_object_iterator {
    long dummy;
} zend_object_iterator;

typedef union _zend_function {
    long dummy;
} zend_function;

typedef struct _zend_serialize_data {
    long dummy;
} zend_serialize_data;

#define TSRMLS_D void
#define TSRMLS_CC
#define ZEND_ACC_PUBLIC 0
#define ZEND_ACC_FINAL_CLASS 0

zend_class_entry *pdo_dbstmt_ce;
zend_class_entry *pdo_row_ce;
zend_class_entry *zend_ce_traversable;
zend_object_handlers pdo_dbstmt_object_handlers;
zend_object_handlers std_object_handlers;

zend_function_entry pdo_dbstmt_functions[1];
zend_function_entry pdo_row_functions[1];

#define INIT_CLASS_ENTRY(ce, classname, funcs) \
    do { (ce).name = (char*)classname; (ce).function_table = funcs; } while (0)

zend_class_entry *zend_register_internal_class(zend_class_entry *ce);
void zend_class_implements(zend_class_entry *ce, int num_interfaces, ...);
void zend_declare_property_null(zend_class_entry *ce, char *name, int name_length, int access_type);

zend_object *pdo_dbstmt_new(zend_class_entry *ce);
zend_object *pdo_row_new(zend_class_entry *ce);
zend_object_iterator *pdo_stmt_iter_get(zend_class_entry *ce, zval *object, int by_ref);
zend_function *dbstmt_method_get(zval *object, char *method, int method_len, const zend_literal *key);
int dbstmt_prop_write(zval *object, zval *member, zval *value, const zend_literal *key);
int dbstmt_prop_delete(zval *object, zval *member, const zend_literal *key);
int dbstmt_compare(zval *object1, zval *object2);
zend_object *dbstmt_clone_obj(zval *object);
int pdo_row_serialize(zval *object, unsigned char **buffer, size_t *buf_len, zend_serialize_data *data);