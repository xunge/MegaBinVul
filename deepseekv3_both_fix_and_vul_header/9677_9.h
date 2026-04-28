#include <stdint.h>
#include <stdlib.h>

typedef int32_t FT_F26Dot6;
typedef uint32_t FT_ULong;
typedef uint16_t FT_UShort;
typedef uint32_t FT_UInt32;

typedef struct {
    FT_F26Dot6 x;
    FT_F26Dot6 y;
} FT_Vector;

typedef struct {
    FT_Vector* org;
    FT_Vector* cur;
    int n_points;
} GlyphZone;

typedef struct {
    FT_F26Dot6 control_value_cutin;
    FT_Vector freeVector;
    int gep0;
    int rp0;
    int rp1;
} GraphicsState;

typedef struct {
    FT_F26Dot6* compensations;
} TT_Metrics;

typedef struct {
    GlyphZone zp0;
    GraphicsState GS;
    TT_Metrics tt_metrics;
    FT_ULong cvtSize;
    int pedantic_hinting;
    int error;
    int opcode;
} T1_ExecContext;

#define BOUNDS(a,b) ((a) >= (b))
#define CUR (exec.context)
#define CUR_Func_read_cvt(n) (0)
#define CUR_Func_round(a,b) (0)
#define CUR_Func_move(a,b,c) (void)0
#define CUR_fast_project(a) (0)
#define TT_Err_Invalid_Reference 0
#define TT_MulFix14(a,b) (0)
#define FT_ABS(x) abs(x)

typedef struct {
    T1_ExecContext context;
    FT_F26Dot6* args;
} INS_ARG;

#define exec (*(INS_ARG*)0)
#define args (exec.args)