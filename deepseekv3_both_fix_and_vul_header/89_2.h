#include <stdint.h>
#include <stddef.h>
#include <arpa/inet.h>

#define NFTA_SET_FIELD_MAX 1
#define NFTA_SET_FIELD_LEN 1
#define NFT_REG32_COUNT 10
#define BITS_PER_BYTE 8
#define U8_MAX 255
#define E2BIG 7
#define EINVAL 22
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef uint32_t u32;

struct nft_set_desc {
    unsigned int field_count;
    uint32_t field_len[NFT_REG32_COUNT];
};

struct nlattr {
    uint16_t nla_len;
    uint16_t nla_type;
};

const void *nft_concat_policy;

extern int nla_parse_nested_deprecated(struct nlattr *tb[], int maxtype, const struct nlattr *nla, const void *policy, void *extack);
extern uint32_t ntohl(uint32_t netlong);
extern uint32_t nla_get_be32(const struct nlattr *attr);