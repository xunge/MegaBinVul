#include <stddef.h>

#define NFTA_EXPR_MAX 255
#define NFTA_EXPR_DATA 1
#define NFTA_EXPR_NAME 2
#define EINVAL 22
#define ENOENT 2 
#define EOPNOTSUPP 95

struct nft_ctx {
    int family;
};

struct nlattr {
    int dummy;
};

struct nft_expr_info {
    struct nlattr **tb;
    const struct nlattr *attr;
    const struct nft_expr_ops *ops;
};

struct nft_expr_type {
    const struct nft_expr_ops *inner_ops;
    const struct nla_policy *policy;
    int maxattr;
};

struct nft_expr_ops {
    int dummy;
};

struct nla_policy {
    int dummy;
};

extern const struct nla_policy nft_expr_policy[];
extern const struct nft_expr_type *__nft_expr_type_get(int family, const struct nlattr *nla);
extern int nla_parse_nested_deprecated(struct nlattr **tb, int maxtype, const struct nlattr *nla, const struct nla_policy *policy, void *extack);