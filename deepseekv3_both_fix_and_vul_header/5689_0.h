#include <stdlib.h>
#include <string.h>

typedef int zval;
typedef int php_unserialize_data_t;
typedef unsigned int php_uint32;

#define TSRMLS_DC
#define TSRMLS_CC
#define PHAR_GET_32(buffer, len)
#define ALLOC_ZVAL(z)
#define INIT_ZVAL(z)
#define PHP_VAR_UNSERIALIZE_INIT(hash)
#define PHP_VAR_UNSERIALIZE_DESTROY(hash)
#define zval_ptr_dtor(z)
#define PHAR_G(flag) 0
#define pemalloc(size, persistent) malloc(size)
#define SUCCESS 0
#define FAILURE -1

int php_var_unserialize(zval **rval, const unsigned char **p, const unsigned char *max, php_unserialize_data_t *var_hash TSRMLS_DC);