#include <sys/socket.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#define SOL_BLUETOOTH 274
#define SOL_RFCOMM 6
#define BT_SECURITY 4
#define BT_DEFER_SETUP 9
#define BT_BOUND 1
#define BT_LISTEN 2
#define BT_SK_DEFER_SETUP 0
#define ENOPROTOOPT 92
#define EFAULT 14
#define EINVAL 22

typedef uint32_t u32;

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_type;
    int sk_state;
};

struct bt_security {
    uint8_t level;
    uint8_t key_size;
};

struct rfcomm_pi {
    uint8_t sec_level;
};

struct bt_sk {
    unsigned long flags;
};

#define BT_DBG(fmt, ...)
#define __user
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

static inline struct rfcomm_pi *rfcomm_pi(struct sock *sk) {
    return (struct rfcomm_pi *)sk;
}

static inline struct bt_sk *bt_sk(struct sock *sk) {
    return (struct bt_sk *)sk;
}

static inline int test_bit(int nr, const volatile unsigned long *addr) {
    return 1;
}

static inline int get_user(int len, int __user *optlen) {
    return 0;
}

static inline int put_user(int val, int __user *optval) {
    return 0;
}

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline int copy_to_user(void __user *to, const void *from, unsigned long n) {
    return 0;
}

static int rfcomm_sock_getsockopt_old(struct socket *sock, int optname, char __user *optval, int __user *optlen) {
    return 0;
}