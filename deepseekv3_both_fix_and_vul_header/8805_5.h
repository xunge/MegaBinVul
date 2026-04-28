#include <sys/types.h>
#include <sys/socket.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint8_t u8;

#define SOCK_DBG 0
#define SOCK_LOCALROUTE 1
#define SOCK_BROADCAST 2
#define SOCK_KEEPOPEN 3
#define SOCK_URGINLINE 4
#define SOCK_LINGER 5
#define SOCK_RCVTSTAMP 6
#define SOCK_RCVTSTAMPNS 7
#define SOCK_PASSCRED 8
#define SOCK_PASSSEC 9
#define SOCK_RXQ_OVFL 10
#define SOCK_WIFI_STATUS 11
#define SOCK_NOFCS 12
#define SOCK_SELECT_ERR_QUEUE 13
#define SOCK_FILTER_LOCKED 14

#define SK_CAN_REUSE 1
#define SK_NO_REUSE 0

#define SOCK_MIN_SNDBUF 2048
#define SOCK_MIN_RCVBUF 256

#define SOCK_TIMESTAMP 0
#define SOCK_TIMESTAMPING_RX_SOFTWARE 1

#define SOF_TIMESTAMPING_MASK 0x0000ffff
#define SOF_TIMESTAMPING_OPT_ID 0x00000001
#define SOF_TIMESTAMPING_RX_SOFTWARE 0x00000002

#define TCPF_CLOSE 0x00000010
#define TCPF_LISTEN 0x00000020

#define CAP_NET_ADMIN 12
#define EINVAL 22
#define EFAULT 14
#define EACCES 13
#define ENOPROTOOPT 92
#define EPERM 1
#define EOPNOTSUPP 95

#define HZ 100
#define MAX_SCHEDULE_TIMEOUT LONG_MAX
#define BITS_PER_LONG (__CHAR_BIT__ * __SIZEOF_LONG__)

#define SOCK_SNDBUF_LOCK (1 << 0)
#define SOCK_RCVBUF_LOCK (1 << 1)

#define IPPROTO_TCP 6

#define sysctl_wmem_max (256 * 1024)
#define sysctl_rmem_max (256 * 1024)

struct socket {
    struct sock *sk;
    unsigned long flags;
    const struct proto_ops *ops;
};

struct sock {
    unsigned int sk_protocol;
    unsigned int sk_type;
    unsigned int sk_state;
    unsigned int sk_userlocks;
    unsigned int sk_sndbuf;
    unsigned int sk_rcvbuf;
    unsigned int sk_priority;
    unsigned int sk_mark;
    unsigned int sk_ll_usec;
    unsigned int sk_max_pacing_rate;
    unsigned int sk_pacing_rate;
    unsigned int sk_incoming_cpu;
    unsigned long sk_lingertime;
    unsigned long sk_tsflags;
    u32 sk_tskey;
    u8 sk_no_check_tx;
    u8 sk_reuse;
    u8 sk_reuseport;
    void (*sk_write_space)(struct sock *sk);
    struct net *sk_net;
    void (*sk_destruct)(struct sock *sk);
    int sk_rcvlowat;
    long sk_rcvtimeo;
    long sk_sndtimeo;
};

struct sock_fprog {
    unsigned short len;
    void *filter;
};

struct net {
    void *user_ns;
};

struct proto_ops {
    int (*set_peek_off)(struct sock *sk, int val);
};

struct tcp_sock {
    u32 snd_una;
};

static inline struct tcp_sock *tcp_sk(const struct sock *sk)
{
    return (struct tcp_sock *)sk;
}

static inline struct net *sock_net(const struct sock *sk)
{
    return sk->sk_net;
}

static inline int capable(int cap) { return 1; }
static inline int ns_capable(void *ns, int cap) { return 1; }
static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline int get_user(int val, int *ptr) { return 0; }
static inline int copy_from_user(void *dst, const void *src, size_t size) { return 0; }
static inline void sock_valbool_flag(struct sock *sk, int flag, int valbool) {}
static inline void sock_reset_flag(struct sock *sk, int flag) {}
static inline void sock_set_flag(struct sock *sk, int flag) {}
static inline void sock_enable_timestamp(struct sock *sk, int flag) {}
static inline void sock_disable_timestamp(struct sock *sk, int flag) {}
static inline int sock_set_timeout(long *timeo, void *optval, unsigned int optlen) { return 0; }
static inline int sk_attach_filter(struct sock_fprog *fprog, struct sock *sk) { return 0; }
static inline int sk_attach_bpf(u32 ufd, struct sock *sk) { return 0; }
static inline int sk_reuseport_attach_filter(struct sock_fprog *fprog, struct sock *sk) { return 0; }
static inline int sk_reuseport_attach_bpf(u32 ufd, struct sock *sk) { return 0; }
static inline int sk_detach_filter(struct sock *sk) { return 0; }
static inline int sock_flag(struct sock *sk, int flag) { return 0; }
static inline void set_bit(int nr, volatile unsigned long *addr) {}
static inline void clear_bit(int nr, volatile unsigned long *addr) {}
static inline void sock_warn_obsolete_bsdism(const char *msg) {}
static inline int sock_setbindtodevice(struct sock *sk, void *optval, unsigned int optlen) { return 0; }
static inline void dst_negative_advice(struct sock *sk) {}

#define min_t(type, x, y) ({ \
    type __min1 = (x); \
    type __min2 = (y); \
    __min1 < __min2 ? __min1 : __min2; \
})

#define max_t(type, x, y) ({ \
    type __max1 = (x); \
    type __max2 = (y); \
    __max1 > __max2 ? __max1 : __max2; \
})

#define min(x, y) ((x) < (y) ? (x) : (y))

#define __user