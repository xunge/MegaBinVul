#include <stdatomic.h>
#include <pthread.h>

struct timer_list {
    // Minimal timer struct definition
};

struct net_device {
    // Minimal net_device struct definition
};

struct xenvif {
    struct net_device *dev;
    atomic_int refcnt;
    pthread_cond_t waiting_to_free;
    struct timer_list credit_timeout;
    int irq;
};

void xenvif_down(struct xenvif *vif);
void xenvif_put(struct xenvif *vif);
void xen_netbk_unmap_frontend_rings(struct xenvif *vif);
void unbind_from_irqhandler(int irq, struct xenvif *vif);