#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define UFX_DEFIO_WRITE_DELAY 0
#define EBUSY 16
#define ENODEV 19
#define GFP_KERNEL 0

extern pthread_mutex_t disconnect_mutex;
extern int console;
extern int fb_defio;
extern void (*ufx_dpy_deferred_io)(void);

struct fb_info {
    void *par;
    int node;
    void *fbdefio;
};

struct fb_deferred_io {
    unsigned int delay;
    void (*deferred_io)(void);
};

struct kref {
    int count;
};

struct ufx_data {
    int virtualized;
    int fb_count;
    struct kref kref;
};

void kref_get(struct kref *kref) {
    kref->count++;
}

void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

void fb_deferred_io_init(struct fb_info *info) {
}

void mutex_lock(pthread_mutex_t *mutex) {
    pthread_mutex_lock(mutex);
}

void mutex_unlock(pthread_mutex_t *mutex) {
    pthread_mutex_unlock(mutex);
}