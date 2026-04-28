#include <stddef.h>
#include <string.h>

typedef unsigned long vector128[4];
typedef unsigned long u32;

struct pt_regs {
    unsigned long msr;
};

struct mcontext {
    unsigned long mc_gregs[64];
    unsigned long mc_vregs[33];
    unsigned long mc_fregs[32];
    unsigned long mc_vsregs[32];
};

struct thread_struct {
    struct pt_regs ckpt_regs;
    unsigned long tm_tfhar;
    unsigned long vrsave;
    unsigned long transact_vrsave;
    unsigned long tm_texasr;
    unsigned long spefscr;
    unsigned long fpexc_mode;
    unsigned long used_vr;
    unsigned long used_vsr;
    unsigned long used_spe;
    vector128 vr_state[32];
    vector128 transact_vr[32];
    struct {
        double fpr[32][2];
    } fp_state;
    struct {
        double fpr[32][2];
    } transact_fp;
    unsigned long evr[32];
};

#define current (&dummy_current)
static struct {
    struct thread_struct thread;
} dummy_current;

#define CONFIG_VSX
#define CONFIG_ALTIVEC
#define CONFIG_SPE

#define MSR_LE 0x00000001
#define MSR_VEC 0x00000020
#define MSR_FP 0x00000080
#define MSR_FE0 0x00000100
#define MSR_FE1 0x00000200
#define MSR_VSX 0x00000200
#define MSR_SPE 0x00000400
#define MSR_TS_MASK 0x00030000

#define PT_NIP 32
#define PT_MSR 33

#define ELF_NVRREG 34
#define ELF_NEVRREG 34

#define SPRN_VRSAVE 256
#define CPU_FTR_ALTIVEC (1UL << 0)

#define TEXASR_FS 0x08000000
#define TS_VSRLOWOFFSET 1

static inline long restore_general_regs(struct pt_regs *regs, struct mcontext *mc) { return 0; }
static inline long __get_user(unsigned long val, const unsigned long *addr) { return 0; }
static inline long __copy_from_user(void *dest, const void *src, size_t size) { return 0; }
static inline void discard_lazy_cpu_state(void) {}
static inline int cpu_has_feature(unsigned long feature) { return 0; }
static inline void mtspr(unsigned long spr, unsigned long val) {}
static inline long copy_fpr_from_user(void *thread, const void *fregs) { return 0; }
static inline long copy_transact_fpr_from_user(void *thread, const void *fregs) { return 0; }
static inline long copy_vsx_from_user(void *thread, const void *vsregs) { return 0; }
static inline long copy_transact_vsx_from_user(void *thread, const void *vsregs) { return 0; }
static inline void tm_enable(void) {}
static inline void tm_recheckpoint(struct thread_struct *thread, unsigned long msr) {}
static inline void do_load_up_transact_fpu(struct thread_struct *thread) {}
static inline void do_load_up_transact_altivec(struct thread_struct *thread) {}

#define __user