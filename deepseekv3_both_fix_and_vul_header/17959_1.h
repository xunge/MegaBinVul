#include <stdint.h>

typedef struct {
    uintptr_t pgd;
} pgd_t;

typedef struct {
    uintptr_t pud;
} pud_t;

typedef struct {
    uintptr_t pmd;
} pmd_t;

typedef struct {
    uintptr_t pte;
} pte_t;

typedef struct {
    int lock;
} spinlock_t;

struct rw_semaphore {
    int count;
};

struct mm_struct {
    struct rw_semaphore mmap_sem;
};

#define pgd_offset(mm, addr) ((pgd_t *)(addr))
#define pud_offset(pgd, addr) ((pud_t *)(addr))
#define pmd_offset(pud, addr) ((pmd_t *)(addr))
#define pte_offset_map_lock(mm, pmd, addr, ptl) ((pte_t *)(addr))
#define pte_unmap_unlock(pte, ptl) do {} while(0)
#define pgd_none_or_clear_bad(pgd) (0)
#define pud_none_or_clear_bad(pud) (0)
#define pmd_none_or_clear_bad(pmd) (0)
#define pte_present(pte) (1)
#define pte_wrprotect(pte) (pte)
#define set_pte(pte, val) do {} while(0)
#define split_huge_page_pmd(mm, pmd) do {} while(0)
#define down_write(sem) do {} while(0)
#define up_write(sem) do {} while(0)
#define flush_tlb() do {} while(0)