#include <limits.h>
#include <stddef.h>

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define ZEND_NUM_ARGS() ht
#define TSRMLS_CC
#define TSRMLS_DC
#define FAILURE (-1)
#define SUCCESS 0
#define ENT_COMPAT 0
#define RETVAL_STRINGL(s, l, dup) do { } while(0)
#define RETURN_FALSE do { } while(0)

typedef int zend_bool;
typedef struct _zval_struct zval;

void efree(void *ptr);
char *php_escape_html_entities_ex(char *str, int str_len, size_t *new_len, int all, int flags, char *hint_charset, zend_bool double_encode);
int zend_parse_parameters(int num_args, const char *type_spec, ...);