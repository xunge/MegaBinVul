#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define CORENAME_MAX_SIZE 64
#define RLIMIT_CORE 4
#define RLIM_INFINITY (~0UL)
#define GFP_KERNEL 0
#define KERN_NOTICE ""
#define KERN_INFO ""
#define TIF_SIGPENDING 0
#define O_LARGEFILE 0100000

struct pt_regs;
struct mm_struct;
struct linux_binfmt;
struct inode;
struct file;
struct task_struct;

struct rlimit {
    unsigned long rlim_cur;
};

struct signal_struct {
    struct rlimit rlim[RLIMIT_CORE+1];
    int group_exit_code;
};

struct task_struct {
    struct mm_struct *mm;
    int fsuid;
    struct signal_struct *signal;
    struct linux_binfmt *binfmt;
    char comm[16];
};

struct file_operations {
    int (*write)();
};

struct file {
    struct {
        struct {
            struct inode *d_inode;
        } *dentry;
    } f_path;
    struct file_operations *f_op;
};

struct linux_binfmt {
    int (*core_dump)(long, struct pt_regs *, struct file *, unsigned long);
    unsigned long min_coredump;
};

struct mm_struct {
    void *mmap_sem;
    int core_waiters;
    void *core_done;
};

struct inode {
    int i_nlink;
    int i_mode;
    int i_uid;
};

#define S_ISREG(mode) (((mode) & S_IFMT) == S_IFREG)

extern struct task_struct *current;
extern char core_pattern[];