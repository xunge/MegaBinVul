#include <stdatomic.h>
#include <pthread.h>

struct ppp_channel {
    struct channel *ppp;
};

struct channel {
    struct ppp_channel *chan;
    pthread_rwlock_t chan_sem;
    pthread_spinlock_t downl;
    struct net *chan_net;
    struct {
        int dead;
        pthread_cond_t rwait;
        atomic_int refcnt;
    } file;
    struct list_head {
        struct list_head *next, *prev;
    } list;
};

struct ppp_net {
    pthread_spinlock_t all_channels_lock;
};

struct net;

void ppp_disconnect_channel(struct channel *pch);
void ppp_destroy_channel(struct channel *pch);
struct ppp_net *ppp_pernet(struct net *net);