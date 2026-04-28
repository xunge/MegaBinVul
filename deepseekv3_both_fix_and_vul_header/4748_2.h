#include <stdint.h>

typedef int32_t FT_Fixed;
typedef int32_t FT_Int;
typedef uint16_t FT_UShort;

typedef struct FT_Vector_ {
    FT_Fixed x;
    FT_Fixed y;
} FT_Vector;

typedef struct FT_Matrix_ {
    FT_Fixed xx;
    FT_Fixed xy;
    FT_Fixed yx;
    FT_Fixed yy;
} FT_Matrix;

typedef struct FT_FaceRec_ {
    FT_UShort units_per_EM;
} FT_FaceRec;
typedef FT_FaceRec* FT_Face;

typedef struct T42_ParserRec_ {
    struct {
        FT_Int error;
    } root;
} *T42_Parser;

typedef struct T42_LoaderRec_ {
    T42_Parser parser;
} *T42_Loader;

typedef struct T42_FaceRec_ {
    struct {
        FT_Matrix font_matrix;
        FT_Vector font_offset;
    } type1;
    FT_FaceRec root;
} *T42_Face;

#define FT_THROW(e) (e)
#define FT_ABS(x) ((x) < 0 ? -(x) : (x))
#define FT_DivFix(a, b) ((a)/(b))
#define FT_ERROR(x)
#define Invalid_File_Format 1

FT_Int T1_ToFixedArray(T42_Parser parser, FT_Int count, FT_Fixed* array, FT_Int decimals);