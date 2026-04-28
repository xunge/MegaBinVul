#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#define ENOBUFS 105
#define EINVAL 22
#define NLMSG_GOODSIZE 32768
#define NLM_F_MULTI 0x2
#define NLMSG_DONE 0x3
#define GFP_KERNEL 0xD0
#define __GFP_NOWARN 0x800
#define __GFP_NORETRY 0x10

struct sock {
    int sk_rmem_alloc;
    int sk_rcvbuf;
};

struct sk_buff {
    void *data;
    unsigned int len;
    unsigned int tail;
};

struct nlmsghdr {
    uint32_t nlmsg_len;
    uint16_t nlmsg_type;
    uint16_t nlmsg_flags;
    uint32_t nlmsg_seq;
    uint32_t nlmsg_pid;
};

struct netlink_callback {
    int (*dump)(struct sk_buff *, struct netlink_callback *);
    void (*done)(struct netlink_callback *);
    int min_dump_alloc;
    void *module;
    struct sk_buff *skb;
};

struct netlink_sock {
    pthread_mutex_t *cb_mutex;
    bool cb_running;
    struct netlink_callback cb;
    int max_recvmsg_len;
};

static inline struct netlink_sock *nlk_sk(struct sock *sk) { return (struct netlink_sock *)sk; }
static inline void netlink_skb_set_owner_r(struct sk_buff *skb, struct sock *sk) {}
static inline bool sk_filter(struct sock *sk, struct sk_buff *skb) { return false; }
static inline void __netlink_sendskb(struct sock *sk, struct sk_buff *skb) {}
static inline struct nlmsghdr *nlmsg_put_answer(struct sk_buff *skb, struct netlink_callback *cb, int type, int len, int flags) { return NULL; }
static inline void nl_dump_check_consistent(struct netlink_callback *cb, struct nlmsghdr *nlh) {}
static inline void consume_skb(struct sk_buff *skb) { free(skb); }
static inline void kfree_skb(struct sk_buff *skb) { free(skb); }
static inline void module_put(void *module) {}

static inline struct sk_buff *alloc_skb(unsigned int size, int flags) {
    struct sk_buff *skb = calloc(1, sizeof(struct sk_buff));
    skb->data = malloc(size);
    skb->len = size;
    skb->tail = size;
    return skb;
}

static inline unsigned int skb_tailroom(const struct sk_buff *skb) {
    return skb->tail;
}

static inline void skb_reserve(struct sk_buff *skb, int len) {
    skb->data += len;
    skb->len -= len;
}

static inline void *nlmsg_data(struct nlmsghdr *nlh) {
    return (void *)(nlh + 1);
}

static inline int atomic_read(int *v) {
    return *v;
}

#define max_t(type, x, y) ((x) > (y) ? (x) : (y))