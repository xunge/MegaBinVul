#include <stdint.h>
#include <errno.h>
#include <linux/netlink.h>

#define NLBL_CIPSOV4_A_DOI 1
#define NLBL_CIPSOV4_A_TAGLST 2
#define NLBL_CIPSOV4_A_TAG 3
#define NLBL_CIPSOV4_A_MAX 3

#define CIPSO_V4_TAG_MAXCNT 5
#define CIPSO_V4_TAG_INVALID 255

#define NLA_U32 1
#define NLA_NESTED 2
#define NLA_U8 3
#define NLA_F_NESTED (1 << 15)

typedef uint32_t u32;

struct genl_info {
    struct nlattr **attrs;
};

struct cipso_v4_doi {
    u32 doi;
    uint8_t tags[CIPSO_V4_TAG_MAXCNT + 1];
};

struct nla_policy {
    uint16_t type;
    uint16_t len;
};

static inline u32 nla_get_u32(const struct nlattr *nla) {
    return *(u32 *)((char *)nla + NLA_HDRLEN);
}

static inline uint8_t nla_get_u8(const struct nlattr *nla) {
    return *(uint8_t *)((char *)nla + NLA_HDRLEN);
}

static inline int nla_validate_nested(const struct nlattr *attr, int maxtype,
                                    const struct nla_policy *policy) {
    return 0;
}

#define nla_for_each_nested(pos, nla, rem) \
    for (pos = (struct nlattr *)((char *)nla + NLA_HDRLEN), rem = nla->nla_len - NLA_HDRLEN; \
         rem >= (int)sizeof(struct nlattr) && \
         pos->nla_len >= sizeof(struct nlattr) && \
         pos->nla_len <= rem; \
         rem -= NLA_ALIGN(pos->nla_len), \
         pos = (struct nlattr *)((char *)pos + NLA_ALIGN(pos->nla_len)))

const struct nla_policy netlbl_cipsov4_genl_policy[NLBL_CIPSOV4_A_MAX + 1] = {
    [NLBL_CIPSOV4_A_DOI] = { .type = NLA_U32 },
    [NLBL_CIPSOV4_A_TAGLST] = { .type = NLA_NESTED },
    [NLBL_CIPSOV4_A_TAG] = { .type = NLA_U8 }
};