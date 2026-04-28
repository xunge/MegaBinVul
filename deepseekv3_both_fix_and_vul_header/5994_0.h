#include <stdbool.h>

#define CONFIG_MAX_IR_ENTRIES 256

enum ptdev_intr_type {
    PTDEV_INTR_MSI
};

struct msi_id {
    unsigned int bdf;
};

struct phys_sid {
    struct msi_id msi_id;
};

struct ptirq_remapping_info {
    unsigned int irte_idx;
    enum ptdev_intr_type intr_type;
    struct phys_sid phys_sid;
    unsigned int allocated_pirq;
};

struct intr_source_msi {
    unsigned int value;
};

struct intr_source {
    bool is_msi;
    union {
        struct intr_source_msi msi;
        unsigned int ioapic_id;
    } src;
};

unsigned int ioapic_irq_to_ioapic_id(unsigned int pirq);
void dmar_free_irte(struct intr_source *intr_src, unsigned int irte_idx);