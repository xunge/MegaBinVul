#include <stddef.h>
#include <errno.h>

struct ion_client {
    int lock;
    void *idr;
};

struct ion_handle;

static void mutex_lock(int *lock) {}
static void mutex_unlock(int *lock) {}
static struct ion_handle *idr_find(void *idr, int id) { return NULL; }
static void ion_handle_get(struct ion_handle *handle) {}

#define ERR_PTR(err) ((void *)(long)(err))
#define EINVAL 22