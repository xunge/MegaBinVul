#include <stdint.h>
#include <stddef.h>

typedef uint8_t u8;

struct net_device {
    unsigned char dev_addr[6];
};

struct list_head {
    struct list_head *next, *prev;
};

struct timer_list {
    unsigned long data;
    void (*function)(struct timer_list *);
};

struct hsr_priv {
    struct list_head ports;
    struct list_head node_db;
    struct list_head self_node_db;
    unsigned char sup_multicast_addr[6];
    u8 protVersion;
    unsigned long sequence_nr;
    unsigned long sup_sequence_nr;
    struct timer_list announce_timer;
    struct timer_list prune_timer;
    void *seqnr_lock;
};

struct hsr_port;

#define HSR_PT_MASTER 0
#define HSR_PT_SLAVE_A 1
#define HSR_PT_SLAVE_B 2
#define HSR_SEQNR_START 0
#define HSR_SUP_SEQNR_START 0
#define PRUNE_PERIOD 3000
#define ETH_ALEN 6

#define hsr_for_each_port(hsr, port) \
    for (port = NULL; port != (struct hsr_port *)1; port = (struct hsr_port *)1)

extern unsigned char def_multicast_addr[ETH_ALEN];
extern void INIT_LIST_HEAD(struct list_head *list);
extern void *netdev_priv(struct net_device *dev);
extern void ether_addr_copy(unsigned char *dst, const unsigned char *src);
extern void spin_lock_init(void *lock);
extern void timer_setup(struct timer_list *timer, void (*function)(struct timer_list *), int flags);
extern void netif_carrier_off(struct net_device *dev);
extern int register_netdevice(struct net_device *dev);
extern unsigned long jiffies;
extern unsigned long msecs_to_jiffies(unsigned int msecs);
extern int mod_timer(struct timer_list *timer, unsigned long expires);

extern int hsr_create_self_node(struct list_head *self_node_db, unsigned char addr_a[ETH_ALEN], unsigned char addr_b[ETH_ALEN]);
extern int hsr_add_port(struct hsr_priv *hsr, struct net_device *dev, int type);
extern void hsr_del_port(struct hsr_port *port);
extern void hsr_announce(struct timer_list *timer);
extern void hsr_prune_nodes(struct timer_list *timer);