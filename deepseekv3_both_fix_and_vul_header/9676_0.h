#include <stddef.h>

typedef unsigned short FT_UShort;
typedef long FT_F26Dot6;

#define BOUNDS(a, b) ((a) < 0 || (a) >= (b))

struct TT_ExecContextRec_ {
    struct {
        FT_F26Dot6* cur;
        size_t n_points;
    } zp0, zp1;
    int pedantic_hinting;
    int error;
};

extern struct TT_ExecContextRec_ CUR;

#define CUR_Func_project(a, b) 0
#define CUR_Func_move(a, b, c) (void)0

#define TT_Err_Invalid_Reference 0

#define INS_ARG int* args