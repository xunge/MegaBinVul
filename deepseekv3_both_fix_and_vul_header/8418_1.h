#include <stddef.h>

#define UNSERIALIZE_PARAMETER zval **rval, const unsigned char **p, const unsigned char *max, php_unserialize_data_t *var_hash
#define E_WARNING 2

typedef struct _zend_class_entry {
    char *name;
    void *serialize;
} zend_class_entry;

typedef struct _zval_struct zval;
typedef struct php_unserialize_data_t php_unserialize_data_t;

static long parse_iv2(const unsigned char *p, const unsigned char **q);
static void object_init_ex(zval *object, zend_class_entry *ce);
static void zend_error(int type, const char *format, ...);