#include <sys/types.h>
#include <sys/resource.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <errno.h>

#define N_MAGIC(exec) ((exec).a_info & 0xffff)
#define ZMAGIC 0x010b
#define OMAGIC 0x0407
#define QMAGIC 0x0314
#define NMAGIC 0x0108
#define N_TXTOFF(x) (32)
#define N_TXTADDR(x) (N_MAGIC(x) == QMAGIC ? PAGE_SIZE : 0)
#define N_DATADDR(x) (N_TXTADDR(x) + (x).a_text)
#define N_BSSADDR(x) (N_DATADDR(x) + (x).a_data)
#define N_TRSIZE(x) ((x).a_trsize)
#define N_DRSIZE(x) ((x).a_drsize)
#define N_SYMSIZE(x) ((x).a_syms)
#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define PER_LINUX 0
#define USER_DS 0x4000
#define __USER32_CS 0x23
#define __USER32_DS 0x2B
#define TIF_IA32 0
#define TIF_ABI_PENDING 0
#define PF_FORKNOEXEC 0
#define TASK_UNMAPPED_BASE 0
#define IA32_STACK_TOP 0
#define EXSTACK_DEFAULT 0
#define SIGKILL 9
#define ENOEXEC 8
#define ENOMEM 12
#define fs 0
#define ds 1
#define es 2

struct exec {
    unsigned long a_info;
    unsigned a_text;
    unsigned a_data;
    unsigned a_bss;
    unsigned a_syms;
    unsigned a_entry;
    unsigned a_trsize;
    unsigned a_drsize;
};

struct linux_binprm {
    void *buf;
    struct file *file;
    void *p;
};

struct pt_regs {
    unsigned long cs;
    unsigned long r8, r9, r10, r11, r12, r13, r14, r15;
    unsigned long ip;
    unsigned long sp;
    unsigned long flags;
    unsigned long ss;
};

struct task_struct {
    struct mm_struct *mm;
    unsigned long flags;
    struct {
        struct rlimit rlim[1];
    } *signal;
};

struct mm_struct {
    unsigned long start_code, end_code;
    unsigned long start_data, end_data;
    unsigned long start_brk, brk;
    unsigned long free_area_cache;
    unsigned long cached_hole_size;
    void *mmap;
    void *mmap_sem;
    unsigned long start_stack;
};

struct file {
    struct {
        struct dentry *dentry;
    } f_path;
    struct file_operations *f_op;
};

struct dentry {
    struct inode *d_inode;
    char *d_name;
};

struct inode {
    unsigned long i_size;
};

struct file_operations {
    ssize_t (*read)(struct file *, void *, size_t, loff_t *);
    int (*mmap)(struct file *, void *);
};

struct aout_format {
    int dummy;
};

extern struct task_struct *current;
extern struct aout_format aout_format;

static inline unsigned long i_size_read(struct inode *inode) {
    return inode->i_size;
}

static inline int flush_old_exec(struct linux_binprm *bprm) { return 0; }
static inline void set_personality(int personality) {}
static inline void set_thread_flag(int flag) {}
static inline void clear_thread_flag(int flag) {}
static inline void install_exec_creds(struct linux_binprm *bprm) {}
static inline void down_write(void *sem) {}
static inline void up_write(void *sem) {}
static inline long do_brk(unsigned long addr, unsigned long len) { return 0; }
static inline void send_sig(int sig, struct task_struct *task, int priv) {}
static inline void flush_icache_range(unsigned long start, unsigned long end) {}
static inline long do_mmap(struct file *file, unsigned long addr,
                          unsigned long len, unsigned long prot,
                          unsigned long flags, unsigned long offset) { return 0; }
static inline void set_binfmt(struct aout_format *fmt) {}
static inline void set_brk(unsigned long start, unsigned long end) {}
static inline int setup_arg_pages(struct linux_binprm *bprm,
                                unsigned long stack_top,
                                int executable_stack) { return 0; }
static inline void *create_aout_tables(void *p, struct linux_binprm *bprm) { return 0; }
static inline void loadsegment(int seg, unsigned short val) {}
static inline void load_gs_index(unsigned int index) {}
static inline void set_fs(unsigned long val) {}

#define __user