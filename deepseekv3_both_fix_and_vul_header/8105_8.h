#include <stdint.h>
#include <stddef.h>

typedef struct _php_snmp_object {
    long oid_output_format;
} php_snmp_object;

#define NETSNMP_OID_OUTPUT_SUFFIX 0
#define NETSNMP_OID_OUTPUT_MODULE 1
#define NETSNMP_OID_OUTPUT_FULL 2
#define NETSNMP_OID_OUTPUT_NUMERIC 3
#define NETSNMP_OID_OUTPUT_UCD 4
#define NETSNMP_OID_OUTPUT_NONE 5

#define TSRMLS_DC
#define TSRMLS_CC
#define SUCCESS 0
#define FAILURE -1
#define E_WARNING 2

typedef struct _zval_struct {
    int type;
    long value;
} zval;

#define Z_TYPE_P(zp) ((zp)->type)
#define Z_LVAL_P(zp) ((zp)->value)
#define IS_LONG 1

void zval_copy_ctor(zval *z);
void convert_to_long(zval *z);
void zval_dtor(zval *z);
void php_error_docref(const char *ref, int type, const char *format, ...);

static int php_snmp_write_oid_output_format(php_snmp_object *snmp_object, zval *newval TSRMLS_DC);

#define PHP_SNMP_BOOL_PROPERTY_WRITER_FUNCTION(name) \
static int name(php_snmp_object *snmp_object, zval *newval) \
{ \
    return php_snmp_write_oid_output_format(snmp_object, newval); \
}