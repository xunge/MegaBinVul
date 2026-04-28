#include <sys/socket.h>
#include <linux/types.h>
#include <linux/net.h>
#include <linux/sched.h>
#include <linux/wait.h>
#include <linux/errno.h>
#include <netinet/in.h>

typedef unsigned int sctp_assoc_t;

struct sock {
    int sk_family;
};
struct socket {
    struct sock *sk;
};
struct wait_queue_head;
struct sctp_association {
    struct wait_queue_head *wait;
    struct {
        struct sockaddr_storage primary_addr;
    } peer;
};
struct sctp_sock {
    struct {
        void (*to_sk_daddr)(struct sockaddr_storage *, struct sock *);
    } *pf;
};
struct nsproxy {
    struct net *net_ns;
};
struct net;
struct task_struct {
    struct nsproxy *nsproxy;
};

extern struct task_struct *current;
#define UDP 0
#define SCTP_SOCKET_UDP_HIGH_BANDWIDTH 0

extern int net_eq(struct net *, struct net *);
extern struct net *sock_net(struct sock *);
extern int waitqueue_active(struct wait_queue_head *);
extern struct sctp_association *sctp_id2assoc(struct sock *, sctp_assoc_t);
extern struct sctp_sock *sctp_sk(struct sock *);
extern int sctp_style(struct sock *, int);
extern int sock_create(int, int, int, struct socket **);
extern void sctp_copy_sock(struct sock *, struct sock *, struct sctp_association *);
extern void sctp_sock_migrate(struct sock *, struct sock *, struct sctp_association *, int);