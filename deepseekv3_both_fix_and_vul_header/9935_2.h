#include <stdatomic.h>
#include <stddef.h>
#include <sys/types.h>

#define CONFIG_NET_DMA
#define GFP_KERNEL 0
#define TCP_CLOSE 0
#define MAX_SCHEDULE_TIMEOUT 0
#define SOCK_ZAPPED 0

struct sk_buff;
struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
};
struct timer_list {
    unsigned long expires;
    void (*function)(unsigned long);
    unsigned long data;
};
struct page;
struct rwlock_t {
    int lock;
};
struct lock_class_key {
    int dummy;
};

struct socket {
    int type;
    void *wait;
    struct sock *sk;
};

struct sock {
    struct sk_buff_head sk_receive_queue;
    struct sk_buff_head sk_write_queue;
    struct sk_buff_head sk_error_queue;
    struct sk_buff_head sk_async_wait_queue;
    struct sk_buff *sk_send_head;
    struct timer_list sk_timer;
    int sk_allocation;
    int sk_rcvbuf;
    int sk_sndbuf;
    struct {
        int limit;
    } sk_backlog;
    int sk_state;
    int sk_type;
    void *sk_sleep;
    struct rwlock_t sk_dst_lock;
    struct rwlock_t sk_callback_lock;
    int sk_family;
    void (*sk_state_change)(struct sock *sk);
    void (*sk_data_ready)(struct sock *sk);
    void (*sk_write_space)(struct sock *sk);
    void (*sk_error_report)(struct sock *sk);
    void (*sk_destruct)(struct sock *sk);
    struct page *sk_sndmsg_page;
    int sk_sndmsg_off;
    struct {
        pid_t pid;
        uid_t uid;
        gid_t gid;
    } sk_peercred;
    int sk_write_pending;
    int sk_rcvlowat;
    long sk_rcvtimeo;
    long sk_sndtimeo;
    long sk_stamp;
    atomic_int sk_refcnt;
    atomic_int sk_drops;
    unsigned long sk_flags;
};

extern int sysctl_rmem_default;
extern int sysctl_wmem_default;
extern struct lock_class_key af_callback_keys[];
extern const char *af_family_clock_key_strings[];

void sock_def_wakeup(struct sock *sk);
void sock_def_readable(struct sock *sk);
void sock_def_write_space(struct sock *sk);
void sock_def_error_report(struct sock *sk);
void sock_def_destruct(struct sock *sk);

void skb_queue_head_init(struct sk_buff_head *list);
void init_timer(struct timer_list *timer);
void sk_set_socket(struct sock *sk, struct socket *sock);
void sock_set_flag(struct sock *sk, int flag);
void rwlock_init(struct rwlock_t *lock);
void lockdep_set_class_and_name(struct rwlock_t *lock, struct lock_class_key *key, const char *name);
long ktime_set(long secs, unsigned long nsecs);
void smp_wmb(void);
void atomic_set(atomic_int *obj, int desired);