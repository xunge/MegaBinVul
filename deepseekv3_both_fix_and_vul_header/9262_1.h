#include <string.h>
#include <stdlib.h>

#define PHPAPI
#ifndef PHP_WIN32
#define PHP_WIN32 0
#endif

typedef struct _zend_string zend_string;
struct _zend_string {
    char *val;
    size_t len;
};

#define ZSTR_VAL(zstr) (zstr)->val
#define ZSTR_LEN(zstr) (zstr)->len

zend_string *zend_string_alloc(size_t len, int persistent);
zend_string *zend_string_truncate(zend_string *s, size_t len, int persistent);
int php_mblen(const char *str, size_t n);