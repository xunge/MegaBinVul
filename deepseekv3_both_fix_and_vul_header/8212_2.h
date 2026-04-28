#include <stdlib.h>
#include <string.h>

typedef struct _zval_struct {
    int type;
    char *value;
    int length;
} zval;

typedef struct _hashtable {
    int size;
    void **elements;
} HashTable;

#define TSRMLS_DC
#define TSRMLS_CC 
#define SUCCESS 0
#define FAILURE -1
#define IS_STRING 6
#define LOC_CANONICALIZE_TAG 1
#define U_ILLEGAL_ARGUMENT_ERROR 1

#define Z_TYPE_PP(ppzval) ((*ppzval)->type)
#define Z_STRVAL_PP(ppzval) ((*ppzval)->value)
#define Z_STRLEN_PP(ppzval) ((*ppzval)->length)

static int zend_hash_num_elements(HashTable *ht) {
    return ht->size;
}
static void zend_hash_internal_pointer_reset(HashTable *ht) {}
static int zend_hash_has_more_elements(HashTable *ht) {
    return SUCCESS;
}
static void zend_hash_move_forward(HashTable *ht) {}
static int zend_hash_get_current_data(HashTable *ht, void **data) {
    return FAILURE;
}
static void intl_error_set(void *null, int err, const char *msg, int dummy TSRMLS_DC) {}

#define LOOKUP_CLEAN_RETURN(val) \
    do { \
        for (i = 0; i < cur_arr_len; i++) { \
            if (cur_arr[i*2]) free(cur_arr[i*2]); \
        } \
        free(cur_arr); \
        return val; \
    } while (0)

static int strToMatch(const char *src, char *dest) {
    return 1;
}
static char *get_icu_value_internal(const char *loc_range, int type, int *result, int fromParseLocale) {
    return NULL;
}
static int getStrrtokenPos(const char *str, int length) {
    return 0;
}

static void *ecalloc(size_t nmemb, size_t size) {
    return calloc(nmemb, size);
}
static void *erealloc(void *ptr, size_t size) {
    return realloc(ptr, size);
}
static char *estrndup(const char *s, size_t length) {
    char *p = malloc(length + 1);
    if (p) {
        memcpy(p, s, length);
        p[length] = '\0';
    }
    return p;
}
static char *estrdup(const char *s) {
    return strdup(s);
}
static void efree(void *ptr) {
    free(ptr);
}