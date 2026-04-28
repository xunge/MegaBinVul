#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#define TCA_FLOWER_KEY_ENC_OPT_GENEVE_MAX 3
#define TCA_FLOWER_KEY_ENC_OPT_GENEVE_CLASS 1
#define TCA_FLOWER_KEY_ENC_OPT_GENEVE_TYPE 2
#define TCA_FLOWER_KEY_ENC_OPT_GENEVE_DATA 3
#define TCA_FLOWER_KEY_ENC_OPTS_GENEVE 1

#define FLOW_DIS_TUN_OPTS_MAX 255
#define IP_TUNNEL_OPTS_MAX 255

struct nlattr {
    int nla_type;
    int nla_len;
};

struct netlink_ext_ack {
    char *msg;
};

struct fl_flow_key {
    struct {
        uint8_t data[FLOW_DIS_TUN_OPTS_MAX];
        int len;
    } enc_opts;
};

struct geneve_opt {
    uint16_t opt_class;
    uint8_t type;
    uint8_t length:6;
    uint8_t r1:2;
    uint8_t r2;
    uint8_t r3;
    uint8_t opt_data[];
};

struct nla_policy {
    unsigned int type;
    unsigned int len;
};

static const struct nla_policy geneve_opt_policy[TCA_FLOWER_KEY_ENC_OPT_GENEVE_MAX + 1];

static inline void *nla_data(const struct nlattr *nla) {
    return (void *)(nla + 1);
}

static inline int nla_len(const struct nlattr *nla) {
    return nla->nla_len - sizeof(*nla);
}

static inline int nla_type(const struct nlattr *nla) {
    return nla->nla_type;
}

static inline uint8_t nla_get_u8(const struct nlattr *nla) {
    return *(uint8_t *)nla_data(nla);
}

static inline uint16_t nla_get_be16(const struct nlattr *nla) {
    return *(uint16_t *)nla_data(nla);
}

static inline void NL_SET_ERR_MSG(struct netlink_ext_ack *extack, const char *msg) {
    extack->msg = (char *)msg;
}

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))

static int nla_parse_nested_deprecated(struct nlattr *tb[], int maxtype,
                                      const struct nlattr *nla,
                                      const struct nla_policy *policy,
                                      struct netlink_ext_ack *extack) {
    return 0;
}