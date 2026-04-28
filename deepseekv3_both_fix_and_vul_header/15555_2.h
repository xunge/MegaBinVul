#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include <errno.h>
#include <stddef.h>

#define __user
#define CONFIG_COMPAT 1

struct sk_buff;
struct sk_buff_head {
    struct sk_buff *next;
    pthread_spinlock_t lock;
};
struct sk_buff {
    unsigned int len;
    struct sk_buff *next;
};
struct sock {
    int sk_sndbuf;
    struct sk_buff_head sk_receive_queue;
};
struct socket {
    int state;
    struct sock *sk;
};
struct atm_vcc {
    unsigned long flags;
};
struct list_head {
    struct list_head *next, *prev;
};
struct atm_ioctl {
    struct list_head list;
    struct module *owner;
    int (*ioctl)(struct socket *, unsigned int, unsigned long);
};
struct module;
struct mutex {
    pthread_mutex_t lock;
};
struct task_struct {
    char comm[16];
    int pid;
};
typedef unsigned long compat_uptr_t;
struct compat_atm_iobuf {
    int length;
    compat_uptr_t buffer;
};
struct atm_iobuf {
    int length;
    void *buffer;
};
struct compat_atmif_sioc {
    int length;
    compat_uptr_t arg;
    int number;
};
struct atmif_sioc {
    int length;
    void *arg;
    int number;
};

extern struct task_struct *current;

struct mutex ioctl_mutex = {.lock = PTHREAD_MUTEX_INITIALIZER};
struct list_head ioctl_list = {&ioctl_list, &ioctl_list};

#define ATM_SD(sock) ((struct atm_vcc *)sock)
#define SS_CONNECTED 1
#define ATM_VF_READY 0
#define EINVAL 22
#define EFAULT 14
#define EPERM 1
#define ENOIOCTLCMD 515
#define CAP_NET_ADMIN 12
#define CAP_SYS_RAWIO 17
#define SIOCOUTQ 0x5411
#define SIOCINQ 0x541B
#define ATM_SETSC 1
#define ATMSIGD_CTRL 2
#define ATM_SETBACKEND 3
#define ATM_NEWBACKENDIF 4
#define ATM_BACKEND_PPP 1
#define ATM_BACKEND_BR2684 2
#define ATMMPC_CTRL 5
#define ATMMPC_DATA 6
#define ATMARPD_CTRL 7
#define ATMLEC_CTRL 8
#define ATM_GETNAMES 9

typedef int atm_backend_t;

static inline int test_bit(int nr, const volatile unsigned long *addr) {
    return (*addr & (1UL << nr)) != 0;
}
static inline int put_user(int x, int *ptr) {
    *ptr = x;
    return 0;
}
static inline int get_user(int *x, void *ptr) {
    *x = *(int *)ptr;
    return 0;
}
static inline int get_user_compat(compat_uptr_t *x, void *ptr) {
    *x = *(compat_uptr_t *)ptr;
    return 0;
}
static inline struct sk_buff *skb_peek(struct sk_buff_head *list) {
    return list->next;
}
static inline int sk_wmem_alloc_get(struct sock *sk) {
    return 0;
}
static inline int capable(int cap) {
    return 1;
}
static inline int sigd_attach(struct atm_vcc *vcc) {
    return 0;
}
static inline int request_module(const char *name) {
    return 0;
}
static inline void mutex_lock(struct mutex *lock) {
    pthread_mutex_lock(&lock->lock);
}
static inline void mutex_unlock(struct mutex *lock) {
    pthread_mutex_unlock(&lock->lock);
}
static inline void spin_lock_irq(pthread_spinlock_t *lock) {
    pthread_spin_lock(lock);
}
static inline void spin_unlock_irq(pthread_spinlock_t *lock) {
    pthread_spin_unlock(lock);
}
#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)
#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr)-offsetof(type, member)))
static inline int try_module_get(struct module *mod) {
    return 1;
}
static inline void module_put(struct module *mod) {
}
static inline int atm_getnames(void *buf, int *len) {
    return 0;
}
static inline int atm_dev_ioctl(unsigned int cmd, void *buf, int *len, int number, int compat) {
    return 0;
}
static inline void net_warn_ratelimited(const char *fmt, ...) {}
static inline int task_pid_nr(struct task_struct *tsk) {
    return tsk->pid;
}
static inline void *compat_ptr(compat_uptr_t uptr) {
    return (void *)(unsigned long)uptr;
}
#define IS_ENABLED(x) 1