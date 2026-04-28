#include <stdint.h>
#include <stdlib.h>

typedef int32_t pj_status_t;
typedef uint8_t pj_uint8_t;
typedef uint32_t pj_uint32_t;

typedef struct pj_pool_t pj_pool_t;

struct pj_stun_attr_hdr {
    uint16_t type;
    uint16_t length;
};

typedef struct pj_stun_msg_hdr {
    uint16_t type;
    uint16_t length;
    uint32_t magic;
    uint8_t id[12];
} pj_stun_msg_hdr;

typedef struct pj_stun_uint_attr {
    struct pj_stun_attr_hdr hdr;
    pj_uint32_t value;
} pj_stun_uint_attr;

#define PJ_UNUSED_ARG(x) (void)(x)
#define PJ_POOL_ZALLOC_T(pool, type) ((type *)calloc(1, sizeof(type)))
#define GETATTRHDR(buf, hdr) do { \
    (hdr)->type = ((buf)[0] << 8) | (buf)[1]; \
    (hdr)->length = ((buf)[2] << 8) | (buf)[3]; \
} while(0)
#define GETVAL32H(buf, pos) (((buf)[pos] << 24) | ((buf)[(pos)+1] << 16) | \
                            ((buf)[(pos)+2] << 8) | (buf)[(pos)+3])

#define PJ_SUCCESS 0
#define PJNATH_ESTUNINATTRLEN (-1)