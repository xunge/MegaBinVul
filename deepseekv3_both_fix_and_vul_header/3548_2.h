#include <stdint.h>
#include <string.h>

#define CAP_NET_ADMIN 0
#define EPERM 1
#define EINVAL 2
#define ENODEV 3
#define ENOBUFS 4
#define IFA_MAX 5
#define IFNAMSIZ 16

#define IFA_LOCAL 0
#define IFA_ADDRESS 1
#define IFA_FLAGS 2
#define IFA_LABEL 3

struct sk_buff {
    void *sk;
};
struct nlmsghdr {};
struct net {};
struct nlattr {};
struct net_device {
    char name[IFNAMSIZ];
    void *dn_ptr;
};
struct dn_dev {};
struct ifaddrmsg {
    int ifa_index;
    int ifa_flags;
    int ifa_scope;
};
struct dn_ifaddr {
    uint16_t ifa_local;
    uint16_t ifa_address;
    int ifa_flags;
    int ifa_scope;
    struct dn_dev *ifa_dev;
    char ifa_label[IFNAMSIZ];
};

static struct net init_net;
static int dn_ifa_policy[IFA_MAX+1];

static inline struct net *sock_net(void *sk) { return &init_net; }
static inline int net_eq(struct net *a, struct net *b) { return a == b; }
static inline int capable(int cap) { return 1; }
static inline int nlmsg_parse(struct nlmsghdr *nlh, int size, struct nlattr **tb, int max, int *policy) { return 0; }
static inline struct ifaddrmsg *nlmsg_data(struct nlmsghdr *nlh) { return 0; }
static inline struct net_device *__dev_get_by_index(struct net *net, int index) { return 0; }
static inline struct dn_dev *rtnl_dereference(void *ptr) { return 0; }
static inline struct dn_dev *dn_dev_create(struct net_device *dev, int *err) { return 0; }
static inline struct dn_ifaddr *dn_dev_alloc_ifa(void) { return 0; }
static inline uint16_t nla_get_le16(struct nlattr *attr) { return 0; }
static inline uint32_t nla_get_u32(struct nlattr *attr) { return 0; }
static inline void nla_strlcpy(char *dst, struct nlattr *src, int size) {}
static inline int dn_dev_insert_ifa(struct dn_dev *db, struct dn_ifaddr *ifa) { return 0; }
static inline void dn_dev_free_ifa(struct dn_ifaddr *ifa) {}