#include <stddef.h>
#include <sys/types.h>

#define GFP_TEMPORARY 0
#define PAGE_SIZE 4096
#define ESRCH 3
#define ENOMEM 12
#define EIO 5
#define EFAULT 14

struct inode;
struct dentry {
    struct inode *d_inode;
};
struct path {
    struct dentry *dentry;
};
struct file {
    struct path f_path;
    void *private_data;
};
struct task_struct {
    long self_exec_id;
};
struct mm_struct;

#define __user
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000)
#define PTR_ERR(x) ((long)(x))

extern struct task_struct *current;

static inline void mmput(struct mm_struct *mm) {}
static inline void put_task_struct(struct task_struct *task) {}
static inline void free_page(unsigned long page) {}
static inline struct task_struct *get_proc_task(struct inode *inode) { return NULL; }
static inline struct mm_struct *check_mem_permission(struct task_struct *task) { return NULL; }
static inline int copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static inline int access_remote_vm(struct mm_struct *mm, unsigned long addr, void *buf, int len, int write) { return 0; }
static inline void *__get_free_page(unsigned int flags) { return NULL; }