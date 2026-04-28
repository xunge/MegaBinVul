#include <stddef.h>

struct work_struct {
    unsigned long data;
};

struct list_head {
    struct list_head *next, *prev;
};

struct domain_device {
    struct list_head disco_list_node;
    struct list_head dev_list_node;
    void *rphy;
};

struct sas_discovery_event {
    struct work_struct work;
    struct asd_sas_port *port;
};

struct asd_sas_port {
    struct {
        unsigned long pending;
    } disc;
    struct list_head disco_list;
    struct list_head dev_list;
    int dev_list_lock;
};

#define DISCE_PROBE 0

static inline void clear_bit(int nr, volatile unsigned long *addr) {
    *addr &= ~(1UL << nr);
}

static inline void spin_lock_irq(int *lock) {
    (void)lock;
}

static inline void spin_unlock_irq(int *lock) {
    (void)lock;
}

static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

static inline void list_del_init(struct list_head *entry) {
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
    entry->next = entry->prev = entry;
}

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member), \
         n = container_of(pos->member.next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = n, n = container_of(n->member.next, typeof(*n), member))

static inline struct sas_discovery_event *to_sas_discovery_event(struct work_struct *work) {
    return container_of(work, struct sas_discovery_event, work);
}

static inline void sas_probe_sata(struct asd_sas_port *port) {
    (void)port;
}

static inline int sas_rphy_add(void *rphy) {
    (void)rphy;
    return 0;
}

static inline void sas_fail_probe(struct domain_device *dev, const char *func, int err) {
    (void)dev;
    (void)func;
    (void)err;
}