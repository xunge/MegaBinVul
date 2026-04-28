#include <stddef.h>

enum x86_segment {
    x86_seg_ss,
    x86_seg_cs,
    x86_seg_ds,
    x86_seg_es,
    x86_seg_fs,
    x86_seg_gs
};

enum hvm_access_type {
    HVM_ACCESS_READ,
    HVM_ACCESS_WRITE,
    HVM_ACCESS_EXECUTE
};

struct segment_register {
    unsigned long base;
    unsigned int limit;
    unsigned char attr;
};

struct sh_emulate_ctxt {
    struct {
        unsigned int addr_size;
    } ctxt;
};

#define X86EMUL_UNHANDLEABLE 0
#define X86EMUL_EXCEPTION 1

#define TRAP_stack_error 12
#define TRAP_gp_fault 13

static inline int is_x86_user_segment(enum x86_segment seg) { return seg >= x86_seg_ds; }
static inline const struct segment_register *hvm_get_seg_reg(enum x86_segment seg, struct sh_emulate_ctxt *sh_ctxt) { return NULL; }
static inline int hvm_virtual_to_linear_addr(enum x86_segment seg, const struct segment_register *reg, unsigned long offset, unsigned int bytes, enum hvm_access_type access_type, unsigned int addr_size, unsigned long *paddr) { return 0; }
static inline void hvm_inject_hw_exception(int trap, int error_code) {}