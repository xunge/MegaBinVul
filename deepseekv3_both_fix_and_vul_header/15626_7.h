#include <stdint.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#define RTN_MAX 8
#define RTN_UNICAST 1
#define RTPROT_UNSPEC 0
#define RTPROT_BOOT 3
#define RTF_PCPU (1 << 5)
#define RTF_CACHE (1 << 6)
#define RTF_ADDRCONF (1 << 7)
#define RTF_EXPIRES (1 << 8)
#define RTF_GATEWAY 0x0002
#define RTF_REJECT 0x0200
#define RTF_NONEXTHOP (1 << 11)

#define NLM_F_CREATE 0x400

#define EINVAL 22
#define ENOBUFS 105
#define ENOMEM 12

struct dst_metrics {
    unsigned long metrics[15];
    atomic_int refcnt;
};
extern struct dst_metrics dst_default_metrics;

struct in6_addr {
    union {
        uint8_t u6_addr8[16];
        uint16_t u6_addr16[8];
        uint32_t u6_addr32[4];
    } in6_u;
    uint8_t addr[16];
    uint8_t plen;
};

struct net_device;
struct netlink_ext_ack;
struct nexthop;

struct fib6_config {
    struct {
        struct {
            struct net* nl_net;
            struct {
                unsigned int nlmsg_flags;
            }* nlh;
        } fc_nlinfo;
        unsigned int fc_flags;
        unsigned char fc_type;
        unsigned char fc_dst_len;
        unsigned char fc_src_len;
        unsigned int fc_nh_id;
        unsigned int fc_table;
        unsigned int fc_mx_len;
        void* fc_mx;
        unsigned int fc_expires;
        unsigned char fc_protocol;
        unsigned int fc_metric;
        struct in6_addr fc_dst;
        struct in6_addr fc_src;
        struct in6_addr fc_prefsrc;
    };
};

struct fib6_table;
struct fib6_info;

struct fib6_nh {
    struct net_device *fib_nh_dev;
};

struct fib6_info {
    struct fib6_table *fib6_table;
    struct fib6_nh fib6_nh[0];
    struct dst_metrics *fib6_metrics;
    struct {
        struct in6_addr addr;
        uint8_t plen;
    } fib6_dst;
    struct {
        struct in6_addr addr;
        uint8_t plen;
    } fib6_src;
    struct {
        struct in6_addr addr;
        uint8_t plen;
    } fib6_prefsrc;
    unsigned char fib6_protocol;
    unsigned char fib6_type;
    unsigned short fib6_flags;
    int fib6_metric;
    bool dst_nocount;
    struct nexthop *nh;
};

typedef unsigned int gfp_t;
typedef unsigned long clock_t;
extern unsigned long jiffies;

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define ERR_PTR(x) ((void *)(long)(x))

void NL_SET_ERR_MSG(struct netlink_ext_ack *extack, const char *msg);
struct nexthop *nexthop_find_by_id(struct net *net, unsigned int id);
int fib6_check_nexthop(struct nexthop *nh, struct fib6_config *cfg, struct netlink_ext_ack *extack);
struct fib6_table *fib6_get_table(struct net *net, unsigned int id);
struct fib6_table *fib6_new_table(struct net *net, unsigned int id);
void pr_warn(const char *fmt, ...);
struct fib6_info *fib6_info_alloc(gfp_t gfp_flags, bool nh);
void *ip_fib_metrics_init(struct net *net, void *mx, unsigned int len, struct netlink_ext_ack *extack);
void fib6_set_expires_locked(struct fib6_info *rt, unsigned long expires);
unsigned long clock_t_to_jiffies(clock_t time);
void fib6_clean_expires_locked(struct fib6_info *rt);
void ipv6_addr_prefix(struct in6_addr *pfx, const struct in6_addr *addr, unsigned int plen);
int fib6_nh_init(struct net *net, struct fib6_nh *fib6_nh, struct fib6_config *cfg, gfp_t gfp_flags, struct netlink_ext_ack *extack);
int ipv6_addr_type(const struct in6_addr *addr);
bool fib6_is_reject(unsigned int flags, struct net_device *dev, int addr_type);
int ipv6_chk_addr(struct net *net, const struct in6_addr *addr, const struct net_device *dev, int strict);
void fib6_info_release(struct fib6_info *rt);
void ip_fib_metrics_put(struct dst_metrics *metrics);
void kfree(const void *objp);
struct nexthop *nexthop_get(struct nexthop *nh);
struct fib6_nh *nexthop_fib6_nh(struct nexthop *nh);
int ipv6_addr_any(const struct in6_addr *addr);

struct net;

static inline void copy_in6_addr(struct in6_addr *dst, const struct in6_addr *src) {
    memcpy(dst, src, sizeof(struct in6_addr));
}