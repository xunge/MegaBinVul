#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <mqueue.h>
#include <time.h>
#include <errno.h>
#include <limits.h>

typedef int mqd_t;

struct fd {
    struct file *file;
};

struct sock;
struct inode {
    struct timespec i_atime;
    struct timespec i_ctime;
    void *i_private;
};
struct sk_buff {
    void *data;
};
struct mqueue_inode_info {
    void *notify_owner;
    void *notify_user_ns;
    struct sigevent notify;
    struct sock *notify_sock;
    struct sk_buff *notify_cookie;
    void *lock;
};
struct file {
    const struct file_operations *f_op;
};
struct task_struct;
struct pid;
struct user_namespace;
struct file_operations;
struct sigevent;

#define MQUEUE_I(inode) ((struct mqueue_inode_info *)inode->i_private)
#define NOTIFY_COOKIE_LEN 32
#define MAX_SCHEDULE_TIMEOUT LONG_MAX
#define GFP_KERNEL 0
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000L)
#define PTR_ERR(ptr) ((long)(ptr))
#define unlikely(x) (x)

static inline struct task_struct *current(void) { return NULL; }
static inline pid_t task_tgid(struct task_struct *task) { return 0; }
static inline struct user_namespace *current_user_ns(void) { return NULL; }
static inline struct timespec current_time(struct inode *inode) { struct timespec ts = {0}; return ts; }
static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}
static inline struct pid *get_pid(pid_t pid) { return NULL; }
static inline struct user_namespace *get_user_ns(struct user_namespace *ns) { return NULL; }
static inline int valid_signal(int sig) { return 1; }
static inline void audit_mq_notify(mqd_t mqdes, const struct sigevent *notification) {}
static inline struct sk_buff *alloc_skb(unsigned int size, int priority) { return NULL; }
static inline void dev_kfree_skb(struct sk_buff *skb) {}
static inline void skb_put(struct sk_buff *skb, unsigned int len) {}
static inline long copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static inline struct fd fdget(int fd) { struct fd f = {0}; return f; }
static inline void fdput(struct fd f) {}
static inline struct sock *netlink_getsockbyfilp(struct file *filp) { return NULL; }
static inline int netlink_attachskb(struct sock *sk, struct sk_buff *skb, long *timeo, void *destructor) { return 0; }
static inline void netlink_detachskb(struct sock *sk, struct sk_buff *skb) {}
static inline struct inode *file_inode(struct file *file) { return NULL; }
static inline void remove_notification(struct mqueue_inode_info *info) {}

extern const struct file_operations mqueue_file_operations;