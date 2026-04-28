#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t __be32;
typedef uint32_t u32;

#define ETH_P_IP 0x0800
#define EINVAL 22
#define ENOBUFS 105

#define htons(x) ((uint16_t)(((x) << 8) | ((x) >> 8)))

struct sk_buff {
    uint16_t protocol;
    void* dev;
};

struct fib_result {
    int nh_sel;
    int oif;
    struct {
        struct rtable* nh_rth_input;
    } nh;
    __be32 gw;
    void* fi;
    int type;
};

struct in_device {
    void* dev;
};

struct fib_nh_exception {
    struct rtable* fnhe_rth_input;
};

struct dst_entry {
    void* dev;
    void (*input)(struct sk_buff*);
    void (*output)(struct sk_buff*);
};

struct list_head {
    struct list_head *next, *prev;
};

struct rtable {
    unsigned int rt_genid;
    unsigned int rt_flags;
    int rt_type;
    int rt_is_input;
    int rt_iif;
    int rt_pmtu;
    __be32 rt_gateway;
    int rt_uses_gateway;
    struct list_head rt_uncached;
    struct dst_entry dst;
};

struct IPCB {
    int flags;
};

#define FIB_RES_DEV(res) ((res).nh_sel)
#define FIB_RES_OIF(res) ((res).oif)
#define FIB_RES_NH(res) ((res).nh)
#define FIB_RES_GW(res) ((res).gw)

#define net_crit_ratelimited(fmt, ...) 
#define RT_CACHE_STAT_INC(x) 
#define IN_DEV_TX_REDIRECTS(x) 0
#define IN_DEV_SHARED_MEDIA(x) 0
#define IN_DEV_PROXY_ARP_PVLAN(x) 0
#define IN_DEV_CONF_GET(x, y) 0
#define IPSKB_DOREDIRECT 0
#define RTCF_DOREDIRECT 0
#define NOPOLICY 0
#define NOXFRM 0

static inline struct IPCB* IPCB(const struct sk_buff *skb) {
    return (struct IPCB*)0;
}

static inline struct in_device* __in_dev_get_rcu(int dev) {
    return (struct in_device*)0;
}

static inline int fib_validate_source(struct sk_buff *skb, __be32 saddr, __be32 daddr, u32 tos, int oif, void* dev, struct in_device *in_dev, u32 *itag) {
    return 0;
}

static inline void ip_handle_martian_source(void* dev, struct in_device *in_dev, struct sk_buff *skb, __be32 daddr, __be32 saddr) {}

static inline bool inet_addr_onlink(struct in_device *out_dev, __be32 saddr, __be32 gw) {
    return false;
}

static inline struct fib_nh_exception* find_exception(const void* nh, __be32 daddr) {
    return (struct fib_nh_exception*)0;
}

static inline struct rtable* rcu_dereference(void* p) {
    return (struct rtable*)p;
}

static inline bool rt_cache_valid(struct rtable *rth) {
    return false;
}

static inline void skb_dst_set_noref(struct sk_buff *skb, void* dst) {}

static inline struct rtable* rt_dst_alloc(void* dev, int nopolicy, int noxfrm, bool do_cache) {
    return (struct rtable*)0;
}

static inline int rt_genid_ipv4(void* net) {
    return 0;
}

static inline void* dev_net(void* dev) {
    return (void*)0;
}

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static inline void ip_forward(struct sk_buff *skb) {}

static inline void ip_output(struct sk_buff *skb) {}

static inline void rt_set_nexthop(struct rtable *rth, __be32 daddr, const struct fib_result *res, struct fib_nh_exception *fnhe, void* fi, int type, u32 itag) {}

static inline void skb_dst_set(struct sk_buff *skb, void* dst) {}