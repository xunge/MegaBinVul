#include <stdint.h>
#include <netinet/in.h>
#include <stddef.h>

typedef uint32_t __be32;

struct in_ifaddr {
    struct in_ifaddr *ifa_next;
    struct in_device *ifa_dev;
    __be32 ifa_address;
    __be32 ifa_local;
    __be32 ifa_broadcast;
    __be32 ifa_mask;
    unsigned int ifa_flags;
    unsigned char ifa_prefixlen;
};

struct in_device {
    struct net_device *dev;
    struct in_ifaddr *ifa_list;
    int dead;
};

struct net_device {
    unsigned int flags;
};

struct net {
    // dummy definition
};

#define IFA_F_SECONDARY 0x01
#define IFA_F_NOPREFIXROUTE 0x02
#define IFF_LOOPBACK 0x8

#define RTM_DELROUTE 0x19
#define RTN_LOCAL 1
#define RTN_UNICAST 2
#define RTN_BROADCAST 3

void fib_magic(int cmd, int type, __be32 dst, int dst_len, struct in_ifaddr *ifa);
struct in_ifaddr *inet_ifa_byprefix(struct in_device *in_dev, __be32 any, __be32 mask);
int inet_ifa_match(__be32 addr, struct in_ifaddr *ifa);
int ipv4_is_zeronet(__be32 addr);
unsigned int inet_addr_type_dev_table(struct net *net, struct net_device *dev, __be32 addr);
int fib_sync_down_addr(struct net *net, __be32 local);
void fib_flush(struct net *net);
void pr_warn(const char *fmt, ...);
struct net *dev_net(struct net_device *dev);