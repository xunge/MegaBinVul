#include <stdlib.h>
#include <string.h>

typedef struct _HashTable {
    size_t nTableSize;
    size_t nNumOfElements;
    void **arBuckets;
} HashTable;

typedef struct _zval_struct {
    union {
        long lval;
        double dval;
        HashTable *ht;
        void *ptr;
    } value;
    unsigned int refcount__gc;
    unsigned char type;
    unsigned char is_ref__gc;
} zval;

typedef struct _spl_filesystem_object {
    struct {
        HashTable *properties;
    } std;
    char *file_name;
    int file_name_len;
    int type;
    union {
        struct {
            void *dirp;
            char *sub_path;
            int sub_path_len;
        } dir;
        struct {
            char *open_mode;
            int open_mode_len;
            char delimiter;
            char enclosure;
        } file;
    } u;
    char *_path;
    int _path_len;
} spl_filesystem_object;

#define SPL_FS_DIR 0
#define SPL_FS_FILE 1

#define ALLOC_HASHTABLE(ht) \
    (ht) = (HashTable *)malloc(sizeof(HashTable))

#define ZEND_INIT_SYMTABLE_EX(ht, n, persistent) \
    (ht)->nTableSize = n; \
    (ht)->nNumOfElements = 0; \
    (ht)->arBuckets = calloc(n, sizeof(void*))

#define INIT_PZVAL(z) do { \
    (z)->refcount__gc = 1; \
    (z)->is_ref__gc = 0; \
} while (0)

#define Z_ARRVAL(z) ((z).value.ht)

#define TSRMLS_DC
#define TSRMLS_CC

typedef void (*copy_ctor_func_t)(void *);

void *zend_object_store_get_object(zval *obj);
void rebuild_object_properties(void *object);
char *spl_gen_private_prop_name(void *ce, const char *name, size_t name_len, int *prop_len);
char *spl_filesystem_object_get_pathname(spl_filesystem_object *intern, int *path_len);
void spl_filesystem_object_get_path(spl_filesystem_object *intern, int *path_len);
int php_stream_is(void *stream, void *ops);
void zend_hash_copy(HashTable *target, HashTable *source, copy_ctor_func_t copy_ctor, void **tmp, size_t size);
void add_assoc_stringl_ex(zval *arg, char *key, int key_len, char *str, int str_len, int duplicate);
void add_assoc_bool_ex(zval *arg, char *key, int key_len, int b);
void efree(void *ptr);
void zval_add_ref(zval *z);

extern void *spl_ce_SplFileInfo;
extern void *spl_ce_DirectoryIterator;
extern void *spl_ce_RecursiveDirectoryIterator;
extern void *spl_ce_SplFileObject;
extern void *php_glob_stream_ops;