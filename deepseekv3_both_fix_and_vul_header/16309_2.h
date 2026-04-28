#include <stddef.h>
#include <stdint.h>

#define FOLL_WRITE    0x01
#define FOLL_LONGTERM 0x02
#define FOLL_FORCE    0x04
#define FOLL_PIN      0x08
#define FOLL_GET      0x10

#define PAGE_SHIFT    12
#define PAGE_SIZE     (1UL << PAGE_SHIFT)
#define PAGE_MASK     (~(PAGE_SIZE-1))

#define EINVAL        22
#define EFAULT        14

#define WARN_ON_ONCE(cond) (cond)
#define unlikely(cond) (cond)
#define IS_ENABLED(option) 0

struct page {
    unsigned long flags;
};

void local_irq_disable(void);
void local_irq_enable(void);

int __gup_longterm_unlocked(unsigned long start, int nr_pages,
                          unsigned int gup_flags, struct page **pages);
int gup_fast_permitted(unsigned long start, unsigned long end);
void gup_pgd_range(unsigned long addr, unsigned long end,
                 unsigned int gup_flags, struct page **pages,
                 int *nr_pinned);
unsigned long untagged_addr(unsigned long addr);
int access_ok(const void *addr, unsigned long size);

#define __user