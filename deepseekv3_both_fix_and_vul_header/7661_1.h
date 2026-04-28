#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>

struct x25_neigh {
    void *dev;
};

struct sock {
    // minimal sock structure needed
    struct sock *next;
};

extern struct sock x25_list;
extern pthread_rwlock_t x25_list_lock;

#define sk_for_each(s, list) for (s = list; s != NULL; s = s->next)
#define write_lock_bh(lock) pthread_rwlock_wrlock(lock)
#define write_unlock_bh(lock) pthread_rwlock_unlock(lock)
#define ENETUNREACH 101

struct x25_sock {
    struct x25_neigh *neighbour;
};

static inline struct x25_sock *x25_sk(struct sock *sk) {
    return (struct x25_sock *)sk;
}

void x25_disconnect(struct sock *sk, int err, unsigned char cause, unsigned char diagnostic);
void x25_clear_forward_by_dev(void *dev);