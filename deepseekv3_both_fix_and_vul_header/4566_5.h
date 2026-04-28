#include <string.h>
#include <stddef.h>
#include <stdint.h>

typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;
typedef struct _xmlNs {
    const char *prefix;
    const char *href;
} xmlNs;
typedef xmlNs *xmlNsPtr;
typedef struct _zend_class_entry zend_class_entry;
typedef struct _HashTable HashTable;
typedef struct _zval {
    uint8_t type;
    union {
        long lval;
        struct {
            char *val;
            size_t len;
        } str;
        struct {
            zend_class_entry *ce;
            HashTable *properties;
        } obj;
        HashTable *ht;
    } value;
} zval;
typedef struct _smart_str { char *c; size_t len; } smart_str;
typedef struct _encode {
    struct {
        const char *ns;
        const char *type_str;
    } details;
} *encodePtr;

#define TSRMLS_DC
#define FALSE 0
#define TRUE 1
#define XSD_ANYTYPE 0
#define APACHE_MAP 0
#define SOAP_GLOBAL(x) (x)
#define E_ERROR 0
#define IS_ARRAY 7
#define IS_OBJECT 8
#define IS_LONG 4
#define IS_STRING 6
#define FAILURE -1
#define SUCCESS 0

#define Z_TYPE_P(zval) ((zval)->type)
#define Z_TYPE_PP(zval) (*(zval))->type
#define Z_OBJCE_PP(zval) (*(zval))->value.obj.ce
#define Z_OBJPROP_PP(zval) (*(zval))->value.obj.properties
#define Z_LVAL_PP(zval) (*(zval))->value.lval
#define Z_STRVAL_PP(zval) (*(zval))->value.str.val

extern zend_class_entry *soap_var_class_entry;
extern encodePtr get_conversion(int type);
extern int zend_hash_num_elements(HashTable *ht);
extern void zend_hash_internal_pointer_reset(HashTable *ht);
extern int zend_hash_get_current_data(HashTable *ht, void **data);
extern int zend_hash_move_forward(HashTable *ht);
extern int zend_hash_find(HashTable *ht, const char *key, unsigned int key_len, void **data);
extern void smart_str_appendl(smart_str *str, const char *s, size_t len);
extern void smart_str_appends(smart_str *str, const char *s);
extern void smart_str_appendc(smart_str *str, char c);
extern void smart_str_0(smart_str *str);
extern void smart_str_free(smart_str *str);
extern void soap_error0(int level, const char *message);
extern HashTable *HASH_OF(zval *array);
extern encodePtr get_encoder_ex(void *sdl, char *type, size_t len);
extern void get_type_str(xmlNodePtr node, const char *ns, const char *type, smart_str *str);
extern xmlNsPtr encode_add_ns(xmlNodePtr node, const char *ns);
extern int is_map(zval *array);
extern void *sdl;