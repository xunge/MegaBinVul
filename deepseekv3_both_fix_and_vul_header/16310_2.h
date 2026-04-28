#include <stddef.h>
#include <signal.h>

#define FOLL_GET     0x01
#define FOLL_PIN     0x02
#define FOLL_FORCE   0x04
#define FOLL_NUMA    0x08
#define FOLL_WRITE   0x10
#define FOLL_NOWAIT  0x20

#define PAGE_SHIFT   12
#define PAGE_SIZE    4096
#define PAGE_MASK    (~(PAGE_SIZE-1))

#define EFAULT       14
#define EINTR        4
#define ENOMEM       12
#define EHWPOISON    133
#define ENOENT       2
#define EBUSY        16
#define EEXIST       17

#define VM_BUG_ON(cond) ((void)0)
#define BUG_ON(cond) ((void)0)
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define fallthrough

struct task_struct {
    int dummy;
};

struct mm_struct {
    int dummy;
};

struct page {
    int dummy;
};

struct vm_area_struct {
    unsigned long vm_end;
    int dummy;
};

struct dev_pagemap {
    int dummy;
};

struct follow_page_context {
    struct dev_pagemap *pgmap;
    unsigned int page_mask;
};

extern struct task_struct *current;

static inline unsigned long untagged_addr(unsigned long addr) { return addr; }

static inline void BUG(void) { while(1); }

extern struct vm_area_struct *find_extend_vma(struct mm_struct *mm, unsigned long addr);
extern int in_gate_area(struct mm_struct *mm, unsigned long addr);
extern long get_gate_page(struct mm_struct *mm, unsigned long addr,
             unsigned int gup_flags, struct vm_area_struct **vma,
             struct page **page);
extern int check_vma_flags(struct vm_area_struct *vma, unsigned int gup_flags);
extern int is_vm_hugetlb_page(struct vm_area_struct *vma);
extern int should_force_cow_break(struct vm_area_struct *vma, unsigned int flags);
extern long follow_hugetlb_page(struct mm_struct *mm, struct vm_area_struct *vma,
                  struct page **pages, struct vm_area_struct **vmas,
                  unsigned long *position, unsigned long *nr_pages,
                  long i, unsigned int gup_flags, int *locked);
extern int fatal_signal_pending(struct task_struct *p);
extern void cond_resched(void);
extern struct page *follow_page_mask(struct vm_area_struct *vma,
                   unsigned long address, unsigned int flags,
                   struct follow_page_context *ctx);
extern long faultin_page(struct task_struct *tsk, struct vm_area_struct *vma,
            unsigned long address, unsigned int *flags, int *locked);
extern void flush_anon_page(struct vm_area_struct *vma, struct page *page,
              unsigned long vmaddr);
extern void flush_dcache_page(struct page *page);
extern void put_dev_pagemap(struct dev_pagemap *pgmap);