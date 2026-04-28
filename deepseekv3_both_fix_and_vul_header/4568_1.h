#include <stdlib.h>
#include <string.h>

typedef unsigned int zend_uint;
typedef unsigned char zend_uchar;

typedef struct _zval_struct zval;
typedef struct _hashtable HashTable;

struct _zval_struct {
    union {
        long lval;
        double dval;
        struct {
            char *val;
            int len;
        } str;
        HashTable *ht;
        struct {
            HashTable *properties;
            void *handlers;
        } obj;
    } value;
    zend_uint refcount__gc;
    zend_uchar type;
    zend_uchar is_ref__gc;
};

typedef struct {
    char *c;
    size_t len;
    size_t a;
} smart_str;

#define Z_OBJPROP_P(zval_p) (zval_p)->value.obj.properties
#define Z_TYPE_PP(ppzval)   (*ppzval)->type
#define Z_STRVAL_PP(ppzval) (*ppzval)->value.str.val
#define Z_STRLEN_PP(ppzval) (*ppzval)->value.str.len

#define SUCCESS 0
#define TSRMLS_DC
#define IS_STRING 6

int zend_hash_find(HashTable *ht, const char *key, unsigned int key_len, void **pData);
void smart_str_appendl(smart_str *str, const char *val, size_t len);
void smart_str_appendc(smart_str *str, char c);
void smart_str_0(smart_str *str);
void smart_str_append_const(smart_str *str, const char *val);
void smart_str_free(smart_str *str);
unsigned char* php_base64_encode(const unsigned char *input, int length, int *ret_length);
void efree(void *ptr);