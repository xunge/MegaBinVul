#include <string.h>
#include <stddef.h>

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)

typedef struct {
    unsigned long pmd;
} pmd_t;

typedef struct {
    unsigned long pte;
} pte_t;

typedef struct {
    unsigned long entry;
} swp_entry_t;

struct spinlock {
    int lock;
};
typedef struct spinlock spinlock_t;

struct mm_walk {
    struct vm_area_struct *vma;
    void *private;
    void *mm;
};

struct vm_area_struct {
    // minimal stub
};

static spinlock_t* pmd_trans_huge_lock(pmd_t *pmd, struct vm_area_struct *vma) { return NULL; }
static int pmd_trans_unstable(pmd_t *pmd) { return 0; }
static void __mincore_unmapped_range(unsigned long addr, unsigned long end, 
                                   struct vm_area_struct *vma, unsigned char *vec) {}
static pte_t* pte_offset_map_lock(void *mm, pmd_t *pmd, unsigned long addr, 
                                spinlock_t **ptl) { return NULL; }
static int pte_none(pte_t pte) { return 0; }
static int pte_present(pte_t pte) { return 0; }
static swp_entry_t pte_to_swp_entry(pte_t pte) { return (swp_entry_t){0}; }
static int non_swap_entry(swp_entry_t entry) { return 0; }
static void pte_unmap_unlock(pte_t *pte, spinlock_t *ptl) {}
static void spin_unlock(spinlock_t *lock) {}
static void cond_resched(void) {}
static void WARN_ON(int condition) {}

#ifdef CONFIG_SWAP
static unsigned char mincore_page(void *mapping, unsigned long offset) { return 0; }
static void* swap_address_space(swp_entry_t entry) { return NULL; }
static unsigned long swp_offset(swp_entry_t entry) { return 0; }
#endif