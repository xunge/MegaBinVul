#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned long u_long;

typedef struct {
    u_char *qb2;
} querybuf;

typedef struct _zval_struct {
    void *value;
    int type;
} zval;

#define DNS_T_A ns_t_a
#define DNS_T_NS ns_t_ns
#define DNS_T_CNAME ns_t_cname
#define DNS_T_SOA ns_t_soa
#define DNS_T_PTR ns_t_ptr
#define DNS_T_HINFO ns_t_hinfo
#define DNS_T_MX ns_t_mx
#define DNS_T_TXT ns_t_txt
#define DNS_T_AAAA ns_t_aaaa
#define DNS_T_SRV ns_t_srv
#define DNS_T_NAPTR ns_t_naptr
#define DNS_T_A6 ns_t_a6
#define T_ANY ns_t_any

#define ALLOC_INIT_ZVAL(z) (z) = malloc(sizeof(zval))
#define MAKE_STD_ZVAL(z) (z) = malloc(sizeof(zval))
#define array_init(z) ((z)->type = 1)
#define add_assoc_string(z, k, v, d) 
#define add_assoc_stringl(z, k, v, l, d) 
#define add_assoc_long(z, k, v) 
#define add_assoc_zval(z, k, v) 
#define add_next_index_stringl(z, v, l, d) 
#define zval_ptr_dtor(z) free(z)
#define emalloc malloc