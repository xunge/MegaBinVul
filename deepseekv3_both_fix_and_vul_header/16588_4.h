#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define unlikely(x) (x)
#define WARN_ON_ONCE(cond) ((void)0)
#define GNTST_okay 0

struct net_device;
struct page;
struct gnttab_copy;
struct gnttab_map_grant_ref;

struct xenvif_queue {
    struct xenvif *vif;
    struct gnttab_copy *tx_copy_ops;
    struct gnttab_map_grant_ref *tx_map_ops;
    struct page **pages_to_map;
};

struct xenvif {
    struct net_device *dev;
};

int tx_work_todo(struct xenvif_queue *queue);
void xenvif_tx_build_gops(struct xenvif_queue *queue, int budget, unsigned *nr_cops, unsigned *nr_mops);
int gnttab_batch_copy(struct gnttab_copy *ops, unsigned int count);
int gnttab_map_refs(struct gnttab_map_grant_ref *ops, void *unused, struct page **pages, unsigned int count);
int xenvif_tx_submit(struct xenvif_queue *queue);
void netdev_err(struct net_device *dev, const char *fmt, ...);