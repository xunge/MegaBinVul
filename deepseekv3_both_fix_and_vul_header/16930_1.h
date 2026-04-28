#include <stdint.h>

typedef uint64_t ut64;
typedef uint32_t ut32;
typedef uint8_t ut8;

typedef struct HexInsn {
    // Add HexInsn members if needed
} HexInsn;

typedef struct RAnalOp {
    int size;
    ut64 addr;
    // Add other RAnalOp members if needed
} RAnalOp;

typedef struct RAnal {
    // Add RAnal members if needed
} RAnal;

typedef int RAnalOpMask;

static ut32 r_read_le32(const ut8 *buf);
static int hexagon_disasm_instruction(ut32 data, HexInsn *hi, ut32 addr);
static int hexagon_anal_instruction(HexInsn *hi, RAnalOp *op);