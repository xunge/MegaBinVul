#include <string.h>
#include <stdint.h>

#define XFRM_MAX_DEPTH 6
#define XFRMA_TMPL 1

struct sk_buff;

struct xfrm_address {
    union {
        uint32_t a4;
        uint32_t a6[4];
    };
};

struct xfrm_id {
    struct xfrm_address daddr;
    uint32_t spi;
    uint8_t proto;
};

struct xfrm_tmpl {
    struct xfrm_id id;
    int encap_family;
    struct xfrm_address saddr;
    uint32_t reqid;
    uint8_t mode;
    uint8_t share;
    uint8_t optional;
    uint32_t aalgos;
    uint32_t ealgos;
    uint32_t calgos;
};

struct xfrm_user_tmpl {
    struct xfrm_id id;
    int family;
    struct xfrm_address saddr;
    uint32_t reqid;
    uint8_t mode;
    uint8_t share;
    uint8_t optional;
    uint32_t aalgos;
    uint32_t ealgos;
    uint32_t calgos;
};

struct xfrm_policy {
    int xfrm_nr;
    struct xfrm_tmpl *xfrm_vec;
};

int nla_put(struct sk_buff *skb, int attrtype, int attrlen, const void *data);