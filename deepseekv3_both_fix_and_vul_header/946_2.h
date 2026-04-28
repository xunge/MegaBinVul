#include <sys/socket.h>
#include <stdint.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/wait.h>

typedef unsigned int sctp_assoc_t;

struct sock {
    int sk_family;
};

struct socket {
    struct sock *sk;
};

struct sctp_association {
    int wait;
    struct {
        struct {
            int primary_addr;
        } peer;
    };
};

struct sctp_sock {
    struct {
        struct {
            void (*to_sk_daddr)(int *, struct sock *);
        } *pf;
    };
};

#define IPPROTO_SCTP 132
#define SCTP_SOCKET_UDP_HIGH_BANDWIDTH 1
#define UDP 1

extern struct sctp_association *sctp_id2assoc(struct sock *sk, sctp_assoc_t id);
extern struct sctp_sock *sctp_sk(struct sock *sk);
extern int sctp_style(struct sock *sk, int style);
extern int sock_create(int family, int type, int protocol, struct socket **res);
extern void sctp_copy_sock(struct sock *newsk, struct sock *sk, struct sctp_association *asoc);
extern void sctp_sock_migrate(struct sock *oldsk, struct sock *newsk, struct sctp_association *asoc, int type);