#include <stdint.h>

typedef uint64_t ut64;
typedef uint8_t ut8;
typedef uint32_t ut32;

typedef enum {
    R_ANAL_OP_TYPE_UNK,
    R_ANAL_OP_TYPE_RET,
    R_ANAL_OP_TYPE_MOV,
    R_ANAL_OP_TYPE_SHL,
    R_ANAL_OP_TYPE_ADD,
    R_ANAL_OP_TYPE_SUB,
    R_ANAL_OP_TYPE_NOP,
    R_ANAL_OP_TYPE_XOR,
    R_ANAL_OP_TYPE_CJMP,
    R_ANAL_OP_TYPE_DIV,
    R_ANAL_OP_TYPE_PUSH,
    R_ANAL_OP_TYPE_CMP,
    R_ANAL_OP_TYPE_CALL
} RAnalOpType;

typedef struct {
    int size;
    ut64 addr;
    RAnalOpType type;
    ut64 jump;
    ut64 fail;
} RAnalOp;

typedef struct {
    // dummy struct for RAnal
} RAnal;

typedef int RAnalOpMask;