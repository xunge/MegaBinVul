#include <stddef.h>

struct domain {
    int is_dying;
};

extern int port_is_valid(struct domain *d, int port);
extern void smp_rmb(void);
extern void BUG_ON(int condition);
extern void evtchn_close(struct domain *d, int port, int flags);