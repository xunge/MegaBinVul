#include <stddef.h>
#include <sys/types.h>

#define unlikely(x) (x)
#define pr_debug(fmt, ...)
#define dprintk(fmt, ...)
#define EINVAL 22
#define EBADF 9
#define EAGAIN 11
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000L)
#define PTR_ERR(ptr) ((long)(ptr))
#define IOCB_FLAG_RESFD (1 << 0)

typedef int spinlock_t;

struct list_head {
    struct list_head *next, *prev;
};

struct file;
struct kioctx {
    spinlock_t ctx_lock;
    struct list_head run_list;
};
struct kiocb {
    struct file *ki_filp;
    void *ki_eventfd;
    unsigned long ki_key;
    struct {
        void *user;
    } ki_obj;
    unsigned long ki_user_data;
    long long ki_pos;
    char *ki_buf;
    size_t ki_left;
    size_t ki_nbytes;
    int ki_opcode;
    struct {
        struct list_head task_list;
    } ki_wait;
};
struct iocb {
    unsigned long aio_reserved1;
    unsigned long aio_reserved2;
    unsigned long aio_buf;
    size_t aio_nbytes;
    int aio_fildes;
    int aio_flags;
    int aio_resfd;
    unsigned long aio_data;
    long long aio_offset;
    int aio_lio_opcode;
    unsigned long aio_key;
};

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}
static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}
static inline void spin_lock_irq(spinlock_t *lock) {}
static inline void spin_unlock_irq(spinlock_t *lock) {}
static inline void init_waitqueue_func_entry(struct list_head *q, void *func) {}

struct file *fget(int fd);
void fput(struct file *file);
struct kiocb *aio_get_req(struct kioctx *ctx);
void aio_put_req(struct kiocb *req);
int aio_setup_iocb(struct kiocb *req);
void aio_run_iocb(struct kiocb *req);
int __aio_run_iocbs(struct kioctx *ctx);
int put_user(unsigned long x, unsigned long *ptr);
void *eventfd_fget(int fd);

#define fastcall
#define __user

void aio_wake_function(struct list_head *wait, unsigned int mode, int sync, void *key);