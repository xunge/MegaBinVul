#include <string.h>
#include <errno.h>
#include <stddef.h>

#define TSRMLS_DC
#define TSRMLS_CC
#define SUCCESS 0
#define FAILURE -1
#define FALSE 0
#define TRUE 1
#define MAX_NAME_LEN 128
#define MAX_OID_LEN 128
#define SNMP_CMD_SET 1
#define SNMP_CMD_WALK 2
#define PHP_SNMP_ERRNO_OID_PARSING_ERROR 1
#define E_WARNING 2
#define IS_ARRAY 7
#define IS_STRING 6
#define IS_REF 8

typedef unsigned int oid;

typedef struct {
    char *oid;
    char type;
    char *value;
    oid name[MAX_OID_LEN];
    size_t name_length;
} snmpobjarg;

struct objid_query {
    int count;
    int offset;
    int step;
    int array_output;
    snmpobjarg *vars;
};

typedef struct _zval {
    int type;
    union {
        long lval;
        double dval;
        struct {
            char *val;
            int len;
        } str;
        void *ht;
    } value;
    unsigned char is_ref;
} zval;

typedef struct _HashPosition {
    void *pos;
} HashPosition;

static oid objid_mib[] = {1, 3, 6, 1, 2, 1};

#define Z_ISREF_PP(ppz) ((*ppz)->is_ref)
#define Z_STRVAL_PP(ppz) ((*ppz)->value.str.val)
#define Z_STRLEN_PP(ppz) ((*ppz)->value.str.len)
#define Z_TYPE_PP(ppz) ((*ppz)->type)
#define Z_ARRVAL_PP(ppz) ((*ppz)->value.ht)

void *emalloc(size_t size);
void efree(void *ptr);
void SEPARATE_ZVAL(zval **ppz);
void convert_to_string_ex(zval **ppz);
int zend_hash_num_elements(void *ht);
int zend_hash_internal_pointer_reset_ex(void *ht, HashPosition *pos);
int zend_hash_get_current_data_ex(void *ht, void **pData, HashPosition *pos);
int zend_hash_move_forward_ex(void *ht, HashPosition *pos);
int snmp_parse_oid(const char *string, oid *objid, size_t *objidlen);
void php_error_docref(const char *docref, int type, const char *format, ...);
void php_snmp_error(zval *object, int dummy, int errno, const char *format, ...);