#include <string.h>
#include <stddef.h>

#define SAS_ADDR_SIZE 8

struct list_head {
    struct list_head *next, *prev;
};

struct asd_sas_phy {
    struct sas_ha_struct *ha;
    struct asd_sas_port *port;
    unsigned int id;
    struct list_head port_phy_el;
    void *phy;
};

struct sas_ha_struct {
    struct {
        struct {
            void *transportt;
        } *shost;
    } core;
    unsigned long phy_port_lock;
};

struct asd_sas_port {
    void *port;
    struct domain_device *port_dev;
    int num_phys;
    unsigned int phy_mask;
    unsigned char sas_addr[SAS_ADDR_SIZE];
    unsigned char attached_sas_addr[SAS_ADDR_SIZE];
    unsigned int class;
    unsigned int iproto;
    unsigned int tproto;
    unsigned int oob_mode;
    struct list_head phy_list;
    unsigned long phy_list_lock;
};

struct sas_internal {
    struct {
        void (*lldd_port_deformed)(struct asd_sas_phy *);
    } *dft;
};

struct domain_device {
    int pathways;
};

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static inline void list_del_init(struct list_head *entry) {
    entry->next = entry;
    entry->prev = entry;
}

static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}
static inline void spin_lock(unsigned long *lock) {}
static inline void spin_unlock(unsigned long *lock) {}

static inline struct sas_internal *to_sas_internal(void *transportt) { return NULL; }
static inline void sas_unregister_domain_devices(struct asd_sas_port *port, int gone) {}
static inline void sas_port_delete(void *port) {}
static inline void sas_port_delete_phy(void *port, void *phy) {}
static inline void sas_device_set_phy(struct domain_device *dev, void *port) {}
static inline void sas_phy_set_target(struct asd_sas_phy *phy, void *target) {}