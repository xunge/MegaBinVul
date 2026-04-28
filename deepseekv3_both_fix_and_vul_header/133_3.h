#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <stddef.h>

typedef uint64_t hwaddr;

#define PAGE_READ   0x01
#define PAGE_WRITE  0x02
#define PAGE_EXEC   0x04
#define IOMMU_RO    0x01
#define IOMMU_WO    0x02
#define IOMMU_NONE  0x00
#define TARGET_PAGE_MASK (~(hwaddr)0xFFF)
#define PHYS_SECTION_UNASSIGNED 0

typedef struct MemTxAttrs MemTxAttrs;
typedef struct IOMMUTLBEntry IOMMUTLBEntry;
typedef struct IOMMUMemoryRegion IOMMUMemoryRegion;

typedef struct MemoryRegionSection {
    void *mr;
} MemoryRegionSection;

typedef struct AddressSpaceDispatch {
    struct {
        MemoryRegionSection sections[16];
    } map;
} AddressSpaceDispatch;

typedef struct CPUState {
    struct {
        struct {
            AddressSpaceDispatch *memory_dispatch;
        } cpu_ases[16];
    };
} CPUState;

typedef struct IOMMUMemoryRegionClass {
    int (*attrs_to_index)(IOMMUMemoryRegion *, MemTxAttrs);
    IOMMUTLBEntry (*translate)(IOMMUMemoryRegion *, hwaddr, int, int);
} IOMMUMemoryRegionClass;

struct IOMMUTLBEntry {
    hwaddr translated_addr;
    hwaddr addr_mask;
    int perm;
    void *target_as;
};

struct MemTxAttrs {
    unsigned int unspecified;
};

static inline void *qatomic_rcu_read(void *ptr) { return ptr; }
static inline void tcg_register_iommu_notifier(CPUState *cpu, IOMMUMemoryRegion *iommu_mr, int iommu_idx) {}
static inline MemoryRegionSection *address_space_translate_internal(AddressSpaceDispatch *d, hwaddr addr, hwaddr *xlat, hwaddr *plen, bool is_write) { return NULL; }
static inline IOMMUMemoryRegion *memory_region_get_iommu(void *mr) { return NULL; }
static inline IOMMUMemoryRegionClass *memory_region_get_iommu_class_nocheck(IOMMUMemoryRegion *iommu_mr) { return NULL; }
static inline bool memory_region_is_iommu(void *mr) { return false; }
static inline void *flatview_to_dispatch(void *fv) { return NULL; }
static inline void *address_space_to_flatview(void *as) { return NULL; }