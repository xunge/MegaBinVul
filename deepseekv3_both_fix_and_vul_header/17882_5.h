#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <errno.h>

#define GFP_TEMPORARY 0
#define PAGE_SIZE 4096
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define ESRCH 3
#define ENOMEM 12
#define EIO 5
#define EFAULT 14

typedef long ssize_t;
typedef long loff_t;

struct file {
    void *private_data;
    struct {
        struct {
            struct {
                void *d_inode;
            } *dentry;
        } f_path;
    };
};

struct task_struct {
    long self_exec_id;
};

struct mm_struct {};

extern struct task_struct *get_proc_task(void *);
extern struct mm_struct *check_mem_permission(struct task_struct *);
extern void mmput(struct mm_struct *);
extern void put_task_struct(struct task_struct *);
extern int access_remote_vm(struct mm_struct *, unsigned long, char *, int, int);
extern int copy_to_user(void *, const void *, unsigned long);
extern void free_page(unsigned long);
extern struct task_struct *current;
extern void *__get_free_page(int);

#define __user