#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member), \
         n = container_of(pos->member.next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = n, n = container_of(n->member.next, typeof(*n), member))

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_empty(head) ((head)->next == (head))

struct nft_ctx;
struct nft_table;
struct nft_chain;
struct nft_set;

struct nft_ctx {
    struct nft_table *table;
    struct nft_chain *chain;
};

struct nft_table {
    struct list_head chains;
    struct list_head sets;
};

struct nft_chain {
    struct list_head list;
};

struct nft_set {
    struct list_head list;
    struct list_head bindings;
    unsigned int flags;
};

#define NFT_SET_ANONYMOUS (1 << 0)

int nft_delrule_by_chain(struct nft_ctx *ctx);
int nft_delset(struct nft_ctx *ctx, struct nft_set *set);
int nft_delchain(struct nft_ctx *ctx);
int nft_deltable(struct nft_ctx *ctx);