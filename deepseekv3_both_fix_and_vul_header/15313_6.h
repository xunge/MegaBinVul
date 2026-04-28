#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/resource.h>
#include <stddef.h>
#include <stdio.h>

#define PF_FORKNOEXEC 0x00000040
#define PER_LINUX 0
#define ENOEXEC 8
#define ENOMEM 12
#define SIGKILL 9
#define MAP_FIXED 0x10
#define MAP_PRIVATE 0x02
#define MAP_DENYWRITE 0x0800
#define MAP_EXECUTABLE 0x1000
#define PROT_READ 0x1
#define PROT_WRITE 0x2
#define PROT_EXEC 0x4
#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define STACK_TOP ((1UL << 47) - PAGE_SIZE)
#define EXSTACK_DEFAULT 0
#define KERN_NOTICE "<5>"
#define KERN_WARNING "<4>"

struct exec {
    unsigned long a_text;
    unsigned long a_data;
    unsigned long a_bss;
    unsigned long a_entry;
    unsigned long a_gpvalue;
};

struct linux_binprm {
    void *buf;
    struct file *file;
    void *p;
};

struct file {
    struct {
        struct dentry *dentry;
    } f_path;
    struct file_operations *f_op;
};

struct dentry {
    struct {
        char *name;
    } d_name;
    struct inode *d_inode;
};

struct inode {
    unsigned long i_size;
};

struct file_operations {
    int (*mmap)(void);
    ssize_t (*read)(struct file *, void *, size_t, loff_t *);
};

struct mm_struct {
    unsigned long start_code;
    unsigned long end_code;
    unsigned long start_data;
    unsigned long end_data;
    unsigned long start_brk;
    unsigned long brk;
    unsigned long mmap_base;
    unsigned long free_area_cache;
    unsigned long cached_hole_size;
    void *mmap_sem;
    unsigned long start_stack;
};

struct task_struct {
    struct mm_struct *mm;
    unsigned long flags;
    struct signal_struct *signal;
};

struct signal_struct {
    struct rlimit rlim[RLIMIT_NLIMITS];
};

struct pt_regs {
    unsigned long gp;
};

typedef long loff_t;

unsigned long i_size_read(struct inode *inode) {
    return inode->i_size;
}

void down_write(void *sem) {}
void up_write(void *sem) {}
void flush_icache_range(unsigned long start, unsigned long end) {}
void send_sig(int sig, struct task_struct *task, int flags) {}
void set_personality(int personality) {}
long do_brk(unsigned long addr, unsigned long len) { return 0; }
long do_mmap(struct file *file, unsigned long addr, unsigned long len, int prot, int flags, loff_t offset) { return 0; }
int flush_old_exec(struct linux_binprm *bprm) { return 0; }
void install_exec_creds(struct linux_binprm *bprm) {}
int set_brk(unsigned long start, unsigned long end) { return 0; }
int setup_arg_pages(struct linux_binprm *bprm, unsigned long stack_top, int flags) { return 0; }
unsigned long create_aout_tables(void *p, struct linux_binprm *bprm) { return 0; }
void start_thread(struct pt_regs *regs, unsigned long pc, unsigned long sp) {}
void set_binfmt(void *fmt) {}
int printk_ratelimit(void) { return 0; }
void printk(const char *fmt, ...) {}

#define N_MAGIC(ex) (0)
#define ZMAGIC 0
#define OMAGIC 0
#define QMAGIC 0
#define NMAGIC 0
#define N_TRSIZE(ex) (0)
#define N_DRSIZE(ex) (0)
#define N_SYMSIZE(ex) (0)
#define N_TXTOFF(ex) (0)
#define N_TXTADDR(ex) (0)
#define N_DATADDR(ex) (0)
#define N_BSSADDR(ex) (0)

extern struct task_struct *current;
extern struct aout_format aout_format;

#define __user