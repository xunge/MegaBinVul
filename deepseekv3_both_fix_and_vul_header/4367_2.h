#include <stdatomic.h>
#include <string.h>
#include <stdlib.h>

struct list_head {
    struct list_head *next, *prev;
};

struct rb_root {
    void *rb_node;
};

struct fuse_iqueue {
    int dummy;
};

struct fuse_pqueue {
    int dummy;
};

struct fuse_conn {
    int lock;
    int killsb;
    atomic_int count;
    int blocked_waitq;
    int reserved_req_waitq;
    struct fuse_iqueue iq;
    struct fuse_pqueue pq;
    struct list_head bg_queue;
    struct list_head entry;
    struct list_head devices;
    atomic_int num_waiting;
    unsigned max_background;
    unsigned congestion_threshold;
    unsigned khctr;
    struct rb_root polled_files;
    unsigned blocked;
    unsigned initialized;
    unsigned connected;
    unsigned attr_version;
    unsigned scramble_key;
};

#define FUSE_DEFAULT_MAX_BACKGROUND 12
#define FUSE_DEFAULT_CONGESTION_THRESHOLD 8

#define spin_lock_init(lock) (*(lock) = 0)
#define init_rwsem(sem) (*(sem) = 0)
#define init_waitqueue_head(wq) (*(wq) = 0)
#define INIT_LIST_HEAD(ptr) do { (ptr)->next = (ptr); (ptr)->prev = (ptr); } while (0)
#define RB_ROOT ((struct rb_root){ NULL })
#define atomic_set(ptr, val) atomic_init(ptr, val)
#define get_random_bytes(buf, len) memset((buf), rand(), (len))

static inline void fuse_iqueue_init(struct fuse_iqueue *iq) { memset(iq, 0, sizeof(*iq)); }
static inline void fuse_pqueue_init(struct fuse_pqueue *pq) { memset(pq, 0, sizeof(*pq)); }