#include <stdbool.h>
#include <stdatomic.h>
#include <stddef.h>

typedef unsigned long hwaddr;

typedef struct MemoryRegion MemoryRegion;
typedef struct AddressSpaceDispatch AddressSpaceDispatch;
typedef struct IOMMUTLBEntry IOMMUTLBEntry;

typedef struct MemoryRegionSection {
    MemoryRegion *mr;
} MemoryRegionSection;

typedef struct AddressSpace {
    AddressSpaceDispatch *dispatch;
} AddressSpace;

typedef struct IOMMUTLBEntry {
    hwaddr translated_addr;
    hwaddr addr_mask;
    int perm;
    AddressSpace *target_as;
} IOMMUTLBEntry;

typedef struct MemoryRegion {
    struct {
        IOMMUTLBEntry (*translate)(MemoryRegion*, hwaddr, bool);
    } *iommu_ops;
} MemoryRegion;

extern MemoryRegion io_mem_unassigned;

void rcu_read_lock(void);
void rcu_read_unlock(void);
MemoryRegionSection *address_space_translate_internal(AddressSpaceDispatch *d, hwaddr addr, hwaddr *xlat, hwaddr *plen, bool is_write);
bool xen_enabled(void);
bool memory_access_is_direct(MemoryRegion *mr, bool is_write);

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define TARGET_PAGE_MASK (~(TARGET_PAGE_SIZE - 1))
#define TARGET_PAGE_SIZE 4096

static inline AddressSpaceDispatch *atomic_rcu_read(AddressSpaceDispatch **ptr)
{
    return atomic_load_explicit((_Atomic AddressSpaceDispatch **)ptr, memory_order_consume);
}