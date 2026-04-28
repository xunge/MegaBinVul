#include <stdatomic.h>
#include <stddef.h>
#include <limits.h>

#define CONFIG_NET_DMA
#define GFP_KERNEL 0
#define TCP_CLOSE 0
#define SOCK_ZAPPED 0
#define MAX_SCHEDULE_TIMEOUT LONG_MAX

struct socket {
    int type;
    void *wait;
    struct sock *sk;
};

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
    unsigned int qlen;
};

struct timer_list {
    unsigned long expires;
    void (*function)(unsigned long);
    unsigned long data;
};

typedef struct {
    int lock;
} spinlock_t;

typedef struct {
    int lock;
} rwlock_t;

struct lockdep_map {
    void *key;
    const char *name;
};

struct lock_class_key {
    int unused;
};

struct sock {
    struct sk_buff_head sk_receive_queue;
    struct sk_buff_head sk_write_queue;
    struct sk_buff_head sk_error_queue;
    struct sk_buff_head sk_async_wait_queue;
    void *sk_send_head;
    struct timer_list sk_timer;
    int sk_allocation;
    int sk_rcvbuf;
    int sk_sndbuf;
    struct {
        int limit;
    } sk_backlog;
    int sk_state;
    int sk_type;
    void **sk_sleep;
    spinlock_t sk_dst_lock;
    rwlock_t sk_callback_lock;
    int sk_family;
    void (*sk_state_change)(struct sock *);
    void (*sk_data_ready)(struct sock *);
    void (*sk_write_space)(struct sock *);
    void (*sk_error_report)(struct sock *);
    void (*sk_destruct)(struct sock *);
    void *sk_sndmsg_page;
    int sk_sndmsg_off;
    struct {
        int pid;
        int uid;
        int gid;
    } sk_peercred;
    int sk_write_pending;
    int sk_rcvlowat;
    long sk_rcvtimeo;
    long sk_sndtimeo;
    long sk_stamp;
    atomic_int sk_refcnt;
    atomic_int sk_drops;
};

struct sk_buff {
    struct sk_buff *next;
    struct sk_buff *prev;
};

extern int sysctl_rmem_default;
extern int sysctl_wmem_default;
extern struct lock_class_key af_callback_keys[];
extern const char *af_family_clock_key_strings[];

static inline void skb_queue_head_init(struct sk_buff_head *list) {
    list->next = (struct sk_buff *)list;
    list->prev = (struct sk_buff *)list;
    list->qlen = 0;
}

static inline void init_timer(struct timer_list *timer) {
    timer->expires = 0;
    timer->function = 0;
    timer->data = 0;
}

static inline void spin_lock_init(spinlock_t *lock) {
    lock->lock = 0;
}

static inline void rwlock_init(rwlock_t *lock) {
    lock->lock = 0;
}

void sk_set_socket(struct sock *sk, struct socket *sock);
void sock_set_flag(struct sock *sk, int flag);
void lockdep_set_class_and_name(struct lockdep_map *lock, const struct lock_class_key *key, const char *name);
void sock_def_wakeup(struct sock *sk);
void sock_def_readable(struct sock *sk);
void sock_def_write_space(struct sock *sk);
void sock_def_error_report(struct sock *sk);
void sock_def_destruct(struct sock *sk);
void smp_wmb(void);
long ktime_set(long secs, long nsecs);