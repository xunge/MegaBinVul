#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdatomic.h>

#define GFP_TEMPORARY 0
#define ENOMEM 12
#define EFAULT 14
#define PAGE_SIZE 4096

struct rw_semaphore {
    atomic_int count;
};

struct mm_struct {
    atomic_int mm_users;
    struct rw_semaphore mmap_sem;
    unsigned long env_start;
    unsigned long env_end;
};

struct file {
    struct mm_struct *private_data;
};

typedef long ssize_t;
typedef long loff_t;

#define __user
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

static void *__get_free_page(int flags) { return NULL; }
static void free_page(unsigned long page) {}
static int atomic_inc_not_zero(atomic_int *v) { return 0; }
static void down_read(struct rw_semaphore *sem) {}
static void up_read(struct rw_semaphore *sem) {}
static int access_remote_vm(struct mm_struct *mm, unsigned long addr, void *buf, size_t size, int write) { return 0; }
static int copy_to_user(void __user *to, const void *from, unsigned long n) { return 0; }
static void mmput(struct mm_struct *mm) {}