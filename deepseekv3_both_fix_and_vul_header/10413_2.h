#define FT_LOCAL_DEF(x) static x
#define FT_CURVE_TAG_ON 1

typedef struct FT_Vector_ {
    long x;
    long y;
} FT_Vector;

typedef struct FT_Outline_ {
    short n_contours;
    short n_points;
    FT_Vector* points;
    char* tags;
    short* contours;
} FT_Outline;

typedef struct T1_Builder_ {
    FT_Outline* current;
} *T1_Builder;

typedef int FT_Int;
typedef unsigned char FT_Byte;