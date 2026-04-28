#include <stdatomic.h>
#include <errno.h>
#include <stddef.h>

#define CAP_NET_ADMIN 12

enum proc_cn_mcast_op {
    PROC_CN_MCAST_LISTEN,
    PROC_CN_MCAST_IGNORE
};

struct cn_msg {
    unsigned int len;
    unsigned int seq;
    unsigned int ack;
    void *data;
};

struct netlink_skb_parms;
struct user_namespace;
struct pid_namespace;
struct task_struct;

extern atomic_int proc_event_num_listeners;
extern struct user_namespace init_user_ns;
extern struct pid_namespace init_pid_ns;
extern struct task_struct *current;

int capable(int cap);
struct user_namespace *current_user_ns(void);
struct pid_namespace *task_active_pid_ns(struct task_struct *task);
void cn_proc_ack(int err, unsigned int seq, unsigned int ack);
void atomic_inc(atomic_int *v);
void atomic_dec(atomic_int *v);