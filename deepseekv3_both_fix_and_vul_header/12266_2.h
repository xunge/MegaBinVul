#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define VCPU_SREG_SS 1
#define GP_VECTOR 13
#define X86EMUL_MODE_PROT64 2
#define X86_TRANSFER_NONE 0

typedef uint16_t u16;
typedef uint8_t u8;

struct x86_emulate_ctxt;

struct x86_emulate_ops {
    u8 (*cpl)(struct x86_emulate_ctxt *);
};

struct x86_emulate_ctxt {
    struct x86_emulate_ops *ops;
    int mode;
};

int emulate_exception(struct x86_emulate_ctxt *ctxt, int vector, int error_code, bool reinject);
int __load_segment_descriptor(struct x86_emulate_ctxt *ctxt, u16 selector, int seg, u8 cpl, int transfer, void *data);