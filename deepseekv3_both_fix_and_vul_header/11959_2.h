#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <errno.h>
#include <pthread.h>

typedef int atomic_t;
typedef pthread_mutex_t spinlock_t;
typedef pthread_mutex_t mutex_t;

struct socket {
    struct sock *sk;
};

struct sk_buff {
    unsigned int len;
    unsigned int data_len;
    unsigned int truesize;
    struct sk_buff *next;
};

struct sk_buff_head {
    struct sk_buff *next;
    spinlock_t lock;
};

struct sock {
    struct sock *sk_peer;
    int sk_state;
    unsigned int sk_shutdown;
    unsigned long sk_flags;
    struct sk_buff_head sk_receive_queue;
    int (*sk_data_ready)(struct sock *sk);
    atomic_t sk_wmem_alloc;
};

struct scm_cookie {
    // placeholder for SCM credentials
};

struct page {
    // placeholder for page structure
};

struct unix_sock {
    mutex_t iolock;
};

#define TCP_ESTABLISHED 1
#define SOCK_DEAD 0x01
#define SEND_SHUTDOWN 0x01
#define RCV_SHUTDOWN 0x02
#define EOPNOTSUPP 95
#define ENOTCONN 107
#define EAGAIN 11
#define ERESTARTSYS 512
#define EPIPE 32
#define SIGPIPE 13

static inline struct unix_sock *unix_sk(struct sock *sk) {
    return (struct unix_sock *)sk;
}

static inline struct sock *unix_peer(struct sock *sk) {
    return sk->sk_peer;
}

static inline void unix_state_lock(struct sock *sk) {}
static inline void unix_state_unlock(struct sock *sk) {}

static inline bool sock_flag(struct sock *sk, int flag) {
    return sk->sk_flags & flag;
}

static inline int mutex_lock_interruptible(mutex_t *lock) {
    return pthread_mutex_lock(lock);
}

static inline void mutex_unlock(mutex_t *lock) {
    pthread_mutex_unlock(lock);
}

static inline struct sk_buff *sock_alloc_send_pskb(struct sock *sk, unsigned long size,
                                                  unsigned long num, int noblock,
                                                  int *errcode, int max_page_order) {
    return NULL;
}

static inline void kfree_skb(struct sk_buff *skb) {}
static inline void consume_skb(struct sk_buff *skb) {}

static inline struct sk_buff *skb_peek_tail(struct sk_buff_head *list) {
    return NULL;
}

static inline bool unix_skb_scm_eq(struct sk_buff *skb, struct scm_cookie *scm) {
    return false;
}

static inline int skb_append_pagefrags(struct sk_buff *skb, struct page *page,
                                      int offset, size_t size) {
    return 0;
}

static inline int unix_scm_to_skb(struct scm_cookie *scm, struct sk_buff *skb, bool send_fds) {
    return 0;
}

static inline void __skb_queue_tail(struct sk_buff_head *list, struct sk_buff *newskb) {}

static inline void spin_lock(spinlock_t *lock) {
    pthread_mutex_lock(lock);
}

static inline void spin_unlock(spinlock_t *lock) {
    pthread_mutex_unlock(lock);
}

static inline void scm_destroy(struct scm_cookie *scm) {}
static inline int maybe_init_creds(struct scm_cookie *scm, struct socket *sock, struct sock *sk) {
    return 0;
}

static inline void send_sig(int sig, void *p, int priv) {}

#define refcount_add(i, v) (*(v) += (i))

static void *current = NULL;