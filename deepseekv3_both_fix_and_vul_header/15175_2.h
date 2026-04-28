#include <sys/socket.h>
#include <string.h>
#include <linux/if_arp.h>

#define SOCK_ZAPPED 0x00000001
#define ENOTCONN 107
#define EINVAL 22
#define TCP_ESTABLISHED 1
#define IFHWADDRLEN 6

struct socket {
    struct sock *sk;
};

struct sock {
    unsigned int sk_state;
    unsigned long sk_flags;
};

struct llc_sock {
    struct {
        unsigned char lsap;
        unsigned char mac[IFHWADDRLEN];
    } daddr;
    struct {
        struct {
            unsigned char lsap;
        } laddr;
    } *sap;
    struct net_device *dev;
};

struct net_device {
    unsigned short type;
    unsigned char dev_addr[IFHWADDRLEN];
};

struct sockaddr_llc {
    unsigned short sllc_family;
    unsigned short sllc_arphrd;
    unsigned char sllc_sap;
    unsigned char sllc_mac[IFHWADDRLEN];
};

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline int sock_flag(struct sock *sk, int flag) { return sk->sk_flags & flag; }
static inline struct llc_sock *llc_sk(struct sock *sk) { return (struct llc_sock *)sk; }