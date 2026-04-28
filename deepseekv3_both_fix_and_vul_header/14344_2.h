#include <stdint.h>

typedef int pj_status_t;
typedef struct pj_pool_t pj_pool_t;
typedef uint8_t pj_uint8_t;

typedef struct {
    char *ptr;
    int slen;
} pj_str_t;

typedef struct pj_stun_msg_hdr pj_stun_msg_hdr;

typedef struct pj_stun_attr_hdr {
    int length;
} pj_stun_attr_hdr;

typedef struct pj_stun_errcode_attr {
    pj_stun_attr_hdr hdr;
    int err_code;
    pj_str_t reason;
} pj_stun_errcode_attr;

#define PJ_UNUSED_ARG(x) (void)(x)
#define PJ_POOL_ZALLOC_T(pool, type) ((type*)0)
#define GETATTRHDR(buf, hdr) 
#define ATTR_HDR_LEN 0
#define PJ_SUCCESS 0

pj_status_t pj_strdup(pj_pool_t *pool, pj_str_t *dst, const pj_str_t *src);