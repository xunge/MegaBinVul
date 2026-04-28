#include <sys/socket.h>
#include <net/if_arp.h>
#include <net/ethernet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define IFHWADDRLEN 6
#define SOCK_ZAPPED 0x10000000
#define ARPHRD_ETHER 1

struct sockaddr_llc {
    unsigned short sllc_family;
    unsigned short sllc_arphrd;
    unsigned char sllc_mac[IFHWADDRLEN];
    unsigned char sllc_sap;
};

struct llc_addr {
    unsigned char mac[IFHWADDRLEN];
    unsigned char lsap;
};

struct llc_sock {
    struct sock *sk;
    struct llc_addr laddr;
    struct llc_addr daddr;
    struct sockaddr_llc addr;
    struct net_device *dev;
    void *dev_tracker;
};

struct socket {
    struct sock *sk;
};

struct sock {
    unsigned int sk_bound_dev_if;
    unsigned long sk_flags;
};

struct net_device {
    unsigned char dev_addr[IFHWADDRLEN];
    unsigned short type;
};

struct llc_sap {
    // Minimal definition for compilation
};

struct net {
    // Minimal definition for compilation
} init_net;

#define unlikely(x) (x)
#define GFP_ATOMIC 0
#define dprintk(...)

static inline struct llc_sock *llc_sk(struct sock *sk) {
    return (struct llc_sock *)sk;
}

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline int sock_flag(struct sock *sk, int flag) { return 0; }
static inline void sock_reset_flag(struct sock *sk, int flag) {}
static inline void rcu_read_lock() {}
static inline void rcu_read_unlock() {}
static inline struct net_device *dev_get_by_index_rcu(struct net *net, int ifindex) { return NULL; }
static inline struct net_device *dev_getbyhwaddr_rcu(struct net *net, int type, unsigned char *mac) { return NULL; }
static inline void dev_hold_track(struct net_device *dev, void **tracker, int flags) {}
static inline unsigned char llc_ui_autoport() { return 0; }
static inline struct llc_sap *llc_sap_find(unsigned char sap) { return NULL; }
static inline struct llc_sap *llc_sap_open(unsigned char sap, void *arg) { return NULL; }
static inline struct sock *llc_lookup_established(struct llc_sap *sap, struct llc_addr *daddr, struct llc_addr *laddr) { return NULL; }
static inline void sock_put(struct sock *sk) {}
static inline void llc_sap_add_socket(struct llc_sap *sap, struct sock *sk) {}
static inline void llc_sap_put(struct llc_sap *sap) {}
static inline int is_zero_ether_addr(unsigned char *addr) { return 0; }
static inline int ether_addr_equal(unsigned char *addr1, unsigned char *addr2) { return 0; }