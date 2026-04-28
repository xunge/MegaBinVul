#include <stdlib.h>
#include <stdbool.h>
#include <stdatomic.h>
#include <string.h>
#include <pthread.h>

#define ENOMEM 12
#define GFP_KERNEL 0
#define IO_WQ_ACCT_BOUND 0
#define IO_WQ_ACCT_UNBOUND 1
#define IO_WQ_BIT_ERROR 0
#define RLIMIT_NPROC 0

struct io_wq_work;
struct mm_struct;
struct cred;
struct task_struct;

struct list_head {
    struct list_head *next, *prev;
};

struct hlist_nulls_node {
    struct hlist_nulls_node *next, **pprev;
};

struct hlist_nulls_head {
    struct hlist_nulls_node *first;
};

struct completion {
    unsigned int done;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};

struct io_wq_data {
    void (*get_work)(struct io_wq_work *work);
    void (*put_work)(struct io_wq_work *work);
    struct mm_struct *mm;
    bool user;
    const struct cred *creds;
};

struct io_wq_acct {
    atomic_int nr_running;
    unsigned max_workers;
};

struct io_wqe {
    struct io_wq *wq;
    int node;
    struct io_wq_acct acct[2];
    pthread_spinlock_t lock;
    struct list_head work_list;
    struct hlist_nulls_head free_list;
    struct hlist_nulls_head busy_list;
    struct list_head all_list;
};

struct io_wq {
    unsigned nr_wqes;
    struct io_wqe **wqes;
    void (*get_work)(struct io_wq_work *work);
    void (*put_work)(struct io_wq_work *work);
    struct mm_struct *mm;
    bool user;
    const struct cred *creds;
    struct task_struct *manager;
    struct completion done;
    unsigned long state;
};

static void *io_wq_manager(void *arg) { return NULL; }

#define kcalloc(n, size, flags) calloc(n, size)
#define kcalloc_node(n, size, flags, node) calloc(n, size)
#define kfree(ptr) free(ptr)
#define ERR_PTR(err) ((void *)(long)(err))
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)(-1000))
#define PTR_ERR(ptr) ((long)(ptr))
#define num_online_nodes() 1
#define for_each_online_node(node) for (node = 0; node < 1; node++)
#define spin_lock_init(lock) pthread_spin_init(lock, 0)
#define INIT_LIST_HEAD(head) do { (head)->next = (head); (head)->prev = (head); } while (0)
#define INIT_HLIST_NULLS_HEAD(head, bits) (head)->first = NULL
#define init_completion(comp) do { \
    (comp)->done = 0; \
    pthread_mutex_init(&(comp)->mutex, NULL); \
    pthread_cond_init(&(comp)->cond, NULL); \
} while (0)
#define reinit_completion(comp) (comp)->done = 0
#define complete(comp) do { \
    pthread_mutex_lock(&(comp)->mutex); \
    (comp)->done = 1; \
    pthread_cond_signal(&(comp)->cond); \
    pthread_mutex_unlock(&(comp)->mutex); \
} while (0)
#define wait_for_completion(comp) do { \
    pthread_mutex_lock(&(comp)->mutex); \
    while (!(comp)->done) { \
        pthread_cond_wait(&(comp)->cond, &(comp)->mutex); \
    } \
    pthread_mutex_unlock(&(comp)->mutex); \
} while (0)
#define test_bit(nr, addr) (0)
#define wake_up_process(task) (void)0
#define current ((struct task_struct *)0)
#define task_rlimit(task, limit) (0)
#define atomic_set(v, i) atomic_store(v, i)
#define kthread_create(fn, data, name) pthread_create(NULL, NULL, fn, data)