#include <stdarg.h>
#include <stdio.h>
#include <string.h>

typedef struct _zval_struct zval;
typedef struct _php_snmp_object php_snmp_object;

#define Z_SNMP_P(zval_p) ((php_snmp_object *)(zval_p))
#define PHP_SNMP_ERRNO_NOERROR 0
#define E_WARNING 0

struct _php_snmp_object {
    char snmp_errstr[256];
    int snmp_errno;
    int exceptions_enabled;
};

typedef struct _zend_class_entry zend_class_entry;
extern zend_class_entry *php_snmp_exception_ce;

void php_verror(const char *docref, const char *param, int type, const char *format, va_list args);
void zend_throw_exception_ex(zend_class_entry *exception_ce, int code, const char *format, ...);