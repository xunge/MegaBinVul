#include <stdarg.h>
#include <string.h>
#include <ctype.h>

typedef struct _zend_class_entry zend_class_entry;
typedef struct _zval zval;
typedef struct _zend_hash_key zend_hash_key;

struct _zend_function {
    struct {
        char *function_name;
        unsigned int fn_flags;
    } common;
};
typedef struct _zend_function zend_function;

#define ZEND_ACC_PUBLIC 0x100
#define FAILURE -1
#define TSRMLS_CC
#define TSRMLS_DC
#define TSRMLS_FETCH()

#define APPLY_TSRMLS_DC
#define APPLY_TSRMLS_FETCH()

char *estrndup(const char *s, size_t length);
void php_strtolower(char *str, size_t length);
int zend_lookup_class(const char *name, size_t length, zend_class_entry ***ce TSRMLS_DC);
int instanceof_function(const zend_class_entry *instance_ce, const zend_class_entry *ce TSRMLS_CC);
void add_assoc_stringl_ex(zval *arg, const char *key, size_t key_len, char *str, size_t length, int duplicate);