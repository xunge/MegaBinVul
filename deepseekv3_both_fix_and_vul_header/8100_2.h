#include <stdlib.h>
#include <stdint.h>

#define SNMP_DEFAULT_TIMEOUT 1000000
#define SNMP_DEFAULT_RETRIES 5
#define SNMP_VERSION_3 3
#define SNMP_CMD_SET 1
#define SNMP_CMD_GET 2
#define SNMP_CMD_GETNEXT 4
#define SNMP_CMD_WALK 8
#define SNMP_USE_SUFFIX_AS_KEYS 16
#define SNMP_ORIGINAL_NAMES_AS_KEYS 32
#define TRUE 1
#define FAILURE -1
#define E_WARNING 2
#define NETSNMP_DS_LIBRARY_ID 0
#define NETSNMP_DS_LIB_PRINT_NUMERIC_ENUM 0
#define NETSNMP_DS_LIB_QUICK_PRINT 0
#define NETSNMP_DS_LIB_OID_OUTPUT_FORMAT 0

typedef int zend_bool;
typedef struct _zval_struct {
    int type;
    void *value;
} zval;

typedef struct _php_snmp_object {
    void *session;
    int max_oids;
    zend_bool oid_increasing_check;
    int valueretrieval;
    zend_bool enum_print;
    zend_bool quick_print;
    int oid_output_format;
} php_snmp_object;

typedef struct _php_snmp_session {
    void *session;
} php_snmp_session;

typedef struct objid_query {
    int max_repetitions;
    int non_repeaters;
    int valueretrieval;
    zend_bool oid_increasing_check;
    void *vars;
    int step;
} objid_query;

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define INTERNAL_FUNCTION_PARAM_PASSTHRU ht, return_value, return_value_ptr, this_ptr, return_value_used
#define TSRMLS_CC
#define TSRMLS_DC
#define RETURN_FALSE return
#define ZEND_NUM_ARGS() 0
#define SNMP_G(x) 0

static inline zval* getThis() { return NULL; }
static inline int zend_parse_parameters(int argc, ...) { return 0; }
static inline int php_snmp_parse_oid(zval *this_ptr, int st, objid_query *query, ...) { return 0; }
static inline int netsnmp_session_init(php_snmp_session **session, ...) { return 0; }
static inline void efree(void *ptr) {}
static inline void netsnmp_session_free(php_snmp_session **session) {}
static inline int netsnmp_session_set_security(php_snmp_session *session, ...) { return 0; }
static inline void* zend_object_store_get_object(zval *obj) { return NULL; }
static inline void php_error_docref(const char *ref, ...) {}
static inline int netsnmp_ds_get_boolean(int library, int id) { return 0; }
static inline void netsnmp_ds_set_boolean(int library, int id, int value) {}
static inline int netsnmp_ds_get_int(int library, int id) { return 0; }
static inline void netsnmp_ds_set_int(int library, int id, int value) {}
static inline void php_snmp_internal(INTERNAL_FUNCTION_PARAMETERS, int st, php_snmp_session *session, objid_query *query) {}