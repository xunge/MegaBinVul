#include <sys/types.h>
#include <sys/socket.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>

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

#define SOF_TIMESTAMPING_TX_HARDWARE (1<<0)
#define SOF_TIMESTAMPING_TX_SOFTWARE (1<<1)
#define SOF_TIMESTAMPING_RX_HARDWARE (1<<2)
#define SOF_TIMESTAMPING_RX_SOFTWARE (1<<3)
#define SOF_TIMESTAMPING_SOFTWARE (1<<4)
#define SOF_TIMESTAMPING_SYS_HARDWARE (1<<5)
#define SOF_TIMESTAMPING_RAW_HARDWARE (1<<6)
#define SOF_TIMESTAMPING_MASK (SOF_TIMESTAMPING_TX_HARDWARE | \
                              SOF_TIMESTAMPING_TX_SOFTWARE | \
                              SOF_TIMESTAMPING_RX_HARDWARE | \
                              SOF_TIMESTAMPING_RX_SOFTWARE | \
                              SOF_TIMESTAMPING_SOFTWARE | \
                              SOF_TIMESTAMPING_SYS_HARDWARE | \
                              SOF_TIMESTAMPING_RAW_HARDWARE)

#define CAP_NET_ADMIN 12
#define HZ 100
#define MAX_SCHEDULE_TIMEOUT LONG_MAX

struct sock;

struct proto_ops {
    int (*set_peek_off)(struct sock *sk, int val);
};

struct socket {
    struct sock *sk;
    unsigned long flags;
    const struct proto_ops *ops;
};

struct sock {
    unsigned int sk_protocol;
    unsigned int sk_userlocks;
    unsigned int sk_sndbuf;
    unsigned int sk_rcvbuf;
    unsigned int sk_priority;
    unsigned int sk_mark;
    unsigned int sk_no_check;
    unsigned int sk_reuse;
    unsigned int sk_lingertime;
    unsigned int sk_rcvlowat;
    long sk_rcvtimeo;
    long sk_sndtimeo;
    void (*sk_write_space)(struct sock *sk);
};

struct sock_fprog {
    unsigned short len;
    struct sock_filter *filter;
};

struct sock_filter {
    unsigned short code;
    unsigned char jt;
    unsigned char jf;
    unsigned int k;
};

static unsigned int sysctl_wmem_max = 131071;
static unsigned int sysctl_rmem_max = 131071;

static inline void set_bit(int nr, volatile unsigned long *addr)
{
    addr[nr / (8 * sizeof(long))] |= (1UL << (nr % (8 * sizeof(long))));
}

static inline void clear_bit(int nr, volatile unsigned long *addr)
{
    addr[nr / (8 * sizeof(long))] &= ~(1UL << (nr % (8 * sizeof(long))));
}

extern int sock_bindtodevice(struct sock *sk, char *optval, unsigned int optlen);
extern void sock_valbool_flag(struct sock *sk, int flag, int valbool);
extern void sock_set_flag(struct sock *sk, int flag);
extern void sock_reset_flag(struct sock *sk, int flag);
extern void sock_enable_timestamp(struct sock *sk, int flag);
extern void sock_disable_timestamp(struct sock *sk, int flag);
extern int sk_attach_filter(struct sock_fprog *fprog, struct sock *sk);
extern int sk_detach_filter(struct sock *sk);
extern void sock_warn_obsolete_bsdism(const char *msg);
extern int sock_set_timeout(long *timeo_p, char *optval, unsigned int optlen);
extern void lock_sock(struct sock *sk);
extern void release_sock(struct sock *sk);
extern int capable(int cap);
extern int get_user(int *val, int *optval);
extern int copy_from_user(void *dst, const void *src, unsigned long size);

#define EINVAL 22
#define EFAULT 14
#define EACCES 13
#define ENOPROTOOPT 92
#define EPERM 1
#define EOPNOTSUPP 95

typedef unsigned int u32;
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define max_t(type, x, y) ((x) > (y) ? (x) : (y))

/* Remove __user attribute */
#define __user