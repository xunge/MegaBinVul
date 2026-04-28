#include <stddef.h>
#include <string.h>

typedef unsigned long ulong;
typedef int zend_bool;
#define TSRMLS_DC
#define SUCCESS 0

typedef struct _zend_hash {
    int dummy;
} zend_hash;

extern zend_hash xlat_table;
extern void *zend_hash_index_find(zend_hash *ht, ulong h, void **pData);

typedef struct _zend_compiler_globals {
    void *mem;
} zend_compiler_globals;
#define ZCG(v) (compiler_globals.v)

extern zend_compiler_globals compiler_globals;
extern void interned_efree(void *ptr);
extern void zend_shared_alloc_register_xlat_entry(void *old, void *new);

#define ZEND_ALIGNED_SIZE(size) (((size) + 7) & ~7)