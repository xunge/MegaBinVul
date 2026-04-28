#include <sys/mman.h>
#include <stddef.h>

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    unsigned long vm_pgoff;
    unsigned long vm_page_prot;
    struct mm_struct *vm_mm;
    void *anon_vma;
    void *vm_file;
};

struct mm_struct;

#define PAGE_SHIFT 12
#define VM_WRITE 0x2
#define VM_ACCOUNT 0x10
#define VM_HUGETLB 0x40000
#define VM_SHARED 0x8
#define VM_NORESERVE 0x20
#define ENOMEM 12

typedef unsigned long pgoff_t;

long security_vm_enough_memory(unsigned long pages);
struct vm_area_struct *vma_merge(struct mm_struct *mm, struct vm_area_struct *prev,
                                unsigned long start, unsigned long end, unsigned long flags,
                                void *anon_vma, void *file, pgoff_t pgoff, void *policy);
int split_vma(struct mm_struct *mm, struct vm_area_struct *vma,
             unsigned long addr, int new_below);
unsigned long pgprot_modify(unsigned long oldprot, unsigned long newprot);
unsigned long vm_get_page_prot(unsigned long flags);
int vma_wants_writenotify(struct vm_area_struct *vma);
void mmu_notifier_invalidate_range_start(struct mm_struct *mm,
                                       unsigned long start, unsigned long end);
int is_vm_hugetlb_page(struct vm_area_struct *vma);
void hugetlb_change_protection(struct vm_area_struct *vma,
                              unsigned long start, unsigned long end,
                              unsigned long prot);
void change_protection(struct vm_area_struct *vma,
                      unsigned long start, unsigned long end,
                      unsigned long prot, int dirty_accountable);
void mmu_notifier_invalidate_range_end(struct mm_struct *mm,
                                     unsigned long start, unsigned long end);
void vm_stat_account(struct mm_struct *mm, unsigned long flags,
                    void *file, long pages);
void vm_unacct_memory(unsigned long pages);
void *vma_policy(struct vm_area_struct *vma);