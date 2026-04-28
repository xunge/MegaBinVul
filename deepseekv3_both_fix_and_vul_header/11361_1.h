#include <stddef.h>
#include <stdbool.h>

#define IO_TLB_DEFAULT_SIZE 0
#define IO_TLB_SHIFT 0
#define IO_TLB_SEGSIZE 0
#define PAGE_ALIGN(x) (x)
#define PAGE_SIZE 0
#define ALIGN(x, y) (((x) + (y) - 1) & ~((y) - 1))

#define __init

extern size_t io_tlb_nslabs;
extern unsigned long io_tlb_start;
extern bool no_iotlb_memory;

void *memblock_virt_alloc_low_nopanic(size_t size, size_t align);
void memblock_free_early(unsigned long addr, size_t size);
int swiotlb_init_with_tbl(unsigned char *vstart, size_t nslabs, int verbose);
void pr_warn(const char *fmt, ...);