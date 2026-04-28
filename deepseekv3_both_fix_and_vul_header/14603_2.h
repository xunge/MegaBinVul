#include <pthread.h>

#define VM_MAYWRITE 0x00000020

struct bpf_map {
    pthread_mutex_t freeze_mutex;
    int writecnt;
};

struct vm_area_struct {
    unsigned long vm_flags;
    struct file *vm_file;
};

struct file {
    void *private_data;
};

static inline void mutex_lock(pthread_mutex_t *mutex) {
    pthread_mutex_lock(mutex);
}

static inline void mutex_unlock(pthread_mutex_t *mutex) {
    pthread_mutex_unlock(mutex);
}