#include <stddef.h>

typedef short FT_Short;
typedef unsigned short FT_UShort;
typedef unsigned int FT_UInt;
typedef long FT_Pos;
typedef unsigned char FT_Byte;

typedef struct FT_Vector_ {
    FT_Pos x;
    FT_Pos y;
} FT_Vector;

typedef struct {
    FT_Vector* org;
    FT_Vector* cur;
    FT_Vector* orus;
    FT_UInt* contours;
    FT_Byte* tags;
    FT_UInt n_points;
    FT_UInt n_contours;
    FT_UInt first_point;
} PTS;

typedef struct {
    PTS pts;
    FT_Byte opcode;
} INS_ARG;

#define CUR (*(INS_ARG*)0)

typedef struct {
    FT_Vector* orgs;
    FT_Vector* curs;
    FT_Vector* orus;
    FT_UInt max_points;
} IUP_WorkerRec;

#define FT_CURVE_TAG_TOUCH_X 0x01
#define FT_CURVE_TAG_TOUCH_Y 0x02
#define FT_UNUSED_ARG

extern void _iup_worker_interpolate(IUP_WorkerRec* worker, FT_UShort p1, FT_UShort p2, FT_UShort ref1, FT_UShort ref2);
extern void _iup_worker_shift(IUP_WorkerRec* worker, FT_UInt p1, FT_UInt p2, FT_UInt ref);