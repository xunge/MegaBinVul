#include <stddef.h>
#include <sys/types.h>

typedef unsigned long pgoff_t;
struct mm_struct;
struct vm_area_struct;
typedef struct { unsigned long val; } pte_t;
typedef struct { unsigned long val; } pmd_t;

#define PAGE_MASK (~(0UL))
#define PAGE_SHIFT 12
#define VM_FAULT_SIGBUS 1
#define FAULT_FLAG_WRITE 0x01
#define VM_SHARED 0x00000008

struct vm_operations_struct {
    int (*fault)(struct vm_area_struct *, unsigned long);
};

struct vm_area_struct {
    unsigned long vm_start;
    pgoff_t vm_pgoff;
    unsigned long vm_flags;
    struct vm_operations_struct *vm_ops;
};

static int do_read_fault(struct mm_struct *mm, struct vm_area_struct *vma,
        unsigned long address, pmd_t *pmd, pgoff_t pgoff,
        unsigned int flags, pte_t orig_pte);
static int do_cow_fault(struct mm_struct *mm, struct vm_area_struct *vma,
        unsigned long address, pmd_t *pmd, pgoff_t pgoff,
        unsigned int flags, pte_t orig_pte);
static int do_shared_fault(struct mm_struct *mm, struct vm_area_struct *vma,
        unsigned long address, pmd_t *pmd, pgoff_t pgoff,
        unsigned int flags, pte_t orig_pte);

static inline void pte_unmap(pte_t *pte) {}