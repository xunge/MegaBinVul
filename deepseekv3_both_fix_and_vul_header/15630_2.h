#include <stdlib.h>

struct net;
struct nft_set_ext;

struct nft_set {
    struct nft_set_elem_catchall *catchall_list;
};

struct nft_set_elem {
    void *priv;
};

struct nft_set_elem_catchall {
    void *elem;
    struct nft_set_elem_catchall *next;
    struct nft_set_elem_catchall *list;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))(head); pos != NULL; pos = pos->next)

#define ENOENT 2

static inline struct nft_set_ext *nft_set_elem_ext(const struct nft_set *set, void *elem) {
    return NULL;
}

static inline int nft_is_active(const struct net *net, const struct nft_set_ext *ext) {
    return 0;
}

static inline void nft_set_elem_change_active(const struct net *net, 
                                            struct nft_set *set, 
                                            struct nft_set_ext *ext) {
}

#define kfree free