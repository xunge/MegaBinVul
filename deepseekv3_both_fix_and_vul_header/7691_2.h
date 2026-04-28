#include <string.h>
#include <stdlib.h>

typedef unsigned long long ut64;
typedef unsigned char ut8;

typedef int RAnalOpMask;

enum {
    R_ANAL_OP_MASK_DISASM = 1,
};

enum RAnalOpType {
    R_ANAL_OP_TYPE_UNK,
    R_ANAL_OP_TYPE_ROR,
    R_ANAL_OP_TYPE_PUSH,
    R_ANAL_OP_TYPE_CALL,
    R_ANAL_OP_TYPE_RET,
    R_ANAL_OP_TYPE_MOV,
    R_ANAL_OP_TYPE_UJMP,
    R_ANAL_OP_TYPE_ADD,
    R_ANAL_OP_TYPE_SUB,
    R_ANAL_OP_TYPE_CMP,
    R_ANAL_OP_TYPE_XOR,
    R_ANAL_OP_TYPE_AND,
    R_ANAL_OP_TYPE_JMP,
    R_ANAL_OP_TYPE_CJMP,
    R_ANAL_OP_TYPE_ILL,
};

enum RAnalOpFamily {
    R_ANAL_OP_FAMILY_CPU,
};

enum {
    MSP430_ONEOP,
    MSP430_TWOOP,
    MSP430_JUMP,
    MSP430_INV,
};

enum {
    MSP430_RRA,
    MSP430_RRC,
    MSP430_PUSH,
    MSP430_CALL,
    MSP430_RETI,
    MSP430_BIT,
    MSP430_BIC,
    MSP430_BIS,
    MSP430_MOV,
    MSP430_DADD,
    MSP430_ADDC,
    MSP430_ADD,
    MSP430_SUBC,
    MSP430_SUB,
    MSP430_CMP,
    MSP430_XOR,
    MSP430_AND,
    MSP430_JMP,
};

struct msp430_cmd {
    int type;
    int opcode;
    int jmp_cond;
    ut64 jmp_addr;
    char instr[32];
    char operands[2][32];
};

typedef struct {
    int size;
    int nopcode;
    int type;
    int family;
    ut64 addr;
    ut64 jump;
    ut64 fail;
    char *mnemonic;
} RAnalOp;

typedef struct {
    int syntax;
} RAnal;

char *strdup(const char *s);
char *r_str_newf(const char *fmt, ...);
void r_str_replace_ch(char *str, char a, char b, int global);
unsigned short r_read_at_le16(const ut8 *buf, int offset);
int msp430_decode_command(const ut8 *buf, int len, struct msp430_cmd *cmd);