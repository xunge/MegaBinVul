#include <stdatomic.h>
#include <stdbool.h>

struct sk_buff;

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
    atomic_int qlen;
};

struct sock {
    atomic_int sk_rmem_alloc;
    unsigned int sk_rcvbuf;
    struct sk_buff_head sk_error_queue;
    void (*sk_data_ready)(struct sock *sk);
    unsigned long sk_flags;
};

struct sk_buff {
    unsigned int truesize;
    struct sock *sk;
    void (*destructor)(struct sk_buff *);
    struct sk_buff *next;
    struct sk_buff *prev;
};

#define ENOMEM 12
#define SOCK_DEAD 0x01

static inline int atomic_read(const atomic_int *v) {
    return atomic_load(v);
}

static inline void atomic_add(int i, atomic_int *v) {
    atomic_fetch_add(v, i);
}

void skb_orphan(struct sk_buff *skb);
void sock_rmem_free(struct sk_buff *skb);
void skb_dst_force(struct sk_buff *skb);
void skb_queue_tail(struct sk_buff_head *list, struct sk_buff *newsk);
bool sock_flag(const struct sock *sk, int flag);