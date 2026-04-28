#include <stddef.h>
#include <stdbool.h>

typedef unsigned long FT_ULong;

typedef struct TT_DefRecord_ {
    FT_ULong opc;
    bool active;
    unsigned start;
    unsigned range;
} TT_DefRecord;

typedef struct TT_CallRec_ {
    unsigned Caller_Range;
    unsigned Caller_IP;
    unsigned Cur_Count;
    unsigned Cur_Restart;
} TT_CallRec;

typedef struct {
    FT_ULong maxFunc;
    unsigned numFDefs;
    TT_DefRecord* FDefs;
    unsigned callTop;
    unsigned callSize;
    TT_CallRec* callStack;
    unsigned error;
    unsigned curRange;
    unsigned IP;
    bool step_ins;
    FT_ULong* args;
} T1_ExecContext;

enum {
    TT_Err_Stack_Overflow,
    TT_Err_Invalid_Reference
};

#define BOUNDS(x, n) ((x) >= (n))
#define INS_Goto_CodeRange(range, ip) do { } while (0)
#define INS_ARG void
#define CUR (*execCtx)
#define args (execCtx->args)
#define Fail Fail_label
#define FALSE false

static T1_ExecContext* execCtx;