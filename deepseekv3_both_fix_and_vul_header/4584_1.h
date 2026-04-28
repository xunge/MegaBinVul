#include <stddef.h>

typedef struct _zend_class_entry {
    int type;
    char *name;
    void *serialize;
    void *unserialize;
    void *create_object;
} zend_class_entry;

typedef struct _zval_struct zval;

#define UNSERIALIZE_PARAMETER zval **rval, const unsigned char **p, const unsigned char *max, size_t buf_len
#define ZEND_INTERNAL_CLASS 0
#define E_WARNING 2

static long parse_iv2(const unsigned char *p, const unsigned char **q);
void object_init_ex(zval *object, zend_class_entry *class_type);
void zend_error(int type, const char *format, ...);
int zend_user_unserialize(zval *object, zend_class_entry *ce, const unsigned char *buf, size_t buf_len, zval **rval);