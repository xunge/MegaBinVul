#include <stddef.h>
#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

static inline bool list_empty(const struct list_head *head)
{
    return head->next == head;
}

struct mutex {
    int dummy;
};

static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}

struct cred {
    int dummy;
};

struct task_struct {
    int dummy;
};

struct socket {
    void *file;
};

struct mm_struct {
    int dummy;
};

struct percpu_ref {
    int dummy;
};

struct xarray {
    int dummy;
};

struct io_alloc_cache {
    int dummy;
};

struct io_ring_ctx {
    struct mutex uring_lock;
    struct list_head rsrc_ref_list;
    void *buf_data;
    void *file_data;
    struct cred *sq_creds;
    struct task_struct *submitter_task;
    void *rsrc_node;
    struct socket *ring_sock;
    struct list_head ltimeout_list;
    struct mm_struct *mm_account;
    struct percpu_ref refs;
    unsigned int user;
    void *hash_map;
    struct {
        void *hbs;
    } cancel_table;
    struct {
        void *hbs;
    } cancel_table_locked;
    void *io_bl;
    struct xarray io_bl_xa;
    struct io_alloc_cache apoll_cache;
    struct io_alloc_cache netmsg_cache;
    struct io_alloc_cache rsrc_node_cache;
};

#define WARN_ON_ONCE(cond) (cond)
#define __cold

static void io_sq_thread_finish(struct io_ring_ctx *ctx) {}
static void __io_sqe_buffers_unregister(struct io_ring_ctx *ctx) {}
static void __io_sqe_files_unregister(struct io_ring_ctx *ctx) {}
static void io_cqring_overflow_kill(struct io_ring_ctx *ctx) {}
static void io_eventfd_unregister(struct io_ring_ctx *ctx) {}
static void io_apoll_cache_free(void *ptr) {}
static void io_netmsg_cache_free(void *ptr) {}
static void io_futex_cache_free(struct io_ring_ctx *ctx) {}
static void io_destroy_buffers(struct io_ring_ctx *ctx) {}
static void io_rsrc_node_destroy(struct io_ring_ctx *ctx, void *node) {}
static void io_rings_free(struct io_ring_ctx *ctx) {}
static void io_req_caches_free(struct io_ring_ctx *ctx) {}
static void io_rsrc_node_cache_free(void *ptr) {}
static void io_wq_put_hash(void *hash_map) {}
static void put_cred(struct cred *cred) {}
static void put_task_struct(struct task_struct *task) {}
static void sock_release(struct socket *sock) {}
static void mmdrop(struct mm_struct *mm) {}
static void percpu_ref_exit(struct percpu_ref *ref) {}
static void free_uid(unsigned int user) {}
static void kfree(void *ptr) {}
static void xa_destroy(struct xarray *xa) {}
static void io_alloc_cache_free(struct io_alloc_cache *cache, void (*free_fn)(void *)) {}