#include <stddef.h>
#include <stdbool.h>

struct nft_ctx;
struct net {
    unsigned int dummy;
};

struct nft_set {
    struct net net;
};

struct nft_set_iter {
    unsigned int genmask;
    unsigned int count;
    unsigned int skip;
    int err;
    int (*fn)(const struct nft_ctx *, struct nft_set *,
              struct nft_set_iter *, void *);
};

struct nft_pipapo {
    void *match;
    void *clone;
};

struct nft_pipapo_match {
    struct nft_pipapo_field *f;
    int field_count;
};

struct nft_pipapo_field {
    int rules;
    struct {
        struct nft_pipapo_elem *e;
    } *mt;
};

struct nft_set_elem_ext {
    unsigned int genmask;
};

struct nft_pipapo_elem {
    struct nft_set_elem_ext ext;
    void *priv;
};

static inline void *nft_set_priv(const struct nft_set *set)
{
    return (void *)set + sizeof(*set);
}

static inline unsigned int nft_genmask_cur(const struct net *net)
{
    return 0;
}

static inline bool nft_set_elem_active(const struct nft_set_elem_ext *ext,
                                     unsigned int genmask)
{
    return true;
}

#define rcu_read_lock()
#define rcu_read_unlock()
#define rcu_dereference(p) (p)
#define unlikely(x) (x)
#define read_pnet(p) (&(*(p)))