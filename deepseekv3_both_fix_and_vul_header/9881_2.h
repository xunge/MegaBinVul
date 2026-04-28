#include <stddef.h>
#include <stdbool.h>

struct page;
struct mm_struct {
    void *mmap_sem;
};
struct vm_area_struct {
    struct vm_area_struct *vm_next;
    unsigned long vm_flags;
    void *anon_vma;
    void *vm_ops;
    void *vm_file;
    unsigned long vm_start;
    unsigned long vm_end;
};

struct list_head {
    struct list_head *next, *prev;
};

struct mm_slot {
    struct mm_struct *mm;
    struct list_head mm_node;
};

struct khugepaged_scan {
    struct mm_slot *mm_slot;
    unsigned long address;
    struct list_head mm_head;
};

static struct khugepaged_scan khugepaged_scan;
static int khugepaged_mm_lock;
static unsigned long khugepaged_full_scans;

#define VM_BUG_ON(cond) ((void)0)
#define BUG_ON(cond) ((void)0)
#define HPAGE_PMD_MASK (~(HPAGE_PMD_SIZE - 1))
#define HPAGE_PMD_NR (HPAGE_PMD_SIZE / PAGE_SIZE)
#define HPAGE_PMD_SIZE (1UL << 21)
#define PAGE_SIZE 4096
#define VM_HUGEPAGE 0x00400000
#define VM_NOHUGEPAGE 0x00800000
#define likely(x) (x)
#define unlikely(x) (x)

static inline bool spin_is_locked(int *lock) { return true; }
static inline void spin_unlock(int *lock) {}
static inline void spin_lock(int *lock) {}
static inline bool khugepaged_test_exit(struct mm_struct *mm) { return false; }
static inline bool khugepaged_always(void) { return false; }
static inline bool is_linear_pfn_mapping(struct vm_area_struct *vma) { return false; }
static inline bool is_pfn_mapping(struct vm_area_struct *vma) { return false; }
static void collect_mm_slot(struct mm_slot *mm_slot) {}
static int khugepaged_scan_pmd(struct mm_struct *mm, struct vm_area_struct *vma,
                              unsigned long address, struct page **hpage) { return 0; }
static void down_read(void *sem) {}
static void up_read(void *sem) {}
static void cond_resched(void) {}
static struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr) { return NULL; }

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))