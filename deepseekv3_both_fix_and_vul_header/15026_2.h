#include <stddef.h>
#include <stdint.h>

#define asmlinkage
#define __user

typedef uint32_t u32;
typedef uint32_t __u32;

struct task_struct;
struct pt_regs;

struct user_regs_struct32 {
    uint32_t ebx, ecx, edx, esi, edi, ebp, eax;
    uint32_t ds, es, fs, gs, orig_eax;
    uint32_t eip, cs, eflags, esp, ss;
};

struct user_i387_ia32_struct {
    uint32_t cwd;
    uint32_t swd;
    uint32_t twd;
    uint32_t fip;
    uint32_t fcs;
    uint32_t foo;
    uint32_t fos;
    uint32_t st_space[20];
};

struct user32_fxsr_struct {
    uint16_t cwd;
    uint16_t swd;
    uint16_t twd;
    uint16_t fop;
    uint32_t fip;
    uint32_t fcs;
    uint32_t foo;
    uint32_t fos;
    uint32_t mxcsr;
    uint32_t reserved;
    uint32_t st_space[32];
    uint32_t xmm_space[32];
    uint32_t padding[56];
};

#define REGSET_GENERAL 0
#define REGSET_FP 1
#define REGSET_XFP 2

#define PTRACE_TRACEME 0
#define PTRACE_ATTACH 16
#define PTRACE_KILL 8
#define PTRACE_CONT 7
#define PTRACE_SINGLESTEP 9
#define PTRACE_SINGLEBLOCK 33
#define PTRACE_DETACH 17
#define PTRACE_SYSCALL 24
#define PTRACE_OLDSETOPTIONS 21
#define PTRACE_SETOPTIONS 0x4200
#define PTRACE_SET_THREAD_AREA 25
#define PTRACE_GET_THREAD_AREA 26
#define PTRACE_BTS_CONFIG 0x4201
#define PTRACE_BTS_STATUS 0x4202
#define PTRACE_BTS_SIZE 0x4203
#define PTRACE_BTS_GET 0x4204
#define PTRACE_BTS_CLEAR 0x4205
#define PTRACE_BTS_DRAIN 0x4206
#define PTRACE_PEEKTEXT 1
#define PTRACE_PEEKDATA 2
#define PTRACE_POKEDATA 5
#define PTRACE_POKETEXT 6
#define PTRACE_POKEUSR 4
#define PTRACE_PEEKUSR 3
#define PTRACE_GETREGS 12
#define PTRACE_SETREGS 13
#define PTRACE_SETFPREGS 14
#define PTRACE_GETFPREGS 15
#define PTRACE_SETFPXREGS 18
#define PTRACE_GETFPXREGS 19
#define PTRACE_GETEVENTMSG 0x4201
#define PTRACE_SETSIGINFO 0x4202
#define PTRACE_GETSIGINFO 0x4203

#define EINVAL 22

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-1000))
#define PTR_ERR(x) ((long)(x))
#define ERR_PTR(x) ((void *)(x))

#define compat_ptr(x) ((void __user *)(uintptr_t)(x))

static inline int put_user(__u32 val, __u32 __user *addr) {
    *addr = val;
    return 0;
}

long sys_ptrace(long request, long pid, long addr, long data);
long ptrace32_siginfo(long request, long pid, long addr, long data);
struct task_struct *ptrace_get_task_struct(long pid);
int ptrace_check_attach(struct task_struct *task, int kill);
void put_task_struct(struct task_struct *t);
struct pt_regs *task_pt_regs(struct task_struct *task);
int getreg32(struct task_struct *child, unsigned long addr, __u32 *val);
int putreg32(struct task_struct *child, unsigned long addr, __u32 val);
int copy_regset_to_user(struct task_struct *task, const void *view,
                       unsigned int regset, unsigned int offset, unsigned int size,
                       void __user *data);
int copy_regset_from_user(struct task_struct *task, const void *view,
                         unsigned int regset, unsigned int offset, unsigned int size,
                         const void __user *data);
long compat_ptrace_request(struct task_struct *child, long request, long addr, long data);

extern const void *user_x86_32_view;