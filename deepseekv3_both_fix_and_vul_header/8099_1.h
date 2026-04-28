#include <stddef.h>

typedef struct _zval_struct {
    int type;
    long value;
} zval;

#define Z_TYPE_P(zval_p) ((zval_p)->type)
#define Z_LVAL_P(zval_p) ((zval_p)->value)
#define IS_NULL 0
#define IS_LONG 1

typedef struct _php_snmp_object {
    int max_oids;
} php_snmp_object;

#define TSRMLS_DC
#define TSRMLS_CC
#define SUCCESS 0
#define E_WARNING 2

static void zval_copy_ctor(zval *z) {}
static void convert_to_long(zval *z) { z->type = IS_LONG; }
static void zval_dtor(zval *z) {}
static void php_error_docref(const char *ref, int type, const char *format, ...) {}