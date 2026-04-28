#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _php_stream php_stream;
typedef struct _phar_zstr {
    char *val;
    size_t len;
} phar_zstr;

typedef struct _HashTable {
    uint32_t nNumOfElements;
} HashTable;

typedef int zend_bool;
typedef void* HashPosition;
typedef int (*sort_func_t)(const void*, const void*);
typedef int (*compare_func_t)(const void*, const void*);

#define TSRMLS_DC
#define TSRMLS_CC
#define ALLOC_HASHTABLE(ht) ((ht) = malloc(sizeof(HashTable)))
#define FREE_HASHTABLE(ht) free(ht)
#define PHAR_STR(key, str_key) ((str_key) = (key).val)
#define PHAR_STR_FREE(str_key)
#define HASH_KEY_IS_STRING 1
#define HASH_KEY_NON_EXISTENT 0
#define SUCCESS 0
#define FAILURE -1

static void *safe_emalloc(size_t nmemb, size_t size, size_t offset) {
    return malloc(nmemb * size + offset);
}
static void efree(void *ptr) {
    free(ptr);
}
static int zend_hash_init(HashTable *ht, uint32_t nSize, uint32_t (*pHashFunction)(void *pData), void (*pDestructor)(void *pData), zend_bool persistent) {
    ht->nNumOfElements = 0;
    return SUCCESS;
}
static int zend_hash_get_current_key_ex(HashTable *ht, phar_zstr *str_index, uint32_t *str_length, uint32_t *num_index, zend_bool duplicate, HashPosition *pos) {
    return HASH_KEY_NON_EXISTENT;
}
static int zend_hash_move_forward(HashTable *ht) {
    return SUCCESS;
}
static int zend_hash_has_more_elements(HashTable *ht) {
    return FAILURE;
}
static void zend_hash_internal_pointer_reset(HashTable *ht) {}
static int zend_hash_sort(HashTable *ht, sort_func_t sort_func, compare_func_t compare_func, int renumber TSRMLS_DC) {
    return SUCCESS;
}
static uint32_t zend_get_hash_value(void *pData) {
    return 0;
}
static php_stream *php_stream_alloc(void *ops, void *abstract, void *path, const char *mode) {
    return NULL;
}
static int phar_compare_dir_name(const void *a, const void *b TSRMLS_DC) {
    return 0;
}
static void phar_add_empty(HashTable *ht, char *key, uint32_t key_len) {}
static void *phar_dir_ops;
static void *zend_qsort;