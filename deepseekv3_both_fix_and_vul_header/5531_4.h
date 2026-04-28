#include <stddef.h>
#include <stdatomic.h>
#include <stdint.h>

struct cred {
    int dummy;
};

struct list_head {
    struct list_head *next, *prev;
};

struct rwlock_t {
    int lock;
};

struct spinlock_t {
    int lock;
};

struct file {
    struct cred *f_cred;
    union {
        struct list_head fu_list;
    } f_u;
    _Atomic long f_count;
    struct {
        struct rwlock_t lock;
    } f_owner;
    struct spinlock_t f_lock;
};

struct kmem_cache;
struct percpu_counter;

struct files_stat_struct {
    unsigned long max_files;
};

#define GFP_KERNEL 0
#define ENOMEM 1
#define ENFILE 2
#define CAP_SYS_ADMIN 0

#define unlikely(x) (x)
#define pr_info(fmt, ...)

static inline const struct cred *current_cred(void) { return NULL; }
static inline long get_nr_files(void) { return 0; }
static inline long get_max_files(void) { return 0; }
static inline int capable(int cap) { return 0; }
static inline long percpu_counter_sum_positive(struct percpu_counter *c) { return 0; }
static inline void percpu_counter_inc(struct percpu_counter *c) {}
static inline void *kmem_cache_zalloc(struct kmem_cache *c, int flags) { return NULL; }
static inline struct cred *get_cred(const struct cred *cred) { return NULL; }
static inline int security_file_alloc(struct file *f) { return 0; }
static inline void file_free(struct file *f) {}
static inline void INIT_LIST_HEAD(struct list_head *list) {}
static inline void atomic_long_set(_Atomic long *v, long i) { *v = i; }
static inline void rwlock_init(struct rwlock_t *lock) {}
static inline void spin_lock_init(struct spinlock_t *lock) {}
static inline void eventpoll_init_file(struct file *f) {}
static inline void *ERR_PTR(long error) { return (void *)(intptr_t)error; }

extern struct kmem_cache *filp_cachep;
extern struct percpu_counter nr_files;
extern struct files_stat_struct files_stat;