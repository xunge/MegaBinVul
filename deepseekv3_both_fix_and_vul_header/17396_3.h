#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>

#define GFP_KERNEL 0
#define FOLL_ANON 0x100
#define ESRCH 3
#define ENOMEM 12
#define EFAULT 14
#define PAGE_SIZE 4096

typedef long ssize_t;
typedef unsigned long size_t;

struct file;
struct inode;

struct task_struct {
    // dummy structure
};

struct rw_semaphore {
    // dummy structure
};

struct mm_struct {
    unsigned long arg_start;
    unsigned long arg_end;
    unsigned long env_start;
    unsigned long env_end;
    struct rw_semaphore mmap_sem;
};

#define BUG_ON(condition) ((void)0)
#define __user

static inline void *__get_free_page(int flags) { return malloc(PAGE_SIZE); }
static inline void free_page(unsigned long addr) { free((void *)addr); }
static inline int copy_to_user(void *to, const void *from, unsigned long n) { return 0; }
static inline struct task_struct *get_proc_task(struct inode *inode) { return NULL; }
static inline struct mm_struct *get_task_mm(struct task_struct *task) { return NULL; }
static inline void put_task_struct(struct task_struct *task) {}
static inline void mmput(struct mm_struct *mm) {}
static inline int access_remote_vm(struct mm_struct *mm, unsigned long addr, void *buf, int len, unsigned int gup_flags) { return 0; }
static inline void down_read(struct rw_semaphore *sem) {}
static inline void up_read(struct rw_semaphore *sem) {}
static inline struct inode *file_inode(struct file *file) { return NULL; }

#define min(x, y) ((x) < (y) ? (x) : (y))
#define min3(x, y, z) min((x), min((y), (z)))