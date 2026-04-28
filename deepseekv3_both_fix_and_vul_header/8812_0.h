#include <stdbool.h>
#include <stdint.h>

typedef uint64_t hwaddr;

typedef struct Int128 {
    uint64_t lo;
    int64_t hi;
} Int128;

typedef struct MemoryRegion MemoryRegion;
typedef struct AddressSpaceDispatch AddressSpaceDispatch;

typedef struct MemoryRegionSection {
    hwaddr offset_within_address_space;
    hwaddr offset_within_region;
    MemoryRegion *mr;
    Int128 size;
} MemoryRegionSection;

static Int128 int128_sub(Int128 a, Int128 b);
static Int128 int128_make64(uint64_t a);
static Int128 int128_min(Int128 a, Int128 b);
static uint64_t int128_get64(Int128 a);
static bool memory_region_is_ram(MemoryRegion *mr);
static MemoryRegionSection *address_space_lookup_region(AddressSpaceDispatch *d, hwaddr addr, bool resolve_subpage);