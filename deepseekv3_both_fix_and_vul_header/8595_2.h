#define FOLL_POPULATE 0x0001
#define FOLL_MLOCK 0x0002
#define FOLL_WRITE 0x0004
#define FOLL_REMOTE 0x0008
#define FOLL_NOWAIT 0x0010
#define FOLL_TRIED 0x0020
#define FOLL_HWPOISON 0x0040
#define FOLL_COW 0x0080

#define VM_FAULT_ERROR 0x0001
#define VM_FAULT_OOM 0x0002
#define VM_FAULT_SIGBUS 0x0004
#define VM_FAULT_SIGSEGV 0x0008
#define VM_FAULT_HWPOISON 0x0010
#define VM_FAULT_HWPOISON_LARGE 0x0020
#define VM_FAULT_MAJOR 0x0040
#define VM_FAULT_RETRY 0x0080
#define VM_FAULT_WRITE 0x0100

#define FAULT_FLAG_WRITE 0x01
#define FAULT_FLAG_REMOTE 0x02
#define FAULT_FLAG_ALLOW_RETRY 0x04
#define FAULT_FLAG_RETRY_NOWAIT 0x08
#define FAULT_FLAG_TRIED 0x10

#define VM_WRITE 0x00000002

#define PAGE_SIZE 4096

#define ENOENT 2
#define ENOMEM 12
#define EFAULT 14
#define EBUSY 16
#define EHWPOISON 133

struct task_struct {
    unsigned long maj_flt;
    unsigned long min_flt;
};

struct vm_area_struct {
    unsigned long vm_flags;
};

static inline int stack_guard_page_start(struct vm_area_struct *vma, unsigned long addr) { return 0; }
static inline int stack_guard_page_end(struct vm_area_struct *vma, unsigned long addr) { return 0; }
static inline int handle_mm_fault(struct vm_area_struct *vma, unsigned long address, unsigned int flags) { return 0; }
#define VM_WARN_ON_ONCE(cond) do { } while (0)
#define BUG() do { } while (0)