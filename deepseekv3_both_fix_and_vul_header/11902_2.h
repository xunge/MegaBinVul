#include <stdbool.h>
#include <stddef.h>

#define __user
#define __u64 unsigned long long
#define BUG_ON(cond) ((void)0)
#define WARN_ON(cond) ((void)0)
#define unlikely(x) (x)
#define cond_resched() do {} while (0)
#define down_write(lock) (0)
#define up_write(lock) do {} while (0)
#define mmget_not_zero(mm) (1)
#define mmput(mm) do {} while (0)
#define min(a, b) ((a) < (b) ? (a) : (b))

#define EFAULT 1
#define EINVAL 2
#define ENOMEM 3
#define EPERM 4
#define EBUSY 5

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
    struct vm_userfaultfd_ctx vm_userfaultfd_ctx;
    void *anon_vma;
    void *vm_file;
    unsigned long vm_pgoff;
};

struct uffdio_register {
    __u64 mode;
    struct {
        __u64 start;
        __u64 len;
    } range;
    __u64 ioctls;
};

#define UFFDIO_REGISTER_MODE_MISSING (1 << 0)
#define UFFDIO_REGISTER_MODE_WP (1 << 1)
#define VM_UFFD_MISSING (1 << 0)
#define VM_UFFD_WP (1 << 1)
#define VM_MAYWRITE (1 << 2)
#define UFFD_API_RANGE_IOCTLS_BASIC 1
#define UFFD_API_RANGE_IOCTLS 2

static inline int copy_from_user(void *to, const void *from, size_t n) { return 0; }
static inline int put_user(unsigned long x, void *ptr) { return 0; }
static inline int is_vm_hugetlb_page(struct vm_area_struct *vma) { return 0; }
static inline unsigned long vma_kernel_pagesize(struct vm_area_struct *vma) { return 0; }
static inline int vma_can_userfault(struct vm_area_struct *vma) { return 1; }
static inline int validate_range(struct mm_struct *mm, unsigned long start, unsigned long len) { return 0; }
static inline struct vm_area_struct *find_vma_prev(struct mm_struct *mm, unsigned long addr, struct vm_area_struct **pprev) { return NULL; }
static inline struct vm_area_struct *vma_merge(struct mm_struct *mm, struct vm_area_struct *prev, unsigned long start, unsigned long end, unsigned long vm_flags, void *anon_vma, void *file, unsigned long pgoff, void *policy, struct vm_userfaultfd_ctx ctx) { return NULL; }
static inline int split_vma(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long addr, int new_below) { return 0; }
static inline void *vma_policy(struct vm_area_struct *vma) { return NULL; }