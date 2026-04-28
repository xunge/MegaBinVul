#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#define SAS_ADDR_SIZE 8
#define DIRECT_ROUTING 1
#define SAS_EDGE_EXPANDER_DEVICE 1
#define SAS_FANOUT_EXPANDER_DEVICE 2

typedef uint8_t u8;

struct list_head {
    struct list_head *next, *prev;
};

struct device {
    int dummy;
};

struct kref {
    int refcount;
};

struct domain_device;
struct sas_expander_device;
struct sas_rphy;
struct asd_sas_port;
struct ex_phy;

struct domain_device {
    struct sas_rphy *rphy;
    struct asd_sas_port *port;
    u8 sas_addr[SAS_ADDR_SIZE];
    u8 hashed_sas_addr[SAS_ADDR_SIZE];
    struct list_head dev_list_node;
    struct list_head siblings;
    struct kref kref;
    struct domain_device *parent;
    int dev_type;
    int iproto;
    int tproto;
    struct {
        struct ex_phy *ex_phy;
        struct list_head children;
    } ex_dev;
};

struct sas_expander_device {
    int level;
};

struct sas_rphy {
    struct device dev;
};

struct ex_phy {
    int routing_attr;
    int attached_dev_type;
    int attached_phy_id;
    int attached_iproto;
    int attached_tproto;
    u8 attached_sas_addr[SAS_ADDR_SIZE];
    struct asd_sas_port *port;
};

struct asd_sas_port {
    unsigned long dev_list_lock;
    struct list_head dev_list;
    struct {
        int max_level;
    } disc;
};

#define SAS_ADDR(addr) (*(unsigned long long*)(addr))
#define pr_warn(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define BUG_ON(cond) do { if (cond) abort(); } while (0)
#define BUG() abort()

static inline struct sas_expander_device *rphy_to_expander_device(struct sas_rphy *rphy) { return NULL; }
static struct domain_device *sas_alloc_device(void) { return NULL; }
static struct asd_sas_port *sas_port_alloc(struct device *dev, int phy_id) { return NULL; }
static int sas_port_add(struct asd_sas_port *port) { return 0; }
static struct sas_rphy *sas_expander_alloc(struct asd_sas_port *port, int type) { return NULL; }
static void get_device(struct device *dev) {}
static void kref_get(struct kref *kref) {}
static void sas_hash_addr(u8 *hashed, const u8 *sas_addr) {}
static void sas_ex_get_linkrate(struct domain_device *parent, struct domain_device *child, struct ex_phy *phy) {}
static void sas_init_dev(struct domain_device *dev) {}
static void sas_fill_in_rphy(struct domain_device *dev, struct sas_rphy *rphy) {}
static void sas_rphy_add(struct sas_rphy *rphy) {}
static int sas_discover_expander(struct domain_device *dev) { return 0; }
static void sas_rphy_delete(struct sas_rphy *rphy) {}
static void sas_put_device(struct domain_device *dev) {}
static void spin_lock_irq(unsigned long *lock) {}
static void spin_unlock_irq(unsigned long *lock) {}
static void list_add_tail(struct list_head *new, struct list_head *head) {}
static void list_del(struct list_head *entry) {}
static int max(int a, int b) { return a > b ? a : b; }