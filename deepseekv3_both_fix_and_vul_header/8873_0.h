#include <stdint.h>

struct desc_ptr {
    uint16_t size;
    uintptr_t address;
};

struct segmented_addr {
    uintptr_t mem;
};

struct operand {
    int type;
    struct segmented_addr addr;
};

struct x86_emulate_ctxt {
    int mode;
    int op_bytes;
    struct operand dst;
};

#define X86EMUL_MODE_PROT64 1
#define OP_NONE 0

int segmented_write(struct x86_emulate_ctxt *ctxt, uintptr_t addr, void *data, int size);