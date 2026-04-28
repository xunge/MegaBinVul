#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>

#define GFP_KERNEL 0
#define ENOMEM 12
#define EFAULT 14
#define FOLL_ANON 0
#define PAGE_SIZE 4096

typedef long ssize_t;
typedef long loff_t;
#define __user

struct mm_struct {
    unsigned long env_start;
    unsigned long env_end;
    void *private_data;
    int mmap_sem;
};

struct file {
    struct mm_struct *private_data;
};

static inline void free_page(unsigned long page) {}
static inline void *__get_free_page(int flags) { return NULL; }
static inline int mmget_not_zero(struct mm_struct *mm) { return 0; }
static inline void down_read(int *sem) {}
static inline void up_read(int *sem) {}
static inline int access_remote_vm(struct mm_struct *mm, unsigned long addr, void *buf, size_t size, int flags) { return 0; }
static inline int copy_to_user(void *to, const void *from, size_t n) { return 0; }
static inline void mmput(struct mm_struct *mm) {}

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))