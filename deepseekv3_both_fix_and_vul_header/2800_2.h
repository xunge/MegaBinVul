#include <stddef.h>

#define UNSERIALIZE_PARAMETER zval **rval, const unsigned char **p, const unsigned char *max, php_unserialize_data_t *var_hash

typedef struct _zend_class_entry {
    void (*serialize)(void);
    const char *name;
    // 其他必要字段...
} zend_class_entry;

typedef struct _zval {
    // zval结构体定义
} zval;

typedef struct _php_unserialize_data_t php_unserialize_data_t;

#define E_WARNING 2

static inline long parse_iv2(const unsigned char *p, const unsigned char **q) {
    // 简单实现
    long result = 0;
    while (*p >= '0' && *p <= '9') {
        result = result * 10 + (*p - '0');
        (*q)++;
        p++;
    }
    return result;
}

void object_init_ex(zval *object, zend_class_entry *class_type);
void zend_error(int type, const char *format, ...);