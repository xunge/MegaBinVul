typedef struct _zval_struct {
    long type;
    union {
        long lval;
    } value;
} zval;

typedef struct _php_snmp_object {
    long exceptions_enabled;
} php_snmp_object;

#define TSRMLS_DC
#define SUCCESS 0
#define IS_LONG 4
#define Z_TYPE_P(zval_p) (zval_p)->type
#define Z_LVAL_P(zval_p) (zval_p)->value.lval

static void zval_copy_ctor(zval *z) {}
static void convert_to_long(zval *z) {}
static void zval_dtor(zval *z) {}