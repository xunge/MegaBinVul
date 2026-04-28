#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE(x) (sizeof(x)/sizeof(x[0]))

typedef unsigned int x86_reg;

typedef enum cs_ac_type {
    CS_AC_INVALID = 0,
    CS_AC_READ,
    CS_AC_WRITE,
    CS_AC_READ_WRITE
} cs_ac_type;

struct insn_reg {
    unsigned int insn;
    x86_reg reg;
    cs_ac_type access;
};

extern struct insn_reg insn_regs_intel[1];
extern struct insn_reg insn_regs_intel_sorted[1];
extern bool intel_regs_sorted;

int regs_cmp(const void *a, const void *b);