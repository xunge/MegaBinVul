#include <stdlib.h>

typedef struct _zval_struct {
    int refcount__gc;
    int is_ref__gc;
    int type;
    void *value;
} zval;

typedef struct _zend_function {
    const char *function_name;
} zend_function;

typedef struct _zend_class_entry {
    const char *name;
} zend_class_entry;

typedef struct _zend_object {
    zend_class_entry *ce;
} zend_object;

typedef struct _spl_array_object {
    zend_object std;
    zval *retval;
    zend_function *fptr_offset_get;
} spl_array_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define BP_VAR_W 0
#define BP_VAR_RW 1
#define BP_VAR_UNSET 2

#define ALLOC_INIT_ZVAL(z) do { \
    (z) = malloc(sizeof(zval)); \
    (z)->refcount__gc = 1; \
    (z)->is_ref__gc = 0; \
} while (0)

#define SEPARATE_ARG_IF_REF(z) if ((z)->is_ref__gc) { \
    zval *tmp = malloc(sizeof(zval)); \
    *tmp = *(z); \
    tmp->is_ref__gc = 0; \
    (z) = tmp; \
}

#define MAKE_STD_ZVAL(zv) ALLOC_INIT_ZVAL(zv)

#define Z_ISREF_P(z) ((z)->is_ref__gc)
#define Z_ISREF_PP(z) ((*(z))->is_ref__gc)
#define Z_REFCOUNT_PP(z) ((*(z))->refcount__gc)
#define Z_SET_REFCOUNT_P(z, rc) ((z)->refcount__gc = (rc))
#define Z_SET_ISREF_PP(z) ((*(z))->is_ref__gc = 1)
#define Z_DELREF_PP(z) ((*(z))->refcount__gc -= 1)
#define ZVAL_ZVAL(z, rv, copy, dtor) do { \
    *(z) = *(rv); \
    if (copy) (z)->refcount__gc++; \
} while (0)

static zval uninitialized_zval;
static zval *uninitialized_zval_ptr = &uninitialized_zval;
#define EG(uninitialized_zval_ptr) uninitialized_zval_ptr

static void zval_ptr_dtor(zval **z) {
    if (*z) {
        free(*z);
    }
}

static void zval_copy_ctor(zval *z) {
    z->refcount__gc = 1;
}

static zend_class_entry* Z_OBJCE_P(zval *z) {
    return ((zend_object*)z)->ce;
}

static void* zend_object_store_get_object(zval *z TSRMLS_DC) {
    return (void*)z;
}

static void zend_call_method_with_1_params(zval **object, zend_class_entry *ce, zend_function **fptr, const char *method_name, zval **rv, zval *param) {
    *rv = malloc(sizeof(zval));
    (*rv)->refcount__gc = 1;
    (*rv)->is_ref__gc = 0;
}

static zval** spl_array_get_dimension_ptr_ptr(int check_inherited, zval *object, zval *offset, int type TSRMLS_DC) {
    static zval *result;
    result = malloc(sizeof(zval));
    result->refcount__gc = 1;
    result->is_ref__gc = 0;
    return &result;
}