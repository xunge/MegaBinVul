#include <stdlib.h>
#include <string.h>

typedef char XML_Char;

typedef struct _zval_struct {
    union {
        long lval;
        void *ht;
    } value;
} zval;

typedef struct _xml_parser {
    int index;
    int level;
    int toffset;
    int lastwasopen;
    void *endElementHandler;
    void *endElementPtr;
    zval *data;
    zval **ctag;
    char **ltags;
} xml_parser;

void zval_ptr_dtor(zval **zval_ptr);
void add_assoc_string(zval *arg, const char *key, const char *str, int duplicate);
void add_assoc_long(zval *arg, const char *key, long n);
void array_init(zval *arg);
void MAKE_STD_ZVAL(zval *z);
int zend_hash_next_index_insert(void *target, void *data, unsigned int size, void *pDest);
#define Z_ARRVAL_P(zval_p) ((zval_p)->value.ht)

char* _xml_decode_tag(xml_parser *parser, const XML_Char *name);
zval* _xml_resource_zval(int index);
zval* _xml_string_zval(char *str);
zval* xml_call_handler(xml_parser *parser, void *handler, void *ptr, int argc, zval **argv);
void _xml_add_to_info(xml_parser *parser, char *tag_name);
void efree(void *ptr);

#define XML_MAXLEVEL 64