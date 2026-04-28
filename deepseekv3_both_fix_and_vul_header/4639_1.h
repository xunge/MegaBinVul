#include <stddef.h>

typedef struct _zval_struct zval;
typedef struct _zend_class_entry zend_class_entry;

#define TSRMLS_DC
#define TSRMLS_CC
#define Z_TYPE_P(zval_p) (0)
#define Z_OBJCE_P(zval_p) (0)
#define Z_OBJ_HANDLE_P(zval_p) (0)
#define IS_OBJECT (0)
#define IS_NULL (0)
#define E_ERROR (0)
#define Z_DELREF_P(zval_p)

extern zend_class_entry *default_exception_ce;

int instanceof_function(zend_class_entry *ce1, zend_class_entry *ce2 TSRMLS_DC);
void zend_error(int type, const char *format, ...);
zval *zend_read_property(zend_class_entry *ce, zval *obj, const char *name, int name_length, int silent TSRMLS_DC);
void zend_update_property(zend_class_entry *ce, zval *obj, const char *name, int name_length, zval *value TSRMLS_DC);