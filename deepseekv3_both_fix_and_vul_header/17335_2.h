#include <stddef.h>

struct socket_ops {
    struct module *owner;
    void (*release)(struct socket *sock);
};

struct socket {
    struct socket_ops *ops;
    struct wait_queue_head *wq;
    void *file;
};

struct module;
struct wait_queue_head {
    void *fasync_list;
};

#define rcu_dereference_protected(p, lock) (p)
#define pr_err(fmt, ...) 
#define __func__ ""
#define iput(inode) 
#define SOCK_INODE(sock) NULL
#define module_put(module)