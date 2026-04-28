#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <pthread.h>

struct sock {
    int sk_type;
};

struct inet_sock {
    int inet_num;
};

struct ip6_ra_chain {
    struct ip6_ra_chain *next;
    struct sock *sk;
    int sel;
};

static pthread_rwlock_t ip6_ra_lock = PTHREAD_RWLOCK_INITIALIZER;
static struct ip6_ra_chain *ip6_ra_chain;

#define GFP_KERNEL 0
#define SOCK_RAW 3
#define IPPROTO_RAW 255

static inline struct inet_sock *inet_sk(const struct sock *sk) {
    return (struct inet_sock *)sk;
}

#define sock_hold(sk) ((void)0)
#define sock_put(sk) ((void)0)
#define write_lock_bh(lock) pthread_rwlock_wrlock(lock)
#define write_unlock_bh(lock) pthread_rwlock_unlock(lock)
#define kmalloc(size, flags) malloc(size)
#define kfree(ptr) free(ptr)