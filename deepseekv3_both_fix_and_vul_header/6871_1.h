#include <stdint.h>

typedef int pj_status_t;
typedef uint8_t pj_uint8_t;
typedef struct pj_pool_t pj_pool_t;
typedef struct pj_stun_msg_hdr pj_stun_msg_hdr;
typedef struct pj_stun_errcode_attr pj_stun_errcode_attr;
typedef struct pj_str_t {
    char *ptr;
    int slen;
} pj_str_t;

#define PJ_UNUSED_ARG(x)
#define PJ_POOL_ZALLOC_T(pool, type) ((type*)0)
#define GETATTRHDR(buf, hdr)
#define ATTR_HDR_LEN 0
#define PJNATH_ESTUNINATTRLEN 0
#define PJ_SUCCESS 0

struct pj_stun_errcode_attr {
    struct {
        int length;
    } hdr;
    int err_code;
    pj_str_t reason;
};

pj_str_t* pj_strdup(pj_pool_t *pool, pj_str_t *dst, const pj_str_t *src);