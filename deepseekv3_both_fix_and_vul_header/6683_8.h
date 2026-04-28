#include <sys/types.h>
#include <stddef.h>

#define DECLARE_WAITQUEUE(wait, current) struct wait_queue_entry wait = { .private = (void*)(long)current }
#define TASK_INTERRUPTIBLE 1
#define TASK_RUNNING 0
#define ERESTARTSYS 512
#define EAGAIN 11
#define UFFD_EVENT_FORK 0
#define LIST_HEAD(name) struct list_head name = { &(name), &(name) }

typedef int spinlock_t;

struct list_head {
    struct list_head *next, *prev;
};

struct wait_queue_entry {
    unsigned int flags;
    void *private;
    struct list_head entry;
};

struct wait_queue_head {
    spinlock_t lock;
    struct list_head head;
};

struct seqcount {
    unsigned sequence;
};

struct uffd_msg {
    int event;
    struct {
        struct {
            unsigned long reserved1;
        } reserved;
    } arg;
};

struct userfaultfd_wait_queue {
    struct uffd_msg msg;
    struct wait_queue_entry wq;
};

struct userfaultfd_ctx {
    struct wait_queue_head fd_wqh;
    struct wait_queue_head fault_pending_wqh;
    struct wait_queue_head fault_wqh;
    struct wait_queue_head event_wqh;
    struct seqcount refile_seq;
};

extern int current;

static inline void spin_lock(spinlock_t *lock) {}
static inline void spin_unlock(spinlock_t *lock) {}
static inline void __add_wait_queue(struct wait_queue_head *wq_head, struct wait_queue_entry *wq_entry) {}
static inline void __remove_wait_queue(struct wait_queue_head *wq_head, struct wait_queue_entry *wq_entry) {}
static inline void set_current_state(long state) {}
static inline void __set_current_state(long state) {}
static inline int signal_pending(int p) { return 0; }
static inline void schedule(void) {}
static inline void write_seqcount_begin(struct seqcount *s) {}
static inline void write_seqcount_end(struct seqcount *s) {}
static inline void list_move(struct list_head *list, struct list_head *head) {}
static inline void list_del(struct list_head *entry) {}
static inline int list_empty(const struct list_head *head) { return 1; }
#define list_first_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

static struct userfaultfd_wait_queue *find_userfault(struct userfaultfd_ctx *ctx) { return NULL; }
static struct userfaultfd_wait_queue *find_userfault_evt(struct userfaultfd_ctx *ctx) { return NULL; }
static void userfaultfd_event_complete(struct userfaultfd_ctx *ctx, struct userfaultfd_wait_queue *uwq) {}
static int resolve_userfault_fork(struct userfaultfd_ctx *ctx, struct userfaultfd_ctx *nctx, struct uffd_msg *msg) { return 0; }