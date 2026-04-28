#include <stdint.h>
#include <stddef.h>

#define CAP_NET_ADMIN 1
#define EPERM 1
#define ENODEV 1
#define EADDRNOTAVAIL 1
#define EINVAL 1
#define IFA_MAX 8
#define IFA_LOCAL 1
#define IFA_LABEL 2

struct sk_buff {
    void *sk;
};

struct nlmsghdr;

struct net {
    // minimal net structure
};

struct nlattr;

struct ifaddrmsg {
    int ifa_index;
};

struct dn_dev {
    struct dn_ifaddr *ifa_list;
};

struct dn_ifaddr {
    struct dn_ifaddr *ifa_next;
    uint16_t ifa_local;
    char *ifa_label;
};

#define __rcu

extern struct net init_net;
extern void *dn_ifa_policy;

static inline struct net *sock_net(void *sk) { return &init_net; }
static inline int net_eq(struct net *a, struct net *b) { return a == b; }
static inline int nlmsg_parse(struct nlmsghdr *nlh, size_t size, struct nlattr **tb, int max, void *policy) { return 0; }
static inline struct ifaddrmsg *nlmsg_data(struct nlmsghdr *nlh) { return (struct ifaddrmsg *)nlh; }
static inline struct dn_dev *dn_dev_by_index(int index) { return NULL; }
static inline int nla_memcmp(struct nlattr *attr, void *data, int size) { return 0; }
static inline int nla_strcmp(struct nlattr *attr, char *str) { return 0; }
static inline void dn_dev_del_ifa(struct dn_dev *db, struct dn_ifaddr **ifap, int flag) {}
static inline int capable(int cap) { return 1; }
static inline struct dn_ifaddr *rtnl_dereference(struct dn_ifaddr *ptr) { return ptr; }