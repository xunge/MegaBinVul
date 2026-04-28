#include <sys/types.h>
#include <stddef.h>
#include <errno.h>

typedef long ssize_t;
#define __user

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)

struct ucma_file;
struct ucma_context;
struct ucma_event;

struct fd {
    struct file *file;
};

struct file {
    const struct file_operations *f_op;
    void *private_data;
};

struct file_operations {
};

struct mutex {
};

struct rdma_cm_id {
};

struct xarray {
};

extern const struct file_operations ucma_fops;
extern struct xarray ctx_table;

struct rdma_ucm_migrate_id {
    int fd;
    unsigned int id;
    unsigned long long response;
};

struct rdma_ucm_migrate_resp {
    unsigned int events_reported;
};

struct ucma_event {
    struct list_head list;
    struct ucma_context *ctx;
};

struct ucma_context {
    struct list_head list;
    struct ucma_file *file;
    unsigned int id;
    unsigned int events_reported;
    struct rdma_cm_id *cm_id;
};

struct ucma_file {
    struct mutex mut;
    struct list_head ctx_list;
    struct list_head event_list;
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define EFAULT 14
#define ENOENT 2
#define EINVAL 22

static inline int copy_from_user(void *to, const void __user *from, unsigned long n) { return 0; }
static inline int copy_to_user(void __user *to, const void *from, unsigned long n) { return 0; }
static inline struct fd fdget(int fd) { struct fd f = {0}; return f; }
static inline void fdput(struct fd f) {}
static inline void rdma_lock_handler(struct rdma_cm_id *cm_id) {}
static inline void rdma_unlock_handler(struct rdma_cm_id *cm_id) {}
static inline void xa_lock(struct xarray *xa) {}
static inline void xa_unlock(struct xarray *xa) {}
static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline void list_del(struct list_head *entry) {}
static inline void list_add_tail(struct list_head *new, struct list_head *head) {}
static inline void list_move_tail(struct list_head *list, struct list_head *head) {}
static inline void list_splice_tail(struct list_head *list, struct list_head *head) {}
#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos != (head); pos = n)
static inline struct ucma_context *ucma_get_ctx(struct ucma_file *file, unsigned int id) { return NULL; }
static inline void ucma_put_ctx(struct ucma_context *ctx) {}
static inline struct ucma_context *_ucma_find_context(unsigned int id, struct ucma_file *file) { return NULL; }