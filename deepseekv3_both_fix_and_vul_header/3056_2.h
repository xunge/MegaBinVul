#include <stddef.h>
#include <sys/socket.h>
#include <netinet/in.h>

struct dst_entry {
    struct {
        int family;
    } *ops;
    struct {
        int ifindex;
    } *dev;
};

struct flowi6 {
    struct in6_addr daddr;
    struct in6_addr saddr;
    int flowi6_oif;
};

struct ipv6_pinfo {
    struct in6_addr daddr_cache;
    struct in6_addr saddr_cache;
};

struct rt6_info {
    struct in6_addr rt6i_dst;
    struct in6_addr rt6i_src;
    struct dst_entry *dst;
};

struct sock;

static inline struct ipv6_pinfo *inet6_sk(const struct sock *sk) { return NULL; }
static inline void dst_release(struct dst_entry *dst) {}
static inline int ip6_rt_check(const struct in6_addr *a, const struct in6_addr *b, const struct in6_addr c) { return 0; }