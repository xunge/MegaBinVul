#include <stddef.h>
#include <string.h>

struct sock;
struct net;
struct inet6_ifaddr {
    int flags;
};
struct in6_addr {
    unsigned char s6_addr[16];
};

struct dst_entry {
    int error;
    struct neighbour *neighbour;
    int dev;
    struct inet6_dev *idev;
};

struct neighbour {
    unsigned int nud_state;
};

struct inet6_dev {
    int dev;
};

struct flowi {
    struct in6_addr fl6_src;
    struct in6_addr fl6_dst;
};

struct inet6_skb_parm {
    int srcprefs;
};

enum {
    NUD_VALID = 1,
    IFA_F_OPTIMISTIC = 1
};

#define CONFIG_IPV6_OPTIMISTIC_DAD 1
#define ENETUNREACH 101
#define IPSTATS_MIB_OUTNOROUTES 1

static inline struct inet6_skb_parm *inet6_sk(const struct sock *sk) {
    return (struct inet6_skb_parm *)sk;
}

static inline struct inet6_dev *ip6_dst_idev(const struct dst_entry *dst) {
    return dst->idev;
}