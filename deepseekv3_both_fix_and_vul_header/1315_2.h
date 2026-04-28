#include <stddef.h>

typedef struct RzReg {
    const char *name[2];
} RzReg;

typedef struct RzAnalysis {
    RzReg *reg;
} RzAnalysis;

typedef struct RzAnalysisFunction RzAnalysisFunction;
typedef struct RzAnalysisOp RzAnalysisOp;

enum {
    RZ_REG_NAME_BP,
    RZ_REG_NAME_SP
};

typedef enum {
    RZ_ANALYSIS_VAR_KIND_BPV,
    RZ_ANALYSIS_VAR_KIND_SPV
} RzAnalysisVarKind;

#define RZ_API
#define rz_return_if_fail(cond) if (!(cond)) return

void extract_arg(RzAnalysis *analysis, RzAnalysisFunction *fcn, RzAnalysisOp *op, const char *reg, const char *sign, RzAnalysisVarKind kind);