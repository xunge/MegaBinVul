#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define WDDX_BUF_LEN 128
#define WDDX_STRUCT_S "<struct>"
#define WDDX_STRUCT_E "</struct>"
#define WDDX_VAR_S "<var name='%s'>"
#define WDDX_VAR_E "</var>"
#define WDDX_STRING_S "<string>"
#define WDDX_STRING_E "</string>"
#define PHP_CLASS_NAME_VAR "php_class_name"
#define SUCCESS 0
#define E_WARNING 2
#define E_NOTICE 8
#define HASH_KEY_IS_STRING 1
#define IS_STRING 6

typedef struct _zend_class_entry zend_class_entry;

typedef struct _zval_struct {
    union {
        struct {
            zend_class_entry *ce;
        } obj;
        struct {
            char *val;
            int len;
        } str;
    } value;
    int type;
} zval;

struct _zend_class_entry {
    int (*serialize)(zval *object, unsigned char **buffer, size_t *buf_len);
    int (*unserialize)(zval **object, const unsigned char *buffer, size_t buf_len);
};

typedef struct _HashTable HashTable;
typedef unsigned long ulong;
typedef uint32_t uint;

typedef struct _wddx_packet {
    // packet members
} wddx_packet;

#define TSRMLS_DC
#define TSRMLS_CC
#define TSRMLS_FETCH()

#define PHP_CLASS_ATTRIBUTES const char *class_name; size_t name_len
#define PHP_SET_CLASS_ATTRIBUTES(obj) class_name = "ClassName"; name_len = strlen(class_name)
#define PHP_CLEANUP_CLASS_ATTRIBUTES()
#define MAKE_STD_ZVAL(z) z = malloc(sizeof(zval))
#define FREE_ZVAL(z) free(z)
#define ZVAL_STRING(z, s, dup) (z)->value.str.val = (dup ? strdup(s) : (char*)s); (z)->type = IS_STRING
#define Z_OBJCE_P(z) ((zend_class_entry*)((z)->value.obj.ce))
#define Z_TYPE_PP(z) (*(z))->type
#define Z_STRVAL_PP(z) (*(z))->value.str.val
#define Z_STRLEN_PP(z) (*(z))->value.str.len
#define CG(function_table) NULL
#define HASH_OF(z) NULL
#define slprintf snprintf

extern int call_user_function_ex(HashTable *function_table, zval **object, zval *function_name, zval **retval_ptr, int param_count, zval **params[], int no_separation, void *);
extern void php_error_docref(const char *docref, int type, const char *format, ...);
extern void php_wddx_add_chunk_static(wddx_packet *packet, const char *chunk);
extern void php_wddx_add_chunk(wddx_packet *packet, const char *chunk);
extern void php_wddx_add_chunk_ex(wddx_packet *packet, const char *chunk, int len);
extern void php_wddx_serialize_var(wddx_packet *packet, zval *var, const char *name, int name_len);
extern void zval_dtor(zval *z);
extern void zval_ptr_dtor(zval **z);
extern int zend_hash_internal_pointer_reset(HashTable *ht);
extern int zend_hash_get_current_data(HashTable *ht, void **data);
extern int zend_hash_move_forward(HashTable *ht);
extern int zend_hash_find(HashTable *ht, const char *key, uint key_len, void **pData);
extern int zend_hash_get_current_key_ex(HashTable *ht, const char **str_index, uint *str_length, ulong *num_index, int duplicate, void *);
extern void zend_unmangle_property_name(const char *mangled, int mangled_len, const char **class_name, const char **prop_name);