#include <stdatomic.h>

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct file {
    struct cred *f_cred;
};

struct sock;

struct unix_sock {
    struct list_head link;
    _Atomic long inflight;
};

struct cred {
    struct user_struct *user;
};

struct user_struct {
    long unix_inflight;
};

extern _Atomic int unix_gc_lock;
extern long unix_tot_inflight;

struct sock *unix_get_socket(struct file *fp);
struct unix_sock *unix_sk(struct sock *sk);

#define spin_lock(lock) while(atomic_flag_test_and_set_explicit(lock, memory_order_acquire)) {}
#define spin_unlock(lock) atomic_flag_clear_explicit(lock, memory_order_release)
#define BUG_ON(condition) do { if (condition) { for(;;); } } while(0)
#define list_empty(list) ((list)->next == (list))
#define list_del_init(list) do { \
    (list)->next = list; \
    (list)->prev = list; \
} while(0)

static inline int atomic_long_dec_and_test(_Atomic long *v) {
    return atomic_fetch_sub(v, 1) - 1 == 0;
}