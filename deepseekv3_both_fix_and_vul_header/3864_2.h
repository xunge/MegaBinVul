#include <stddef.h>
#include <stdbool.h>

#define FOLL_WRITE 0x01
#define FOLL_DUMP 0x02
#define TASK_SIZE ((1UL << 47) - 4096)
#define ENOMEM 12
#define EFAULT 14
#define VM_BUG_ON(cond) do { if (cond) {} } while (0)
#define unlikely(x) (x)

struct mm_struct;
struct vm_area_struct;
struct page;

typedef struct { unsigned long pgd; } pgd_t;
typedef struct { unsigned long p4d; } p4d_t;
typedef struct { unsigned long pud; } pud_t;
typedef struct { unsigned long pmd; } pmd_t;
typedef struct { unsigned long pte; } pte_t;

static inline bool pgd_none(pgd_t pgd) { return !pgd.pgd; }
static inline bool p4d_none(p4d_t p4d) { return !p4d.p4d; }
static inline bool pud_none(pud_t pud) { return !pud.pud; }
static inline bool pmd_present(pmd_t pmd) { return pmd.pmd; }
static inline bool pte_none(pte_t pte) { return !pte.pte; }
static inline bool pmd_trans_huge(pmd_t pmd) { return false; }

static inline pgd_t *pgd_offset_k(unsigned long address) { return NULL; }
static inline pgd_t *pgd_offset_gate(struct mm_struct *mm, unsigned long address) { return NULL; }
static inline p4d_t *p4d_offset(pgd_t *pgd, unsigned long address) { return NULL; }
static inline pud_t *pud_offset(p4d_t *p4d, unsigned long address) { return NULL; }
static inline pmd_t *pmd_offset(pud_t *pud, unsigned long address) { return NULL; }
static inline pte_t *pte_offset_map(pmd_t *pmd, unsigned long address) { return NULL; }
static inline void pte_unmap(pte_t *pte) {}
static inline struct vm_area_struct *get_gate_vma(struct mm_struct *mm) { return NULL; }
static inline struct page *vm_normal_page(struct vm_area_struct *vma, unsigned long address, pte_t pte) { return NULL; }
static inline int is_zero_pfn(unsigned long pfn) { return 0; }
static inline unsigned long pte_pfn(pte_t pte) { return 0; }
static inline struct page *pte_page(pte_t pte) { return NULL; }
static inline int try_get_page(struct page *page) { return 0; }