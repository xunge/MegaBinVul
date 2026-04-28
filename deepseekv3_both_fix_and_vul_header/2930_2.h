#include <stddef.h>
#include <stdint.h>

struct list_head {
    struct list_head *next, *prev;
};

struct spinlock {
    int lock;
};

typedef struct spinlock spinlock_t;

struct net_device {
    const char *name;
    const struct dcbnl_rtnl_ops *dcbnl_ops;
    int ifindex;
};

struct sk_buff;
struct nlattr;

struct dcb_app {
    uint8_t selector;
    uint8_t priority;
    uint16_t protocol;
};

struct dcb_app_type {
    struct list_head list;
    int ifindex;
    struct dcb_app app;
};

struct dcbnl_rtnl_ops {
    int (*ieee_getets)(struct net_device *, void *);
    int (*ieee_getmaxrate)(struct net_device *, void *);
    int (*ieee_getpfc)(struct net_device *, void *);
    int (*ieee_peer_getets)(struct net_device *, void *);
    int (*ieee_peer_getpfc)(struct net_device *, void *);
    int (*peer_getappinfo)(struct net_device *, void *);
    int (*peer_getapptable)(struct net_device *, void *);
    int (*getdcbx)(struct net_device *);
};

struct ieee_ets {
    uint8_t willing;
    uint8_t ets_cap;
    uint8_t cbs;
    uint8_t tc_tx_bw[8];
    uint8_t tc_rx_bw[8];
    uint8_t tc_tsa[8];
    uint8_t prio_tc[8];
    uint8_t tc_reco_bw[8];
    uint8_t tc_reco_tsa[8];
    uint8_t reco_prio_tc[8];
};

struct ieee_maxrate {
    uint8_t tc_maxrate[8];
};

struct ieee_pfc {
    uint8_t pfc_cap;
    uint8_t pfc_en;
    uint8_t mbc;
    uint16_t delay;
    uint8_t requests[8];
    uint8_t indications[8];
};

#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != (void *)(head); pos = NULL)

#define DCB_ATTR_IFNAME 1
#define DCB_ATTR_IEEE 2
#define DCB_ATTR_IEEE_ETS 3
#define DCB_ATTR_IEEE_MAXRATE 4
#define DCB_ATTR_IEEE_PFC 5
#define DCB_ATTR_IEEE_APP_TABLE 6
#define DCB_ATTR_IEEE_APP 7
#define DCB_ATTR_IEEE_PEER_ETS 8
#define DCB_ATTR_IEEE_PEER_PFC 9
#define DCB_ATTR_IEEE_PEER_APP 10
#define DCB_ATTR_IEEE_APP_UNSPEC 11
#define DCB_ATTR_DCBX 12

#define EMSGSIZE 90
#define EOPNOTSUPP 95

extern spinlock_t dcb_lock;
extern struct list_head dcb_app_list;

static inline int nla_put_string(struct sk_buff *skb, int attrtype, const char *str) { return 0; }
static inline struct nlattr *nla_nest_start(struct sk_buff *skb, int attrtype) { return NULL; }
static inline int nla_put(struct sk_buff *skb, int attrtype, int len, const void *data) { return 0; }
static inline int nla_put_u8(struct sk_buff *skb, int attrtype, uint8_t value) { return 0; }
static inline void nla_nest_end(struct sk_buff *skb, struct nlattr *start) {}
static inline void spin_lock(spinlock_t *lock) { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }
static inline int dcbnl_build_peer_app(struct net_device *dev, struct sk_buff *skb, int type1, int type2, int type3) { return 0; }