#include <sys/socket.h>
#include <string.h>
#include <errno.h>

#define BT_OPEN 0
#define BT_BOUND 1
#define EINVAL 22
#define EBADFD 77
#define EADDRINUSE 98

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_state;
    int sk_type;
};

struct sockaddr_rc {
    unsigned short rc_family;
    unsigned char rc_bdaddr[6];
    unsigned char rc_channel;
};

struct rfcomm_sk_list {
    int lock;
};

extern struct rfcomm_sk_list rfcomm_sk_list;
#define rfcomm_pi(sk) ((struct rfcomm_pinfo *)sk)

struct rfcomm_pinfo {
    unsigned char src[6];
    unsigned char channel;
};

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline void write_lock(int *lock) {}
static inline void write_unlock(int *lock) {}
static inline void bacpy(unsigned char dest[6], const unsigned char src[6]) {}
static inline int __rfcomm_get_listen_sock_by_addr(unsigned char channel, const unsigned char bdaddr[6]) { return 0; }
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define BT_DBG(fmt, ...) {}