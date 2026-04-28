#include <stddef.h>
#include <stdatomic.h>

#define ENOMEM 1
#define EINVAL 2
#define EAGAIN 3
#define GFP_KERNEL 0

typedef _Atomic int atomic_t;

struct io_event {
    int dummy;
};

struct kiocb {
    int dummy;
};

struct kioctx_cpu {
    int dummy;
};

struct mm_struct {
    int dummy;
};

struct task_struct {
    struct mm_struct *mm;
};

struct percpu_ref {
    atomic_t count;
    void *pcpu_count;
    void (*release)(struct percpu_ref *);
};

struct kioctx {
    unsigned max_reqs;
    unsigned nr_events;
    unsigned req_batch;
    struct kioctx_cpu *cpu;
    struct percpu_ref users;
    struct percpu_ref reqs;
    atomic_t reqs_available;
    long user_id;
    int ctx_lock;
    int completion_lock;
    int ring_lock;
    int wait;
    int active_reqs;
};

typedef int spinlock_t;
typedef int mutex_t;

extern struct task_struct *current;
extern struct kmem_cache *kioctx_cachep;
extern unsigned long aio_nr;
extern unsigned long aio_max_nr;
extern spinlock_t aio_nr_lock;

static inline int max(int a, int b) { return a > b ? a : b; }
static inline int num_possible_cpus(void) { return 1; }

#define ERR_PTR(err) ((void*)(long)(err))
#define pr_debug(fmt, ...) ((void)0)
#define spin_lock_init(lock) ((void)0)
#define spin_lock(lock) ((void)0)
#define spin_unlock(lock) ((void)0)
#define mutex_init(lock) ((void)0)
#define INIT_LIST_HEAD(head) ((void)0)
#define init_waitqueue_head(wq) ((void)0)
#define atomic_set(v, i) (*(v) = (i))
#define percpu_ref_init(ref, release) 0
#define percpu_ref_get(ref) ((void)0)
#define alloc_percpu(type) ((type*)0)
#define free_percpu(ptr) ((void)0)
#define kmem_cache_zalloc(cache, flags) ((void*)0)
#define kmem_cache_free(cache, ptr) ((void)0)

static void free_ioctx_users(struct percpu_ref *ref) {}
static void free_ioctx_reqs(struct percpu_ref *ref) {}
static int aio_setup_ring(struct kioctx *ctx) { return 0; }
static void aio_free_ring(struct kioctx *ctx) {}
static void aio_nr_sub(unsigned long nr) {}
static int ioctx_add_table(struct kioctx *ctx, struct mm_struct *mm) { return 0; }