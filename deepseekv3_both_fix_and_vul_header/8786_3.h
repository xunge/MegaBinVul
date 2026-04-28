#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>

#define SOCK_DBG 1
#define SOCK_LOCALROUTE 2
#define SOCK_BROADCAST 3
#define SOCK_KEEPOPEN 4
#define SOCK_URGINLINE 5
#define SOCK_LINGER 6
#define SOCK_RCVTSTAMP 7
#define SOCK_RCVTSTAMPNS 8
#define SOCK_TIMESTAMP 9
#define SOCK_TIMESTAMPING_TX_HARDWARE 10
#define SOCK_TIMESTAMPING_TX_SOFTWARE 11
#define SOCK_TIMESTAMPING_RX_HARDWARE 12
#define SOCK_TIMESTAMPING_RX_SOFTWARE 13
#define SOCK_TIMESTAMPING_SOFTWARE 14
#define SOCK_TIMESTAMPING_SYS_HARDWARE 15
#define SOCK_TIMESTAMPING_RAW_HARDWARE 16
#define SOCK_RXQ_OVFL 17
#define SOCK_WIFI_STATUS 18
#define SOCK_NOFCS 19
#define SOCK_PASSCRED 20
#define SOCK_PASSSEC 21

#define SK_CAN_REUSE 1
#define SK_NO_REUSE 0

#define SOCK_SNDBUF_LOCK 1
#define SOCK_RCVBUF_LOCK 2

#define SOCK_MIN_SNDBUF 2048
#define SOCK_MIN_RCVBUF 256

#define SOF_TIMESTAMPING_TX_HARDWARE 1
#define SOF_TIMESTAMPING_TX_SOFTWARE 2
#define SOF_TIMESTAMPING_RX_HARDWARE 4
#define SOF_TIMESTAMPING_RX_SOFTWARE 8
#define SOF_TIMESTAMPING_SOFTWARE 16
#define SOF_TIMESTAMPING_SYS_HARDWARE 32
#define SOF_TIMESTAMPING_RAW_HARDWARE 64
#define SOF_TIMESTAMPING_MASK 127

#define CAP_NET_ADMIN 12
#define capable(x) (1)

#define EINVAL 22
#define EFAULT 14
#define EACCES 13
#define ENOPROTOOPT 92
#define EPERM 1
#define EOPNOTSUPP 95

#define __user
#define u32 uint32_t
#define HZ 100
#define MAX_SCHEDULE_TIMEOUT LONG_MAX

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define max_t(type, x, y) ((x) > (y) ? (x) : (y))

struct socket {
    struct sock *sk;
    unsigned long flags;
    struct proto_ops *ops;
};

struct sock {
    int sk_reuse;
    unsigned int sk_userlocks;
    u32 sk_sndbuf;
    u32 sk_rcvbuf;
    void (*sk_write_space)(struct sock *);
    int sk_no_check;
    int sk_priority;
    unsigned long sk_lingertime;
    int sk_mark;
    int sk_protocol;
    int sk_rcvlowat;
    long sk_rcvtimeo;
    long sk_sndtimeo;
};

struct proto_ops {
    int (*set_peek_off)(struct sock *, int);
};

struct sock_fprog {
    unsigned short len;
    void *filter;
};

static inline void set_bit(int nr, volatile unsigned long *addr)
{
    *addr |= (1UL << nr);
}

static inline void clear_bit(int nr, volatile unsigned long *addr)
{
    *addr &= ~(1UL << nr);
}

static u32 sysctl_wmem_max = 131071;
static u32 sysctl_rmem_max = 131071;

extern int sock_bindtodevice(struct sock *sk, char *optval, unsigned int optlen);
extern void lock_sock(struct sock *sk);
extern void release_sock(struct sock *sk);
extern void sock_valbool_flag(struct sock *sk, int flag, int valbool);
extern void sock_reset_flag(struct sock *sk, int flag);
extern void sock_set_flag(struct sock *sk, int flag);
extern void sock_enable_timestamp(struct sock *sk, int flag);
extern void sock_disable_timestamp(struct sock *sk, int flag);
extern int sk_attach_filter(struct sock_fprog *fprog, struct sock *sk);
extern int sk_detach_filter(struct sock *sk);
extern int sock_set_timeout(long *timeo, char *optval, unsigned int optlen);
extern int get_user(int *val, int *uaddr);
extern int copy_from_user(void *to, const void *from, unsigned long n);
extern void sock_warn_obsolete_bsdism(const char *name);