#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member), \
         n = container_of(pos->member.next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = n, n = container_of(n->member.next, typeof(*n), member))

struct net;
struct nft_table {
    int family;
    struct list_head chains;
    struct list_head flowtables;
    struct list_head sets;
    struct list_head objects;
    int use;
};

struct nft_flowtable {
    struct list_head list;
};

struct nft_chain {
    struct list_head list;
    struct list_head rules;
    int use;
};

struct nft_object {
    struct list_head list;
};

struct nft_rule {
    struct list_head list;
};

struct nft_set {
    struct list_head list;
    int flags;
};

struct nft_ctx {
    struct net *net;
    int family;
    struct nft_table *table;
    struct nft_chain *chain;
};

enum {
    NFPROTO_NETDEV,
    NFT_SET_MAP = 1 << 0,
    NFT_SET_OBJECT = 1 << 1
};

static inline void list_del(struct list_head *entry) {
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
}

static inline int nft_chain_is_bound(struct nft_chain *chain) { return 0; }
static inline void nft_use_dec(int *use) { (*use)--; }
static inline void nf_tables_rule_release(struct nft_ctx *ctx, struct nft_rule *rule) {}
static inline void nf_tables_flowtable_destroy(struct nft_flowtable *flowtable) {}
static inline void nft_map_deactivate(struct nft_ctx *ctx, struct nft_set *set) {}
static inline void nft_set_destroy(struct nft_ctx *ctx, struct nft_set *set) {}
static inline void nft_obj_del(struct nft_object *obj) {}
static inline void nft_obj_destroy(struct nft_ctx *ctx, struct nft_object *obj) {}
static inline void nft_chain_del(struct nft_chain *chain) {}
static inline void nf_tables_chain_destroy(struct nft_ctx *ctx) {}
static inline void nf_tables_table_destroy(struct nft_ctx *ctx) {}