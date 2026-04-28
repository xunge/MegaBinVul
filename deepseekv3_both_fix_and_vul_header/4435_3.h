#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;

struct in_ifaddr {
    struct in_ifaddr *ifa_next;
    unsigned int ifa_flags;
    u32 ifa_scope;
    u32 ifa_mask;
    u32 ifa_address;
};

struct in_device {
    struct in_ifaddr *ifa_list;
    int dead;
};

struct nlmsghdr;

extern struct blocking_notifier_head inetaddr_chain;

#define IFA_F_SECONDARY 0x01
#define NETDEV_DOWN 0
#define NETDEV_UP 1
#define RTM_DELADDR 0
#define RTM_NEWADDR 1

#define ASSERT_RTNL() do {} while (0)

static inline int IN_DEV_PROMOTE_SECONDARIES(struct in_device *in_dev) { return 0; }
static inline void inet_hash_remove(struct in_ifaddr *ifa) {}
static inline void rtmsg_ifa(int type, struct in_ifaddr *ifa, struct nlmsghdr *nlh, u32 portid) {}
static inline void inet_free_ifa(struct in_ifaddr *ifa) {}
static inline int inet_ifa_match(u32 addr, struct in_ifaddr *ifa) { return 0; }
static inline void fib_del_ifaddr(struct in_ifaddr *ifa, struct in_ifaddr *ifa1) {}
static inline void fib_add_ifaddr(struct in_ifaddr *ifa) {}