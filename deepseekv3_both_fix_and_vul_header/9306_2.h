#include <stdatomic.h>
#include <stddef.h>

struct sock;
struct file {
    struct {
        struct {
            struct {
                long unix_inflight;
            } *user;
        } *f_cred;
    };
};
struct unix_sock;
struct list_head {
    struct list_head *next, *prev;
};
extern struct list_head gc_inflight_list;
extern atomic_flag unix_gc_lock;
extern long unix_tot_inflight;

struct unix_sock {
    _Atomic long inflight;
    struct list_head link;
};

#define BUG_ON(cond) ((void)0)
#define spin_lock(lock) while (atomic_flag_test_and_set(lock)) {}
#define spin_unlock(lock) atomic_flag_clear(lock)
#define list_empty(list) ((list)->next == (list))
static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}
static inline long atomic_long_inc_return(_Atomic long *v) {
    return atomic_fetch_add(v, 1) + 1;
}

struct sock *unix_get_socket(struct file *fp);
struct unix_sock *unix_sk(struct sock *s);