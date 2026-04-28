#include <stdint.h>
#include <stddef.h>

typedef unsigned int uint;
typedef unsigned long ulong;

typedef struct _zend_object_iterator {
    void *data;
} zend_object_iterator;

typedef struct _spl_array_it {
    zend_object_iterator intern;
    struct _spl_array_object *object;
} spl_array_it;

typedef struct _spl_array_object {
    uint ar_flags;
    void *pos;
} spl_array_object;

typedef struct _HashTable {
    void *dummy;
} HashTable;

#define TSRMLS_DC
#define TSRMLS_CC
#define FAILURE -1
#define HASH_KEY_NON_EXISTANT -1
#define SPL_ARRAY_OVERLOADED_KEY (1<<0)

int zend_user_it_get_current_key(zend_object_iterator *iter, char **str_key, uint *str_key_len, ulong *int_key);
int spl_array_get_hash_table(spl_array_object *object, int flags);
int spl_array_object_verify_pos_ex(spl_array_object *object, HashTable *aht, const char *message);
int zend_hash_get_current_key_ex(HashTable *ht, char **str_key, uint *str_key_len, ulong *int_key, int duplicate, void *pos);