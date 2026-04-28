#include <stdint.h>
#include <stddef.h>

#define E_WARNING 2

typedef struct _zval_struct {
    int type;
    long value;
} zval;

typedef struct _php_snmp_object {
    long valueretrieval;
} php_snmp_object;

#define IS_LONG 1
#define Z_TYPE_P(z) (z)->type
#define Z_LVAL_P(z) (z)->value
#define Z_LVAL(z) (z).value

#define SNMP_VALUE_LIBRARY 1
#define SNMP_VALUE_PLAIN 2
#define SNMP_VALUE_OBJECT 4

#define SUCCESS 0
#define FAILURE -1

#define TSRMLS_DC
#define TSRMLS_CC

static void zval_copy_ctor(zval *z) {}
static void convert_to_long(zval *z) { z->type = IS_LONG; }
static void zval_dtor(zval *z) {}
static void php_error_docref(const char *ref, int type, const char *msg, ...) {}