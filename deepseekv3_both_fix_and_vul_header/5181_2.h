#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define PAGE_SHIFT 12
#define VM_GROWSDOWN 0x00000100
#define VM_WRITE 0x00000002
#define VM_READ 0x00000001
#define VM_EXEC 0x00000004
#define VM_LOCKED 0x00002000
#define EPERM 1
#define ENOMEM 12

#define unlikely(x) (x)

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_pgoff;
    unsigned long vm_flags;
    struct vm_area_struct *vm_prev;
    struct vm_area_struct *vm_next;
    struct mm_struct *vm_mm;
    struct anon_vma *anon_vma;
};

struct mm_struct {
    unsigned long mmap_min_addr;
    unsigned long locked_vm;
    struct {
        int lock;
    } page_table_lock;
};

struct anon_vma;

static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}

int anon_vma_prepare(struct vm_area_struct *vma) { return 0; }
void anon_vma_lock_write(struct anon_vma *anon_vma) {}
void anon_vma_unlock_write(struct anon_vma *anon_vma) {}
void anon_vma_interval_tree_pre_update_vma(struct vm_area_struct *vma) {}
void anon_vma_interval_tree_post_update_vma(struct vm_area_struct *vma) {}
int acct_stack_growth(struct vm_area_struct *vma, unsigned long size, unsigned long grow) { return 0; }
void vm_stat_account(struct mm_struct *mm, unsigned long flags, unsigned long pages) {}
void vma_gap_update(struct vm_area_struct *vma) {}
void perf_event_mmap(struct vm_area_struct *vma) {}
void khugepaged_enter_vma_merge(struct vm_area_struct *vma, unsigned long flags) {}
void validate_mm(struct mm_struct *mm) {}

unsigned long stack_guard_gap;
unsigned long mmap_min_addr;