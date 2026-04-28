#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <errno.h>

#define XC_PAGE_SHIFT 12
#define DOMPRINTF_CALLED(xch)
#define DOMPRINTF(fmt, ...)

struct zimage64_hdr {
    uint64_t text_offset;
};

struct xc_dom_segment {
    uint64_t vstart;
    uint64_t vend;
};

struct xc_dom_parameters {
    uint64_t virt_entry;
    uint64_t virt_base;
};

struct xc_dom_image {
    void *xch;
    uint64_t rambase_pfn;
    struct zimage64_hdr *kernel_blob;
    uint64_t kernel_size;
    struct xc_dom_segment kernel_seg;
    struct xc_dom_parameters parms;
    const char *guest_type;
};