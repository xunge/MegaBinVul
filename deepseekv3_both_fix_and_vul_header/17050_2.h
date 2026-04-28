#include <stddef.h>
#include <stdint.h>

struct work_struct {
    // minimal work_struct definition
    unsigned long data;
};

struct list_head {
    struct list_head *next, *prev;
};

struct domain_device {
    int dev_type;
    void *rphy;
    struct list_head disco_list_node;
    struct list_head dev_list_node;
};

struct asd_sas_port {
    struct domain_device *port_dev;
    struct {
        unsigned long pending;
    } disc;
    int id;
    uintptr_t dev_list_lock; // using uintptr_t as spinlock placeholder
};

struct sas_discovery_event {
    struct asd_sas_port *port;
    struct work_struct work;
};

#define DISCE_DISCOVER_DOMAIN 0
#define SAS_END_DEVICE 1
#define SAS_EDGE_EXPANDER_DEVICE 2
#define SAS_FANOUT_EXPANDER_DEVICE 3
#define SAS_SATA_DEV 4
#define SAS_SATA_PM 5
#define ENXIO 6

#define SAS_DPRINTK(fmt, ...)

static inline struct sas_discovery_event *to_sas_discovery_event(struct work_struct *work)
{
    return (struct sas_discovery_event *)((char *)work - offsetof(struct sas_discovery_event, work));
}

static inline void clear_bit(int nr, volatile unsigned long *addr)
{
    *addr &= ~(1UL << nr);
}

static inline void list_del_init(struct list_head *entry)
{
    entry->next = entry;
    entry->prev = entry;
}

static inline void spin_lock_irq(uintptr_t *lock)
{
    (void)lock;
}

static inline void spin_unlock_irq(uintptr_t *lock)
{
    (void)lock;
}

extern int sas_get_port_device(struct asd_sas_port *port);
extern int sas_discover_end_dev(struct domain_device *dev);
extern int sas_discover_root_expander(struct domain_device *dev);
extern int sas_discover_sata(struct domain_device *dev);
extern void sas_rphy_free(void *rphy);
extern void sas_put_device(struct domain_device *dev);