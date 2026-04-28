#include <stdint.h>
#include <stddef.h>

typedef uint32_t grant_ref_t;
typedef uint16_t domid_t;
typedef uintptr_t phys_addr_t;

#define GNTMAP_contains_pte (1<<0)
#define XENFEAT_auto_translated_physmap 0

struct gnttab_map_grant_ref {
    union {
        phys_addr_t host_addr;
        phys_addr_t dev_bus_addr;
    };
    uint32_t flags;
    grant_ref_t ref;
    domid_t dom;
    int16_t status;
};

static inline int xen_feature(int feature) {
    return 0;
}

static inline phys_addr_t __pa(phys_addr_t addr) {
    return addr;
}