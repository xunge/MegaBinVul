#include <stdint.h>
#include <stddef.h>

typedef uint8_t u8;
typedef uint16_t u16;

struct sk_buff;
struct nlattr;

struct net_device {
    const char *name;
    int ifindex;
    struct dcbnl_rtnl_ops *dcbnl_ops;
};

struct list_head {
    struct list_head *next, *prev;
};

struct dcb_app {
    u8 selector;
    u8 priority;
    u16 protocol;
};

struct dcb_app_type {
    struct list_head list;
    int ifindex;
    struct dcb_app app;
};

struct dcbnl_rtnl_ops {
    int (*getpgtccfgtx)(struct net_device *, int, u8 *);
    int (*getpgbwgcfgtx)(struct net_device *, int, u8 *);
    int (*getpgtccfgrx)(struct net_device *, int, u8 *);
    int (*getpgbwgcfgrx)(struct net_device *, int, u8 *);
    int (*getpfccfg)(struct net_device *, int, u8 *);
    int (*getdcbx)(struct net_device *);
    int (*getfeatcfg)(struct net_device *, int, u8 *);
    int (*cee_peer_getpg)(struct net_device *, void *);
    int (*cee_peer_getpfc)(struct net_device *, void *);
    int (*peer_getappinfo)(struct net_device *, void *);
    int (*peer_getapptable)(struct net_device *, void *);
};

struct cee_pg {
    u8 willing;
    u8 error;
    u8 pg_en;
    u8 tcs_supported;
    u8 pg_bw[8];
    u8 prio_pg[8];
};

struct cee_pfc {
    u8 willing;
    u8 error;
    u8 pfc_en;
    u8 mbc;
    u8 delay;
    u8 prio_pfc[8];
};

typedef int spinlock_t;
extern spinlock_t dcb_lock;
extern struct list_head dcb_app_list;

#define DCB_ATTR_IFNAME 1
#define DCB_ATTR_CEE 2
#define DCB_ATTR_CEE_PFC 3
#define DCB_ATTR_CEE_APP_TABLE 4
#define DCB_ATTR_APP 5
#define DCB_APP_ATTR_IDTYPE 6
#define DCB_APP_ATTR_ID 7
#define DCB_APP_ATTR_PRIORITY 8
#define DCB_ATTR_CEE_FEAT 9
#define DCB_FEATCFG_ATTR_ALL 10
#define DCB_FEATCFG_ATTR_MAX 11
#define DCB_ATTR_CEE_PEER_PG 12
#define DCB_ATTR_CEE_PEER_PFC 13
#define DCB_ATTR_CEE_PEER_APP_TABLE 14
#define DCB_ATTR_CEE_PEER_APP_INFO 15
#define DCB_ATTR_CEE_PEER_APP 16
#define DCB_ATTR_DCBX 17
#define DCB_PFC_UP_ATTR_0 18
#define DCB_PFC_UP_ATTR_7 25

#define EMSGSIZE 90
#define EOPNOTSUPP 95

static inline int nla_put_string(struct sk_buff *skb, int attrtype, const char *str) { return 0; }
static inline struct nlattr *nla_nest_start(struct sk_buff *skb, int attrtype) { return NULL; }
static inline int nla_put_u8(struct sk_buff *skb, int attrtype, u8 value) { return 0; }
static inline int nla_put_u16(struct sk_buff *skb, int attrtype, u16 value) { return 0; }
static inline int nla_put(struct sk_buff *skb, int attrtype, int len, const void *data) { return 0; }
static inline void nla_nest_end(struct sk_buff *skb, struct nlattr *start) {}
static inline void spin_lock(spinlock_t *lock) {}
static inline void spin_unlock(spinlock_t *lock) {}
static inline int dcbnl_cee_pg_fill(struct sk_buff *skb, struct net_device *netdev, int dir) { return 0; }
static inline int dcbnl_build_peer_app(struct net_device *netdev, struct sk_buff *skb, int attr1, int attr2, int attr3) { return 0; }

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(*pos)*)((char*)(head)->next - offsetof(typeof(*pos), member)); \
         &pos->member != (head); \
         pos = (typeof(*pos)*)((char*)pos->member.next - offsetof(typeof(*pos), member)))