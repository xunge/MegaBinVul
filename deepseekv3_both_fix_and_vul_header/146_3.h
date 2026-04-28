#include <stdatomic.h>
#include <stdbool.h>
#include <pthread.h>

struct task_struct {
    unsigned int flags;
};

extern struct task_struct *current;

struct userfaultfd_ctx {
    struct {
        pthread_mutex_t lock;
    } event_wqh;
    struct {
        int dummy;
    } fd_wqh;
    atomic_bool released;
    atomic_bool mmap_changing;
    struct mm_struct *mm;
};

struct userfaultfd_wait_queue {
    struct userfaultfd_ctx *ctx;
    struct {
        int event;
        struct {
            struct {
                unsigned long reserved1;
            } reserved;
        } arg;
    } msg;
    struct {
        int dummy;
    } wq;
};

struct vm_userfaultfd_ctx {
    struct userfaultfd_ctx *ctx;
};

struct vm_area_struct {
    struct vm_area_struct *vm_next;
    unsigned long vm_flags;
    struct vm_userfaultfd_ctx vm_userfaultfd_ctx;
};

struct mm_struct {
    struct vm_area_struct *mmap;
    pthread_rwlock_t mmap_sem;
};

#define NULL_VM_UFFD_CTX ((struct vm_userfaultfd_ctx){0})
#define VM_UFFD_WP (1 << 0)
#define VM_UFFD_MISSING (1 << 1)

#define WARN_ON_ONCE(cond) (cond)
#define PF_EXITING 0
#define TASK_KILLABLE 0
#define TASK_RUNNING 0
#define EPOLLIN 0x001
#define UFFD_EVENT_FORK 0

#define READ_ONCE(x) atomic_load_explicit(&(x), memory_order_relaxed)
#define WRITE_ONCE(x, val) atomic_store_explicit(&(x), val, memory_order_relaxed)

static inline void init_waitqueue_entry(void *wq, void *task) {}
static inline void __add_wait_queue(void *wqh, void *wq) {}
static inline void __remove_wait_queue(void *wqh, void *wq) {}
static inline void wake_up_poll(void *wqh, int flags) {}
static inline void schedule(void) {}
static inline void __set_current_state(int state) {}
static inline void set_current_state(int state) {}
static inline int fatal_signal_pending(void *task) { return 0; }
static inline void down_write(pthread_rwlock_t *lock) { pthread_rwlock_wrlock(lock); }
static inline void up_write(pthread_rwlock_t *lock) { pthread_rwlock_unlock(lock); }
static inline void userfaultfd_ctx_put(struct userfaultfd_ctx *ctx) {}

static void spin_lock(pthread_mutex_t *lock) { pthread_mutex_lock(lock); }
static void spin_unlock(pthread_mutex_t *lock) { pthread_mutex_unlock(lock); }