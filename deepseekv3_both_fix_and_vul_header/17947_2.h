#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>
#include <netinet/in.h>

typedef uint32_t __be32;
typedef unsigned long jiffies_t;
typedef int spinlock_t;

#define HZ 100
#define IGMP_Query_Response_Interval 10
#define IGMP_V1_Router_Present_Timeout 400
#define IGMP_V2_Router_Present_Timeout 400
#define IGMP_TIMER_SCALE 10
#define IGMP_ALL_HOSTS 0xE0000001

extern jiffies_t jiffies;

struct igmphdr {
    __be32 group;
    uint8_t code;
};

struct igmpv3_query {
    uint8_t type;
    uint8_t code;
    uint16_t nsrcs;
    __be32 group;
    uint8_t qrv;
    uint8_t suppress;
    uint16_t resv;
    __be32 srcs[0];
};

struct timer_list {
    // dummy structure
};

struct ip_mc_list {
    __be32 multiaddr;
    int tm_running;
    int gsquery;
    spinlock_t lock;
    // other members omitted
};

struct in_device {
    jiffies_t mr_v1_seen;
    jiffies_t mr_v2_seen;
    int mr_ifc_count;
    struct timer_list mr_ifc_timer;
    int mr_maxdelay;
    int mr_qrv;
    // other members omitted
};

struct sk_buff {
    // dummy structure
};

#define IGMP_V1_SEEN(in_dev) (0)
#define IGMP_V2_SEEN(in_dev) (0)
#define IGMPV3_MRC(code) (code)

static inline struct igmphdr *igmp_hdr(const struct sk_buff *skb) { return NULL; }
static inline struct igmpv3_query *igmpv3_query_hdr(const struct sk_buff *skb) { return NULL; }
static inline int del_timer(struct timer_list *timer) { return 0; }
static inline void __in_dev_put(struct in_device *in_dev) {}
static inline void igmpv3_clear_delrec(struct in_device *in_dev) {}
static inline void igmp_gq_start_timer(struct in_device *in_dev) {}
static inline int igmp_marksources(struct ip_mc_list *im, int nsrcs, __be32 *srcs) { return 0; }
static inline void igmp_mod_timer(struct ip_mc_list *im, int max_delay) {}
static inline int pskb_may_pull(struct sk_buff *skb, unsigned int len) { return 1; }

#define spin_lock_bh(lock) do {} while (0)
#define spin_unlock_bh(lock) do {} while (0)
#define rcu_read_lock() do {} while (0)
#define rcu_read_unlock() do {} while (0)
#define for_each_pmc_rcu(in_dev, im) for (im = NULL; im != NULL; im = NULL)