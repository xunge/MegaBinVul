#include <string.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define LOC_NOT_FOUND -2
#define IS_STRING 1
#define LOC_LANG_TAG ""
#define LOC_GRANDFATHERED_LANG_TAG ""
#define SEPARATOR ""

typedef struct {
    char *c;
    size_t len;
    size_t a;
} smart_str;

typedef struct _HashTable HashTable;
typedef struct _zval {
    int type;
    char *value;
    int len;
} zval;

#define Z_TYPE_PP(ppzval) ((*ppzval)->type)
#define Z_STRVAL_PP(ppzval) ((*ppzval)->value)
#define Z_STRLEN_PP(ppzval) ((*ppzval)->len)

static void smart_str_appendl(smart_str *str, const char *val, size_t len) {
    // dummy implementation
}

static int zend_hash_find(HashTable *ht, const char *key, size_t key_len, void **data) {
    // dummy implementation
    return FAILURE;
}