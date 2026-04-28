#include <stdbool.h>

#define IOMMU_FLUSHF_added   0x1
#define IOMMU_FLUSHF_modified 0x2

union amd_iommu_pte {
    struct {
        unsigned long mfn:52;
        unsigned int ign0:4;
        unsigned int fc:1;
        unsigned int ign1:3;
        bool iw:1;
        bool ir:1;
        bool next_level:1;
        bool pr:1;
        unsigned int ign2:2;
    };
    unsigned long raw;
};

static unsigned long read_atomic(unsigned long *addr) { return *addr; }
static void write_atomic(unsigned long *addr, unsigned long val) { *addr = val; }