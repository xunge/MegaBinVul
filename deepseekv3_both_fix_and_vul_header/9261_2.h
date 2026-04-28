#include <string.h>
#include <stdlib.h>

typedef struct _zend_string {
    char *val;
    size_t len;
} zend_string;

#define ZSTR_VAL(zstr) ((zstr)->val)
#define ZSTR_LEN(zstr) ((zstr)->len)

zend_string *zend_string_alloc(size_t len, int persistent);
zend_string *zend_string_truncate(zend_string *s, size_t len, int persistent);
int php_mblen(const char *str, size_t n);

#define PHPAPI