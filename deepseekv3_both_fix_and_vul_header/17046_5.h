#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#define SAS_ADDR_SIZE 8
#define SAS_ADDR(addr) (*(uint64_t *)(addr))
#define SAS_DEV_GONE 0

enum sas_device_type {
    SAS_EDGE_EXPANDER_DEVICE,
    SAS_FANOUT_EXPANDER_DEVICE
};

struct list_head {
    struct list_head *next, *prev;
};

struct ex_phy;
struct sas_port;
struct sas_phy;

struct expander_device {
    struct ex_phy *ex_phy;
    struct list_head children;
};

struct domain_device {
    struct expander_device ex_dev;
    uint8_t sas_addr[SAS_ADDR_SIZE];
    enum sas_device_type dev_type;
    unsigned long state;
    struct sas_port *port;
    struct list_head siblings;
};

struct ex_phy {
    uint8_t attached_sas_addr[SAS_ADDR_SIZE];
    struct sas_port *port;
    struct sas_phy *phy;
    int num_phys;
    struct list_head del_list;
};

struct sas_port {
    struct list_head del_list;
    struct list_head sas_port_del_list;
    int num_phys;
};

static inline void set_bit(int nr, volatile unsigned long *addr) {
    *addr |= (1UL << nr);
}

static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = (typeof(pos))((char *)((head)->next) - offsetof(typeof(*pos), member)), \
         n = (typeof(n))((char *)(pos->member.next) - offsetof(typeof(*n), member)); \
         &pos->member != (head); \
         pos = n, n = (typeof(n))((char *)(n->member.next) - offsetof(typeof(*n), member)))

static inline void sas_unregister_ex_tree(struct sas_port *port, struct domain_device *dev) {}
static inline void sas_unregister_dev(struct sas_port *port, struct domain_device *dev) {}
static inline void sas_disable_routing(struct domain_device *parent, uint8_t *addr) {}
static inline void sas_port_delete_phy(struct sas_port *port, struct sas_phy *phy) {}
static inline void sas_device_set_phy(struct domain_device *dev, struct sas_port *port) {}
static inline void sas_port_delete(struct sas_port *port) {}