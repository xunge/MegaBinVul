#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

struct som_hdr {
    unsigned int aux_header_size;
    unsigned int aux_header_location;
};

struct som_exec_auxhdr {
    unsigned long exec_entry;
};

struct linux_binprm {
    char *buf;
    struct file *file;
    unsigned long p;
};

struct pt_regs;
struct file;

struct thread_struct {
    unsigned long task_size;
    unsigned long map_base;
};

struct mm_struct {
    unsigned long start_stack;
    unsigned long start_brk;
    unsigned long end_code;
    unsigned long start_code;
    unsigned long end_data;
    unsigned long brk;
};

struct task_struct {
    unsigned int flags;
    unsigned int personality;
    struct thread_struct thread;
    struct mm_struct *mm;
};

#define SOM_PAGESIZE 4096
#define GFP_KERNEL 0
#define ENOMEM 12
#define EIO 5
#define PF_FORKNOEXEC 0x00000040
#define PER_HPUX 0
#define STACK_TOP 0
#define EXSTACK_DEFAULT 0

extern struct task_struct *current;
extern int check_som_header(struct som_hdr *som_ex);
extern void *kmalloc(size_t size, int flags);
extern void kfree(void *ptr);
extern int kernel_read(struct file *file, unsigned long offset, char *addr, unsigned long count);
extern int flush_old_exec(struct linux_binprm *bprm);
extern int map_som_binary(struct file *file, struct som_exec_auxhdr *hpuxhdr);
extern void set_binfmt(void *fmt);
extern void install_exec_creds(struct linux_binprm *bprm);
extern void setup_arg_pages(struct linux_binprm *bprm, unsigned long stack_top, int executable_stack);
extern void create_som_tables(struct linux_binprm *bprm);
extern void map_hpux_gateway_page(struct task_struct *tsk, struct mm_struct *mm);
extern void start_thread_som(struct pt_regs *regs, unsigned long pc, unsigned long sp);

static struct {
    int dummy;
} som_format;