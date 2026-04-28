#include <stddef.h>
#include <string.h>
#include <stdbool.h>

enum es_result {
    ES_DECODE_FAILED,
    ES_UNSUPPORTED
};

enum insn_mmio_type {
    INSN_MMIO_DECODE_FAILED,
    INSN_MMIO_WRITE_IMM,
    INSN_MMIO_MOVS,
    INSN_MMIO_WRITE,
    INSN_MMIO_READ,
    INSN_MMIO_READ_ZERO_EXTEND,
    INSN_MMIO_READ_SIGN_EXTEND
};

typedef unsigned char u8;
typedef unsigned short u16;

struct insn {
    unsigned int opnd_bytes;
    union {
        char bytes[8];
    } immediate1;
};

struct ghcb {
    char shared_buffer[64];
};

struct es_em_ctxt {
    struct insn insn;
    void *regs;
};

static enum insn_mmio_type insn_decode_mmio(struct insn *insn, unsigned int *bytes);
static long *insn_get_modrm_reg_ptr(struct insn *insn, void *regs);
static enum es_result vc_do_mmio(struct ghcb *ghcb, struct es_em_ctxt *ctxt, unsigned int bytes, bool read);
static enum es_result vc_handle_mmio_movs(struct es_em_ctxt *ctxt, unsigned int bytes);