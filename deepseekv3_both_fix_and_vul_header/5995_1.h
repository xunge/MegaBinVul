#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

struct intr_source {
    bool is_msi;
    union {
        struct {
            struct {
                uint32_t b;
            } bits;
            struct {
                uint16_t devfun;
            } fields;
        } msi;
        uint32_t ioapic_id;
    } src;
};

struct dmar_drhd_rt {
    uint64_t ir_table_addr;
    uint64_t irte_alloc_bitmap[0];
    int lock;
};

union dmar_ir_entry {
    struct {
        struct {
            uint64_t present;
        } remap;
    } bits;
};

union pci_bdf {
    uint16_t value;
    struct {
        uint8_t bus;
        uint8_t devfun;
    } fields;
};

#define CONFIG_MAX_IR_ENTRIES 256

static inline void spinlock_obtain(int *lock) {}
static inline void spinlock_release(int *lock) {}

static inline void bitmap_clear_nolock(uint32_t bit, uint64_t *bitmap) {}

static inline struct dmar_drhd_rt *device_to_dmaru(uint8_t bus, uint16_t devfun) { return NULL; }
static inline struct dmar_drhd_rt *ioapic_to_dmaru(uint32_t ioapic_id, union pci_bdf *sid) { return NULL; }
static inline bool is_dmar_unit_valid(struct dmar_drhd_rt *dmar_unit, union pci_bdf sid) { return false; }
static inline void *hpa2hva(uint64_t addr) { return NULL; }
static inline void iommu_flush_cache(void *addr, size_t size) {}
static inline void dmar_invalid_iec(struct dmar_drhd_rt *dmar_unit, uint16_t index, uint32_t type, bool global) {}
static inline bool is_irte_reserved(struct dmar_drhd_rt *dmar_unit, uint16_t index) { return false; }