#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define HVMIRQ_callback_none 0
#define HVMIRQ_callback_gsi 1
#define HVMIRQ_callback_pci_intx 2
#define HVMIRQ_callback_vector 3

struct pci_intx {
    uint8_t dev;
    uint8_t intx;
};

union callback_via {
    uint8_t gsi;
    struct pci_intx pci;
    uint8_t vector;
};

struct hvm_irq {
    uint8_t callback_via_type;
    union callback_via callback_via;
    bool callback_via_asserted;
    unsigned int gsi_assert_count[256];
};

struct arch_hvm_domain {
    struct hvm_irq irq;
    void *irq_lock;
};

struct arch_domain {
    struct arch_hvm_domain hvm_domain;
};

struct domain {
    struct arch_domain arch;
    unsigned int domain_id;
};

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}

static inline bool has_vlapic(struct domain *d) { return false; }
static inline bool has_vioapic(struct domain *d) { return false; }
static inline bool has_vpic(struct domain *d) { return false; }

static inline void vpic_irq_negative_edge(struct domain *d, unsigned int gsi) {}
static inline void vpic_irq_positive_edge(struct domain *d, unsigned int gsi) {}
static inline void vioapic_irq_positive_edge(struct domain *d, unsigned int gsi) {}
static inline void __hvm_pci_intx_deassert(struct domain *d, unsigned int pdev, unsigned int pintx) {}
static inline void __hvm_pci_intx_assert(struct domain *d, unsigned int pdev, unsigned int pintx) {}

#define XENLOG_G_INFO "Dom%u callback via changed to "
#define printk(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define dprintk(level, fmt, ...) printf(fmt, ##__VA_ARGS__)