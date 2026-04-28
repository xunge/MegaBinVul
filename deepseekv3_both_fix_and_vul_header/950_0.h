#include <string.h>

typedef unsigned int zend_uint;
typedef unsigned long zend_ulong;

#define SUCCESS 0
#define FAILURE -1
#ifndef ZEND_WIN32
#define ZCG(root_hash) 0
#endif

typedef struct _zend_accel_hash_entry zend_accel_hash_entry;
struct _zend_accel_hash_entry {
    zend_ulong hash_value;
    zend_uint key_length;
    char *key;
    zend_accel_hash_entry *next;
    int indirect;
};

typedef struct _zend_accel_hash zend_accel_hash;
struct _zend_accel_hash {
    zend_accel_hash_entry **hash_table;
    zend_ulong max_num_entries;
    zend_ulong num_direct_entries;
};

static zend_ulong zend_inline_hash_func(char *key, zend_uint key_length);