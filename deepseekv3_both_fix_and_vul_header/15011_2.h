#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>

#define VM_READ 0x00000001
#define VM_WRITE 0x00000002
#define VM_MAYREAD 0x00000010
#define VM_MAYWRITE 0x00000020
#define VM_IO 0x00004000
#define VM_LOCKED 0x00002000
#define VM_PFNMAP 0x10000000

#define VM_FAULT_OOM 0x0001
#define VM_FAULT_SIGBUS 0x0002
#define VM_FAULT_MAJOR 0x0004
#define VM_FAULT_WRITE 0x0008
#define VM_FAULT_ERROR (VM_FAULT_OOM | VM_FAULT_SIGBUS)

#define FOLL_WRITE 0x01
#define FOLL_TOUCH 0x02
#define FOLL_GET 0x04
#define FOLL_ANON 0x08

#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define TASK_SIZE ((1UL << 47) - PAGE_SIZE)

#define BUG_ON(condition) do { if (unlikely(condition)) abort(); } while(0)
#define unlikely(x) __builtin_expect(!!(x), 0)

#define ENOMEM 12
#define EFAULT 14

#define TIF_MEMDIE 0

typedef struct {
    unsigned long pgd;
} pgd_t;

typedef struct {
    unsigned long pud;
} pud_t;

typedef struct {
    unsigned long pmd;
} pmd_t;

typedef struct {
    unsigned long pte;
} pte_t;

struct vm_area_struct {
    unsigned long vm_flags;
    unsigned long vm_end;
    struct vm_operations_struct *vm_ops;
};

struct vm_operations_struct {
    int (*fault)();
};

struct task_struct {
    unsigned long maj_flt;
    unsigned long min_flt;
};

struct page;

static inline int pgd_none(pgd_t pgd) { return !pgd.pgd; }
static inline int pud_none(pud_t pud) { return !pud.pud; }
static inline int pmd_none(pmd_t pmd) { return !pmd.pmd; }
static inline int pte_none(pte_t pte) { return !pte.pte; }

struct vm_area_struct *find_extend_vma(struct mm_struct *mm, unsigned long addr);
int in_gate_area(struct task_struct *task, unsigned long addr);
struct vm_area_struct *get_gate_vma(struct task_struct *task);
pgd_t *pgd_offset_k(unsigned long address);
pgd_t *pgd_offset_gate(struct mm_struct *mm, unsigned long address);
pud_t *pud_offset(pgd_t *pgd, unsigned long address);
pmd_t *pmd_offset(pud_t *pud, unsigned long address);
pte_t *pte_offset_map(pmd_t *pmd, unsigned long address);
void pte_unmap(pte_t *pte);
struct page *vm_normal_page(struct vm_area_struct *vma, unsigned long addr, pte_t pte);
void get_page(struct page *page);
int is_vm_hugetlb_page(struct vm_area_struct *vma);
int follow_hugetlb_page(struct mm_struct *mm, struct vm_area_struct *vma,
                       struct page **pages, struct vm_area_struct **vmas,
                       unsigned long *position, int *length, int i, int write);
struct page *follow_page(struct vm_area_struct *vma, unsigned long address,
                        int foll_flags);
int handle_mm_fault(struct mm_struct *mm, struct vm_area_struct *vma,
                   unsigned long address, int write_access);
void flush_anon_page(struct vm_area_struct *vma, struct page *page, unsigned long vmaddr);
void flush_dcache_page(struct page *page);
void cond_resched(void);
int test_tsk_thread_flag(struct task_struct *tsk, int flag);