#include <stdbool.h>
#include <stddef.h>
#include <inttypes.h>

#define PFMT64x PRIx64
typedef uint64_t ut64;

#define INSOP64(n) insn->detail->operands[n]
#define REG64(n) arm64_reg_name(handle, insn->detail->operands[n].reg)
#define VEC64_MASK(shift, size) (((1ULL << (size)) - 1) << (shift))
#define BITMASK_BY_WIDTH_COUNT (sizeof(bitmask_by_width)/sizeof(bitmask_by_width[0]))

static const ut64 bitmask_by_width[] = {
    0xFFFFFFFFFFFFFFFFULL,
    0x5555555555555555ULL,
    0x1111111111111111ULL,
    0x0101010101010101ULL,
    0x0001000100010001ULL,
    0x0000000100000001ULL,
    0x0000000000000001ULL
};

typedef struct {
    char *buf;
    size_t len;
    size_t ptr;
} RStrBuf;

typedef struct csh csh;
typedef struct cs_insn cs_insn;

typedef struct {
    int vector_index;
    bool vess;
    bool vas;
    int reg;
} cs_arm64_op;

typedef struct {
    cs_arm64_op operands[8];
} cs_detail;

struct cs_insn {
    cs_detail *detail;
};

const char *arm64_reg_name(csh *handle, int reg);
int vector_size(cs_arm64_op *op);
void r_strbuf_appendf(RStrBuf *sb, const char *fmt, ...);