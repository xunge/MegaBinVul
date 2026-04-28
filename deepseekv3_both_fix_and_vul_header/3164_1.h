#include <stdint.h>

struct fb_info;
struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_pgoff;
    uint64_t vm_page_prot;
};

struct au1100fb_device {
    unsigned long fb_phys;
    unsigned int fb_len;
};

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE - 1))
#define PAGE_ALIGN(addr) (((addr) + PAGE_SIZE - 1) & PAGE_MASK)

#define EINVAL 22
#define EAGAIN 11

#define pgprot_noncached(prot) (prot)
#define pgprot_val(x) (x)

static inline struct au1100fb_device* to_au1100fb_device(struct fb_info *fbi) {
    return (struct au1100fb_device*)0;
}

int io_remap_pfn_range(struct vm_area_struct *vma, unsigned long addr,
                      unsigned long pfn, unsigned long size, uint64_t prot) {
    return 0;
}