#include <stdint.h>
#include <stdbool.h>

typedef struct {
    int bits;
} RAsm;

typedef struct {
    int type;
    bool is_good_flag;
    int64_t immediate;
    int sign;
    bool extended;
    int reg;
    int reg_size;
    int dest_size;
    bool explicit_size;
    int offset;
    int offset_sign;
    int regs[2];
    int scale[2];
} Operand;

typedef struct {
    Operand operands[2];
} Opcode;

#define OT_CONSTANT 1
#define OT_GPREG 2
#define OT_MEMORY 4
#define OT_QWORD 8
#define OT_WORD 16
#define OT_BYTE 32
#define OT_REGALL 64
#define OT_REGTYPE 128
#define OT_SEGMENTREG 256
#define OT_DWORD 512

#define ALL_SIZE 0x1f
#define OPSIZE_SHIFT 0

#define X86R_RIP 0
#define X86R_EAX 1
#define X86R_BX 2
#define X86R_SI 3
#define X86R_DI 4
#define X86R_BP 5
#define X86R_EBP 6
#define X86R_ESP 7
#define X86R_EIP 8
#define X86R_R8 9
#define X86R_UNDEFINED -1

#define B0000 0
#define B0001 1
#define B0010 2
#define B0011 3
#define B0100 4
#define B0101 5
#define B0111 7

#define UT32_MAX 0xFFFFFFFFU
static const uint8_t SEG_REG_PREFIXES[] = {0x2E, 0x3E, 0x26, 0x64, 0x65, 0x36};

typedef int64_t st64;
typedef uint8_t ut8;
typedef uint32_t ut32;
typedef uint64_t ut64;

static int getsib(int scale) {
    return scale;
}