#include <string.h>
#include <stdlib.h>

typedef int zend_bool;
typedef struct _zval_struct zval;
typedef struct _post_var_data_t {
    char *ptr;
    char *end;
    size_t already_scanned;
} post_var_data_t;

typedef struct _sapi_module_struct {
    int (*input_filter)(int type, char *var, char **val, size_t vlen, unsigned int *new_vlen);
} sapi_module_struct;

extern sapi_module_struct sapi_module;

#define TSRMLS_DC
#define TSRMLS_CC
#define PARSE_POST 0

extern void *efree(void *ptr);
extern char *estrndup(const char *s, size_t len);
extern size_t php_url_decode(char *str, size_t len);
extern int php_register_variable_safe(char *name, char *val, size_t vlen, zval *arr);