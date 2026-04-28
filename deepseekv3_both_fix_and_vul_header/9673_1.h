#include <stddef.h>

typedef long FT_F26Dot6;
typedef unsigned long FT_ULong;

#define BOUNDS(a,b) ((a) >= (b))

struct TT_ExecContextRec_ {
    int pedantic_hinting;
    int error;
    unsigned int opcode;
    struct {
        size_t n_points;
        FT_F26Dot6 *org;
        FT_F26Dot6 *cur;
    } zp2;
};

#define CUR (*exec)
#define CUR_fast_dualproj(p) (0)
#define CUR_fast_project(p) (0)
#define INS_ARG struct TT_ExecContextRec_ *exec, FT_F26Dot6 *args

enum {
    TT_Err_Invalid_Reference
};