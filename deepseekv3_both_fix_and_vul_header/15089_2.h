#include <sys/socket.h>
#include <sys/time.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

typedef unsigned char u8;

struct socket {
    struct sock *sk;
    unsigned long flags;
    const struct proto_ops *ops;
};

struct sock {
    int sk_sndbuf;
    int sk_rcvbuf;
    int sk_reuse;
    int sk_type;
    int sk_err_soft;
    int sk_no_check;
    int sk_priority;
    unsigned long sk_flags;
    int sk_lingertime;
    long sk_rcvtimeo;
    long sk_sndtimeo;
    int sk_rcvlowat;
    int sk_mark;
    u8 sk_state;
    struct {
        pid_t pid;
        uid_t uid;
        gid_t gid;
    } sk_peercred;
};

struct proto_ops {
    int (*getname)(struct socket *, struct sockaddr *, int *, int);
};

#define HZ 100
#define MAX_SCHEDULE_TIMEOUT LONG_MAX

#define SOCK_DBG 0
#define SOCK_LOCALROUTE 0
#define SOCK_BROADCAST 0
#define SOCK_KEEPOPEN 0
#define SOCK_URGINLINE 0
#define SOCK_LINGER 0
#define SOCK_RCVTSTAMP 0
#define SOCK_RCVTSTAMPNS 0
#define SOCK_PASSCRED 0
#define SOCK_PASSSEC 0

#define TCP_LISTEN 0

#define __user
#define EFAULT 14
#define EINVAL 22
#define ENOTCONN 107
#define ENOPROTOOPT 92

static inline int sock_flag(const struct sock *sk, int flag) { return 0; }
static inline int sock_error(const struct sock *sk) { return 0; }
static inline int xchg(int *ptr, int new) { return 0; }
static inline void sock_warn_obsolete_bsdism(const char *msg) {}
static inline int test_bit(int nr, const volatile unsigned long *addr) { return 0; }
static inline int security_socket_getpeersec_stream(struct socket *sock, char __user *optval, int __user *optlen, int len) { return 0; }
static inline int get_user(int val, int __user *addr) { return 0; }
static inline int put_user(int val, int __user *addr) { return 0; }
static inline int copy_to_user(void __user *to, const void *from, unsigned long n) { return 0; }