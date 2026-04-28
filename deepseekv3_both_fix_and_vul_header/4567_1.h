#include <stdlib.h>
#include <string.h>

typedef union _zvalue_value {
    long lval;
    double dval;
    struct {
        char *val;
        int len;
    } str;
    struct {
        void *properties;
    } obj;
    void *ptr;
} zvalue_value;

typedef struct _zval_struct {
    zvalue_value value;
    unsigned char type;
} zval;

typedef struct _smart_str {
    char *c;
    size_t len;
    size_t a;
} smart_str;

#define Z_OBJPROP_P(zval_p) ((zval_p)->value.obj.properties)
#define Z_TYPE_PP(ppzval) ((*ppzval)->type)
#define Z_STRVAL_PP(ppzval) ((*ppzval)->value.str.val)
#define Z_STRLEN_PP(ppzval) ((*ppzval)->value.str.len)

#define SUCCESS 0
#define FAILURE -1
#define IS_STRING 6

#define TSRMLS_DC
#define TSRMLS_CC

void smart_str_appendl(smart_str *dest, const char *str, size_t len);
void smart_str_appendc(smart_str *dest, char ch);
void smart_str_append_const(smart_str *dest, const char *str);
void smart_str_0(smart_str *dest);
void smart_str_free(smart_str *dest);
unsigned char *php_base64_encode(const unsigned char *str, int length, int *ret_length);
void efree(void *ptr);
int zend_hash_find(void *ht, const char *arKey, unsigned int nKeyLength, void **pData);
int zend_hash_exists(void *ht, const char *arKey, unsigned int nKeyLength);