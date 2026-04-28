#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LOC_VARIANT_TAG "variant"
#define LOC_EXTLANG_TAG "extlang"
#define LOC_PRIVATE_TAG "private"
#define MAX_NO_VARIANT 8
#define MAX_NO_EXTLANG 3
#define MAX_NO_PRIVATE 8
#define SEPARATOR "-"
#define SUCCESS 0
#define FAILURE -1
#define IS_STRING 1
#define IS_ARRAY 2

typedef struct {
    int type;
    union {
        char *str_val;
        void *arr_val;
    } value;
    int length;
} zval;

typedef struct {
    unsigned int size;
    void **buckets;
} HashTable;

typedef struct {
    unsigned int pos;
} HashPosition;

typedef struct {
    char *s;
    size_t len;
    size_t a;
} smart_str;

#define Z_TYPE_PP(ppzval) ((*ppzval)->type)
#define Z_STRVAL_PP(ppzval) ((*ppzval)->value.str_val)
#define Z_STRLEN_PP(ppzval) ((*ppzval)->length)
#define HASH_OF(zval_p) ((HashTable *)(zval_p)->value.arr_val)
#define TSRMLS_DC

static int zend_hash_find(HashTable *ht, const char *arKey, unsigned int nKeyLength, void **pData) {
    return FAILURE;
}

static void zend_hash_internal_pointer_reset_ex(HashTable *ht, HashPosition *pos) {
    pos->pos = 0;
}

static int zend_hash_get_current_data_ex(HashTable *ht, void **pData, HashPosition *pos) {
    if (pos->pos < ht->size) {
        *pData = ht->buckets[pos->pos];
        return SUCCESS;
    }
    return FAILURE;
}

static void zend_hash_move_forward_ex(HashTable *ht, HashPosition *pos) {
    pos->pos++;
}

static void smart_str_appendl(smart_str *str, const char *s, size_t len) {
    if (str->len + len >= str->a) {
        str->a = str->len + len + 1;
        str->s = realloc(str->s, str->a);
    }
    memcpy(str->s + str->len, s, len);
    str->len += len;
    str->s[str->len] = '\0';
}

static void add_prefix(smart_str *loc_name, char *key_name) {
    smart_str_appendl(loc_name, key_name, strlen(key_name));
}