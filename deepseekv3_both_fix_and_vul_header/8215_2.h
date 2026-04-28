#include <unicode/utypes.h>
#include <unicode/uloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _zend_execute_data zend_execute_data;
typedef struct _zval_struct zval;
typedef struct _zend_function_entry zend_function_entry;
typedef struct _zend_module_entry zend_module_entry;
typedef struct _zend_class_entry zend_class_entry;

#define INTERNAL_FUNCTION_PARAMETERS zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define TSRMLS_CC
#define TSRMLS_C
#define ZEND_NUM_ARGS() 0
#define FAILURE -1
#define RETURN_FALSE
#define RETURN_STRING(s, dup)
#define RETURN_NULL()
#define U_ZERO_ERROR 0
#define U_ILLEGAL_ARGUMENT_ERROR 1

void intl_error_reset(void *);
void intl_error_set(void *, int, char *, int);
char *intl_locale_get_default(TSRMLS_C);
char *get_icu_value_internal(const char *, char *, int *, int);
int spprintf(char **, size_t, const char *, ...);
void efree(void *);