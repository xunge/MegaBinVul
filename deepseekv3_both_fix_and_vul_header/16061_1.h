#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uint64_t paddr_t;

#define ENODEV 19
#define ENXIO 6
#define ENOMEM 12
#define ENODATA 61

#define PCI_CAP_ID_MSIX 0x11
#define PCI_MSIX_FLAGS_ENABLE 0x8000
#define PCI_MSIX_FLAGS_MASKALL 0x4000
#define PCI_MSIX_BIRMASK 0x7
#define PCI_MSIX_ENTRY_SIZE 16
#define PCI_MSIX_ENTRY_VECTOR_CTRL_OFFSET 12
#define PCI_SLOT(devfn) (((devfn) >> 3) & 0x1f)
#define PCI_FUNC(devfn) ((devfn) & 0x07)
#define PCI_BDF2(bus, devfn) (((bus) << 8) | (devfn))

#define PFN_DOWN(x) ((x) >> PAGE_SHIFT)
#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_OFFSET(x) ((x) & (PAGE_SIZE - 1))

#define XENLOG_WARNING "warning"
#define XENLOG_ERR "error"

#define ASSERT(x) do { if (!(x)) abort(); } while (0)
#define WARN_ON(x) do { if (x) {} } while (0)
#define WARN() do {} while (0)
#define unlikely(x) (x)
#define BITS_TO_LONGS(nr) (((nr) + 8 * sizeof(long) - 1) / (8 * sizeof(long)))

struct list_head {
    struct list_head *next, *prev;
};

struct pci_dev {
    struct arch_msix *msix;
    unsigned int sbdf;
    unsigned int seg;
    unsigned int bus;
    unsigned int devfn;
    struct {
        bool is_virtfn;
        struct {
            unsigned int bus;
            unsigned int devfn;
        } physfn;
    } info;
    struct domain *domain;
    struct list_head msi_list;
};

struct msi_info {
    u64 table_base;
    unsigned int entry_nr;
    unsigned int irq;
};

struct msi_desc {
    struct {
        unsigned int type;
        bool is_64;
        unsigned int entry_nr;
        bool maskbit;
        bool host_masked;
        bool guest_masked;
        unsigned int pos;
    } msi_attrib;
    unsigned int irq;
    struct pci_dev *dev;
    void *mask_base;
    struct list_head list;
};

struct arch_msix {
    bool host_maskall;
    bool guest_maskall;
    unsigned int used_entries;
    unsigned int nr_entries;
    struct {
        unsigned long first;
        unsigned long last;
    } table;
    struct {
        unsigned long first;
        unsigned long last;
    } pba;
};

struct domain {
    unsigned int tot_pages;
};

struct current {
    struct domain *domain;
} *current;

struct rangeset;
static struct rangeset *mmio_ro_ranges;
static bool hardware_domain;
static struct domain *dom_io;

typedef void* iomem_ptr;
#define __iomem

static int pcidevs_locked(void) { return 1; }
static int rangeset_overlaps_range(struct rangeset *r, unsigned long s, unsigned long e) { return 0; }

static unsigned int pci_find_cap_offset(unsigned int seg, unsigned int bus,
                                      unsigned int slot, unsigned int func,
                                      unsigned int cap) { return 0; }
static u16 pci_conf_read16(unsigned int sbdf, unsigned int reg) { return 0; }
static void pci_conf_write16(unsigned int sbdf, unsigned int reg, u16 val) {}
static u32 pci_conf_read32(unsigned int sbdf, unsigned int reg) { return 0; }
static bool memory_decoded(struct pci_dev *dev) { return true; }
static struct msi_desc *alloc_msi_entry(unsigned int nr_entries) { return NULL; }
static void xfree(void *ptr) {}
static u64 read_pci_mem_bar(unsigned int seg, unsigned int bus,
                           unsigned int slot, unsigned int func,
                           unsigned int bir, int vf) { return 0; }
static int msix_get_fixmap(struct arch_msix *msix, u64 table_paddr,
                          u64 entry_paddr) { return 0; }
static void *fix_to_virt(int idx) { return NULL; }
static void writel(u32 val, void *addr) {}
static void list_add_tail(struct list_head *new, struct list_head *head) {}
static int rangeset_add_range(struct rangeset *r, unsigned long s,
                             unsigned long e) { return 0; }
static void pci_intx(struct pci_dev *dev, bool enable) {}
static void printk(const char *fmt, ...) {}
static void domain_crash(struct domain *d) {}
static bool is_hardware_domain(struct domain *d) { return false; }
static unsigned long domain_tot_pages(struct domain *d) { return 0; }
static unsigned int msix_control_reg(unsigned int pos) { return 0; }
static unsigned int msix_table_offset_reg(unsigned int pos) { return 0; }
static unsigned int msix_pba_offset_reg(unsigned int pos) { return 0; }