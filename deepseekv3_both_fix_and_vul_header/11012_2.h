#include <stddef.h>
#include <string.h>

#define SAS_ADDR_SIZE        8
#define ENODEV               19
#define ENOMEM               12
#define SAS_SATA_PM          5
#define SAS_SATA_DEV         4
#define SAS_PROTOCOL_SATA    1
#define SAS_END_DEVICE       2
#define SAS_EDGE_EXPANDER_DEVICE 3
#define SAS_FANOUT_EXPANDER_DEVICE 6
#define SATA_OOB_MODE        1
#define SAS_OOB_MODE         2

struct list_head {
    struct list_head *next, *prev;
};

struct device {
    int dummy;
};

struct sas_phy {
    struct {
        unsigned char phy_identifier;
    } identify;
};

struct sas_port {
    int dummy;
};

struct asd_sas_phy {
    struct list_head port_phy_el;
    int frame_rcvd_lock;
    unsigned char *frame_rcvd;
    unsigned int frame_rcvd_size;
    struct sas_phy *phy;
};

struct asd_sas_port {
    int phy_list_lock;
    struct list_head phy_list;
    unsigned char attached_sas_addr[SAS_ADDR_SIZE];
    unsigned char oob_mode;
    struct {
        unsigned char fanout_sas_addr[SAS_ADDR_SIZE];
        unsigned char eeds_a[SAS_ADDR_SIZE];
        unsigned char eeds_b[SAS_ADDR_SIZE];
        int max_level;
    } disc;
    int dev_list_lock;
    struct list_head dev_list;
    struct list_head disco_list;
    struct domain_device *port_dev;
    unsigned int linkrate;
    unsigned int num_phys;
    struct sas_port *port;
};

struct sas_rphy {
    struct device dev;
    struct {
        unsigned char phy_identifier;
    } identify;
};

struct domain_device {
    unsigned char frame_rcvd[64];
    unsigned char dev_type;
    unsigned char tproto;
    unsigned char iproto;
    unsigned char sas_addr[SAS_ADDR_SIZE];
    unsigned char hashed_sas_addr[SAS_ADDR_SIZE];
    unsigned int linkrate;
    unsigned int min_linkrate;
    unsigned int max_linkrate;
    unsigned int pathways;
    struct asd_sas_port *port;
    struct sas_rphy *rphy;
    struct list_head disco_list_node;
    struct list_head dev_list_node;
};

struct dev_to_host_fis {
    unsigned char interrupt_reason;
    unsigned char lbal;
    unsigned char byte_count_low;
    unsigned char byte_count_high;
    unsigned char device;
};

struct sas_identify_frame {
    unsigned char dev_type;
    unsigned char initiator_bits;
    unsigned char target_bits;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define spin_lock_irq(lock) do { (void)(lock); } while (0)
#define spin_unlock_irq(lock) do { (void)(lock); } while (0)
#define spin_lock(lock) do { (void)(lock); } while (0)
#define spin_unlock(lock) do { (void)(lock); } while (0)
#define list_empty(list) ((list)->next == (list))
#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))
#define list_add_tail(new, head) do { \
    (new)->next = (head); \
    (new)->prev = (head)->prev; \
    (head)->prev->next = (new); \
    (head)->prev = (new); \
} while (0)

#define min(a, b) ((a) < (b) ? (a) : (b))
#define pr_warn(fmt, ...) do { } while (0)
#define get_device(dev) do { } while (0)
#define SAS_ADDR(addr) (0)

extern struct domain_device *sas_alloc_device(void);
extern void sas_put_device(struct domain_device *dev);
extern void sas_init_dev(struct domain_device *dev);
extern int sas_ata_init(struct domain_device *dev);
extern struct sas_rphy *sas_end_device_alloc(struct sas_port *port);
extern struct sas_rphy *sas_expander_alloc(struct sas_port *port, int type);
extern void sas_fill_in_rphy(struct domain_device *dev, struct sas_rphy *rphy);
extern void sas_hash_addr(unsigned char *hashed, const unsigned char *sas_addr);
extern void sas_device_set_phy(struct domain_device *dev, struct sas_port *port);
extern void sas_phy_set_target(struct asd_sas_phy *phy, struct domain_device *dev);
extern int dev_is_sata(struct domain_device *dev);