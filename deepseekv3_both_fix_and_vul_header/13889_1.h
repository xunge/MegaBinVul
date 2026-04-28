#include <stdint.h>
#include <stdlib.h>
#include <math.h>

typedef int32_t Int;
typedef int32_t TT_F26Dot6;

#define TT_Err_Invalid_Reference 1

typedef struct {
    TT_F26Dot6 x;
    TT_F26Dot6 y;
} TT_Vector;

typedef struct {
    TT_F26Dot6* org_x;
    TT_F26Dot6* org_y;
    TT_F26Dot6* cur_x;
    TT_F26Dot6* cur_y;
    Int n_points;
} TT_Zone;

typedef struct {
    TT_F26Dot6 single_width_cutin;
    TT_F26Dot6 single_width_value;
    TT_F26Dot6 control_value_cutin;
    TT_F26Dot6 minimum_distance;
    TT_Vector freeVector;
    Int gep0;
    Int gep1;
    Int rp0;
    Int rp1;
    Int rp2;
    uint8_t auto_flip;
} TT_GraphicsState;

typedef struct {
    TT_F26Dot6 compensations[4];
} TT_Metrics;

typedef struct {
    TT_Zone zp0;
    TT_Zone zp1;
    TT_GraphicsState GS;
    TT_Metrics metrics;
    TT_F26Dot6* cvt;
    Int cvtSize;
    Int error;
    uint8_t opcode;
} TT_ExecContext;

#define BOUNDS(n, size) ((n) < 0 || (n) >= (size))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MulDiv_Round(a, b, c) (((a) * (b) + (c)/2) / (c))
#define INS_ARG Int* args
#define EXEC_ARGS

extern TT_ExecContext CUR;

TT_F26Dot6 CUR_Func_read_cvt(Int entry);
TT_F26Dot6 CUR_Func_dualproj(TT_F26Dot6 x, TT_F26Dot6 y);
TT_F26Dot6 CUR_Func_project(TT_F26Dot6 x, TT_F26Dot6 y);
TT_F26Dot6 CUR_Func_round(TT_F26Dot6 distance, TT_F26Dot6 compensation);
void CUR_Func_move(TT_Zone* zone, Int point, TT_F26Dot6 distance);
TT_F26Dot6 Round_None(TT_F26Dot6 value, TT_F26Dot6 compensation);