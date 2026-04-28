#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;

struct nlattr;
struct nft_set_desc {
    unsigned int field_count;
    unsigned int field_len[];
};

#define EINVAL 22
#define E2BIG 7
#define NFT_REG32_COUNT 8
#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))
#define NFTA_LIST_ELEM 1

extern int nft_set_desc_concat_parse(struct nlattr *attr, struct nft_set_desc *desc);

#define nla_for_each_nested(attr, nla, rem) \
    for (attr = nla_data(nla), rem = nla_len(nla); \
         nla_ok(attr, rem); \
         attr = nla_next(attr, &(rem)))

static inline int nla_type(const struct nlattr *nla) { return 0; }
static inline void *nla_data(const struct nlattr *nla) { return NULL; }
static inline int nla_len(const struct nlattr *nla) { return 0; }
static inline struct nlattr *nla_next(const struct nlattr *nla, int *remaining) { return NULL; }
static inline int nla_ok(const struct nlattr *nla, int remaining) { return 0; }