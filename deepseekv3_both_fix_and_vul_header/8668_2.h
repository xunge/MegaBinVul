#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <pthread.h>

struct ion_client {
    pthread_mutex_t lock;
};

struct ion_handle {
    struct ion_client *client;
};

bool ion_handle_validate(struct ion_client *client, struct ion_handle *handle);
void ion_handle_put(struct ion_handle *handle);

#define BUG_ON(cond) assert(!(cond))
#define WARN(cond, fmt, ...) (void)((cond) ? fprintf(stderr, fmt, ##__VA_ARGS__) : 0)
#define mutex_lock(lock) pthread_mutex_lock(lock)
#define mutex_unlock(lock) pthread_mutex_unlock(lock)