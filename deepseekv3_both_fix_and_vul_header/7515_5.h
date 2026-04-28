#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <string.h>

typedef unsigned int gfp_t;

struct socket {
    struct sock *sk;
};

struct sock {
    unsigned int sk_bound_dev_if;
};

struct net_device {
    unsigned short type;
    unsigned char dev_addr[6];
};

struct netdev_tracker {
};

struct net {
};

struct sockaddr_llc {
    unsigned short sllc_arphrd;
    unsigned char sllc_test;
    unsigned char sllc_xid;
    unsigned char sllc_ua;
    unsigned char sllc_sap;
};

struct llc_sock {
    struct sock sk;
    struct net_device *dev;
    struct netdev_tracker dev_tracker;
    struct {
        unsigned char lsap;
        unsigned char mac[6];
    } laddr;
    struct sockaddr_llc addr;
};

struct llc_sap {
};

#define SOCK_ZAPPED 0x00000001
#define ARPHRD_ETHER 1
#define IFHWADDRLEN 6
#define GFP_KERNEL 0
#define EINVAL 22
#define ENODEV 19
#define EUSERS 87
#define EBUSY 16

extern struct net init_net;
extern struct llc_sock *llc_sk(struct sock *sk);
extern int llc_ui_autoport(void);
extern struct net_device *dev_get_by_index(struct net *net, int ifindex);
extern void dev_put(struct net_device *dev);
extern struct net_device *dev_getfirstbyhwtype(struct net *net, int type);
extern void netdev_tracker_alloc(struct net_device *dev, struct netdev_tracker *tracker, gfp_t gfp);
extern struct llc_sap *llc_sap_open(unsigned char lsap, void (*func)(void *skb, struct sock *sk));
extern void llc_sap_add_socket(struct llc_sap *sap, struct sock *sk);
extern void sock_reset_flag(struct sock *sk, int flag);
extern int sock_flag(struct sock *sk, int flag);