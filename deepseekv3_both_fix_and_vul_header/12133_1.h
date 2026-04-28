#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint64_t u64;
typedef uint8_t u8;
typedef uint16_t u16;

enum es_result {
    ES_OK,
    ES_DECODE_FAILED
};

#define IOIO_TYPE_INS    (1 << 0)
#define IOIO_TYPE_OUTS   (1 << 1)
#define IOIO_TYPE_IN     (1 << 2)
#define IOIO_TYPE_OUT    (1 << 3)
#define IOIO_SEG_ES      (1 << 4)
#define IOIO_SEG_DS      (1 << 5)
#define IOIO_DATA_8      (1 << 6)
#define IOIO_DATA_16     (1 << 7)
#define IOIO_DATA_32     (1 << 8)
#define IOIO_ADDR_16     (1 << 9)
#define IOIO_ADDR_32     (1 << 10)
#define IOIO_ADDR_64     (1 << 11)
#define IOIO_REP         (1 << 12)

struct insn {
    struct {
        uint8_t bytes[16];
    } opcode;
    uint8_t opnd_bytes;
    uint8_t addr_bytes;
    struct {
        uint64_t value;
    } immediate;
};

struct pt_regs {
    uint64_t dx;
};

struct es_em_ctxt {
    struct insn insn;
    struct pt_regs *regs;
};

static enum es_result vc_ioio_check(struct es_em_ctxt *ctxt, u16 port, size_t size);
static bool insn_has_rep_prefix(const struct insn *insn);