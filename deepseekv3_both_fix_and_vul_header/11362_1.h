#include <stddef.h>

#define IO_TLB_SHIFT 11
#define IO_TLB_SEGSIZE 128
#define IO_TLB_MIN_SLABS 1
#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define SLABS_PER_PAGE (1 << (PAGE_SHIFT - IO_TLB_SHIFT))
#define ALIGN(x, a) (((x) + ((a) - 1)) & ~((a) - 1))
#define ENOMEM 12
#define GFP_DMA 0x01u
#define __GFP_NOWARN 0x800u
#define KERN_WARNING ""

extern unsigned long io_tlb_nslabs;
extern unsigned int get_order(unsigned long size);
extern void *__get_free_pages(unsigned int gfp_mask, unsigned int order);
extern void free_pages(unsigned long addr, unsigned int order);
extern int swiotlb_late_init_with_tbl(unsigned char *vstart, unsigned long nslabs);
extern int printk(const char *fmt, ...);