#include <signal.h>
#include <errno.h>
#include <string.h>
#include <time.h>

typedef struct _zval_struct {
    long type;
    union {
        long lval;
        double dval;
        struct {
            void *ptr;
            int type;
        } ht;
    } value;
} zval;

typedef struct _HashPosition {
    void *pos;
} HashPosition;

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define TSRMLS_CC
#define ZEND_NUM_ARGS() ht
#define FAILURE -1
#define SUCCESS 0
#define IS_LONG 1
#define IS_ARRAY 7
#define RETURN_FALSE do { return_value->value.lval = 0; return; } while (0)
#define RETURN_LONG(l) do { return_value->value.lval = l; return; } while (0)
#define Z_ARRVAL_P(zv) ((zv)->value.ht)
#define Z_TYPE_PP(ppzv) ((*ppzv)->type)
#define Z_LVAL_PP(ppzv) ((*ppzv)->value.lval)
#define Z_TYPE_P(zv) ((zv)->type)
#define SEPARATE_ZVAL(ppzv)
#define convert_to_long_ex(ppzv)
#define zend_hash_internal_pointer_reset_ex(ht, pos)
#define zend_hash_get_current_data_ex(ht, data, pos) 0
#define zend_hash_move_forward_ex(ht, pos)
#define PCNTL_G(last_error) errno
#define php_error_docref(ref, level, fmt, ...)
#define zval_dtor(zv)
#define array_init(zv)
#define zend_hash_clean(ht)
#define add_assoc_long_ex(zv, key, len, val)
#define add_assoc_double_ex(zv, key, len, val)
#define EMPTY_SWITCH_DEFAULT_CASE() default: break