#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <errno.h>

#define XC_PAGE_SHIFT 12
#define ZIMAGE32_START_OFFSET 0x24
#define DOMPRINTF_CALLED(xch)
#define DOMPRINTF(fmt, ...)

struct xc_dom_segment {
    uint64_t vstart;
    uint64_t vend;
};

struct xc_dom_params {
    uint64_t virt_entry;
    uint64_t virt_base;
};

struct xc_dom_image {
    uint64_t rambase_pfn;
    void *kernel_blob;
    uint64_t kernel_size;
    struct xc_dom_segment kernel_seg;
    struct xc_dom_params parms;
    const char *guest_type;
    void *xch;
};