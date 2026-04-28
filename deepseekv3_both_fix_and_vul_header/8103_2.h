#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef unsigned long oid;

struct counter64 {
    unsigned long high;
    unsigned long low;
};

typedef struct variable_list {
    struct variable_list *next_variable;
    oid *name;
    size_t name_length;
    unsigned char type;
    unsigned char val_len;
    union {
        unsigned char *string;
        oid *objid;
        unsigned char *bitstring;
        long *integer;
        unsigned long *unsigned_int;
        struct counter64 counter64;
        float *floatVal;
        double *doubleVal;
    } val;
} variable_list;

#define TSRMLS_DC
#define TSRMLS_CC
#define SNMP_VALUE_PLAIN 1
#define SNMP_VALUE_OBJECT 2
#define ASN_BIT_STR 0x03
#define ASN_OCTET_STR 0x04
#define ASN_NULL 0x05
#define ASN_OBJECT_ID 0x06
#define ASN_INTEGER 0x02
#define ASN_IPADDRESS 0x40
#define ASN_COUNTER 0x41
#define ASN_GAUGE 0x42
#define ASN_TIMETICKS 0x43
#define ASN_OPAQUE 0x44
#define ASN_COUNTER64 0x46
#define ASN_UINTEGER 0x47
#define ASN_OPAQUE_FLOAT 0x78
#define ASN_OPAQUE_DOUBLE 0x79
#define ASN_OPAQUE_I64 0x80
#define ASN_OPAQUE_U64 0x81

typedef struct _zval_struct {
    long value;
    struct {
        char *val;
        int len;
    } str;
    int type;
    int refcount__gc;
    int is_ref__gc;
} zval;

#define MAKE_STD_ZVAL(zv) do { \
    (zv) = (zval *)malloc(sizeof(zval)); \
    (zv)->refcount__gc = 1; \
    (zv)->is_ref__gc = 0; \
} while (0)

#define ZVAL_STRINGL(z, s, l, duplicate) do { \
    (z)->str.val = (duplicate) ? strndup((s), (l)) : (char *)(s); \
    (z)->str.len = (l); \
    (z)->type = 6; \
} while (0)

#define ZVAL_STRING(z, s, duplicate) ZVAL_STRINGL(z, s, strlen(s), duplicate)
#define ZVAL_NULL(z) (z)->type = 1
#define ZVAL_LONG(z, l) do { (z)->value = (l); (z)->type = 4; } while (0)
#define ZVAL_DOUBLE(z, d) do { (z)->value = (long)(d); (z)->type = 5; } while (0)

#define ALLOC_ZVAL(z) (z) = (zval *)malloc(sizeof(zval))
#define INIT_PZVAL(z) do { (z)->refcount__gc = 1; (z)->is_ref__gc = 0; } while (0)

#define zval_ptr_dtor(z) do { \
    if (*(z)) { \
        free(*(z)); \
        *(z) = NULL; \
    } \
} while (0)

#define zval_copy_ctor(z) (*(z) = *(z))
#define object_init(z) ((z)->type = 8)
#define add_property_long(z, name, l) (void)0
#define add_property_zval(z, name, zv) (void)0
#define php_error_docref(docref, type, ...) fprintf(stderr, __VA_ARGS__)
#define E_WARNING 2

static int snprint_value(char *buf, size_t buflen, oid *name, size_t name_length, struct variable_list *vars) { return 0; }
static int snprint_objid(char *buf, size_t buflen, oid *objid, size_t objidlen) { return 0; }
static void printI64(char *buf, struct counter64 val) {}
static void printU64(char *buf, struct counter64 val) {}

static void *emalloc(size_t size) { return malloc(size); }
static void *erealloc(void *ptr, size_t size) { return realloc(ptr, size); }
static void efree(void *ptr) { free(ptr); }