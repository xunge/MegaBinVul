#include <elf.h>
#include <fcntl.h>
#include <signal.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define ELFMAG "\177ELF"
#define SELFMAG 4

#define ET_EXEC 2
#define ET_DYN 3

#define PT_INTERP 3
#define PT_GNU_STACK 0x6474e551
#define PT_LOAD 1

#define PAGE_SIZE 4096
#define PATH_MAX 4096
#define BINPRM_BUF_SIZE 128

#define GFP_KERNEL 0
#define ENOMEM 12
#define ENOEXEC 8
#define EIO 5
#define ELIBBAD 80
#define EINVAL 22
#define EFAULT 14

#define IS_ERR(x) ((unsigned long)(x) >= (unsigned long)-4096)
#define PTR_ERR(x) ((long)(x))
#define BAD_ADDR(x) ((unsigned long)(x) >= TASK_SIZE)

#define EXSTACK_DEFAULT 0
#define EXSTACK_DISABLE_X 1
#define EXSTACK_ENABLE_X 2

#define PROT_READ 0x1
#define PROT_WRITE 0x2
#define PROT_EXEC 0x4

#define SIGKILL 9
#define SIGSEGV 11

#define MAY_READ 1
#define BINPRM_FLAGS_ENFORCE_NONDUMP (1 << 0)
#define PF_FORKNOEXEC (1 << 0)
#define READ_IMPLIES_EXEC (1 << 0)
#define ADDR_NO_RANDOMIZE (1 << 0)
#define PF_RANDOMIZE (1 << 0)
#define MMAP_PAGE_ZERO (1 << 0)

#define ELF_ET_DYN_BASE (TASK_SIZE / 3 * 2)
#define ELF_MIN_ALIGN PAGE_SIZE
#define ELF_PAGESTART(_v) ((_v) & ~(unsigned long)(ELF_MIN_ALIGN-1))
#define ELF_PAGEOFFSET(_v) ((_v) & (ELF_MIN_ALIGN-1))

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

struct linux_binprm {
    void *buf;
    struct file *file;
    unsigned long p;
    unsigned interp_flags;
};

struct pt_regs {
    unsigned long dummy;
};

struct elfhdr {
    unsigned char e_ident[16];
    unsigned short e_type;
    unsigned short e_machine;
    unsigned long e_entry;
    unsigned long e_phoff;
    unsigned short e_phentsize;
    unsigned short e_phnum;
};

struct elf_phdr {
    unsigned long p_type;
    unsigned long p_offset;
    unsigned long p_vaddr;
    unsigned long p_filesz;
    unsigned long p_memsz;
    unsigned long p_flags;
};

struct file {
    struct file_operations *f_op;
};

struct file_operations {
    int (*mmap)(void);
};

struct task_struct {
    unsigned long flags;
    struct mm_struct *mm;
    unsigned personality;
};

struct mm_struct {
    unsigned long def_flags;
    unsigned long start_code;
    unsigned long end_code;
    unsigned long start_data;
    unsigned long end_data;
    unsigned long start_stack;
    unsigned long brk;
    unsigned long start_brk;
    unsigned long free_area_cache;
    unsigned long cached_hole_size;
    unsigned long mmap_base;
    void *mmap_sem;
};

#define current ((struct task_struct *)0)
#define TASK_SIZE ((unsigned long)-1)
#define STACK_TOP 0

struct elf_format {
    int dummy;
};

static void *kmalloc(size_t size, int flags) { return malloc(size); }
static void kfree(void *ptr) { free(ptr); }
static int kernel_read(struct file *file, unsigned long offset, char *addr, unsigned long count) { return 0; }
static struct file *open_exec(const char *name) { return NULL; }
static int file_permission(struct file *file, int mask) { return 0; }
static void fput(struct file *file) {}
static void allow_write_access(struct file *file) {}
static int set_brk(unsigned long start, unsigned long end) { return 0; }
static int padzero(unsigned long addr) { return 0; }
static int flush_old_exec(struct linux_binprm *bprm) { return 0; }
static void send_sig(int sig, struct task_struct *p, int priv) {}
static void force_sig(int sig, struct task_struct *p) {}
static int setup_arg_pages(struct linux_binprm *bprm, unsigned long stack_top, int executable_stack) { return 0; }
static unsigned long randomize_stack_top(unsigned long stack_top) { return stack_top; }
static void arch_pick_mmap_layout(struct mm_struct *mm) {}
static int create_elf_tables(struct linux_binprm *bprm, struct elfhdr *elf_ex, unsigned long load_addr, unsigned long interp_load_addr) { return 0; }
static void install_exec_creds(struct linux_binprm *bprm) {}
static void set_binfmt(void *fmt) {}
static int elf_check_arch(struct elfhdr *hdr) { return 1; }
static int elf_read_implies_exec(struct elfhdr hdr, int executable_stack) { return 0; }
static void SET_PERSONALITY(struct elfhdr hdr) {}
static void start_thread(struct pt_regs *regs, unsigned long pc, unsigned long sp) {}
static unsigned long load_elf_interp(struct elfhdr *hdr, struct file *interp, unsigned long *interp_map_addr, unsigned long load_bias) { return 0; }
static unsigned long elf_map(struct file *file, unsigned long addr, struct elf_phdr *phdr, int prot, int flags, int offset) { return 0; }
static unsigned long randomize_va_space = 0;
static struct elf_format elf_format;

static int clear_user(void *to, unsigned long n) { return 0; }
static void down_write(void *sem) {}
static void up_write(void *sem) {}
static unsigned long do_mmap(void *addr, unsigned long len, unsigned long prot, unsigned long flags, unsigned long fd, unsigned long off) { return 0; }

/* Remove __user attribute */
#define __user

/* Fix uninitialized_var macro */
#define uninitialized_var(x) x = 0