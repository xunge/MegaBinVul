#include <pthread.h>

struct bus_id_priv {
    pthread_spinlock_t busid_lock;
};

extern pthread_spinlock_t busid_table_lock;
extern struct bus_id_priv *busid_table;
extern int get_busid_idx(const char *busid);