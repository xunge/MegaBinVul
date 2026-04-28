#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_OPERANDS 8

enum {
    ARM_NOTYPE,
    ARM_GPR,
    ARM_FP,
    ARM_MEM_OPT,
    ARM_CONSTANT
};

enum {
    ARM_UNDEFINED,
    ARM_REG32,
    ARM_REG64,
    ARM_SP
};

enum {
    ARM_NO_SHIFT,
    ARM_LSL,
    ARM_LSR,
    ARM_ASR
};

typedef struct {
    const char *name;
    int val;
} MsrConst;

typedef struct {
    int type;
    int reg_type;
    int reg;
    int shift;
    int shift_amount;
    int immediate;
    int sign;
    int mem_option;
    int sp_val;
} ArmOperand;

typedef struct {
    ArmOperand operands[MAX_OPERANDS];
    int operands_count;
} ArmOp;

extern MsrConst msr_const[];
extern int r_num_math(void *user, const char *str);
extern int get_mem_option(const char *token);
extern void eprintf(const char *fmt, ...);