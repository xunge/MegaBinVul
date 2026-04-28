#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct _zval_struct zval;
typedef struct _HashTable HashTable;
typedef struct _HashPosition HashPosition;
typedef struct _sdlPtr sdlPtr;
typedef struct _soapMapping soapMapping;
typedef struct _encode_details encode_details;
typedef struct _encode encode;
typedef encode* encodePtr;
typedef struct _smart_str smart_str;

struct _HashTable {
    uint nTableSize;
    uint nTableMask;
    uint nNumOfElements;
    ulong nNextFreeElement;
    void *pInternalPointer;
    void *pListHead;
    void *pListTail;
    void **arBuckets;
};

struct _HashPosition {
    void *pos;
};

struct _sdlPtr {
    void *ptr;
};

struct _soapMapping {
    zval *to_xml;
    zval *to_zval;
};

struct _encode_details {
    int type;
    char *ns;
    char *type_str;
    void *sdl_type;
    soapMapping *map;
};

struct _encode {
    encode_details details;
    void (*to_xml)(encodePtr, zval*, zval*);
    void (*to_zval)(encodePtr, zval*, zval*);
};

struct _smart_str {
    char *c;
    size_t len;
    size_t a;
};

struct _zval_struct {
    union {
        long lval;
        double dval;
        struct {
            char *val;
            int len;
        } str;
        HashTable *ht;
        void *ptr;
    } value;
    unsigned char type;
    unsigned char is_ref;
    unsigned short refcount;
};

#define TSRMLS_DC
#define TSRMLS_CC
#define SUCCESS 0
#define IS_ARRAY 7
#define IS_STRING 6
#define IS_NULL 0
#define UNKNOWN_TYPE 0
#define E_WARNING 2

#define Z_TYPE_PP(ppzval) ((*ppzval)->type)
#define Z_ARRVAL_PP(ppzval) ((*ppzval)->value.ht)
#define Z_STRVAL_PP(ppzval) ((*ppzval)->value.str.val)

void php_error_docref(const char *docref, int type, const char *format, ...);
void* emalloc(size_t size);
char* estrdup(const char *s);
void zend_hash_internal_pointer_reset_ex(HashTable *ht, HashPosition *pos);
int zend_hash_get_current_data_ex(HashTable *ht, void **data, HashPosition *pos);
void zend_hash_move_forward_ex(HashTable *ht, HashPosition *pos);
void zend_hash_get_current_key_ex(HashTable *ht, char **str_index, unsigned int *str_length, ulong *num_index, int duplicate, HashPosition *pos);
int zend_hash_update(HashTable *ht, const char *arKey, uint nKeyLength, void *pData, uint pDataSize, void **pDest);
void zend_hash_init(HashTable *ht, uint nSize, void (*pDestructor)(void *), void (*pDestructorParam)(void *), int persistent);
void zval_add_ref(zval **z);
void smart_str_appends(smart_str *str, const char *s);
void smart_str_appendc(smart_str *str, char c);
void smart_str_0(smart_str *str);
void smart_str_free(smart_str *str);
encodePtr get_encoder(sdlPtr sdl, const char *type_ns, const char *type_name);
encodePtr get_encoder_ex(sdlPtr sdl, const char *type_name, size_t len);
encodePtr get_conversion(int type);
void delete_encoder(void *pDest);
void to_xml_user(encodePtr enc, zval *data, zval *ret);
void to_zval_user(encodePtr enc, zval *data, zval *ret);