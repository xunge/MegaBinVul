#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct _php_stream php_stream;
typedef struct _php_stream_ops {
    int dummy;
} php_stream_ops;
typedef struct _HashTable {
    uint nNumOfElements;
} HashTable;
typedef struct _phar_zstr {
    char *str;
    uint len;
} phar_zstr;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef int (*hash_func_t)(const void *key, size_t key_len);
typedef void (*dtor_func_t)(void *pData);
typedef int (*sort_func_t)(const void *, const void *);
typedef int (*compare_func_t)(const void *, const void *);
typedef int zend_bool;
typedef void *HashPosition;

#define TSRMLS_DC
#define TSRMLS_CC
#define ALLOC_HASHTABLE(ht) ((ht) = malloc(sizeof(HashTable)))
#define FREE_HASHTABLE(ht) free(ht)
#define PHAR_STR(key, str_key) do { (str_key) = (key).str; } while (0)
#define PHAR_STR_FREE(str_key) do { } while (0)
#define SUCCESS 0
#define FAILURE -1
#define HASH_KEY_NON_EXISTENT 0
#define HASH_KEY_IS_STRING 1

static php_stream_ops phar_dir_ops;
static void *safe_emalloc(size_t nmemb, size_t size, size_t offset) { return malloc(nmemb * size + offset); }
static int zend_get_hash_value(const void *key, size_t key_len) { return 0; }
static int zend_hash_init(HashTable *ht, uint nSize, hash_func_t pHashFunction, dtor_func_t pDestructor, zend_bool persistent) { return SUCCESS; }
static int zend_hash_internal_pointer_reset(HashTable *ht) { return SUCCESS; }
static int zend_hash_has_more_elements(const HashTable *ht) { return FAILURE; }
static int zend_hash_get_current_key_ex(const HashTable *ht, phar_zstr *str_index, uint *str_length, ulong *num_index, zend_bool duplicate, HashPosition *pos) { return HASH_KEY_NON_EXISTENT; }
static int zend_hash_move_forward(HashTable *ht) { return SUCCESS; }
static int zend_hash_sort(HashTable *ht, sort_func_t sort_func, compare_func_t compare_func, int renumber TSRMLS_DC) { return SUCCESS; }
static void efree(void *ptr) { free(ptr); }
static php_stream *php_stream_alloc(php_stream_ops *ops, void *abstract, const char *mode, int options) { return NULL; }
static int zend_qsort(void *base, size_t nmemb, size_t siz, compare_func_t compare TSRMLS_DC) { return 0; }

static void phar_add_empty(HashTable *ht, char *key, uint key_len) {}
static int phar_compare_dir_name(const void *a, const void *b TSRMLS_DC) { return 0; }