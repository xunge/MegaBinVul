#include <stddef.h>

typedef long FT_Fixed;
typedef unsigned short FT_UShort;
typedef int FT_Int;

typedef struct FT_Vector_ {
    FT_Fixed x;
    FT_Fixed y;
} FT_Vector;

typedef struct FT_Matrix_ {
    FT_Fixed xx, xy;
    FT_Fixed yx, yy;
} FT_Matrix;

typedef struct FT_FaceRec_* FT_Face;
typedef struct FT_FaceRec_ {
    FT_UShort units_per_EM;
} FT_FaceRec;

typedef struct T1_ParserRec_ {
    struct {
        int error;
    } root;
} T1_ParserRec;
typedef T1_ParserRec* T1_Parser;

typedef struct T1_LoaderRec_ {
    T1_Parser parser;
} T1_LoaderRec;
typedef T1_LoaderRec* T1_Loader;

typedef struct T1_FaceRec_ {
    struct {
        FT_Matrix font_matrix;
        FT_Vector font_offset;
    } type1;
    FT_FaceRec root;
} T1_FaceRec;
typedef T1_FaceRec* T1_Face;

#define FT_THROW(e) e
#define Invalid_File_Format 1
#define FT_ABS(x) ((x) < 0 ? -(x) : (x))
#define FT_DivFix(a, b) ((a) / (b))
#define FT_ERROR(x)

int T1_ToFixedArray(T1_Parser parser, int count, FT_Fixed* values, int power);