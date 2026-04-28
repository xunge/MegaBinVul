#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define WARN_ON(condition) ((void)0)
#define IPSEC_PROTO_ANY 0

typedef uint8_t u8;

struct hlist_head {
    struct hlist_node *first;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct list_head {
    struct list_head *next, *prev;
};

struct work_struct {
    unsigned long data;
};

struct net {
    struct {
        struct work_struct state_hash_work;
        unsigned int state_hmask;
        struct hlist_head *state_byspi;
        struct hlist_head *state_bysrc;
        struct hlist_head *state_bydst;
        struct list_head state_all;
    } xfrm;
};

extern struct work_struct xfrm_state_gc_work;

void flush_work(struct work_struct *work);
void xfrm_state_flush(struct net *net, u8 proto, bool task_valid, bool sync);
void xfrm_hash_free(struct hlist_head *n, unsigned int sz);