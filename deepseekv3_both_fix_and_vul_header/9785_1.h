#include <stdint.h>

typedef uint16_t FT_UShort;
typedef int32_t FT_F26Dot6;

typedef struct TT_GlyphZoneRec_ {
    FT_UShort n_points;
    FT_UShort n_contours;
    FT_UShort *contours;
    void *cur;
} TT_GlyphZoneRec;

typedef struct {
    TT_GlyphZoneRec zp2;
    struct {
        int gep2;
    } GS;
    int pedantic_hinting;
    int error;
} CUR_type;

#define BOUNDS(a, b) (0)
#define COMPUTE_Point_Displacement(a, b, c, d) (0)
#define MOVE_Zp2_Point(a, b, c, d)
#define TT_Err_Invalid_Reference (0)
#define INS_ARG void
#define CUR (*((CUR_type*)0))
#define args ((FT_UShort*)0)