#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>

#define __user
#define BUG_ON(cond) ((void)0)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define WARN_ON(cond) ((void)0)

struct vm_userfaultfd_ctx {
    struct userfaultfd_ctx *ctx;
};

struct userfaultfd_ctx {
    struct mm_struct *mm;
};

struct mm_struct {
    struct vm_area_struct *mmap;
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

struct uffdio_range {
    unsigned long start;
    unsigned long len;
};

struct userfaultfd_wake_range {
    unsigned long start;
    unsigned long len;
};

#define VM_UFFD_MISSING 0
#define VM_UFFD_WP 0
#define VM_MAYWRITE 0
#define NULL_VM_UFFD_CTX ((struct vm_userfaultfd_ctx) { NULL })

#define ENOMEM 12
#define EINVAL 22
#define EFAULT 14

static int validate_range(struct mm_struct *mm, unsigned long start, unsigned long len) { return 0; }
static bool is_vm_hugetlb_page(struct vm_area_struct *vma) { return false; }
static unsigned long vma_kernel_pagesize(struct vm_area_struct *vma) { return 0; }
static bool vma_can_userfault(struct vm_area_struct *vma) { return true; }
static bool userfaultfd_missing(struct vm_area_struct *vma) { return false; }
static void wake_userfault(struct userfaultfd_ctx *ctx, struct userfaultfd_wake_range *range) {}
static struct vm_area_struct *vma_merge(struct mm_struct *mm, struct vm_area_struct *prev,
                                      unsigned long start, unsigned long end, unsigned long flags,
                                      void *anon_vma, void *file, unsigned long pgoff,
                                      void *policy, struct vm_userfaultfd_ctx uffd_ctx) { return NULL; }
static int split_vma(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long addr, int new_below) { return 0; }
static void up_write(void *sem) {}
static void down_write(void *sem) {}
static void mmput(struct mm_struct *mm) {}
static bool mmget_not_zero(struct mm_struct *mm) { return true; }
static void cond_resched(void) {}
static struct vm_area_struct *find_vma_prev(struct mm_struct *mm, unsigned long addr, struct vm_area_struct **pprev) { return NULL; }
static int copy_from_user(void *to, const void __user *from, unsigned long n) { return 0; }
static void *vma_policy(struct vm_area_struct *vma) { return vma->vm_policy; }