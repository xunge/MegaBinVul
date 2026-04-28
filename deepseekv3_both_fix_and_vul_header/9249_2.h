#include <stddef.h>

typedef struct _HashTable HashTable;

typedef struct _zend_object_iterator {
    void *data;
    void *funcs;
} zend_object_iterator;

typedef struct _zend_object {
    void *properties;
} zend_object;

typedef struct _spl_array_it {
    zend_object_iterator intern;
    struct _spl_array_object *object;
    HashTable *ht;
    long pos;
    int valid;
} spl_array_it;

typedef struct _spl_array_object {
    zend_object std;
    HashTable *array;
    long flags;
    long ar_flags;
    long pos;
    long max_pos;
    long current;
    long current_valid;
    long current_key_type;
    void *current_key;
    void *current_data;
} spl_array_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define FAILURE (-1)
#define SPL_ARRAY_OVERLOADED_NEXT (1<<0)
#define SPL_ARRAY_IS_REF (1<<1)
#define E_NOTICE 8