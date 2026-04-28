#include <stddef.h>

typedef struct _zval_struct zval;
typedef struct _zend_class_entry zend_class_entry;
typedef struct _spl_SplObjectStorage spl_SplObjectStorage;
typedef struct _spl_SplObjectStorageElement spl_SplObjectStorageElement;

#define TSRMLS_DC
#define TSRMLS_CC
#define EG(e) (0)
#define SUCCESS 0
#define IS_LONG 1
#define IS_STRING 2
#define RETURN_FALSE do { return; } while (0)
#define ALLOC_INIT_ZVAL(zv) do { (zv) = NULL; } while (0)
#define Z_LVAL_P(zv) (0)
#define Z_STRLEN_P(zv) (0)
#define Z_STRVAL_P(zv) (NULL)
#define Z_TYPE_P(zv) (0)
#define Z_OBJCE_P(zv) ((zend_class_entry*)0)

struct _spl_SplObjectStorage {
    void *storage;
    void *pos;
    int flags;
};

struct _spl_SplObjectStorageElement {
    zval *obj;
    zval *inf;
};

struct _zend_class_entry {
    struct {
        void *zf_valid;
        void *zf_current;
        void *zf_key;
    } iterator_funcs;
};

#define MIT_NEED_ALL 1
#define MIT_KEYS_ASSOC 2
#define SPL_MULTIPLE_ITERATOR_GET_ALL_CURRENT 0

extern void zend_hash_internal_pointer_reset_ex(void *ht, void *pos);
extern int zend_hash_get_current_data_ex(void *ht, void **data, void *pos);
extern void zend_hash_move_forward_ex(void *ht, void *pos);
extern int zend_hash_num_elements(void *ht);
extern void zend_call_method_with_0_params(zval **object, zend_class_entry *ce, void **function_ptr, const char *function_name, zval **retval);
extern void zval_ptr_dtor(zval **zval_ptr);
extern void zend_throw_exception(zend_class_entry *exception_ce, const char *message, int code TSRMLS_DC);
extern void array_init_size(zval *arg, int size);
extern void add_index_zval(zval *arg, int index, zval *value);
extern void add_assoc_zval_ex(zval *arg, const char *key, size_t key_len, zval *value);
extern void add_next_index_zval(zval *arg, zval *value);

zend_class_entry *spl_ce_RuntimeException;
zend_class_entry *spl_ce_InvalidArgumentException;