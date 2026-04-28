#include <stddef.h>

#define SAS_EDGE_EXPANDER_DEVICE 1
#define SAS_FANOUT_EXPANDER_DEVICE 2
#define DISCE_RESUME 3

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

struct asd_sas_phy;
struct domain_device;
struct asd_sas_port;
struct sas_ha_struct;
struct sas_internal;
struct ex_phy;

struct domain_device {
    int dev_type;
    struct list_head dev_list_node;
    struct {
        int ex_change_count;
        int num_phys;
        struct ex_phy *ex_phy;
    } ex_dev;
};

struct asd_sas_port {
    int suspended;
    struct list_head dev_list;
};

struct asd_sas_phy {
    struct asd_sas_port *port;
    struct sas_ha_struct *ha;
};

struct sas_ha_struct {
    struct {
        struct {
            void *transportt;
        } *shost;
    } core;
};

struct sas_internal {
    struct {
        void (*lldd_port_formed)(struct asd_sas_phy *);
    } *dft;
};

struct ex_phy {
    int phy_change_count;
};

static int sas_notify_lldd_dev_found(struct domain_device *dev);
static void sas_unregister_dev(struct asd_sas_port *port, struct domain_device *dev);
static void sas_discover_event(struct asd_sas_port *port, int event);
static struct sas_internal *to_sas_internal(void *transportt);