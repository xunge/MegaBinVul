#include <stddef.h>
#include <string.h>

#define __user
#define PT_NIP 32
#define PT_MSR 33
#define PT_CTR 34
#define PT_LNK 35
#define PT_XER 36
#define PT_CCR 37
#define PT_TRAP 38
#define PT_DAR 39
#define PT_DSISR 40
#define PT_RESULT 41

#define MSR_TS_MASK 0x300000000
#define MSR_LE 0x1
#define MSR_FP 0x2000
#define MSR_FE0 0x4000
#define MSR_FE1 0x8000
#define MSR_VEC 0x2000000
#define MSR_VSX 0x4000000
#define MSR_TM_RESV(msr) ((msr) & 0x8000000000000000)

#define TEXASR_FS 0x80000000
#define ELF_NVRREG 34
#define CPU_FTR_ALTIVEC 0x00000001
#define SPRN_VRSAVE 256
#define VERIFY_READ 0
#define EINVAL 22
#define EFAULT 14

typedef unsigned int u32;
typedef unsigned long vector128[4];
typedef union {
    vector128 v;
    double d[2];
} elf_vrreg_t;

struct pt_regs {
    unsigned long gpr[32];
    unsigned long nip;
    unsigned long msr;
    unsigned long ctr;
    unsigned long link;
    unsigned long xer;
    unsigned long ccr;
    unsigned long trap;
    unsigned long dar;
    unsigned long dsisr;
    unsigned long result;
};

struct ckpt_regs {
    unsigned long ctr;
    unsigned long link;
    unsigned long xer;
    unsigned long ccr;
    unsigned long gpr[32];
};

struct thread_struct {
    struct ckpt_regs ckpt_regs;
    unsigned long tm_tfhar;
    unsigned long vrsave;
    unsigned long transact_vrsave;
    int used_vr;
    union {
        struct {
            double fpr[32][2];
        } fp_state;
        struct {
            vector128 vr[32];
            vector128 vscr;
        } vr_state;
    };
    union {
        struct {
            double fpr[32][2];
        } transact_fp;
        struct {
            vector128 vr[32];
            vector128 vscr;
        } transact_vr;
    };
    unsigned long tm_texasr;
    unsigned long fpexc_mode;
};

struct task_struct {
    struct thread_struct thread;
};

struct sigcontext {
    unsigned long gp_regs[48];
    unsigned long *v_regs;
    unsigned long fp_regs[32];
};

extern struct task_struct *current;

static inline int access_ok(int type, const void *addr, unsigned long size) {
    return 1;
}

static inline unsigned long __copy_from_user(void *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

static inline unsigned long __get_user(unsigned long *val, const void *addr) {
    *val = *(const unsigned long *)addr;
    return 0;
}

static inline void discard_lazy_cpu_state(void) {}
static inline void tm_enable(void) {}
static inline void tm_recheckpoint(struct thread_struct *thread, unsigned long msr) {}
static inline void do_load_up_transact_fpu(struct thread_struct *thread) {}
static inline void do_load_up_transact_altivec(struct thread_struct *thread) {}
static inline int cpu_has_feature(unsigned long feature) { return 1; }
static inline void mtspr(unsigned long spr, unsigned long val) {}
static inline int copy_fpr_from_user(struct task_struct *task, unsigned long fp_regs[32]) { return 0; }
static inline int copy_transact_fpr_from_user(struct task_struct *task, unsigned long fp_regs[32]) { return 0; }
static inline int copy_vsx_from_user(struct task_struct *task, elf_vrreg_t *v_regs) { return 0; }
static inline int copy_transact_vsx_from_user(struct task_struct *task, elf_vrreg_t *v_regs) { return 0; }