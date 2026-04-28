#include <pthread.h>

struct ion_handle {
    struct ion_client *client;
    struct {
        int count;
    } ref;
};

struct ion_client {
    pthread_mutex_t lock;
};

int kref_put(struct { int count; } *kref, void (*release)(struct { int count; } *kref));
void ion_handle_destroy(struct { int count; } *ref);

#define mutex_lock(lock) pthread_mutex_lock(lock)
#define mutex_unlock(lock) pthread_mutex_unlock(lock)