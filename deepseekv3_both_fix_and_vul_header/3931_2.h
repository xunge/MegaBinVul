#include <stddef.h>

#define EBADF 9
#define REQ_F_INFLIGHT (1U << 0)

struct list_head {
    struct list_head *next, *prev;
};

struct files_struct;
struct file;

struct io_kiocb {
    struct io_ring_ctx *ctx;
    int ring_fd;
    struct file *ring_file;
    unsigned int flags;
    struct list_head inflight_entry;
    struct {
        struct files_struct *files;
    } work;
};

struct io_ring_ctx {
    struct list_head inflight_list;
    int inflight_lock;
};

struct task_struct {
    struct files_struct *files;
};

extern struct task_struct *current;
extern void rcu_read_lock(void);
extern void rcu_read_unlock(void);
extern void spin_lock_irq(int *lock);
extern void spin_unlock_irq(int *lock);
extern struct file *fcheck(int fd);
extern void list_add(struct list_head *new, struct list_head *head);