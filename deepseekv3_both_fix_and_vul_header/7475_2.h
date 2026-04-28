#include <stddef.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stdint.h>

#define GFP_KERNEL 0
#define TCP_CLOSE 0
#define SOCK_ZAPPED 0
#define MAX_SCHEDULE_TIMEOUT ((long)(~0UL>>1))
#define SK_DEFAULT_STAMP 0
#define BITS_PER_LONG (__CHAR_BIT__ * __SIZEOF_LONG__)
#define CONFIG_NET_RX_BUSY_POLL 0
#define WRITE_ONCE(x, val) (x = val)

struct timer_list {
    void *function;
    unsigned long data;
};

struct rwlock {
    int lock;
};

struct spinlock {
    int lock;
};

struct seqlock {
    unsigned sequence;
};

struct wq_struct {
    int dummy;
};

struct inode {
    unsigned int i_uid;
};

struct user_namespace {
    int dummy;
};

struct net {
    struct user_namespace *user_ns;
};

struct socket {
    int type;
    struct sock *sk;
    struct inode *i_uid;
    struct wq_struct wq;
};

struct sock {
    void *sk_send_head;
    struct timer_list sk_timer;
    int sk_allocation;
    int sk_rcvbuf;
    int sk_sndbuf;
    int sk_state;
    int sk_type;
    struct socket *sk_socket;
    unsigned int sk_uid;
    bool sk_kern_sock;
    int sk_family;
    struct rwlock sk_callback_lock;
    void *sk_wq;
    void (*sk_state_change)(struct sock *sk);
    void (*sk_data_ready)(struct sock *sk);
    void (*sk_write_space)(struct sock *sk);
    void (*sk_error_report)(struct sock *sk);
    void (*sk_destruct)(struct sock *sk);
    struct {
        void *page;
        int offset;
    } sk_frag;
    int sk_peek_off;
    void *sk_peer_pid;
    void *sk_peer_cred;
    struct spinlock sk_peer_lock;
    int sk_write_pending;
    int sk_rcvlowat;
    long sk_rcvtimeo;
    long sk_sndtimeo;
    long sk_stamp;
#if BITS_PER_LONG==32
    struct seqlock sk_stamp_seq;
#endif
    atomic_int sk_zckey;
#ifdef CONFIG_NET_RX_BUSY_POLL
    int sk_napi_id;
    int sk_ll_usec;
#endif
    unsigned long sk_max_pacing_rate;
    unsigned long sk_pacing_rate;
    int sk_pacing_shift;
    int sk_incoming_cpu;
    atomic_int sk_refcnt;
    atomic_int sk_drops;
};

struct lockdep_map {
    int dummy;
};

extern int sysctl_rmem_default;
extern int sysctl_wmem_default;
extern int sysctl_net_busy_read;
extern struct lockdep_map af_kern_callback_keys[];
extern struct lockdep_map af_callback_keys[];
extern const char *af_family_kern_clock_key_strings[];
extern const char *af_family_clock_key_strings[];

void sk_init_common(struct sock *sk);
void timer_setup(struct timer_list *timer, void (*callback)(struct timer_list *), unsigned int flags);
void sk_set_socket(struct sock *sk, struct socket *sock);
void sock_set_flag(struct sock *sk, int flag);
void RCU_INIT_POINTER(void *p, void *v);
#define SOCK_INODE(sock) ((struct inode *)sock)
struct net *sock_net(struct sock *sk);
unsigned int make_kuid(struct user_namespace *ns, int uid);
void rwlock_init(struct rwlock *lock);
void spin_lock_init(struct spinlock *lock);
void lockdep_set_class_and_name(struct rwlock *lock, struct lockdep_map *key, const char *name);
void sock_def_wakeup(struct sock *sk);
void sock_def_readable(struct sock *sk);
void sock_def_write_space(struct sock *sk);
void sock_def_error_report(struct sock *sk);
void sock_def_destruct(struct sock *sk);
void sk_rx_queue_clear(struct sock *sk);
void smp_wmb(void);
void atomic_set(atomic_int *v, int i);
void refcount_set(atomic_int *r, int value);