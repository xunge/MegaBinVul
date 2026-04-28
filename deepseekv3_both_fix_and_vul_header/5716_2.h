#include <signal.h>
#include <time.h>
#include <errno.h>
#include <string.h>

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define TSRMLS_CC
#define ZEND_NUM_ARGS() ht
#define FAILURE -1
#define SUCCESS 0
#define IS_LONG 1
#define IS_ARRAY 7
#define E_WARNING 2
#define RETURN_FALSE do { return; } while(0)
#define RETURN_LONG(x) do { return; } while(0)
#define PCNTL_G(x) pcntl_globals.x
#define SEPARATE_ZVAL(x)
#define convert_to_long_ex(x)
#define Z_ARRVAL_P(x) ((x)->value.ht)
#define Z_TYPE_PP(x) ((*x)->type)
#define Z_LVAL_PP(x) ((*x)->value.lval)
#define Z_TYPE_P(x) ((x)->type)
#define array_init(x)
#define zval_dtor(x)
#define zend_hash_clean(x)
#define add_assoc_long_ex(a, b, c, d)
#define add_assoc_double_ex(a, b, c, d)
#define EMPTY_SWITCH_DEFAULT_CASE() default: break

typedef struct _zval_struct {
    int type;
    union {
        long lval;
        void *ht;
    } value;
} zval;

typedef struct _HashTable {
    /* dummy structure */
    int dummy;
} HashTable;

typedef struct _HashPosition {
    /* dummy structure */
    int dummy;
} HashPosition;

typedef struct {
    int last_error;
} pcntl_globals_struct;

extern pcntl_globals_struct pcntl_globals;

void php_error_docref(const char *docref, int type, const char *format, ...);
int zend_parse_parameters(int num_args, const char *type_spec, ...);
void zend_hash_internal_pointer_reset_ex(HashTable *ht, HashPosition *pos);
int zend_hash_get_current_data_ex(HashTable *ht, void **data, HashPosition *pos);
void zend_hash_move_forward_ex(HashTable *ht, HashPosition *pos);