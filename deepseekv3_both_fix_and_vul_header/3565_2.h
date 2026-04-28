#include <stdint.h>
#include <stddef.h>

#define IFA_MAX 255
#define IFA_LOCAL 1
#define CAP_NET_ADMIN 12
#define CAP_SYS_ADMIN 21
#define EPERM 1
#define ENODEV 19
#define EINVAL 22
#define RTM_NEWADDR 20

typedef uint8_t u8;

struct sk_buff {
    void *sk;
};
struct nlmsghdr {
    uint16_t nlmsg_type;
};
struct net;
struct net_device;
struct nlattr;
struct ifaddrmsg {
    int ifa_index;
};

static const void *ifa_phonet_policy;

static inline struct net *sock_net(void *sk) { return 0; }
static inline int capable(int cap) { return 1; }
#define ASSERT_RTNL()
static inline int nlmsg_parse(struct nlmsghdr *nlh, int size, struct nlattr **tb, int max, const void *policy) { return 0; }
static inline struct ifaddrmsg *nlmsg_data(struct nlmsghdr *nlh) { return 0; }
static inline uint8_t nla_get_u8(struct nlattr *attr) { return 0; }
static inline struct net_device *__dev_get_by_index(struct net *net, int index) { return 0; }
static inline int phonet_address_add(struct net_device *dev, uint8_t addr) { return 0; }
static inline int phonet_address_del(struct net_device *dev, uint8_t addr) { return 0; }
static inline void phonet_address_notify(int type, struct net_device *dev, uint8_t addr) {}