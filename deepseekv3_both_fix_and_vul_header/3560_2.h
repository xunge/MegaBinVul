#include <stdint.h>
#include <stddef.h>

#define TCA_ACT_MAX 32
#define TCA_ACT_TAB 1

#define RTM_GETACTION 42
#define RTM_NEWACTION 43
#define RTM_DELACTION 44
#define NLM_F_REPLACE 0x100
#define NLM_F_CREATE 0x400

#define CAP_NET_ADMIN 12
#define EPERM 1
#define EINVAL 22
#define EAGAIN 11

typedef uint32_t u32;

struct sk_buff {
    void *sk;
};

struct nlmsghdr {
    uint16_t nlmsg_type;
    uint16_t nlmsg_flags;
};

struct net;
struct nlattr;

struct NETLINK_CB {
    u32 portid;
};

#define NETLINK_CB(skb) ((struct NETLINK_CB){0})

struct tcamsg {
    unsigned char tca_family;
    unsigned char tca__pad1;
    unsigned short tca__pad2;
};

static struct net *sock_net(void *sk) { return 0; }
static int nlmsg_parse(struct nlmsghdr *n, size_t size, struct nlattr *tca[], int max, void *null) { return 0; }
static int tcf_action_add(struct net *net, struct nlattr *attr, struct nlmsghdr *n, u32 portid, int ovr) { return 0; }
static int tca_action_gd(struct net *net, struct nlattr *attr, struct nlmsghdr *n, u32 portid, int action) { return 0; }
static int capable(int cap) { return 0; }
static void BUG(void) {}
static void pr_notice(const char *fmt, ...) {}