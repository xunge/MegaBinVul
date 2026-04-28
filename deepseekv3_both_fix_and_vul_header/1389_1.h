#include <stdatomic.h>
#include <pthread.h>

struct tty_struct {
    void *disc_data;
};

struct sixpack {
    struct tty_struct *tty;
    void *dev;
    unsigned char *rbuff;
    unsigned char *xbuff;
    void *tx_t;
    void *resync_t;
    atomic_int refcnt;
    pthread_cond_t dead;
};

pthread_rwlock_t disc_data_lock = PTHREAD_RWLOCK_INITIALIZER;