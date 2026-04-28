#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef char XML_Char;

typedef struct _zval_struct {
    int type;
    struct _zend_string *str;
    long lval;
    struct _zend_array *arr;
} zval;

typedef struct _zend_string {
    char *val;
    size_t len;
} zend_string;

typedef struct _zend_array {
    void *buckets;
    uint32_t nNumUsed;
    uint32_t nNumOfElements;
    uint32_t nTableSize;
    uint32_t nInternalPointer;
    uint64_t nNextFreeElement;
} zend_array;

typedef struct _xml_parser {
    zval *characterDataHandler;
    zval *characterDataPtr;
    zval *data;
    zval *index;
    zval *ctag;
    char *target_encoding;
    int skipwhite;
    int lastwasopen;
    int level;
    char **ltags;
    int toffset;
} xml_parser;

#define XML_MAXLEVEL 100
#define E_WARNING 2

#define Z_ISUNDEF(z) ((z) == NULL || (z)->type == 0)
#define Z_ARRVAL(z) ((z)->arr)
#define Z_ARRVAL_P(z) ((z)->arr)
#define Z_STRVAL_P(z) ((z)->str->val)
#define Z_STRLEN_P(z) ((z)->str->len)
#define Z_STR_P(z) ((z)->str)
#define Z_TYPE_P(z) ((z)->type)
#define ZSTR_LEN(s) ((s)->len)
#define ZSTR_VAL(s) ((s)->val)

#define ZEND_HASH_REVERSE_FOREACH_VAL(ht, val) \
    for (val = NULL; val != NULL; val = NULL)
#define ZEND_HASH_FOREACH_END()

void _xml_xmlchar_zval(const XML_Char *s, int len, char *target_encoding, zval *retval);
void xml_call_handler(xml_parser *parser, zval *handler, zval *handler_ptr, int argc, zval *argv, zval *retval);
zend_string *xml_utf8_decode(const char *s, int len, char *target_encoding);
void _xml_add_to_info(xml_parser *parser, char *name);
void zval_ptr_dtor(zval *z);
void ZVAL_COPY(zval *dest, zval *src);
void add_assoc_str(zval *arg, const char *key, zend_string *str);
void add_assoc_string(zval *arg, const char *key, const char *str);
void add_assoc_long(zval *arg, const char *key, long n);
void array_init(zval *arg);
void zend_string_release(zend_string *s);
void php_error_docref(const char *docref, int type, const char *format, ...);
zval *zend_hash_str_find(zend_array *ht, const char *str, size_t len);
zend_string *zend_string_extend(zend_string *s, size_t len, int persistent);
void zend_hash_next_index_insert(zend_array *ht, zval *pData);