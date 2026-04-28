#include <stdbool.h>
#include <stddef.h>

#define __user
#define BUG_ON(cond) ((void)0)
#define WARN_ON(cond) ((void)0)
#define EFAULT 1
#define ENOMEM 2
#define EINVAL 3
#define VM_UFFD_MISSING 0
#define VM_UFFD_WP 0
#define VM_MAYWRITE 0

struct vm_userfaultfd_ctx {
    struct userfaultfd_ctx *ctx;
};

struct userfaultfd_ctx {
    struct mm_struct *mm;
};

struct mm_struct {
    void *mmap_sem;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    struct vm_area_struct *vm_next;
    void *anon_vma;
    void *vm_file;
    unsigned long vm_pgoff;
    struct vm_userfaultfd_ctx vm_userfaultfd_ctx;
};

struct uffdio_range {
    unsigned long start;
    unsigned long len;
};

struct userfaultfd_wake_range {
    unsigned long start;
    unsigned long len;
};

#define NULL_VM_UFFD_CTX ((struct vm_userfaultfd_ctx){NULL})

static inline bool is_vm_hugetlb_page(struct vm_area_struct *vma) { return false; }
static inline unsigned long vma_kernel_pagesize(struct vm_area_struct *vma) { return 0; }
static inline bool vma_can_userfault(struct vm_area_struct *vma) { return false; }
static inline bool userfaultfd_missing(struct vm_area_struct *vma) { return false; }
static inline void wake_userfault(struct userfaultfd_ctx *ctx, struct userfaultfd_wake_range *range) {}
static inline int validate_range(struct mm_struct *mm, unsigned long start, unsigned long len) { return 0; }
static inline int copy_from_user(void *dst, const void *src, size_t size) { return 0; }
static inline bool mmget_not_zero(struct mm_struct *mm) { return true; }
static inline void down_write(void *sem) {}
static inline void up_write(void *sem) {}
static inline void mmput(struct mm_struct *mm) {}
static inline struct vm_area_struct *find_vma_prev(struct mm_struct *mm, unsigned long addr, struct vm_area_struct **pprev) { return NULL; }
static inline struct vm_area_struct *vma_merge(struct mm_struct *mm, struct vm_area_struct *prev, unsigned long start, unsigned long end, unsigned long vm_flags, void *anon_vma, void *file, unsigned long pgoff, void *policy, struct vm_userfaultfd_ctx ctx) { return NULL; }
static inline int split_vma(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long addr, int new_below) { return 0; }
static inline void cond_resched(void) {}
static inline void *vma_policy(struct vm_area_struct *vma) { return NULL; }
static inline unsigned long min(unsigned long a, unsigned long b) { return a < b ? a : b; }