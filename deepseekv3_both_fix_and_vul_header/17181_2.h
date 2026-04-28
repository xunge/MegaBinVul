#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef uint64_t ut64;
typedef uint32_t ut32;
typedef uint8_t ut8;

#define UT64_MAX UINT64_MAX
#define PFMT64x "llx"

typedef struct {
    int len;
} DalvikOpcode;

extern DalvikOpcode dalvik_opcodes[];

typedef struct {
    int type;
    int family;
    int stackop;
    int nopcode;
    int id;
    int size;
    int refptr;
    ut64 ptr;
    ut64 val;
    ut64 jump;
    ut64 fail;
    bool eob;
} RAnalOp;

typedef struct {
    void *bin;
    int (*get_offset)(void *bin, char type, int index);
} RAnalBinb;

typedef struct {
    RAnalBinb binb;
} RAnal;

#define R_ANAL_OP_TYPE_UNK 0
#define R_ANAL_OP_TYPE_MOV 1
#define R_ANAL_OP_TYPE_CMP 2
#define R_ANAL_OP_TYPE_LOAD 3
#define R_ANAL_OP_TYPE_STORE 4
#define R_ANAL_OP_TYPE_MUL 5
#define R_ANAL_OP_TYPE_NOT 6
#define R_ANAL_OP_TYPE_SHR 7
#define R_ANAL_OP_TYPE_MOD 8
#define R_ANAL_OP_TYPE_XOR 9
#define R_ANAL_OP_TYPE_DIV 10
#define R_ANAL_OP_TYPE_RET 11
#define R_ANAL_OP_TYPE_JMP 12
#define R_ANAL_OP_TYPE_SWITCH 13
#define R_ANAL_OP_TYPE_CJMP 14
#define R_ANAL_OP_TYPE_UPUSH 15
#define R_ANAL_OP_TYPE_POP 16
#define R_ANAL_OP_TYPE_CALL 17
#define R_ANAL_OP_TYPE_SWI 18
#define R_ANAL_OP_TYPE_NEW 19
#define R_ANAL_OP_TYPE_NOP 20
#define R_ANAL_OP_TYPE_ADD 21
#define R_ANAL_OP_TYPE_SUB 22
#define R_ANAL_OP_TYPE_AND 23
#define R_ANAL_OP_TYPE_OR 24
#define R_ANAL_OP_TYPE_SHL 25
#define R_ANAL_OP_TYPE_LENGTH 26
#define R_ANAL_OP_TYPE_CAST 27

#define R_ANAL_OP_FAMILY_FPU 1

#define R_ANAL_STACK_SET 1

#define R_ANAL_GET_OFFSET(anal, type, index) (anal)->binb.get_offset((anal)->binb.bin, type, index)

static void esilprintf(RAnalOp *op, const char *fmt, ...) {
    // Implementation not provided
}