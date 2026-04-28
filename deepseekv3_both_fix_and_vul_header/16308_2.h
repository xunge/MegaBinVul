#define FOLL_GET 0x01
#define FOLL_WRITE 0x02
#define PAGE_SHIFT 12
#define PAGE_MASK (~((1UL << PAGE_SHIFT) - 1))

struct page {
    unsigned long flags;
};

#define __user
#define untagged_addr(addr) (addr)
#define unlikely(x) (x)
#define IS_ENABLED(x) 1
#define CONFIG_HAVE_FAST_GUP 1

void local_irq_save(unsigned long flags);
void local_irq_restore(unsigned long flags);
int gup_fast_permitted(unsigned long start, unsigned long end);
int gup_pgd_range(unsigned long start, unsigned long end, unsigned int gup_flags, struct page **pages, int *nr_pinned);
int access_ok(const void *addr, unsigned long size);