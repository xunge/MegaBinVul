#include <stddef.h>
#include <stdint.h>

typedef char XML_Char;

typedef struct _zend_string {
    size_t len;
    char val[1];
} zend_string;

#define ZSTR_LEN(s) ((s)->len)
#define ZSTR_VAL(s) ((s)->val)

typedef struct {
    unsigned short (*encoding_function)(unsigned char);
} xml_encoding;

zend_string *zend_string_init(const char *s, size_t len, int persistent);
zend_string *zend_string_alloc(size_t len, int persistent);
zend_string *zend_string_truncate(zend_string *s, size_t len, int persistent);
xml_encoding *xml_get_encoding(const XML_Char *encoding);

#define PHP_XML_API
PHP_XML_API zend_string *xml_utf8_encode(const char *s, size_t len, const XML_Char *encoding);