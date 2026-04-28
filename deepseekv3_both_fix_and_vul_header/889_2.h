#include <stdbool.h>
#include <stddef.h>

struct fib_rule {
    int suppress_prefixlen;
    int suppress_ifgroup;
};

struct fib_lookup_arg {
    unsigned int flags;
    void *result;
};

struct fib6_result {
    struct rt6_info *rt6;
};

struct in6_addr {
    unsigned char s6_addr[16];
    int plen;
};

struct rt6_info {
    struct in6_addr rt6i_dst;
    struct inet6_dev *rt6i_idev;
};

struct inet6_dev {
    struct net_device *dev;
};

struct net_device {
    int group;
};

#define FIB_LOOKUP_NOREF 1

void ip6_rt_put(struct rt6_info *rt);