#include <stdbool.h>
#include <stddef.h>

#define __LINK_STATE_QDISC_RUNNING 0

struct net_device {
    unsigned long state;
};

extern unsigned long jiffies;
extern int qdisc_restart(struct net_device *dev);
extern bool netif_queue_stopped(struct net_device *dev);
extern void netif_schedule(struct net_device *dev);
extern int need_resched(void);
extern void clear_bit(int nr, volatile unsigned long *addr);