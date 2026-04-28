#include <stddef.h>
#include <stdbool.h>

typedef long FT_Int;
typedef unsigned long FT_ULong;

enum {
    TT_Err_Stack_Overflow,
    TT_Err_Invalid_Reference
};

#define FALSE false

typedef struct TT_DefRecord_ {
    FT_ULong opc;
    bool active;
    FT_ULong start;
    FT_ULong range;
} TT_DefRecord;

typedef struct TT_CallRec_ {
    FT_ULong Caller_Range;
    FT_ULong Caller_IP;
    FT_Int Cur_Count;
    FT_ULong Cur_Restart;
} TT_CallRec;

typedef struct {
    TT_DefRecord* FDefs;
    FT_ULong maxFunc;
    FT_ULong numFDefs;
    TT_CallRec* callStack;
    FT_ULong callTop;
    FT_ULong callSize;
    FT_ULong IP;
    FT_ULong curRange;
    FT_Int error;
    bool step_ins;
    FT_ULong* args;
} T1_ExecContext;

#define BOUNDS(n, m) ((n) >= (m))
#define INS_Goto_CodeRange(a, b) do { } while (0)
#define INS_ARG T1_ExecContext* execCtx
#define CUR (*execCtx)
#define args (execCtx->args)