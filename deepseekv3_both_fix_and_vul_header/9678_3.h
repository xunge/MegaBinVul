#include <stddef.h>

typedef struct TT_GlyphZoneRec_ {
    int n_points;
    int n_contours;
    short *contours;
    void *cur;
} TT_GlyphZoneRec;

typedef struct {
    TT_GlyphZoneRec zp2;
    struct {
        int gep2;
    } GS;
    int pedantic_hinting;
    int error;
} INS_ARG;

#define BOUNDS(a, b) (0)
#define COMPUTE_Point_Displacement(a, b, c, d) (0)
#define MOVE_Zp2_Point(a, b, c, d)
#define TT_Err_Invalid_Reference (0)

typedef short FT_UShort;
typedef int FT_F26Dot6;

#define CUR (*(INS_ARG*)0)