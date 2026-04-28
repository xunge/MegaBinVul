#include <sys/poll.h>
#include <stdatomic.h>

#define DEFAULT_POLLMASK (POLLIN | POLLRDNORM)
#define EPOLLIN POLLIN
#define EPOLLRDNORM POLLRDNORM
#define EPOLLERR POLLERR
#define EPOLLPRI POLLPRI

typedef unsigned int __poll_t;

struct kref {
    atomic_int refcount;
};

struct psi_trigger {
    struct kref refcount;
    int event_wait;
    atomic_int event;
};

struct file;
typedef struct poll_table_struct poll_table;

extern atomic_int psi_disabled;

void kref_get(struct kref *kref);
void kref_put(struct kref *kref, void (*release)(struct kref *kref));
void psi_trigger_destroy(struct kref *ref);
void poll_wait(struct file *file, int *wait_address, poll_table *wait);
int static_branch_likely(atomic_int *key);
void rcu_read_lock(void);
void rcu_read_unlock(void);
void *rcu_dereference(void *ptr);
int cmpxchg(atomic_int *ptr, int old, int new);

#define __rcu
#define __force