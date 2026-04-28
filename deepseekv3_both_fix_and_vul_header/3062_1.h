#include <stdlib.h>
#include <string.h>

typedef struct _xml_parser xml_parser;
typedef char XML_Char;

typedef struct _zval {
    int type;
    union {
        long lval;
        double dval;
        struct {
            char *val;
            int len;
        } str;
        struct {
            void *ht;
        } ht;
    } value;
} zval;

typedef void* HashTable;
typedef void* HashPosition;

#define Z_ARRVAL_PP(ppzval) ((*(ppzval))->value.ht.ht)
#define Z_STRLEN_PP(ppzval) ((*(ppzval))->value.str.len)
#define Z_STRVAL_PP(ppzval) ((*(ppzval))->value.str.val)
#define Z_ARRVAL_P(zval) (zval->value.ht.ht)
#define Z_STRLEN_P(zval) (zval->value.str.len)
#define Z_STRVAL_P(zval) (zval->value.str.val)

#define SUCCESS 0
#define E_WARNING 2
#define XML_MAXLEVEL 100

#define MAKE_STD_ZVAL(zv) \
    zv = (zval *) malloc(sizeof(zval))

#define TSRMLS_FETCH()
#define TSRMLS_CC

#define erealloc realloc
#define efree free

struct _xml_parser {
    int index;
    char *target_encoding;
    zval *characterDataHandler;
    void *characterDataPtr;
    int skipwhite;
    int lastwasopen;
    zval **ctag;
    zval *data;
    char **ltags;
    int level;
    int toffset;
};

int zend_hash_find(HashTable *ht, const char *key, unsigned int key_len, void **pData);
void zend_hash_internal_pointer_end_ex(HashTable *ht, HashPosition *pos);
int zend_hash_get_current_data_ex(HashTable *ht, void **pData, HashPosition *pos);
void array_init(zval *arg);
int zend_hash_next_index_insert(HashTable *ht, void *pData, unsigned int nDataSize, void **pDest);

zval *_xml_resource_zval(int index);
zval *_xml_xmlchar_zval(const XML_Char *s, int len, char *encoding);
zval *xml_call_handler(xml_parser *parser, zval *handler, void *ptr, int argc, zval **argv);
void zval_ptr_dtor(zval **zval_ptr);
char *xml_utf8_decode(const XML_Char *s, int len, int *decoded_len, char *encoding);
void add_assoc_string(zval *arg, const char *key, char *str, int duplicate);
void add_assoc_long(zval *arg, const char *key, long n);
void _xml_add_to_info(xml_parser *parser, char *name);
void php_error_docref(const char *docref, int type, const char *format, ...);