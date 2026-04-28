#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>

#define __user
#define __u64 unsigned long long
#define unlikely(x) (x)

#define VM_UFFD_MISSING 0
#define VM_UFFD_WP 0
#define VM_MAYWRITE 0
#define UFFDIO_REGISTER_MODE_MISSING 0
#define UFFDIO_REGISTER_MODE_WP 0
#define UFFD_API_RANGE_IOCTLS_BASIC 0
#define UFFD_API_RANGE_IOCTLS 0

#define EFAULT 1
#define EINVAL 2
#define ENOMEM 3
#define EPERM 4
#define EBUSY 5

struct userfaultfd_ctx {
    void *mm;
};

struct vm_userfaultfd_ctx {
    struct userfaultfd_ctx *ctx;
};

struct uffdio_register {
    __u64 mode;
    struct {
        __u64 start;
        __u64 len;
    } range;
    __u64 ioctls;
};

struct mm_struct {
    void *mmap;
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
    void *vm_policy;
};

#define BUG_ON(condition) do { if (condition) {} } while (0)
#define WARN_ON(condition) do { if (condition) {} } while (0)
#define cond_resched() do {} while (0)

static inline int mmget_not_zero(void *mm) { return 1; }
static inline void mmput(void *mm) {}
static inline void down_write(void *sem) {}
static inline void up_write(void *sem) {}
static inline struct vm_area_struct *find_vma_prev(void *mm, unsigned long addr, struct vm_area_struct **pprev) { return NULL; }
static inline int is_vm_hugetlb_page(struct vm_area_struct *vma) { return 0; }
static inline unsigned long vma_kernel_pagesize(struct vm_area_struct *vma) { return 0; }
static inline int vma_can_userfault(struct vm_area_struct *vma) { return 1; }
static inline struct vm_area_struct *vma_merge(void *mm, struct vm_area_struct *prev, unsigned long start, unsigned long end, unsigned long vm_flags, void *anon_vma, void *file, unsigned long pgoff, void *policy, struct vm_userfaultfd_ctx ctx) { return NULL; }
static inline int split_vma(void *mm, struct vm_area_struct *vma, unsigned long addr, int new_below) { return 0; }
static inline void *vma_policy(struct vm_area_struct *vma) { return NULL; }
static inline int validate_range(void *mm, unsigned long start, unsigned long len) { return 0; }
static inline int copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static inline int put_user(__u64 val, __u64 *addr) { return 0; }

static inline unsigned long min(unsigned long a, unsigned long b) {
    return a < b ? a : b;
}