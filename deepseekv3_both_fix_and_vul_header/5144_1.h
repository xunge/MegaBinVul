#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <resolv.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHECKCP(n) if (cp + (n) > end) { return NULL; }

typedef struct {
    u_char *qb2;
} querybuf;

typedef struct _zval_struct zval;
typedef struct _zend_string zend_string;

struct _zend_string {
    char *val;
    size_t len;
};

struct _zval_struct {
    union {
        long lval;
        double dval;
        zend_string *str;
        struct {
            void *ptr;
            size_t len;
        } arr;
    } value;
    unsigned int type;
};

#define DNS_T_A     1
#define DNS_T_NS    2
#define DNS_T_CNAME 5
#define DNS_T_SOA   6
#define DNS_T_PTR   12
#define DNS_T_HINFO 13
#define DNS_T_MX    15
#define DNS_T_TXT   16
#define DNS_T_AAAA  28
#define DNS_T_SRV   33
#define DNS_T_NAPTR 35
#define DNS_T_A6    38
#define DNS_T_CAA   257

#define ZSTR_VAL(s) ((s)->val)
#define ZSTR_LEN(s) ((s)->len)

void ZVAL_UNDEF(zval *z);
void array_init(zval *z);
void add_assoc_string(zval *z, const char *key, const char *str);
void add_assoc_stringl(zval *z, const char *key, const char *str, unsigned int len);
void add_assoc_long(zval *z, const char *key, long l);
void add_assoc_zval(zval *z, const char *key, zval *value);
void add_assoc_str(zval *z, const char *key, zend_string *str);
void add_next_index_stringl(zval *z, const char *str, unsigned int len);
zend_string *zend_string_alloc(size_t len, int persistent);
void zval_ptr_dtor(zval *z);