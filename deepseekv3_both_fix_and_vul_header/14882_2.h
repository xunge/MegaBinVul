#include <stddef.h>
#include <stdint.h>
#include <signal.h>
#include <sys/ucontext.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct thread_info {
    struct exec_domain *exec_domain;
};

struct rt_sigframe {
    siginfo_t info;
    ucontext_t uc;
    void *pretcode;
};

struct k_sigaction {
    struct sigaction sa;
};

struct exec_domain {
    unsigned int signal_invmap[32];
};

struct pt_regs {
    unsigned long sp;
    unsigned long ip;
    unsigned long ax;
    unsigned long dx;
    unsigned long cx;
    unsigned long flags;
    unsigned long cs;
    unsigned long ss;
};

struct task_struct {
    void *sas_ss_sp;
    size_t sas_ss_size;
    struct mm_struct *mm;
    char comm[16];
    int pid;
};

struct mm_struct {
    struct vdso_image *context;
};

struct vdso_image {
    void *vdso;
};

typedef uint32_t compat_sigset_t;

#define __user
#define __attribute_packed__ __attribute__((packed))
#define VERIFY_WRITE 1
#define SA_RESTORER 0x04000000
#define __NR_ia32_rt_sigreturn 173
#define X86_EFLAGS_TF 0x00000100
#define X86_EFLAGS_DF 0x00000400
#define TIF_SINGLESTEP 4
#define SIGTRAP 5
#define EFAULT 14
#define DEBUG_SIG 0
#define __USER32_DS 0x2B
#define __USER32_CS 0x23
#define USER_DS 0x2B

#define current_thread_info() ((struct thread_info *)0)
#define current ((struct task_struct *)0)
#define sas_ss_flags(sp) 0
#define force_sigsegv(sig, tsk) do { } while (0)
#define ptrace_notify(sig) do { } while (0)
#define test_thread_flag(flag) 0
#define set_fs(fs) do { } while (0)
#define __copy_to_user(dst, src, size) 0
#define __put_user(x, ptr) 0
#define access_ok(type, addr, size) 1
#define ptr_to_compat(ptr) ((unsigned int)(ptr))
#define VDSO32_SYMBOL(mm, sym) 0
#define get_sigframe(ka, regs, size) ((void *)0)
#define copy_siginfo_to_user32(dst, src) 0
#define ia32_setup_sigcontext(mc, fp, regs, mask) 0