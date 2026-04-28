#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define type2_transient_array 32

typedef enum {
    CS2_OPERATOR,
    CS2_OPERAND,
    CS2_FRACTION,
    cff_DOUBLE
} cff_ValueType;

typedef struct {
    cff_ValueType t;
    double d;
    int32_t i;
} cff_Value;

typedef struct {
    uint8_t *data;
    uint32_t *offset;
    uint32_t count;
} cff_Index;

typedef struct {
    cff_Value stack[48];
    cff_Value transient[type2_transient_array];
    uint16_t index;
    uint16_t stem;
} cff_Stack;

typedef struct {
    void (*setWidth)(void *context, double width);
    void (*newContour)(void *context);
    void (*lineTo)(void *context, double x1, double y1);
    void (*curveTo)(void *context, double x1, double y1, double x2, double y2, double x3, double y3);
    void (*setHint)(void *context, bool isVertical, double position, double width);
    void (*setMask)(void *context, bool isContourMask, bool *mask);
    double (*getrand)(void *context);
} cff_IOutlineBuilder;

typedef struct {
    // Add necessary fields for options
} otfcc_Options;

#define NEW(p, n) ((p) = malloc(sizeof(*(p)) * (n)))

#define CHECK_STACK_TOP(op, n) \
    if (stack->index < (n)) {  \
        return;                \
    }

enum {
    op_hstem,
    op_vstem,
    op_hstemhm,
    op_vstemhm,
    op_hintmask,
    op_cntrmask,
    op_vmoveto,
    op_rmoveto,
    op_hmoveto,
    op_endchar,
    op_rlineto,
    op_vlineto,
    op_hlineto,
    op_rrcurveto,
    op_rcurveline,
    op_rlinecurve,
    op_vvcurveto,
    op_hhcurveto,
    op_vhcurveto,
    op_hvcurveto,
    op_hflex,
    op_flex,
    op_hflex1,
    op_flex1,
    op_and,
    op_or,
    op_not,
    op_abs,
    op_add,
    op_sub,
    op_div,
    op_neg,
    op_eq,
    op_drop,
    op_put,
    op_get,
    op_ifelse,
    op_random,
    op_mul,
    op_sqrt,
    op_dup,
    op_exch,
    op_index,
    op_roll,
    op_return,
    op_callsubr,
    op_callgsubr
};

static uint16_t compute_subr_bias(uint32_t count);
static uint32_t cff_decodeCS2Token(uint8_t *data, cff_Value *val);
static void reverseStack(cff_Stack *stack, uint8_t first, uint8_t last);

static void callback_nopSetWidth(void *context, double width) {}
static void callback_nopNewContour(void *context) {}
static void callback_nopLineTo(void *context, double x1, double y1) {}
static void callback_nopCurveTo(void *context, double x1, double y1, double x2, double y2, double x3, double y3) {}
static void callback_nopsetHint(void *context, bool isVertical, double position, double width) {}
static void callback_nopsetMask(void *context, bool isContourMask, bool *mask) {}
static double callback_nopgetrand(void *context) { return 0.0; }