#include <sys/socket.h>
#include <sys/time.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

struct socket {
    struct sock *sk;
    unsigned long flags;
    struct proto_ops *ops;
};

struct sock {
    int sk_sndbuf;
    int sk_rcvbuf;
    int sk_reuse;
    int sk_type;
    int sk_protocol;
    int sk_family;
    int sk_err_soft;
    int sk_no_check;
    int sk_priority;
    int sk_lingertime;
    int sk_rcvtimeo;
    int sk_sndtimeo;
    int sk_rcvlowat;
    int sk_state;
    int sk_mark;
    int sk_peek_off;
    pid_t sk_peer_pid;
    void *sk_peer_cred;
};

struct proto_ops {
    int (*getname)(struct socket *, struct sockaddr *, int *, int);
    int (*set_peek_off)(struct socket *, int);
};

struct ucred {
    pid_t pid;
    uid_t uid;
    gid_t gid;
};

#define HZ 100
#define MAX_SCHEDULE_TIMEOUT LONG_MAX

#define SOCK_DBG 1
#define SOCK_LOCALROUTE 2
#define SOCK_BROADCAST 3
#define SOCK_KEEPOPEN 4
#define SOCK_URGINLINE 5
#define SOCK_LINGER 6
#define SOCK_RCVTSTAMP 7
#define SOCK_RCVTSTAMPNS 8
#define SOCK_TIMESTAMPING_TX_HARDWARE 9
#define SOCK_TIMESTAMPING_TX_SOFTWARE 10
#define SOCK_TIMESTAMPING_RX_HARDWARE 11
#define SOCK_TIMESTAMPING_RX_SOFTWARE 12
#define SOCK_TIMESTAMPING_SOFTWARE 13
#define SOCK_TIMESTAMPING_SYS_HARDWARE 14
#define SOCK_TIMESTAMPING_RAW_HARDWARE 15
#define SOCK_PASSCRED 16
#define SOCK_PASSSEC 17
#define SOCK_RXQ_OVFL 18
#define SOCK_WIFI_STATUS 19
#define SOCK_NOFCS 20

#define SOF_TIMESTAMPING_TX_HARDWARE 1
#define SOF_TIMESTAMPING_TX_SOFTWARE 2
#define SOF_TIMESTAMPING_RX_HARDWARE 4
#define SOF_TIMESTAMPING_RX_SOFTWARE 8
#define SOF_TIMESTAMPING_SOFTWARE 16
#define SOF_TIMESTAMPING_SYS_HARDWARE 32
#define SOF_TIMESTAMPING_RAW_HARDWARE 64

#define TCP_LISTEN 1

#define __user
#define EFAULT 14
#define EINVAL 22
#define ENOTCONN 107
#define EOPNOTSUPP 95
#define ENOPROTOOPT 92

static inline int get_user(int val, int __user *addr) { return 0; }
static inline int put_user(int val, int __user *addr) { return 0; }
static inline int copy_to_user(void __user *to, const void *from, unsigned long n) { return 0; }
static inline int sock_flag(struct sock *sk, int flag) { return 0; }
static inline int sock_error(struct sock *sk) { return 0; }
static inline int xchg(int *ptr, int new) { int old = *ptr; *ptr = new; return old; }
static inline int test_bit(int nr, const volatile unsigned long *addr) { return 0; }
static inline void cred_to_ucred(pid_t pid, void *cred, struct ucred *ucred) {}
static inline int security_socket_getpeersec_stream(struct socket *sock, char __user *optval, int __user *optlen, int len) { return 0; }
static inline void sock_warn_obsolete_bsdism(const char *msg) {}