#include <stddef.h>
#include <stdint.h>
#include <errno.h>

typedef int ret_t;

#define XEN_GUEST_HANDLE_PARAM(type) void*

#define NR_ISAIRQS 16
#define IOBMP_BYTES 8192
#define PIRQ_ALLOCATED (-1)
#define IRQ_UNBOUND (-1)
#define PGT_writable_page 0
#define P2M_ALLOC 0

struct physdev_eoi {
    int irq;
};

struct physdev_pirq_eoi_gmfn {
    unsigned long gmfn;
};

struct physdev_irq_status_query {
    int irq;
    uint32_t flags;
};

typedef struct {
    int domid;
    int type;
    int index;
    int pirq;
    int bus;
    int devfn;
    int entry_nr;
    unsigned long table_base;
} physdev_map_pirq_t;

struct physdev_unmap_pirq {
    int domid;
    int pirq;
};

struct physdev_apic {
    unsigned long apic_physbase;
    int reg;
    uint32_t value;
};

struct physdev_irq {
    int irq;
    int vector;
};

struct physdev_set_iopl {
    uint8_t iopl;
};

struct physdev_set_iobitmap {
    void* bitmap;
    unsigned int nr_ports;
};

struct physdev_manage_pci {
    int bus;
    int devfn;
};

struct physdev_manage_pci_ext {
    int bus;
    int devfn;
    int is_extfn;
    int is_virtfn;
    struct {
        int bus;
        int devfn;
    } physfn;
};

struct physdev_pci_device {
    int seg;
    int bus;
    int devfn;
};

struct physdev_pci_device_add {
    int seg;
    int bus;
    int devfn;
    int flags;
    struct {
        int bus;
        int devfn;
    } physfn;
};

struct physdev_pci_mmcfg_reserved {
    uint64_t address;
    uint16_t segment;
    uint8_t start_bus;
    uint8_t end_bus;
    uint32_t flags;
};

struct physdev_restore_msi {
    int bus;
    int devfn;
};

struct physdev_setup_gsi {
    int gsi;
    int triggering;
    int polarity;
};

struct physdev_get_free_pirq {
    int type;
    int pirq;
};

struct physdev_dbgp_op {
    int cmd;
    int bus;
    int devfn;
    int reg;
    uint32_t value;
};

struct pirq {
    int evtchn;
    struct {
        int irq;
    } arch;
};

struct hvm_irq {
    int* gsi_assert_count;
};

struct vcpu {
    struct domain *domain;
    struct {
        struct {
            uint8_t iopl;
            void* iobmp;
            unsigned int iobmp_limit;
        } pv_vcpu;
    } arch;
};

struct domain {
    int nr_pirqs;
    int event_lock;
    struct {
        struct {
            int auto_unmask;
            unsigned long pirq_eoi_map_mfn;
            void *pirq_eoi_map;
        } pv_domain;
        struct {
            struct hvm_irq irq;
        } hvm_domain;
    } arch;
};

struct page_info;
struct msi_info {
    int seg;
    int bus;
    int devfn;
    int entry_nr;
    unsigned long table_base;
};

struct pci_dev_info {
    int is_extfn;
    int is_virtfn;
    struct {
        int bus;
        int devfn;
    } physfn;
};

struct pci_dev;

extern int nr_irqs_gsi;
extern int pcidevs_lock;
extern struct vcpu *current;

#define XENIRQSTAT_needs_eoi (1 << 0)
#define XENIRQSTAT_shared (1 << 1)
#define MAP_PIRQ_TYPE_MSI 0
#define MAP_PIRQ_TYPE_MSI_SEG 1
#define MAP_PIRQ_TYPE_MULTI_MSI 2
#define PHYSDEVOP_eoi 0
#define PHYSDEVOP_pirq_eoi_gmfn_v1 1
#define PHYSDEVOP_pirq_eoi_gmfn_v2 2
#define PHYSDEVOP_IRQ_UNMASK_NOTIFY 3
#define PHYSDEVOP_irq_status_query 4
#define PHYSDEVOP_map_pirq 5
#define PHYSDEVOP_unmap_pirq 6
#define PHYSDEVOP_apic_read 7
#define PHYSDEVOP_apic_write 8
#define PHYSDEVOP_alloc_irq_vector 9
#define PHYSDEVOP_set_iopl 10
#define PHYSDEVOP_set_iobitmap 11
#define PHYSDEVOP_manage_pci_add 12
#define PHYSDEVOP_manage_pci_remove 13
#define PHYSDEVOP_manage_pci_add_ext 14
#define PHYSDEVOP_pci_device_add 15
#define PHYSDEVOP_pci_device_remove 16
#define PHYSDEVOP_prepare_msix 17
#define PHYSDEVOP_release_msix 18
#define PHYSDEVOP_pci_mmcfg_reserved 19
#define PHYSDEVOP_restore_msi 20
#define PHYSDEVOP_restore_msi_ext 21
#define PHYSDEVOP_setup_gsi 22
#define PHYSDEVOP_get_free_pirq 23
#define PHYSDEVOP_dbgp_op 24

