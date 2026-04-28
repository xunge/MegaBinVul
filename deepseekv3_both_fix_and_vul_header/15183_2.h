#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>

#define ETH_ALEN 6
#define AARP_HASH_SIZE 16
#define ATADDR_BCAST 0xFF
#define NET_XMIT_SUCCESS 0
#define NET_XMIT_DROP 1
#define ARPHRD_LOCALTLK 1
#define ARPHRD_PPP 512
#define ARPHRD_ETHER 1
#define ETH_P_PPPTALK 0
#define ETH_P_ATALK 0

typedef uint16_t __be16;

struct net_device {
    int type;
};

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
};

struct sk_buff {
    unsigned char *data;
    struct net_device *dev;
    __be16 protocol;
    struct sock *sk;
    int priority;
    unsigned int len;
    struct sk_buff_head packet_queue;
};

struct sock {
    int sk_priority;
};

struct atalk_addr {
    uint8_t s_node;
    uint16_t s_net;
};

struct aarp_entry {
    struct aarp_entry *next;
    struct sk_buff_head packet_queue;
    unsigned long expires_at;
    struct net_device *dev;
    struct atalk_addr target_addr;
    unsigned char hwaddr[ETH_ALEN];
    int xmit_count;
};

struct ddpehdr {
    __be16 deh_snet;
    __be16 deh_dnet;
};

struct ddp_dl {
    void (*request)(struct ddp_dl *, struct sk_buff *, void *);
};

struct timer_list {
    unsigned long expires;
};

extern struct ddp_dl *ddp_dl;
extern struct aarp_entry *resolved[AARP_HASH_SIZE];
extern struct aarp_entry *unresolved[AARP_HASH_SIZE];
extern int unresolved_count;
extern int aarp_lock;
extern struct timer_list aarp_timer;
extern int sysctl_aarp_expiry_time;
extern int sysctl_aarp_resolve_time;
extern int sysctl_aarp_tick_time;
extern unsigned long jiffies;

static inline void skb_reset_network_header(struct sk_buff *skb) {}
static inline void skb_pull(struct sk_buff *skb, unsigned int len) {}
static inline void skb_push(struct sk_buff *skb, unsigned int len) {}
static inline __be16 htons(unsigned short hostshort) { return 0; }
static inline struct atalk_addr *atalk_find_dev_addr(struct net_device *dev) { return NULL; }
static inline struct aarp_entry *__aarp_find_entry(struct aarp_entry *list, struct net_device *dev, struct atalk_addr *addr) { return NULL; }
static inline struct aarp_entry *aarp_alloc(void) { return NULL; }
static inline void __aarp_send_query(struct aarp_entry *entry) {}
static inline int dev_queue_xmit(struct sk_buff *skb) { return 0; }
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void write_lock_bh(int *lock) {}
static inline void write_unlock_bh(int *lock) {}
static inline void mod_timer(struct timer_list *timer, unsigned long expires) {}
static inline void skb_queue_tail(struct sk_buff_head *list, struct sk_buff *skb) {}