#include <stdlib.h>
#include <stdatomic.h>
#include <stdbool.h>

typedef _Atomic long atomic_long_t;

struct list_head {
    struct list_head *next, *prev;
};

struct user_struct {
    atomic_long_t unix_inflight;
};

struct cred {
    struct user_struct *user;
};

struct file {
    struct cred *f_cred;
};

struct sock;
struct unix_sock;

extern struct spinlock unix_gc_lock;
extern struct list_head gc_inflight_list;
extern atomic_long_t unix_tot_inflight;

struct unix_sock {
    atomic_long_t inflight;
    struct list_head link;
};

#define BUG_ON(cond) ((cond) ? (void)0 : abort())

static inline void spin_lock(struct spinlock *lock) {}
static inline void spin_unlock(struct spinlock *lock) {}

static inline bool list_empty(const struct list_head *head) {
    return head->next == head;
}

static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

static inline long atomic_long_inc_return(atomic_long_t *v) {
    return atomic_fetch_add(v, 1) + 1;
}

struct sock *unix_get_socket(struct file *fp);
struct unix_sock *unix_sk(struct sock *s);