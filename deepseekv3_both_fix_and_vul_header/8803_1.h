#include <stdint.h>
#include <string.h>
#include <assert.h>

#define VCPU_SREG_CS 0
#define X86EMUL_CONTINUE 0
#define X86EMUL_UNHANDLEABLE 1
#define X86_TRANSFER_CALL_JMP 0
#define X86EMUL_MODE_PROT64 1

typedef uint8_t u8;

struct desc_struct {
    uint64_t a;
    uint64_t b;
};

struct x86_emulate_ctxt;

struct x86_emulate_ops {
    u8 (*cpl)(struct x86_emulate_ctxt *);
    void (*get_segment)(struct x86_emulate_ctxt *, unsigned short *, struct desc_struct *, void *, int);
    void (*set_segment)(struct x86_emulate_ctxt *, unsigned short, struct desc_struct *, int, int);
};

struct x86_emulate_ctxt {
    const struct x86_emulate_ops *ops;
    int mode;
    int op_bytes;
    struct {
        void *valptr;
        uint64_t val;
    } src;
};

int __load_segment_descriptor(struct x86_emulate_ctxt *, unsigned short, int, u8, int, struct desc_struct *);
int assign_eip_far(struct x86_emulate_ctxt *, uint64_t, struct desc_struct *);
#define WARN_ON(cond) assert(!(cond))