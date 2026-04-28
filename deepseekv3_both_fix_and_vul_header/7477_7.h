#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>

struct socket {
    struct sock *sk;
    unsigned long flags;
    struct proto_ops *ops;
};

struct sock {
    int sk_sndbuf;
    int sk_rcvbuf;
    int sk_reuse;
    int sk_reuseport;
    int sk_type;
    int sk_protocol;
    int sk_family;
    int sk_err_soft;
    int sk_no_check_tx;
    int sk_priority;
    int sk_lingertime;
    int sk_tsflags;
    int sk_bind_phc;
    int sk_rcvtimeo;
    int sk_sndtimeo;
    int sk_rcvlowat;
    int sk_mark;
    int sk_ll_usec;
    int sk_prefer_busy_poll;
    int sk_incoming_cpu;
    int sk_napi_id;
    int sk_clockid;
    int sk_txtime_deadline_mode;
    int sk_txtime_report_errors;
    int sk_bound_dev_if;
    int sk_userlocks;
    int sk_peek_off;
    unsigned long sk_max_pacing_rate;
    pid_t sk_peer_pid;
    struct cred *sk_peer_cred;
    void *sk_peer_lock;
    int sk_state;
};

struct net {
    uint64_t net_cookie;
};

struct old_timeval32 {
    int tv_sec;
    int tv_usec;
};

struct __kernel_old_timeval {
    long tv_sec;
    long tv_usec;
};

struct __kernel_sock_timeval {
    long tv_sec;
    long tv_usec;
};

struct sock_txtime {
    int clockid;
    int flags;
};

struct so_timestamping {
    int flags;
    int bind_phc;
};

struct ucred {
    pid_t pid;
    uid_t uid;
    gid_t gid;
};

struct sock_filter {
    unsigned short code;
    unsigned char jt;
    unsigned char jf;
    unsigned int k;
};

struct proto_ops {
    int (*getname)(struct socket *, struct sockaddr *, int);
    int (*set_peek_off)(struct sock *, int);
};

#define __user
#define SOCK_DBG 0
#define SOCK_LOCALROUTE 1
#define SOCK_BROADCAST 2
#define SOCK_KEEPOPEN 3
#define SOCK_URGINLINE 4
#define SOCK_LINGER 5
#define SOCK_RCVTSTAMP 6
#define SOCK_TSTAMP_NEW 7
#define SOCK_RCVTSTAMPNS 8
#define SOCK_PASSCRED 9
#define SOCK_PASSSEC 10
#define SOCK_RXQ_OVFL 11
#define SOCK_WIFI_STATUS 12
#define SOCK_NOFCS 13
#define SOCK_FILTER_LOCKED 14
#define SOCK_SELECT_ERR_QUEUE 15
#define SOCK_ZEROCOPY 16

#define TCP_LISTEN 1
#define HZ 100
#define MIN_NAPI_ID 0
#define SOCK_BUF_LOCK_MASK 0
#define SK_MEMINFO_VARS 10
#define SOF_TXTIME_DEADLINE_MODE (1 << 0)
#define SOF_TXTIME_REPORT_ERRORS (1 << 1)

#define EFAULT 14
#define EINVAL 22
#define ENODATA 61
#define ERANGE 34
#define ENOTCONN 107
#define EOPNOTSUPP 95
#define ENOPROTOOPT 92

typedef uint32_t u32;
typedef uint64_t u64;

struct cred {
    struct group_info *group_info;
};

struct group_info {
    int ngroups;
    gid_t *gid;
};

#define min_t(type, x, y) ({ type __x = (x); type __y = (y); __x < __y ? __x : __y; })

static inline int get_user(int val, int __user *ptr) { return 0; }
static inline int put_user(int val, int __user *ptr) { return 0; }
static inline int copy_to_user(void __user *to, const void *from, unsigned long n) { return 0; }
static inline int sock_error(struct sock *sk) { return 0; }
static inline int xchg(int *ptr, int val) { return 0; }
static inline int sock_flag(struct sock *sk, int flag) { return 0; }
static inline int sock_get_timeout(unsigned long timeout, void *v, int old) { return 0; }
static inline int test_bit(int nr, const volatile unsigned long *addr) { return 0; }
static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}
static inline void cred_to_ucred(pid_t pid, struct cred *cred, struct ucred *ucred) {}
static inline const struct cred *sk_get_peer_cred(struct sock *sk) { return NULL; }
static inline void put_cred(const struct cred *cred) {}
static inline int groups_to_user(gid_t __user *grouplist, struct group_info *group_info) { return 0; }
static inline int security_socket_getpeersec_stream(struct socket *sock, char __user *optval, int __user *optlen, int len) { return 0; }
static inline int sock_getbindtodevice(struct sock *sk, char __user *optval, int __user *optlen, int len) { return 0; }
static inline int sk_get_filter(struct sock *sk, struct sock_filter __user *filter, int len) { return 0; }
static inline int bpf_tell_extensions(void) { return 0; }
static inline void sk_get_meminfo(struct sock *sk, u32 *meminfo) {}
static inline u64 sock_gen_cookie(struct sock *sk) { return 0; }
static inline struct net *sock_net(struct sock *sk) { return NULL; }
static inline int READ_ONCE(int x) { return x; }