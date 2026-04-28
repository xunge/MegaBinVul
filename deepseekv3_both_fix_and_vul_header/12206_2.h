#include <stddef.h>
#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

struct nft_set {
    struct list_head catchall_list;
};

struct nft_set_ext;
struct nft_elem_priv;
struct net;

struct nft_trans_gc {
    struct nft_set *set;
    struct net *net;
};

struct nft_set_elem_catchall {
    struct list_head list;
    struct nft_elem_priv *elem;
};

#define GFP_ATOMIC 0
#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = (typeof(*pos)*)((char*)(head)->next - offsetof(typeof(*pos), member)), \
        n = (typeof(*pos)*)((char*)pos->member.next - offsetof(typeof(*pos), member)); \
        &pos->member != (head); \
        pos = n, n = (typeof(*pos)*)((char*)n->member.next - offsetof(typeof(*pos), member)))

#define list_for_each_entry_rcu(pos, head, member) \
    for (pos = (typeof(*pos)*)((char*)(head)->next - offsetof(typeof(*pos), member)); \
        &pos->member != (head); \
        pos = (typeof(*pos)*)((char*)pos->member.next - offsetof(typeof(*pos), member)))