#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct rw_semaphore {
    int dummy;
};

struct mm_struct {
    struct rw_semaphore mmap_sem;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    struct vm_area_struct *vm_next;
    unsigned long vm_flags;
    void *anon_vma;
    void *vm_ops;
    void *vm_file;
};

struct page;

struct mm_slot {
    struct mm_struct *mm;
    struct list_head mm_node;
};

struct khugepaged_scan {
    struct mm_slot *mm_slot;
    unsigned long address;
    struct list_head mm_head;
};

extern struct khugepaged_scan khugepaged_scan;
extern int khugepaged_mm_lock;
extern unsigned long khugepaged_full_scans;

#define VM_BUG_ON(cond) 
#define HPAGE_PMD_MASK (~(HPAGE_PMD_SIZE - 1))
#define HPAGE_PMD_SIZE ((1UL) << 21)
#define HPAGE_PMD_NR (HPAGE_PMD_SIZE / 4096)
#define VM_HUGEPAGE 0x00400000
#define VM_NOHUGEPAGE 0x00800000

static inline int spin_is_locked(int *lock) { return 0; }
static inline void spin_unlock(int *lock) {}
static inline void spin_lock(int *lock) {}
static inline void down_read(struct rw_semaphore *sem) {}
static inline void up_read(struct rw_semaphore *sem) {}
static inline int khugepaged_test_exit(struct mm_struct *mm) { return 0; }
static inline int khugepaged_always(void) { return 0; }
static inline int is_vma_temporary_stack(struct vm_area_struct *vma) { return 0; }
static inline int is_linear_pfn_mapping(struct vm_area_struct *vma) { return 0; }
static inline int is_pfn_mapping(struct vm_area_struct *vma) { return 0; }
static inline void cond_resched(void) {}
static inline void collect_mm_slot(struct mm_slot *mm_slot) {}
static inline int khugepaged_scan_pmd(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long address, struct page **hpage) { return 0; }
static inline struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr) { return NULL; }
#define list_entry(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
#define unlikely(x) (x)