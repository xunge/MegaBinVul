#include <string.h>
#include <sys/socket.h>

#define SOCK_ZAPPED 3
#define TCP_ESTABLISHED 1
#define IFHWADDRLEN 6
#define EBADF 9
#define ENOTCONN 107
#define EINVAL 22

struct socket {
    struct sock *sk;
};

struct sock {
    unsigned short sk_state;
    int sk_flags;
};

struct llc_addr {
    unsigned char lsap;
    unsigned char mac[IFHWADDRLEN];
};

struct llc_sap {
    struct llc_addr laddr;
};

struct net_device {
    unsigned short type;
    unsigned char dev_addr[IFHWADDRLEN];
};

struct llc_sock {
    struct sock sk;
    struct llc_addr daddr;
    struct net_device *dev;
    struct llc_sap *sap;
};

struct sockaddr_llc {
    unsigned short sllc_family;
    unsigned char sllc_arphrd;
    unsigned char sllc_sap;
    unsigned char sllc_mac[IFHWADDRLEN];
};

static inline struct llc_sock *llc_sk(const struct sock *sk)
{
    return (struct llc_sock *)sk;
}

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}

static inline int sock_flag(const struct sock *sk, int flag)
{
    return sk->sk_flags & flag;
}