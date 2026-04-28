#include <sys/select.h>
#include <stdlib.h>
#include <stddef.h>

typedef int php_socket_t;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef struct _hashtable {
    unsigned int nNumOfElements;
    void *pInternalPointer;
} HashTable;

typedef union _zvalue_value {
    long lval;
    struct {
        HashTable *ht;
    } arr;
} zvalue_value;

typedef struct _zval_struct {
    zvalue_value value;
    unsigned char type;
} zval;

typedef struct _php_stream {
    int fd;
} php_stream;

#define TSRMLS_DC
#define IS_ARRAY 7
#define SUCCESS 0
#define FAILURE -1
#define HASH_KEY_NON_EXISTENT 0
#define HASH_KEY_IS_LONG 1
#define HASH_KEY_IS_STRING 2

#define PHP_STREAM_AS_FD_FOR_SELECT 1
#define PHP_STREAM_CAST_INTERNAL 2
#define PHP_SAFE_FD_ISSET(fd, set) FD_ISSET(fd, set)

#define Z_TYPE_P(p) ((p)->type)
#define Z_ARRVAL_P(p) ((p)->value.arr.ht)
#define ALLOC_HASHTABLE(ht) (ht = malloc(sizeof(HashTable)))
#define ZVAL_PTR_DTOR NULL