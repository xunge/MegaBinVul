#include <stddef.h>

typedef long  TT_F26Dot6;
typedef int   Int;

#define BOUNDS(n, size) ((n) < 0 || (n) >= (size))

enum {
    TT_Err_Invalid_Reference
};

typedef struct {
    TT_F26Dot6 *org_x;
    TT_F26Dot6 *org_y;
    TT_F26Dot6 *cur_x;
    TT_F26Dot6 *cur_y;
    Int        n_points;
} PointSet;

typedef struct {
    Int rp1;
    Int rp2;
    Int loop;
} GraphicsState;

typedef struct {
    PointSet zp0;
    PointSet zp1;
    PointSet zp2;
    GraphicsState GS;
    Int top;
    Int args;
    Int new_top;
    TT_F26Dot6 *stack;
    int error;
} ControlValueRecord;

#define INS_ARG ControlValueRecord* args
#define CUR (*args)