#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct _zval_struct {
    /* zval结构体内容 */
    int type;
    union {
        long lval;
        double dval;
        struct {
            char *val;
            int len;
        } str;
        struct {
            void *ptr;
            int type;
        } obj;
    } value;
} zval;

typedef struct _zend_class_entry {
    /* zend_class_entry结构体内容 */
    void *function_table;
    void *properties_info;
    /* 其他成员 */
} zend_class_entry;

typedef struct _zend_hash_key {
    /* zend_hash_key结构体内容 */
    unsigned long h;
    char *key;
    unsigned int key_length;
} zend_hash_key;

#define ALLOC_INIT_ZVAL(z) do { \
    z = malloc(sizeof(zval)); \
    memset(z, 0, sizeof(zval)); \
} while (0)

#define TSRMLS_DC
#define TSRMLS_CC 
#define APPLY_TSRMLS_CC

void array_init(zval *z);
void add_assoc_zval(zval *array, const char *key, zval *value);
zend_class_entry *zend_get_class_entry(zval *object TSRMLS_DC);
int zend_hash_apply_with_arguments(void *ht, void (*apply_func)(void *pDest, int num_args, va_list args, zend_hash_key *hash_key), int num_args, ...);
void twig_add_method_to_class(void *pDest, int num_args, va_list args, zend_hash_key *hash_key);
void twig_add_property_to_class(void *pDest, int num_args, va_list args, zend_hash_key *hash_key);