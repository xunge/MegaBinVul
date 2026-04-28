#include <stdint.h>
#include <signal.h>
#include <errno.h>

typedef uint16_t u16;
typedef uint32_t u32;

typedef struct {
    uint32_t sig[2];
} compat_sigset_t;

#define __user
#define __attribute_packed__ __attribute__((packed))

struct pt_regs {
    unsigned long sp;
    unsigned long ip;
    unsigned long ax;
    unsigned long dx;
    unsigned long cx;
    unsigned long cs;
    unsigned long ss;
    unsigned long flags;
};

struct task_struct {
    struct mm_struct *mm;
    struct binprm_struct *binfmt;
    int pid;
    char comm[16];
};

struct mm_struct {
    void *vdso;
};

struct binprm_struct {
    int hasvdso;
};

struct k_sigaction {
    struct sigaction sa;
};

struct sigframe {
    int sig;
    struct sigcontext sc;
    struct _fpstate fpstate;
    unsigned long extramask[1];
    char retcode[8];
    unsigned long pretcode;
};

#define __USER32_DS 0x2B
#define __USER32_CS 0x23
#define USER_DS 0x2B
#define _COMPAT_NSIG_WORDS 2
#define __NR_ia32_sigreturn 0
#define VDSO32_SYMBOL(a, b) 0
#define DEBUG_SIG 0
#define VERIFY_WRITE 1
#define SA_RESTORER 0x04000000
#define X86_EFLAGS_TF 0x00000100
#define X86_EFLAGS_DF 0x00000400
#define TIF_SINGLESTEP 0
#define SIGTRAP 5
#define EFAULT 14

#define current ((struct task_struct *)0)
#define test_thread_flag(flag) 0
#define ptrace_notify(sig) do {} while (0)
#define force_sigsegv(sig, task) do {} while (0)

static inline int access_ok(int type, const void *addr, unsigned long size) { return 1; }
static inline int __put_user(int val, void *ptr) { return 0; }
static inline int __copy_to_user(void *to, const void *from, unsigned long n) { return 0; }
static inline unsigned long ptr_to_compat(const void *ptr) { return (unsigned long)ptr; }
static inline int ia32_setup_sigcontext(struct sigcontext *sc, struct _fpstate *fp, struct pt_regs *regs, unsigned int mask) { return 0; }
static inline void set_fs(unsigned long seg) {}
static inline struct sigframe *get_sigframe(struct k_sigaction *ka, struct pt_regs *regs, size_t size) { return 0; }