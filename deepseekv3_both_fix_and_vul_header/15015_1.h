#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>

#define GFP_KERNEL 0
#define PPP_MRU 1500
#define EOPNOTSUPP 95
#define ENOMEM 12

struct tty_struct {
    struct {
        int (*write)();
    } *driver;
    void *disc_data;
    int receive_room;
};

struct sk_buff_head {};
struct tasklet_struct {
    void (*func)(unsigned long);
    unsigned long data;
};
struct ppp_channel {
    void *private;
    const void *ops;
    unsigned int mtu;
};
struct semaphore {};

struct asyncppp {
    struct tty_struct *tty;
    unsigned int mru;
    pthread_spinlock_t xmit_lock;
    pthread_spinlock_t recv_lock;
    unsigned int xaccm[4];
    unsigned int raccm;
    unsigned char *optr;
    unsigned char *olim;
    unsigned char obuf[PPP_MRU];
    int lcp_fcs;
    struct sk_buff_head rqueue;
    struct tasklet_struct tsk;
    int refcnt;
    struct semaphore dead_sem;
    struct ppp_channel chan;
};

extern const struct ppp_channel_ops async_ops;
extern void ppp_async_process(unsigned long);
extern int ppp_register_channel(struct ppp_channel *);

static inline void spin_lock_init(pthread_spinlock_t *lock) {
    pthread_spin_init(lock, 0);
}
static inline void skb_queue_head_init(struct sk_buff_head *queue) {}
static inline void tasklet_init(struct tasklet_struct *t, void (*func)(unsigned long), unsigned long data) {
    t->func = func;
    t->data = data;
}
static inline void atomic_set(int *v, int i) { *v = i; }
static inline void init_MUTEX_LOCKED(struct semaphore *sem) {}
static void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static void kfree(void *ptr) { free(ptr); }