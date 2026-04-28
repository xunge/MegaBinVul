#include <stdarg.h>
#include <stdio.h>
#include <string.h>

typedef struct _zval_struct zval;
typedef struct _zend_object_store zend_object_store;
typedef struct _php_snmp_object php_snmp_object;
typedef struct _zend_class_entry zend_class_entry;

#define TSRMLS_DC
#define TSRMLS_CC
#define PHP_SNMP_ERRNO_NOERROR 0
#define E_WARNING 0

void *zend_object_store_get_object(zval *object TSRMLS_DC);
void zend_throw_exception_ex(zend_class_entry *ce, int type TSRMLS_DC, const char *format, ...);
void php_verror(const char *docref, const char *param, int type, const char *format, va_list args TSRMLS_DC);

struct _php_snmp_object {
    char snmp_errstr[256];
    int snmp_errno;
    int exceptions_enabled;
};

extern zend_class_entry *php_snmp_exception_ce;