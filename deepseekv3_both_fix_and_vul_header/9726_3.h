#include <linux/types.h>
#include <linux/netdevice.h>
#include <linux/ethtool.h>
#include <linux/errno.h>

typedef unsigned int u32;
typedef unsigned short u16;

struct niu {
    struct niu_parent *parent;
    struct net_device *dev;
};

struct niu_parent {
    struct niu_tcam_entry *tcam;
    int index;
};

struct niu_tcam_entry {
    int valid;
};

static inline int tcam_get_size(struct niu *np) { return 0; }
static inline int tcam_get_index(struct niu *np, int i) { return 0; }
static inline void niu_lock_parent(struct niu *np, unsigned long flags) {}
static inline void niu_unlock_parent(struct niu *np, unsigned long flags) {}