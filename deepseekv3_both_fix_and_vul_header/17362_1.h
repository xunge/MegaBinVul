#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint64_t ut64;
typedef uint8_t ut8;

typedef struct {
    char *buf;
} RStrBuf;

typedef struct {
    int size;
    ut64 addr;
    int type;
    int id;
    int cycles;
    int failcycles;
    ut64 jump;
    ut64 fail;
    bool eob;
    int stackop;
    int stackptr;
    RStrBuf esil;
} RAnalOp;

typedef struct {
    int dummy;
} RAnal;

enum {
    R_ANAL_OP_TYPE_UNK,
    R_ANAL_OP_TYPE_ILL,
    R_ANAL_OP_TYPE_SWI,
    R_ANAL_OP_TYPE_NOP,
    R_ANAL_OP_TYPE_MOV,
    R_ANAL_OP_TYPE_ADD,
    R_ANAL_OP_TYPE_SUB,
    R_ANAL_OP_TYPE_OR,
    R_ANAL_OP_TYPE_AND,
    R_ANAL_OP_TYPE_XOR,
    R_ANAL_OP_TYPE_SHL,
    R_ANAL_OP_TYPE_SHR,
    R_ANAL_OP_TYPE_ROL,
    R_ANAL_OP_TYPE_ROR,
    R_ANAL_OP_TYPE_STORE,
    R_ANAL_OP_TYPE_CMP,
    R_ANAL_OP_TYPE_CJMP,
    R_ANAL_OP_TYPE_JMP,
    R_ANAL_OP_TYPE_UJMP,
    R_ANAL_OP_TYPE_RET,
    R_ANAL_OP_TYPE_LOAD,
    R_ANAL_OP_TYPE_PUSH,
    R_ANAL_OP_TYPE_POP,
    R_ANAL_OP_TYPE_CALL
};

enum {
    R_ANAL_STACK_INC,
    R_ANAL_STACK_SET,
    R_ANAL_STACK_GET
};

enum {
    _6502_FLAGS_NZ,
    _6502_FLAGS_BNZ
};

extern int snes_op_get_size(int, int, const void*);
extern void r_strbuf_init(RStrBuf*);
extern void r_strbuf_set(RStrBuf*, const char*);
extern void r_strbuf_setf(RStrBuf*, const char*, ...);
extern void r_strbuf_append(RStrBuf*, const char*);
extern void _6502_anal_esil_flags(RAnalOp*, ut8);
extern void _6502_anal_esil_get_addr_pattern1(RAnalOp*, const ut8*, char*, int);
extern void _6502_anal_esil_get_addr_pattern2(RAnalOp*, const ut8*, char*, int, char);
extern void _6502_anal_esil_get_addr_pattern3(RAnalOp*, const ut8*, char*, int, char);
extern void _6502_anal_update_flags(RAnalOp*, int);
extern void _6502_anal_esil_inc_reg(RAnalOp*, ut8, const char*);
extern void _6502_anal_esil_ccall(RAnalOp*, ut8);
extern void _6502_anal_esil_push(RAnalOp*, ut8);
extern void _6502_anal_esil_pop(RAnalOp*, ut8);
extern void _6502_anal_esil_mov(RAnalOp*, ut8);

static const void* snes_op;