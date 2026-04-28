#include <stdbool.h>
#include <stddef.h>

#define PAGE_SIZE 4096
#define SINGLE_DEPTH_NESTING 1

typedef unsigned long pte_t;
typedef unsigned long pmd_t;
typedef unsigned long spinlock_t;

struct vm_area_struct {
    struct mm_struct *vm_mm;
    unsigned long vm_page_prot;
};
struct mm_struct;

void take_rmap_locks(struct vm_area_struct *vma);
void drop_rmap_locks(struct vm_area_struct *vma);
pte_t *pte_offset_map_lock(struct mm_struct *mm, pmd_t *pmd, unsigned long addr, spinlock_t **ptl);
pte_t *pte_offset_map(pmd_t *pmd, unsigned long addr);
spinlock_t *pte_lockptr(struct mm_struct *mm, pmd_t *pmd);
void spin_lock_nested(spinlock_t *lock, int subclass);
void spin_unlock(spinlock_t *lock);
void flush_tlb_batched_pending(struct mm_struct *mm);
void arch_enter_lazy_mmu_mode(void);
void arch_leave_lazy_mmu_mode(void);
int pte_none(pte_t pte);
pte_t ptep_get_and_clear(struct mm_struct *mm, unsigned long addr, pte_t *ptep);
int pte_present(pte_t pte);
int pte_dirty(pte_t pte);
pte_t move_pte(pte_t pte, unsigned long prot, unsigned long old_addr, unsigned long new_addr);
pte_t move_soft_dirty_pte(pte_t pte);
void set_pte_at(struct mm_struct *mm, unsigned long addr, pte_t *ptep, pte_t pte);
void pte_unmap(pte_t *pte);
void pte_unmap_unlock(pte_t *pte, spinlock_t *ptl);
void flush_tlb_range(struct vm_area_struct *vma, unsigned long start, unsigned long end);