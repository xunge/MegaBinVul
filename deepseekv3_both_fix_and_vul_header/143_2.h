#include <stdbool.h>
#include <stddef.h>

struct inode;
struct file;
struct userfaultfd_ctx;
struct mm_struct;
struct vm_area_struct;
struct userfaultfd_wake_range {
    unsigned long len;
};
struct rw_semaphore {
    int dummy;
};
struct wait_queue_head {
    int lock;
};
struct anon_vma;

#define VM_UFFD_MISSING 0
#define VM_UFFD_WP 0
#define NULL_VM_UFFD_CTX ((struct vm_userfaultfd_ctx){0})
#define WRITE_ONCE(x, val) (x = val)
#define TASK_NORMAL 0
#define EPOLLHUP 0x10

struct vm_userfaultfd_ctx {
    struct userfaultfd_ctx *ctx;
};

struct userfaultfd_ctx {
    struct mm_struct *mm;
    bool released;
    struct wait_queue_head fault_pending_wqh;
    struct wait_queue_head fault_wqh;
    struct wait_queue_head event_wqh;
    struct wait_queue_head fd_wqh;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    struct vm_area_struct *vm_next;
    struct anon_vma *anon_vma;
    struct file *vm_file;
    unsigned long vm_pgoff;
    struct vm_userfaultfd_ctx vm_userfaultfd_ctx;
};

struct mm_struct {
    struct vm_area_struct *mmap;
    struct rw_semaphore mmap_sem;
};

struct file {
    void *private_data;
};

static inline void cond_resched(void) {}
static inline void BUG_ON(int condition) {}
static inline void down_write(struct rw_semaphore *sem) {}
static inline void up_write(struct rw_semaphore *sem) {}
static inline int mmget_not_zero(struct mm_struct *mm) { return 1; }
static inline void mmput(struct mm_struct *mm) {}
static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline void __wake_up_locked_key(struct wait_queue_head *wqh, int state, void *key) {}
static inline void __wake_up(struct wait_queue_head *wqh, int state, int nr, void *key) {}
static inline void wake_up_all(struct wait_queue_head *wqh) {}
static inline void wake_up_poll(struct wait_queue_head *wqh, int events) {}
static inline void userfaultfd_ctx_put(struct userfaultfd_ctx *ctx) {}
static inline struct vm_area_struct *vma_merge(struct mm_struct *mm, struct vm_area_struct *prev,
    unsigned long start, unsigned long end, unsigned long flags, struct anon_vma *anon_vma,
    struct file *file, unsigned long pgoff, void *policy, struct vm_userfaultfd_ctx ctx) { return NULL; }
static inline void *vma_policy(struct vm_area_struct *vma) { return NULL; }