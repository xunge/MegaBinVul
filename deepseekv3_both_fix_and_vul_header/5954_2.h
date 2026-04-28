#include <stdint.h>
#include <stddef.h>

typedef int zend_bool;
typedef struct _zval_struct zval;
typedef struct _zend_class_entry zend_class_entry;

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define TSRMLS_DC
#define TSRMLS_CC
#define RETURN_FALSE return
#define RETURN_BOOL(b) return
#define RETVAL_FALSE
#define RETVAL_BOOL(b)
#define Z_TYPE_P(z) 0
#define Z_STRVAL_P(z) NULL
#define Z_STRLEN_P(z) 0
#define Z_OBJCE_P(z) NULL
#define Z_BVAL_P(z) 0
#define IS_STRING 0
#define IS_OBJECT 0
#define IS_BOOL 0
#define FAILURE -1
#define HAS_CLASS_ENTRY(z) 0

static int zend_parse_parameters(int num_args, const char *type_spec, ...) { return 0; }
static int zend_lookup_class(const char *name, int len, zend_class_entry ***ce) { return 0; }
static int zend_lookup_class_ex(const char *name, int len, const char *key, int key_len, zend_class_entry ***ce) { return 0; }
static zend_bool instanceof_function(zend_class_entry *ce1, zend_class_entry *ce2) { return 0; }
#define ZEND_NUM_ARGS() 0