#include <string.h>
#include <stdlib.h>

typedef char XML_Char;

#define XML_MAXLEVEL 100
#define E_WARNING 2

typedef struct _xml_parser {
    int level;
    int index;
    int toffset;
    char *target_encoding;
    void *startElementHandler;
    void *startElementPtr;
    struct _zval *data;
    char *ltags[XML_MAXLEVEL];
    int lastwasopen;
    int ctag;
} xml_parser;

typedef struct _zval {
    union {
        struct _hashtable *ht;
    } value;
} zval;

typedef struct _hashtable {
    // dummy hashtable structure
} HashTable;

#define MAKE_STD_ZVAL(zv) \
    (zv) = (zval *) malloc(sizeof(zval))
#define Z_ARRVAL_P(zv) ((zval *)(zv))->value.ht
#define TSRMLS_FETCH()
#define TSRMLS_CC
#define estrdup(str) strdup(str)
#define efree(ptr) free(ptr)

void zval_ptr_dtor(zval **zval_ptr);
void add_assoc_string(zval *arg, const char *key, const char *str, int duplicate);
void add_assoc_stringl(zval *arg, const char *key, char *str, int length, int duplicate);
void add_assoc_long(zval *arg, const char *key, long n);
void array_init(zval *arg);
void zend_hash_next_index_insert(HashTable *ht, void *pData, unsigned int nDataSize, void **pDest);
void zend_hash_add(HashTable *ht, const char *arKey, unsigned int nKeyLength, void *pData, unsigned int nDataSize, void **pDest);
void php_error_docref(const char *docref, int errcode, const char *format, ...);

char* _xml_decode_tag(xml_parser *parser, const XML_Char *name);
char* xml_utf8_decode(const char *data, int length, int *ret_length, const char *encoding);
zval* _xml_resource_zval(int res_id);
zval* _xml_string_zval(char *str);
zval* xml_call_handler(xml_parser *parser, void *handler, void *ptr, int argc, zval **argv);
void _xml_add_to_info(xml_parser *parser, char *name);