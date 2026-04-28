#include <stddef.h>
#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != (head); pos = pos->member.next)

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos != (head); pos = n, n = pos ? pos->member.next : NULL)

#define list_empty(head) ((head)->next == (head))

struct nft_ctx;
struct nft_flowtable;
struct nft_chain;
struct nft_object;
struct nft_set;
struct net;

struct nft_ctx {
    struct net *net;
    struct {
        struct list_head chains;
        struct list_head sets;
        struct list_head flowtables;
        struct list_head objects;
    } *table;
    struct nft_chain *chain;
};

struct nft_flowtable {
    struct list_head list;
};

struct nft_chain {
    struct list_head list;
};

struct nft_object {
    struct list_head list;
};

struct nft_set {
    struct list_head list;
    struct list_head bindings;
    bool anonymous;
};

static inline bool nft_is_active_next(struct net *net, void *item);
static inline bool nft_chain_is_bound(struct nft_chain *chain);
static inline bool nft_set_is_anonymous(struct nft_set *set);
static int nft_delrule_by_chain(struct nft_ctx *ctx);
static int nft_delset(struct nft_ctx *ctx, struct nft_set *set);
static int nft_delflowtable(struct nft_ctx *ctx, struct nft_flowtable *flowtable);
static int nft_delobj(struct nft_ctx *ctx, struct nft_object *obj);
static int nft_delchain(struct nft_ctx *ctx);
static int nft_deltable(struct nft_ctx *ctx);