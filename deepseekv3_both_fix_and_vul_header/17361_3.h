#include <stdint.h>
#include <stdio.h>

#define UT16_MAX 0xFFFF
#define PFMT64x "llx"

typedef uint64_t ut64;
typedef uint32_t ut32;
typedef uint16_t ut16;
typedef uint8_t ut8;

struct RAnalCaseOp {
    ut64 bb_ref_to;
    ut64 bb_ref_from;
};

struct RAnalSwitchOp {
    ut64 addr;
    int min_val;
    ut32 default_loc;
};

struct RAnalOp {
    int size;
    struct RAnalSwitchOp *switch_op;
};

struct RAnal {};

typedef struct RAnal RAnal;
typedef struct RAnalOp RAnalOp;
typedef struct RAnalCaseOp RAnalCaseOp;
typedef struct RAnalSwitchOp RAnalSwitchOp;

#define UINT(data, pos) (*(ut32*)(data + pos))
#define R_BIN_JAVA_UINT(data, pos) (*(ut32*)(data + pos))

static ut64 java_get_method_start(void);
static RAnalCaseOp *r_anal_switch_op_add_case(RAnalSwitchOp *op, ut64 addr, ut32 val, ut64 jump);
static RAnalSwitchOp *r_anal_switch_op_new(ut64 addr, int min_val, ut32 default_loc);
static void eprintf(const char *format, ...);