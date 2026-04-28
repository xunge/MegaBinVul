#include <sys/socket.h>
#include <sys/time.h>
#include <errno.h>
#include <unistd.h>

struct socket {
    struct sock *sk;
    struct file *file;
};

struct sock {
    int sk_err;
};

struct file;

struct mmsghdr {
    int msg_len;
};

struct compat_mmsghdr {
    int msg_len;
};

struct user_msghdr {
    int msg_len;
};

#define __user
#define EINVAL 22
#define EAGAIN 11
#define MSG_CMSG_COMPAT 0x80000000

static inline int poll_select_set_timeout(struct timespec *to, time_t sec, long nsec) {
    return 0;
}

static inline void cond_resched(void) {
}

static inline void fput_light(struct file *file, int fput_needed) {
}

static inline void ktime_get_ts(struct timespec *ts) {
}

static inline struct timespec timespec_sub(struct timespec lhs, struct timespec rhs) {
    return lhs;
}

static inline struct socket *sockfd_lookup_light(int fd, int *err, int *fput_needed) {
    return 0;
}

static inline int sock_error(struct sock *sk) {
    return 0;
}

static inline int ___sys_recvmsg(struct socket *sock, struct user_msghdr *msg, struct msghdr *msg_sys, unsigned int flags, int datagrams) {
    return 0;
}

static inline int __put_user(int val, int *addr) {
    return 0;
}

static inline int put_user(int val, int *addr) {
    return 0;
}