#include <stdlib.h>

typedef struct _zval_struct {
    int type;
    union {
        struct _HashTable *ht;
        void *ptr;
        long lval;
        double dval;
    } value;
} zval;

typedef struct _HashTable {
    unsigned int nApplyCount;
    unsigned int nTableSize;
    unsigned int nTableMask;
    unsigned int nNumOfElements;
    unsigned long nNextFreeElement;
    void *pInternalPointer;
    void *pListHead;
    void *pListTail;
    void **arBuckets;
} HashTable;

typedef struct _spl_array_object {
    HashTable *array;
    int ar_flags;
    void *std;
} spl_array_object;

typedef void* zend_object_value;

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define TSRMLS_CC
#define TSRMLS_DC
#define FAILURE (-1)
#define SUCCESS 0
#define IS_NULL 0
#define IS_ARRAY 7
#define ZEND_NUM_ARGS() ht
#define ZEND_PARSE_PARAMS_QUIET 0
#define SPL_ARRAY_METHOD_MAY_USER_ARG 1

#define MAKE_STD_ZVAL(zv) do { (zv) = (zval *)malloc(sizeof(zval)); } while (0)
#define Z_TYPE_P(zv) ((zv)->type)
#define Z_ARRVAL_P(zv) ((zv)->value.ht)
#define COPY_PZVAL_TO_ZVAL(dst, src) do { (dst).type = (src)->type; (dst).value = (src)->value; } while (0)

extern zend_object_value getThis(void);
extern void *zend_object_store_get_object(zend_object_value obj);
extern HashTable *spl_array_get_hash_table(spl_array_object *intern, int flags);
extern int zend_parse_parameters_ex(int flags, int num_args, const char *type_spec, ...);
extern void zend_call_method(void *object, void *obj_ce, void **obj_pp, const char *method_name, int method_len, zval **retval_ptr_ptr, int param_count, zval *arg1, zval *arg2);
extern void zval_ptr_dtor(zval **zval_ptr);
extern void zend_throw_exception(void *exception, const char *message, int code);

extern void *spl_ce_BadMethodCallException;