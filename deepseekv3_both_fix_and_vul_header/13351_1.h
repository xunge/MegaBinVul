#include <stdbool.h>
#include <linux/types.h>

#define fallthrough do {} while (0)

enum nft_trans_phase {
    NFT_TRANS_PREPARE,
    NFT_TRANS_ABORT,
    NFT_TRANS_RELEASE,
    NFT_TRANS_COMMIT
};

struct nft_ctx {
    struct net *net;
};

struct nft_set {
    bool anonymous;
    unsigned int use;
};

struct nft_set_binding {
};

struct net {
};

bool nft_set_is_anonymous(const struct nft_set *set);
void nft_deactivate_next(struct net *net, struct nft_set *set);
void nf_tables_unbind_set(const struct nft_ctx *ctx, struct nft_set *set,
                         struct nft_set_binding *binding, bool commit);