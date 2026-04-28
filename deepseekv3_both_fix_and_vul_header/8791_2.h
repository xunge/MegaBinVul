#include <stdatomic.h>
#include <stddef.h>
#include <errno.h>

struct ns_common {
    const struct proc_ns_operations *ops;
    unsigned int inum;
};

struct list_head {
    struct list_head *next, *prev;
};

struct wait_queue_head {
    _Atomic int dummy;
};

struct user_namespace;
struct ucounts;
struct mount;

struct mnt_namespace {
    struct ns_common ns;
    _Atomic long long seq;
    _Atomic int count;
    struct mount *root;
    struct list_head list;
    struct wait_queue_head poll;
    unsigned int event;
    struct user_namespace *user_ns;
    struct ucounts *ucounts;
    unsigned int mounts;
    unsigned int pending_mounts;
};

#define GFP_KERNEL 0
#define ENOSPC 28
#define ENOMEM 12
#define ERR_PTR(ptr) ((void*)(long)(ptr))
#define atomic64_add_return(i, v) ((*v) += (i), (*v))
#define atomic_set(v, i) (*(v) = (i))
#define INIT_LIST_HEAD(ptr) do { (ptr)->next = (ptr); (ptr)->prev = (ptr); } while (0)
#define init_waitqueue_head(ptr) ((ptr)->dummy = 0)

extern struct ucounts *inc_mnt_namespaces(struct user_namespace *user_ns);
extern void dec_mnt_namespaces(struct ucounts *ucounts);
extern int ns_alloc_inum(struct ns_common *ns);
extern void kfree(void *ptr);
extern void *kmalloc(size_t size, int flags);
extern struct user_namespace *get_user_ns(struct user_namespace *user_ns);
extern const struct proc_ns_operations mntns_operations;
extern _Atomic long long mnt_ns_seq;