#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define IORING_SETUP_CQE32 (1U << 3)
#define IORING_SETUP_SQE128 (1U << 4)
#define IORING_SETUP_SQPOLL (1U << 1)
#define IORING_SETUP_NO_SQARRAY (1U << 2)

#define READ_ONCE(x) (x)
#define __cold __attribute__((cold))

typedef uint64_t u64;

struct seq_file {
    FILE *file;
};

struct file {
    void *private_data;
    struct dentry *f_dentry;
};

struct dentry {
    char d_iname[256];
};

struct mutex {
    int dummy;
};

struct spinlock {
    int dummy;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct list_head {
    struct list_head *next, *prev;
};

struct xarray {
    void *dummy;
};

struct cred {
    int dummy;
};

struct task_struct {
    int dummy;
};

struct io_ring_ctx {
    void *private_data;
    struct io_rings *rings;
    unsigned int sq_entries;
    unsigned int cq_entries;
    unsigned int flags;
    unsigned int cached_sq_head;
    unsigned int cached_cq_tail;
    unsigned int *sq_array;
    struct io_uring_sqe *sq_sqes;
    struct mutex uring_lock;
    struct io_sq_data *sq_data;
    unsigned int nr_user_files;
    unsigned int nr_user_bufs;
    struct xarray personalities;
    struct {
        unsigned int hash_bits;
        struct io_hash_bucket *hbs;
    } cancel_table;
    struct {
        struct io_hash_bucket *hbs;
    } cancel_table_locked;
    struct spinlock completion_lock;
    struct list_head cq_overflow_list;
    struct {
        int dummy;
    } file_table;
    struct io_mapped_ubuf **user_bufs;
};

struct io_sq_data {
    struct mutex lock;
    struct task_struct *thread;
};

struct io_rings {
    struct {
        unsigned int head;
        unsigned int tail;
    } sq;
    struct {
        unsigned int head;
        unsigned int tail;
    } cq;
    struct io_uring_cqe *cqes;
};

struct io_uring_sqe {
    unsigned int opcode;
    int fd;
    unsigned int flags;
    unsigned long long off;
    unsigned long long addr;
    unsigned int rw_flags;
    int buf_index;
    unsigned long long user_data;
};

struct io_uring_cqe {
    unsigned long long user_data;
    int res;
    unsigned int flags;
    unsigned long long big_cqe[2];
};

struct io_overflow_cqe {
    struct io_uring_cqe cqe;
    struct list_head list;
};

struct io_hash_bucket {
    struct spinlock lock;
    struct hlist_head list;
};

struct io_kiocb {
    int opcode;
    struct task_struct *task;
    struct hlist_node hash_node;
};

struct io_mapped_ubuf {
    unsigned long long ubuf;
    unsigned long long ubuf_end;
};

static inline unsigned int min(unsigned int a, unsigned int b) {
    return a < b ? a : b;
}

static inline bool task_work_pending(struct task_struct *task) {
    return false;
}

static inline const char *io_uring_get_opcode(unsigned int opcode) {
    return "";
}

static inline struct file *io_file_from_index(void *table, unsigned int index) {
    return NULL;
}

static inline void io_uring_show_cred(struct seq_file *m, unsigned long index, const struct cred *cred) {
}

static inline int mutex_trylock(struct mutex *lock) {
    return 1;
}

static inline void mutex_unlock(struct mutex *lock) {
}

static inline void spin_lock(struct spinlock *lock) {
}

static inline void spin_unlock(struct spinlock *lock) {
}

static inline int task_pid_nr(struct task_struct *task) {
    return -1;
}

static inline int task_cpu(struct task_struct *task) {
    return -1;
}

static inline bool xa_empty(struct xarray *xa) {
    return true;
}

static inline void seq_printf(struct seq_file *m, const char *fmt, ...) {
}

static inline void seq_puts(struct seq_file *m, const char *s) {
}

static inline struct dentry *file_dentry(struct file *f) {
    return f->f_dentry;
}

#define xa_for_each(xa, index, entry) \
    for (index = 0, entry = NULL; index < 1; index++)

#define hlist_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != NULL; pos = NULL)

#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != NULL; pos = NULL)