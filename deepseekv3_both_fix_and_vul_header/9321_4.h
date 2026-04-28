#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

typedef uint32_t __be32;
typedef uint16_t __be16;

struct sk_buff {
    void *dev;
};

struct nf_conn;
struct in_device {
    struct in_ifaddr *ifa_list;
};
struct in_ifaddr {
    __be32 ifa_local;
};

enum ip_conntrack_info {
    IP_CT_NEW,
    IP_CT_RELATED
};

struct nf_nat_range {
    struct {
        __be32 ip;
    } min_addr, max_addr;
    __be16 min_proto;
    __be16 max_proto;
    unsigned int flags;
};

struct nf_nat_ipv4_multi_range_compat {
    struct {
        unsigned int flags;
        __be16 min;
        __be16 max;
    } range[1];
};

#define NF_INET_PRE_ROUTING 0
#define NF_INET_LOCAL_OUT 1
#define NF_DROP 0
#define NF_NAT_RANGE_MAP_IPS 1
#define NF_NAT_MANIP_DST 0

#define NF_CT_ASSERT(expr)

static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}

struct nf_conn *nf_ct_get(struct sk_buff *skb, enum ip_conntrack_info *ctinfo);
struct in_device *__in_dev_get_rcu(const void *dev);
unsigned int nf_nat_setup_info(struct nf_conn *ct, const struct nf_nat_range *range, unsigned int type);