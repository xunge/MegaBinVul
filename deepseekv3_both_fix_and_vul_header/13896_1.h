#include <stddef.h>
#include <stdlib.h>
#include <math.h>

typedef int Int;
typedef float TT_F26Dot6;

#define BOUNDS(index, count) ((index) < 0 || (index) >= (count))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define INS_ARG Int* args
#define EXEC_ARGS (void*)0,

typedef struct {
    Int rp0;
    Int rp1;
    Int rp2;
    TT_F26Dot6 single_width_cutin;
    TT_F26Dot6 single_width_value;
    TT_F26Dot6 minimum_distance;
} GS_State;

typedef struct {
    TT_F26Dot6 *org_x;
    TT_F26Dot6 *org_y;
    TT_F26Dot6 *cur_x;
    TT_F26Dot6 *cur_y;
    Int n_points;
} PointSet;

typedef struct {
    TT_F26Dot6 compensations[4];
} Metrics;

typedef struct {
    PointSet zp0;
    PointSet zp1;
    GS_State GS;
    Metrics metrics;
    Int opcode;
    Int error;
} TTCur;

extern TTCur CUR;

TT_F26Dot6 CUR_Func_dualproj(TT_F26Dot6 x, TT_F26Dot6 y);
TT_F26Dot6 CUR_Func_round(TT_F26Dot6 distance, TT_F26Dot6 compensation);
TT_F26Dot6 Round_None(void* exec_args, TT_F26Dot6 distance, TT_F26Dot6 compensation);
TT_F26Dot6 CUR_Func_project(TT_F26Dot6 x, TT_F26Dot6 y);
void CUR_Func_move(PointSet* zp, Int point, TT_F26Dot6 distance);