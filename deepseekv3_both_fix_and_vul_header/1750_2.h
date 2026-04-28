#include <stddef.h>
#include <stdbool.h>
#include <errno.h>

struct socket {
    struct sock *sk;
};

struct sock {
    struct kcm_sock *sk;
    void *sk_write_queue;
};

struct list_head {
    struct list_head *next, *prev;
};

struct work_struct {
    unsigned long data;
};

typedef struct {
    int lock;
} spinlock_t;

struct kcm_sock {
    struct sock *sk;
    void *seq_skb;
    struct kcm_mux *mux;
    bool tx_stopped;
    bool tx_wait;
    struct list_head wait_psock_list;
    struct work_struct tx_work;
    struct kcm_psock *tx_psock;
};

struct kcm_mux {
    spinlock_t lock;
};

struct kcm_psock;

static inline struct kcm_sock *kcm_sk(const struct sock *sk) { return (struct kcm_sock *)sk; }
static void kcm_done(struct kcm_sock *kcm) {}
static void kcm_abort_tx_psock(struct kcm_psock *psock, int err, bool wakeup_kcm) {}
static void unreserve_psock(struct kcm_sock *kcm) {}

#define WARN_ON(condition) ((void)0)
#define spin_lock_bh(lock) ((void)0)
#define spin_unlock_bh(lock) ((void)0)
#define lock_sock(sk) ((void)0)
#define release_sock(sk) ((void)0)
#define sock_orphan(sk) ((void)0)
#define kfree_skb(skb) ((void)0)
#define __skb_queue_purge(queue) ((void)0)
#define cancel_work_sync(work) ((void)0)
#define list_del(list) ((void)0)
#define EPIPE 32