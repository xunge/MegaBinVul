#include <stdbool.h>
#include <stddef.h>

enum nft_trans_phase {
    NFT_TRANS_PREPARE,
    NFT_TRANS_PREPARE_ERROR,
    NFT_TRANS_COMMIT
};

enum nft_registers {
    NFT_REG_VERDICT
};

enum nft_verdicts {
    NFT_JUMP,
    NFT_GOTO
};

struct list_head {
    struct list_head *next, *prev;
};

struct nft_ctx {
    struct net *net;
    struct nft_chain *chain;
};

struct nft_expr {
};

struct nft_data {
    union {
        struct {
            enum nft_verdicts code;
            struct nft_chain *chain;
        } verdict;
    };
};

struct nft_immediate_expr {
    struct nft_data data;
    enum nft_registers dreg;
};

struct nft_chain {
    bool bound;
    struct list_head rules;
    struct nft_table *table;
};

struct nft_rule {
    struct list_head list;
};

struct nft_table {
    int use;
};

struct net {
};

#define fallthrough

#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != (typeof(*pos)*)(head); pos = NULL)

static inline bool nft_chain_binding(const struct nft_chain *chain) { return false; }
static inline void nft_rule_expr_deactivate(const struct nft_ctx *ctx, struct nft_rule *rule, enum nft_trans_phase phase) {}
static inline void nf_tables_unbind_chain(const struct nft_ctx *ctx, struct nft_chain *chain) {}
static inline void nft_deactivate_next(struct net *net, struct nft_chain *chain) {}
static inline void nft_chain_del(struct nft_chain *chain) {}
static inline void nft_use_dec(int *use) {}
static inline void nft_data_release(const struct nft_data *data, int type) {}
static inline int nft_dreg_to_type(enum nft_registers dreg) { return 0; }
static inline void *nft_expr_priv(const struct nft_expr *expr) { return NULL; }