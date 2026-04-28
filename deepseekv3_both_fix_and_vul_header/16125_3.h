#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define XENLOG_WARNING 0
#define EINVAL 1
#define ENOMEM 2
#define NR_ISAIRQS 16
#define NR_HVM_DOMU_IRQS 32
#define HVM_NR_PARAMS 64
#define NR_IO_HANDLERS 256
#define HVM_IOBITMAP_SIZE 8192
#define PERDOMAIN_VIRT_START 0
#define PG_refcounts 0
#define PG_translate 0
#define PG_external 0
#define SHUTDOWN_reboot 0
#define XEN_HVM_DEBUGCONS_IOPORT 0
#define PAGE_SIZE 4096
#define HVM_PARAM_TRIPLE_FAULT_REASON 0

struct hvm_irq {
    unsigned int nr_gsis;
};

struct hvm_io_handler {
    // dummy structure
};

struct pl_time {
    struct domain *domain;
    void *pt_migrate;
};

struct domain {
    struct {
        struct {
            void *irq_lock;
            void *uc_lock;
            struct {
                void *lock;
                void *list;
            } write_map;
            void *mmcfg_lock;
            void *g2m_ioport_list;
            void *mmcfg_regions;
            void *msix_tables;
            struct pl_time *pl_time;
            uint64_t *params;
            struct hvm_io_handler *io_handler;
            void *irq;
            void *io_bitmap;
            uint64_t tsc_scaling_ratio;
        } hvm;
    } arch;
};

extern int hvm_enabled;
extern unsigned int nr_irqs_gsi;
extern void *hvm_io_bitmap;
extern int hvm_tsc_scaling_supported;
extern uint64_t hvm_default_tsc_scaling_ratio;
extern struct {
    int (*domain_initialise)(struct domain *d);
} hvm_funcs;

void gdprintk(int level, const char *fmt, ...);
void spin_lock_init(void *lock);
void rwlock_init(void *lock);
void INIT_LIST_HEAD(void *list);
int create_perdomain_mapping(struct domain *d, unsigned long start, unsigned long size, void *a, void *b);
void hvm_init_cacheattr_region_list(struct domain *d);
int paging_enable(struct domain *d, int flags);
int is_hardware_domain(struct domain *d);
void *xzalloc(size_t size);
void *xzalloc_array(size_t nmemb, size_t size);
void *xzalloc_bytes(size_t size);
size_t hvm_irq_size(unsigned int nr_gsis);
void BUILD_BUG_ON(int condition);
void ASSERT(int condition);
void register_g2m_portio_handler(struct domain *d);
void register_vpci_portio_handler(struct domain *d);
void hvm_ioreq_init(struct domain *d);
void hvm_init_guest_time(struct domain *d);
void vpic_init(struct domain *d);
int vioapic_init(struct domain *d);
void stdvga_init(struct domain *d);
void rtc_init(struct domain *d);
void register_portio_handler(struct domain *d, unsigned int port, unsigned int size, void *handler);
void hvm_print_line(void);
int viridian_domain_init(struct domain *d);
void stdvga_deinit(struct domain *d);
void vioapic_deinit(struct domain *d);
void xfree(void *ptr);
void XFREE(void *ptr);
void hvm_destroy_cacheattr_region_list(struct domain *d);
void destroy_perdomain_mapping(struct domain *d, unsigned long start, unsigned long size);
void hvm_domain_relinquish_resources(struct domain *d);
void *_xmalloc(size_t size, size_t alignment);
struct hvm_irq *hvm_domain_irq(struct domain *d);

#define xzalloc(type) ((type *)xzalloc(sizeof(type)))
#define xzalloc_array(type, count) ((type *)xzalloc_array((count), sizeof(type)))