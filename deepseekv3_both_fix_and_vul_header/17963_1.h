#include <stddef.h>
#include <sys/types.h>
#include <stdint.h>

typedef struct mmu_gather mmu_gather;
typedef struct vm_area_struct vm_area_struct;
typedef struct zap_details zap_details;
typedef uint64_t pud_t;
typedef uint64_t pmd_t;

struct rw_semaphore;
struct mm_struct {
    struct rw_semaphore *mmap_sem;
};

struct vm_area_struct {
    struct mm_struct *vm_mm;
};

struct mmu_gather {
    struct mm_struct *mm;
};

#define HPAGE_PMD_SIZE (1UL << 21)
#define VM_BUG_ON(cond) ((void)0)

static inline pmd_t *pmd_offset(pud_t *pud, unsigned long addr) { return NULL; }
static inline unsigned long pmd_addr_end(unsigned long addr, unsigned long end) { return 0; }
static inline int pmd_trans_huge(pmd_t pmd) { return 0; }
static inline int rwsem_is_locked(struct rw_semaphore *sem) { return 0; }
static inline void split_huge_page_pmd(struct mm_struct *mm, pmd_t *pmd) {}
static inline int zap_huge_pmd(struct mmu_gather *tlb, struct vm_area_struct *vma, pmd_t *pmd, unsigned long addr) { return 0; }
static inline int pmd_none_or_clear_bad(pmd_t *pmd) { return 0; }
static inline unsigned long zap_pte_range(struct mmu_gather *tlb, struct vm_area_struct *vma, pmd_t *pmd, unsigned long addr, unsigned long end, struct zap_details *details) { return 0; }
static inline void cond_resched(void) {}