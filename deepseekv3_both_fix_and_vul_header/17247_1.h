#include <string.h>
#include <stdint.h>

typedef uint64_t ut64;
typedef uint16_t ut16;
typedef uint8_t ut8;

#define R_ANAL_OP_TYPE_UNK 0

typedef struct {
    int type;
    ut64 addr;
    ut64 jump;
    ut64 fail;
    ut64 ptr;
    ut64 val;
    int size;
} RAnalOp;

typedef struct {
    int big_endian;
} RAnal;

extern int (*first_nibble_decode[16])(RAnal *anal, RAnalOp *op, ut16 data);