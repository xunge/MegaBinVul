#include <string.h>
#include <stdlib.h>

typedef struct _php_stream php_stream;

typedef struct _HashTable {
    unsigned int nNumOfElements;
} HashTable;

typedef struct {
    char *ptr;
    size_t len;
} phar_zstr;

typedef void (*dtor_func_t)(void *pDest);

#define TSRMLS_DC
#define TSRMLS_CC
#define SUCCESS 0
#define FAILURE -1
#define HASH_KEY_NON_EXISTENT 0

#define ALLOC_HASHTABLE(ht) (ht = malloc(sizeof(HashTable)))
#define FREE_HASHTABLE(ht) free(ht)
#define PHAR_STR(key, str_key) (str_key = key.ptr)
#define PHAR_STR_FREE(str_key)
#define efree free
#define safe_emalloc(n, size, offset) malloc((n)*(size)+(offset))

static void *zend_get_hash_value = NULL;
static void *phar_dir_ops = NULL;
static int (*phar_compare_dir_name)(const void *, const void *) = NULL;
static void *zend_qsort = NULL;

static int zend_hash_init(HashTable *ht, unsigned int size, void *hash_func, dtor_func_t destructor, int persistent);
static void zend_hash_internal_pointer_reset(HashTable *ht);
static int zend_hash_has_more_elements(HashTable *ht);
static int zend_hash_get_current_key_ex(HashTable *ht, phar_zstr *str_index, uint *str_length, ulong *num_index, int duplicate, void *pos);
static int zend_hash_move_forward(HashTable *ht);
static int zend_hash_sort(HashTable *ht, void *sort_func, int (*compare_func)(const void *, const void *), int renumber);
static php_stream *php_stream_alloc(void *ops, void *abstract, void *path, const char *mode);
static void phar_add_empty(HashTable *ht, char *key, uint len);