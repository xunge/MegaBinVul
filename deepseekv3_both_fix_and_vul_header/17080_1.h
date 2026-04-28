#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef uint64_t ut64;
typedef uint8_t ut8;
typedef uint32_t ut32;

#define UT64_MAX UINT64_MAX
#define PFMT64x "llx"

typedef struct {
    int len;
} DalvikOpcode;

extern DalvikOpcode dalvik_opcodes[];

typedef struct RAnalBinB {
    ut64 (*get_offset)(void *bin, char type, ut32 idx);
    void *bin;
} RAnalBinB;

typedef struct RAnal {
    RAnalBinB binb;
} RAnal;

typedef struct RAnalOp {
    int type;
    ut64 ptr;
    ut64 val;
    ut64 jump;
    ut64 fail;
    int refptr;
    int size;
    int nopcode;
    int id;
    int family;
    int stackop;
    bool eob;
} RAnalOp;

#define R_ANAL_OP_TYPE_UNK 0
#define R_ANAL_OP_TYPE_MOV 1
#define R_ANAL_OP_TYPE_CAST 2
#define R_ANAL_OP_TYPE_LENGTH 3
#define R_ANAL_OP_TYPE_LOAD 4
#define R_ANAL_OP_TYPE_STORE 5
#define R_ANAL_OP_TYPE_MUL 6
#define R_ANAL_OP_TYPE_NOT 7
#define R_ANAL_OP_TYPE_SHR 8
#define R_ANAL_OP_TYPE_MOD 9
#define R_ANAL_OP_TYPE_XOR 10
#define R_ANAL_OP_TYPE_DIV 11
#define R_ANAL_OP_TYPE_RET 12
#define R_ANAL_OP_TYPE_JMP 13
#define R_ANAL_OP_TYPE_SWITCH 14
#define R_ANAL_OP_TYPE_CMP 15
#define R_ANAL_OP_TYPE_CJMP 16
#define R_ANAL_OP_TYPE_UPUSH 17
#define R_ANAL_OP_TYPE_POP 18
#define R_ANAL_OP_TYPE_CALL 19
#define R_ANAL_OP_TYPE_SWI 20
#define R_ANAL_OP_TYPE_NEW 21
#define R_ANAL_OP_TYPE_NOP 22
#define R_ANAL_OP_TYPE_ADD 23
#define R_ANAL_OP_TYPE_SUB 24
#define R_ANAL_OP_TYPE_AND 25
#define R_ANAL_OP_TYPE_OR 26
#define R_ANAL_OP_TYPE_SHL 27

#define R_ANAL_OP_FAMILY_FPU 1
#define R_ANAL_STACK_SET 1

#define R_ANAL_GET_OFFSET(anal, type, idx) 0

static void esilprintf(RAnalOp *op, const char *fmt, ...) {
    // Implementation not provided
}