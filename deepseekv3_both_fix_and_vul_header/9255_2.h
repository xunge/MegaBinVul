#include <stddef.h>

typedef struct _zval_struct {
    int type;
    void *value;
} zval;

typedef struct _Bucket {
    struct _Bucket *pListTail;
    // other bucket fields...
} Bucket;

typedef struct _hashtable {
    Bucket *pListTail;
    // other hashtable fields...
} HashTable;

typedef struct _spl_array_object {
    zval *array;
    Bucket *pos;
    // other array object fields...
} spl_array_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define IS_OBJECT 7
#define E_NOTICE 8
#define E_RECOVERABLE_ERROR 4096

#define Z_TYPE_P(zval_p) ((zval_p)->type)
#define Z_OBJCE_P(zval_p) ((zobj_ce*)((zval_p)->value))

typedef struct _zobj_ce {
    char *name;
    // other class entry fields...
} zobj_ce;

extern spl_array_object* zend_object_store_get_object(zval *object TSRMLS_DC);
extern HashTable* spl_array_get_hash_table(spl_array_object *intern, int check_std_props TSRMLS_DC);
extern void php_error_docref(const char *docref TSRMLS_DC, int type, const char *format, ...);
extern void spl_array_write_dimension(zval *object, zval *offset, zval *value TSRMLS_DC);
extern void spl_array_set_pos(spl_array_object *intern, Bucket *pos);