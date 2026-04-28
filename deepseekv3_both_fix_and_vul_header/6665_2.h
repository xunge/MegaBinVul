#include <stdatomic.h>
#include <pthread.h>

typedef int fmode_t;

struct gendisk {
    void *private_data;
};

struct loop_device;
extern pthread_mutex_t loop_index_mutex;
extern void __lo_release(struct loop_device *lo);
extern int loop_clr_fd(struct loop_device *lo);

struct loop_device {
    fmode_t mode;
    int lo_flags;
    int lo_state;
    atomic_int lo_refcnt;
    pthread_mutex_t lo_ctl_mutex;
    void *lo_queue;
};

#define LO_FLAGS_AUTOCLEAR (1 << 0)
#define Lo_bound 1