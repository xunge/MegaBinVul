#include <stddef.h>
#include <linux/types.h>

#define PERF_MAX_STACK_DEPTH 127
#define PERF_CONTEXT_USER 0x01
#define PT_NIP 0
#define PT_LNK 1
#define PT_R1 2

struct pt_regs {
    unsigned long link;
    unsigned long gpr[32];
};

struct perf_callchain_entry {
    unsigned long nr;
    unsigned long ip[PERF_MAX_STACK_DEPTH];
};

struct signal_frame_64 {
    struct ucontext {
        struct mcontext {
            unsigned long gp_regs[48];
        } uc_mcontext;
    } uc;
};

static inline unsigned long perf_instruction_pointer(struct pt_regs *regs) { return regs->link; }
static void perf_callchain_store(struct perf_callchain_entry *entry, unsigned long ip) { entry->ip[entry->nr++] = ip; }
static int valid_user_sp(unsigned long sp, int is_64) { return sp != 0; }
static int read_user_stack_64(const unsigned long *ptr, unsigned long *ret) { *ret = *ptr; return 0; }
static int is_sigreturn_64_address(unsigned long nip, unsigned long frame) { return 0; }
static int sane_signal_64_frame(unsigned long sp) { return 1; }

#define __user