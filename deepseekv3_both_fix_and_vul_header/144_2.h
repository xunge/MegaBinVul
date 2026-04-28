#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

typedef uint64_t __u64;

struct userfaultfd_ctx {
    void *mm;
};

struct uffdio_register {
    __u64 mode;
    struct {
        __u64 start;
        __u64 len;
    } range;
    __u64 ioctls;
};

struct vm_userfaultfd_ctx {
    struct userfaultfd_ctx *ctx;
};

struct mm_struct {
    void *mmap_sem;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    struct vm_area_struct *vm_next;
    unsigned long vm_flags;
    void *anon_vma;
    void *vm_file;
    unsigned long vm_pgoff;
    struct vm_userfaultfd_ctx vm_userfaultfd_ctx;
};

#define UFFDIO_REGISTER_MODE_MISSING    (1 << 0)
#define UFFDIO_REGISTER_MODE_WP         (1 << 1)

#define VM_UFFD_MISSING   0x00000020
#define VM_UFFD_WP        0x00000040
#define VM_MAYWRITE       0x00000080

#define UFFD_API_RANGE_IOCTLS_BASIC     0x1
#define UFFD_API_RANGE_IOCTLS           0x2

#define EFAULT       14
#define EINVAL       22
#define ENOMEM       12
#define EPERM        1
#define EBUSY        16

#define __user

static inline unsigned long min(unsigned long a, unsigned long b) {
    return a < b ? a : b;
}