#include <stdint.h>
#include <string.h>

typedef unsigned int zend_uint;
typedef unsigned long zend_ulong;

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

typedef struct {
    zend_ulong root_hash;
} zend_compiler_globals;
#define ZCG(v) (compiler_globals.v)
extern zend_compiler_globals compiler_globals;

extern zend_ulong zend_inline_hash_func(char *key, zend_uint key_length);