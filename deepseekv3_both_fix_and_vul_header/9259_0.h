#include <stdarg.h>
#include <stdio.h>

typedef struct _zend_class_entry zend_class_entry;

#define ZEND_FETCH_CLASS_EXCEPTION (1<<0)
#define E_ERROR 1

void zend_vspprintf(char **message, int max_len, const char *format, va_list args);
void zend_throw_error(zend_class_entry *exception_ce, const char *format, ...);
void zend_error(int type, const char *format, ...);
void efree(void *ptr);