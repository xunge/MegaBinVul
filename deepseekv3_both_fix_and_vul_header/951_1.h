#include <stdint.h>
#include <string.h>

typedef unsigned int zend_uint;
typedef uint64_t zend_ulong;

typedef struct _zend_accel_hash_entry zend_accel_hash_entry;
typedef struct _zend_accel_hash zend_accel_hash;

struct _zend_accel_hash_entry {
    zend_ulong hash_value;
    char *key;
    zend_uint key_length;
    void *data;
    zend_accel_hash_entry *next;
    int indirect;
};

struct _zend_accel_hash {
    zend_accel_hash_entry **hash_table;
    zend_ulong max_num_entries;
};

#ifndef ZEND_WIN32
zend_ulong ZCG_root_hash;
#define ZCG(root_hash) ZCG_root_hash
#endif

static zend_ulong zend_inline_hash_func(char *key, zend_uint key_length) {
    zend_ulong hash = 5381;
    for (; key_length--; key++) {
        hash = ((hash << 5) + hash) + *key;
    }
    return hash;
}