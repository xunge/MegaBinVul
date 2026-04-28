#include <stdint.h>
#include <string.h>

typedef unsigned int zend_uint;
typedef unsigned char zend_bool;
typedef uint64_t zend_ulong;

typedef struct _zend_accel_hash_entry {
    zend_ulong hash_value;
    char *key;
    zend_uint key_length;
    void *data;
    zend_bool indirect;
    struct _zend_accel_hash_entry *next;
} zend_accel_hash_entry;

typedef struct _zend_accel_hash {
    zend_accel_hash_entry **hash_table;
    zend_accel_hash_entry *hash_entries;
    zend_uint num_entries;
    zend_uint max_num_entries;
    zend_uint num_direct_entries;
} zend_accel_hash;

typedef struct _zend_compiler_globals {
    zend_ulong root_hash;
} zend_compiler_globals;

extern zend_compiler_globals ZCG;
extern zend_ulong zend_inline_hash_func(char *key, zend_uint key_length);

#define ZCG(v) (ZCG.v)