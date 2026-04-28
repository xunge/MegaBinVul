#include <stdint.h>
#include <stddef.h>

#define __releases(x)
#define IO_WQE_FLAG_STALLED (1 << 0)
#define IO_WQ_WORK_CB (1 << 0)
#define IO_WQ_WORK_NEEDS_FILES (1 << 1)
#define IO_WQ_WORK_NEEDS_USER (1 << 2)
#define IO_WQ_WORK_CANCEL (1 << 3)
#define IO_WQ_WORK_HAS_MM (1 << 4)
#define IO_WQ_WORK_INTERNAL (1 << 5)
#define IO_WQ_BIT_CANCEL 0
#define USER_DS 0

struct list_head {
    struct list_head *next, *prev;
};

struct files_struct;
struct mm_struct;
struct cred;

struct io_wq_work {
    unsigned int flags;
    void (*func)(struct io_wq_work **);
    struct list_head list;
    struct files_struct *files;
};

struct io_wq {
    struct mm_struct *mm;
    const struct cred *creds;
    unsigned long state;
    void (*put_work)(struct io_wq_work *);
    void (*get_work)(struct io_wq_work *);
};

struct io_wqe {
    void *lock;
    struct io_wq *wq;
    struct list_head work_list;
    unsigned long hash_map;
    unsigned int flags;
};

struct io_worker {
    void *lock;
    struct io_wqe *wqe;
    struct io_wq_work *cur_work;
    struct mm_struct *mm;
    const struct cred *creds;
};

struct task_struct {
    struct files_struct *files;
};

#define BIT_ULL(nr) (1ULL << (nr))
#define spin_lock_irq(lock) 
#define spin_unlock_irq(lock) 
#define task_lock(task) 
#define task_unlock(task) 
#define signal_pending(task) 0
#define flush_signals(task) 
#define mmget_not_zero(mm) 1
#define use_mm(mm) 
#define set_fs(fs) 
#define override_creds(creds) NULL
#define test_bit(nr, addr) 0
#define current ((struct task_struct*)0)

static struct io_wq_work *io_get_next_work(struct io_wqe *wqe, unsigned *hash) { return NULL; }
static void __io_worker_busy(struct io_wqe *wqe, struct io_worker *worker, struct io_wq_work *work) {}
static int list_empty(const struct list_head *head) { return 1; }