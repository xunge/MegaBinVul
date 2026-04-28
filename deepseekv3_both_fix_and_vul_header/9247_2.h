#include <stddef.h>

#define SUCCESS 0
#define FAILURE -1
#define E_NOTICE 1
#define IS_OBJECT 8

typedef struct _spl_array_object {
    void *array;
    unsigned long pos;
} spl_array_object;

typedef struct _HashTable HashTable;
typedef unsigned long HashPosition;

#define Z_TYPE_P(zval_p) (*(int*)(zval_p))
#define TSRMLS_DC
#define TSRMLS_CC
#define php_error_docref(a, b, c)

HashTable* spl_array_get_hash_table(spl_array_object* intern, int flag);
int spl_array_rewind(spl_array_object* intern);
int spl_array_next(spl_array_object* intern);
void spl_array_set_pos(spl_array_object* intern, HashPosition pos);
unsigned long zend_hash_num_elements(HashTable* ht);