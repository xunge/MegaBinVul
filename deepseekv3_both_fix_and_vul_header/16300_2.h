#include <stddef.h>
#include <stdbool.h>

#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define TASK_SIZE ((1UL << 47) - PAGE_SIZE)
#define EINVAL 22
#define ENOMEM 12
#define VM_LOCKED 0x00002000
#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

struct list_head {
    struct list_head *next, *prev;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    struct vm_area_struct *vm_next;
    struct vm_area_struct *vm_prev;
};

struct mm_struct {
    unsigned long map_count;
    unsigned long locked_vm;
    struct vm_area_struct *mmap;
};

#define offset_in_page(p) ((unsigned long)(p) & ~PAGE_MASK)
#define PAGE_ALIGN(addr) (((addr)+PAGE_SIZE-1)&PAGE_MASK)

extern int arch_unmap(struct mm_struct *mm, unsigned long start, unsigned long end);
extern struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr);
extern int __split_vma(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long addr, int new_below);
extern int userfaultfd_unmap_prep(struct vm_area_struct *vma, unsigned long start, unsigned long end, struct list_head *uf);
extern void munlock_vma_pages_all(struct vm_area_struct *vma);
extern bool detach_vmas_to_be_unmapped(struct mm_struct *mm, struct vm_area_struct *vma, struct vm_area_struct *prev, unsigned long end);
extern void mmap_write_downgrade(struct mm_struct *mm);
extern void unmap_region(struct mm_struct *mm, struct vm_area_struct *vma, struct vm_area_struct *prev, unsigned long start, unsigned long end);
extern void remove_vma_list(struct mm_struct *mm, struct vm_area_struct *vma);
extern unsigned long vma_pages(struct vm_area_struct *vma);

extern int sysctl_max_map_count;