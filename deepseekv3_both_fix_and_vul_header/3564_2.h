#include <stdint.h>
#include <stddef.h>

#define RTA_MAX 16
#define RTA_DST 1
#define RTA_OIF 2
#define RT_TABLE_MAIN 254
#define RTN_UNICAST 1
#define RTM_NEWROUTE 24
#define CAP_NET_ADMIN 12
#define CAP_SYS_ADMIN 21
#define EPERM 1
#define EINVAL 22
#define ENODEV 19

typedef uint8_t u8;
typedef uint32_t u32;

struct nlattr;
struct net_device;
struct net;
struct rtmsg {
    unsigned char rtm_table;
    unsigned char rtm_type;
};
struct nlmsghdr {
    int nlmsg_type;
};
struct sk_buff {
    void *sk;
};
struct sock;

static const void *rtm_phonet_policy;

struct net *sock_net(struct sock *sk);
int nlmsg_parse(const struct nlmsghdr *nlh, int hdrlen, struct nlattr *tb[], int maxtype, const void *policy);
void *nlmsg_data(const struct nlmsghdr *nlh);
u8 nla_get_u8(const struct nlattr *nla);
u32 nla_get_u32(const struct nlattr *nla);
struct net_device *__dev_get_by_index(struct net *net, int ifindex);
int phonet_route_add(struct net_device *dev, u8 dst);
int phonet_route_del(struct net_device *dev, u8 dst);
void rtm_phonet_notify(int event, struct net_device *dev, u8 dst);
void ASSERT_RTNL(void);
int capable(int cap);