#define XSM_PRIV 0
#define XEN_PCI_DEV_EXTFN (1 << 0)
#define XEN_PCI_DEV_VIRTFN (1 << 1)

/* Function prototypes */
static inline int copy_from_guest(void* dest, void* src, size_t size) { return 0; }
static inline int __copy_to_guest(void* dest, void* src, size_t size) { return 0; }
static inline int guest_handle_okay(void* handle, size_t size) { return 1; }
static inline void spin_lock(int* lock) {}
static inline void spin_unlock(int* lock) {}
static inline int cmpxchg(unsigned long* ptr, unsigned long old, unsigned long new) { return 0; }
static inline struct pirq* pirq_info(struct domain* d, int irq) { return NULL; }
static inline int is_pv_domain(struct domain* d) { return 0; }
static inline int is_hvm_domain(struct domain* d) { return 0; }
static inline int domain_pirq_to_irq(struct domain* d, int pirq) { return 0; }
static inline int domain_pirq_to_emuirq(struct domain* d, int pirq) { return 0; }
static inline void evtchn_unmask(int evtchn) {}
static inline void pirq_guest_eoi(struct pirq* pirq) {}
static inline void send_guest_pirq(struct domain* d, struct pirq* pirq) {}
static inline struct page_info* get_page_from_gfn(struct domain* d, unsigned long gfn, void* p2m, int flags) { return NULL; }
static inline int get_page_type(struct page_info* page, int type) { return 0; }
static inline void put_page(struct page_info* page) {}
static inline unsigned long page_to_mfn(struct page_info* page) { return 0; }
static inline void put_page_and_type(struct page_info* page) {}
static inline void* map_domain_page_global(unsigned long mfn) { return NULL; }
static inline int pirq_guest_unmask(struct domain* d) { return 0; }
static inline int pirq_shared(struct domain* d, int pirq) { return 0; }
static inline int physdev_map_pirq(int domid, int type, int* index, int* pirq, struct msi_info* msi) { return 0; }
static inline int physdev_unmap_pirq(int domid, int pirq) { return 0; }
static inline int xsm_apic(int priv, struct domain* d, int cmd) { return 0; }
static inline int ioapic_guest_read(unsigned long base, int reg, uint32_t* value) { return 0; }
static inline int ioapic_guest_write(unsigned long base, int reg, uint32_t value) { return 0; }
static inline int is_pvh_vcpu(struct vcpu* v) { return 0; }
static inline int pci_add_device(int seg, int bus, int devfn, struct pci_dev_info* info) { return 0; }
static inline int pci_remove_device(int seg, int bus, int devfn) { return 0; }
static inline int pci_prepare_msix(int seg, int bus, int devfn, int release) { return 0; }
static inline int xsm_resource_setup_misc(int priv) { return 0; }
static inline int pci_mmcfg_reserved(uint64_t addr, uint16_t seg, uint8_t start, uint8_t end, uint32_t flags) { return 0; }
static inline struct pci_dev* pci_get_pdev(int seg, int bus, int devfn) { return NULL; }
static inline int pci_restore_msi_state(struct pci_dev* pdev) { return 0; }
static inline int xsm_resource_setup_gsi(int priv, int gsi) { return 0; }
static inline int mp_register_gsi(int gsi, int triggering, int polarity) { return 0; }
static inline int get_free_pirq(struct domain* d, int type) { return 0; }
static inline struct pirq* pirq_get_info(struct domain* d, int pirq) { return NULL; }
static inline int is_hardware_domain(struct domain* d) { return 0; }
static inline int dbgp_op(struct physdev_dbgp_op* op) { return 0; }