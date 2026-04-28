#include <stddef.h>

typedef unsigned long pte_t;
typedef unsigned long cpumask_t;

struct mm_context {
    unsigned long id;
    unsigned long user_psize;
    unsigned long sllp;
};

struct mm_struct {
    struct mm_context context;
    void *pgd;
    cpumask_t cpu_vm_mask;
};

#define unlikely(x) (x)
#define DBG_LOW(fmt, ...)
#define CONFIG_PPC_64K_PAGES
#define CONFIG_SPE_BASE
#define MMU_PAGE_4K 0
#define MMU_PAGE_64K 1
#define SLB_VSID_USER 0
#define _PAGE_NO_CACHE (1UL << 0)

struct mmu_psize_def {
    unsigned long sllp;
};
extern struct mmu_psize_def mmu_psize_defs[];
extern int mmu_ci_restrictions;

struct paca_struct {
    struct mm_context context;
};
#define get_paca() ((struct paca_struct *)0)

static inline unsigned long pte_val(pte_t pte) { return pte; }

int in_hugepage_area(struct mm_context context, unsigned long ea);
pte_t *find_linux_pte(void *pgdir, unsigned long ea);
unsigned long get_vsid(unsigned long context_id, unsigned long ea);
int smp_processor_id(void);
cpumask_t cpumask_of_cpu(int cpu);
int cpus_equal(cpumask_t a, cpumask_t b);
void local_irq_save(unsigned long flags);
void local_irq_restore(unsigned long flags);
void __hash_page_4K(unsigned long ea, unsigned long access, unsigned long vsid, pte_t *ptep, unsigned long trap, int local);
void __hash_page_64K(unsigned long ea, unsigned long access, unsigned long vsid, pte_t *ptep, unsigned long trap, int local);
void slb_flush_and_rebolt(void);
void spu_flush_all_slbs(struct mm_struct *mm);