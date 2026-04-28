#include <stddef.h>

#define PAGE_SHIFT 12

extern int iomem_is_exclusive(unsigned long addr);
extern int page_is_ram(unsigned long pagenr);