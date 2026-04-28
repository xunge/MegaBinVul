#include <stddef.h>

struct device {
    struct device *dev;
};

struct work_struct {
    // minimal definition needed
};

struct list_head {
    struct list_head *next, *prev;
};

struct domain_device {
    struct list_head disco_list_node;
    struct device *rphy;
};

struct sas_discovery_event {
    struct work_struct work;
    struct asd_sas_port *port;
};

struct asd_sas_port {
    struct {
        unsigned long pending;
    } disc;
    struct list_head destroy_list;
};

#define DISCE_DESTRUCT 0
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

static inline void clear_bit(int nr, volatile unsigned long *addr) {
    *addr &= ~(1UL << nr);
}

static inline struct sas_discovery_event *to_sas_discovery_event(struct work_struct *work) {
    return container_of(work, struct sas_discovery_event, work);
}

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member), \
        n = container_of(pos->member.next, typeof(*pos), member); \
        &pos->member != (head); \
        pos = n, n = container_of(n->member.next, typeof(*n), member))

#define list_del_init(ptr) do { \
    (ptr)->next = (ptr); \
    (ptr)->prev = (ptr); \
} while (0)

void sas_remove_children(struct device *dev);
void sas_rphy_delete(struct device *rphy);
void sas_unregister_common_dev(struct asd_sas_port *port, struct domain_device *dev);