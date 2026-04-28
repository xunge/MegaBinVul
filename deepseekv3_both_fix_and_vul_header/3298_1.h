#include <stddef.h>
#include <stdint.h>

#define ENOMEM 12
#define NLM_F_CREATE 0x400
#define NLM_F_REPLACE 0x100
#define RTN_ROOT 0x1
#define RTN_RTINFO 0x2
#define RTF_CACHE 0x10000

struct in6_addr {
    uint8_t s6_addr[16];
};

struct dst_entry {
    // minimal definition
};

struct fib6_node {
    struct fib6_node *parent;
    struct fib6_node *subtree;
    void *leaf;
    int fn_flags;
    int fn_sernum;
};

struct rt6_info {
    struct dst_entry dst;
    struct {
        struct in6_addr addr;
        int plen;
    } rt6i_dst, rt6i_src;
    int rt6i_flags;
    int rt6i_ref;
};

struct nlmsghdr {
    int nlmsg_flags;
};

struct net {
    struct {
        struct rt6_info *ip6_null_entry;
    } ipv6;
};

struct nl_info {
    struct nlmsghdr *nlh;
    struct net *nl_net;
};

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-1000))
#define PTR_ERR(x) ((int)(uintptr_t)(x))