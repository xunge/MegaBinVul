#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define __init
#define KERN_CRIT ""
#define ENOMEM 12

struct timer_list {
    unsigned long expires;
    void (*function)(struct timer_list *);
};

struct notifier_block {
    int dummy;
};

struct datalink_proto {
    int dummy;
};

struct sk_buff {
    int dummy;
};

struct net_device {
    int dummy;
};

struct packet_type {
    int dummy;
};

static struct timer_list aarp_timer;
static struct datalink_proto *aarp_dl;
static struct notifier_block aarp_notifier;
static unsigned char aarp_snap_id[] = { 0x00, 0x00, 0x00, 0x80, 0xF3 };
static unsigned long jiffies;
static int sysctl_aarp_expiry_time;

static int aarp_rcv(struct sk_buff *skb, struct net_device *dev, struct packet_type *pt, struct net_device *orig_dev) { return 0; }
static void aarp_expire_timeout(struct timer_list *unused) {}
static void timer_setup(struct timer_list *timer, void (*function)(struct timer_list *), int flags) {}
static void add_timer(struct timer_list *timer) {}
static void del_timer_sync(struct timer_list *timer) {}
static struct datalink_proto *register_snap_client(unsigned char *snap_id, int (*rcvfunc)(struct sk_buff *, struct net_device *, struct packet_type *, struct net_device *)) { return NULL; }
static void unregister_snap_client(struct datalink_proto *dl) {}
static int register_netdevice_notifier(struct notifier_block *nb) { return 0; }
static int printk(const char *fmt, ...) { return 0; }