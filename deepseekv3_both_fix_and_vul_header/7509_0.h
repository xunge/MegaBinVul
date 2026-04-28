#include <stdint.h>

#define UT64_MAX UINT64_MAX
#define UT32_MAX UINT32_MAX

typedef uint64_t ut64;
typedef uint32_t ut32;
typedef uint8_t ut8;
typedef int32_t st32;
typedef int8_t st8;

typedef enum {
    R_ANAL_OP_TYPE_MOV,
    R_ANAL_OP_TYPE_LEA,
    R_ANAL_OP_TYPE_CALL,
    R_ANAL_OP_TYPE_TRAP,
    R_ANAL_OP_TYPE_JMP,
    R_ANAL_OP_TYPE_RET,
    R_ANAL_OP_TYPE_CJMP,
    R_ANAL_OP_TYPE_SHR,
    R_ANAL_OP_TYPE_CMP,
    R_ANAL_OP_TYPE_NOP,
    R_ANAL_OP_TYPE_ADD,
    R_ANAL_OP_TYPE_SUB,
    R_ANAL_OP_TYPE_UJMP
} RAnalOpType;

typedef struct {
    int type;
    ut64 ptr;
    ut64 jump;
    ut64 fail;
    int size;
} RAnalOp;

typedef struct {
    // Placeholder for RAnal structure
} RAnal;

typedef int RAnalOpMask;