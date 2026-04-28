#include <string.h>
#include <stddef.h>

struct sk_buff;
struct nlattr;

struct xfrm_algo_auth {
    char alg_name[64];
    unsigned int alg_key_len;
    char alg_key[0];
};

struct xfrm_algo {
    char alg_name[64];
    unsigned int alg_key_len;
    char alg_key[0];
};

#define XFRMA_ALG_AUTH 1
#define EMSGSIZE 90

struct nlattr *nla_reserve(struct sk_buff *skb, int attrtype, int attrlen);
void *nla_data(const struct nlattr *nla);