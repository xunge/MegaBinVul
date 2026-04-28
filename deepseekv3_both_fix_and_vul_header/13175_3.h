#include <stddef.h>
#include <limits.h>

#define AF_UNSPEC 0
#define GFP_KERNEL 0
#define ENOMEM 12
#define SOCK_ZEROCOPY 0

struct net;
struct nsproxy {
    struct net *net_ns;
};
struct task_struct {
    struct nsproxy *nsproxy;
};
extern struct task_struct *current;

struct ptr_ring {
    int dummy;
};
struct mutex {
    int dummy;
};
struct sock {
    void (*sk_write_space)(struct sock *sk);
    int sk_sndbuf;
};
struct list_head {
    struct list_head *next, *prev;
};
struct socket {
    struct file *file;
    struct proto_ops *ops;
    struct {
        struct {
            void *wait;
        } wq;
    };
};
struct file {
    void *private_data;
};
struct inode {
    unsigned int i_uid;
};
struct proto_ops;
struct proto {
    int dummy;
};
struct tun_file {
    struct ptr_ring tx_ring;
    struct mutex napi_mutex;
    void *tun;
    int flags;
    int ifindex;
    struct socket socket;
    struct sock sk;
    struct list_head next;
};

extern struct proto tun_proto;
extern struct proto_ops tun_socket_ops;
extern void *sk_alloc(struct net *net, int family, int priority, struct proto *prot, int zero);
extern void sk_free(struct sock *sk);
extern int ptr_ring_init(struct ptr_ring *ring, int size, int gfp);
extern void mutex_init(struct mutex *lock);
extern void RCU_INIT_POINTER(void *p, void *v);
extern void init_waitqueue_head(void *wq);
extern void sock_init_data(struct socket *sock, struct sock *sk);
extern void sock_init_data_uid(struct socket *sock, struct sock *sk, unsigned int uid);
extern void sock_set_flag(struct sock *sk, int flag);
extern void tun_sock_write_space(struct sock *sk);
extern void INIT_LIST_HEAD(struct list_head *list);