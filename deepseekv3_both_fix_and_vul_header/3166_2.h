#include <stdint.h>

struct fb_info {
    void *par;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_pgoff;
    uint64_t vm_page_prot;
};

struct au1200fb_device {
    unsigned long fb_phys;
    unsigned int fb_len;
};

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))
#define _CACHE_MASK (0x1f << 9)

#define PAGE_ALIGN(addr) (((addr)+PAGE_SIZE-1)&PAGE_MASK)
#define EINVAL 22

typedef uint64_t pgprot_t;
#define pgprot_noncached(x) (x)
#define pgprot_val(x) (x)
#define vm_iomap_memory(vma, phys, len) (0)
#define io_remap_pfn_range(vma, start, pfn, size, prot) (0)