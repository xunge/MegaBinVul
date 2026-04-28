#include <stddef.h>
#include <stdbool.h>

struct mm_struct;
struct vm_area_struct {
    struct vm_operations_struct *vm_ops;
};
struct vm_operations_struct {
    int (*fault)(void);
};

typedef unsigned long pte_t;
typedef unsigned long pmd_t;
typedef struct spinlock spinlock_t;

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

#define pte_present(x) 0
#define pte_none(x) 0
#define pte_protnone(x) 0
#define pte_write(x) 0
#define pte_same(x, y) 0
#define pte_mkdirty(x) (x)
#define pte_mkyoung(x) (x)

#define FAULT_FLAG_WRITE 0x01

static void barrier(void) {}
static void spin_lock(spinlock_t *lock) {}
static void pte_unmap_unlock(pte_t *pte, spinlock_t *ptl) {}
static spinlock_t *pte_lockptr(struct mm_struct *mm, pmd_t *pmd) { return NULL; }
static int ptep_set_access_flags(struct vm_area_struct *vma, unsigned long address, pte_t *pte, pte_t entry, int write) { return 0; }
static void update_mmu_cache(struct vm_area_struct *vma, unsigned long address, pte_t *pte) {}
static void flush_tlb_fix_spurious_fault(struct vm_area_struct *vma, unsigned long address) {}

static int do_fault(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long address, pte_t *pte, pmd_t *pmd, unsigned int flags, pte_t entry) { return 0; }
static int do_anonymous_page(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long address, pte_t *pte, pmd_t *pmd, unsigned int flags) { return 0; }
static int do_swap_page(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long address, pte_t *pte, pmd_t *pmd, unsigned int flags, pte_t entry) { return 0; }
static int do_numa_page(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long address, pte_t entry, pte_t *pte, pmd_t *pmd) { return 0; }
static int do_wp_page(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long address, pte_t *pte, pmd_t *pmd, spinlock_t *ptl, pte_t entry) { return 0; }