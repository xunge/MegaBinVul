#include <stddef.h>

typedef long FT_Fixed;
typedef unsigned short FT_UShort;
typedef int FT_Int;
typedef int FT_Error;

struct FT_Vector {
    FT_Fixed x;
    FT_Fixed y;
};

struct FT_Matrix {
    FT_Fixed xx, xy;
    FT_Fixed yx, yy;
};

struct FT_FaceRec_ {
    FT_UShort units_per_EM;
};

struct CID_FaceDictRec_ {
    struct FT_Matrix font_matrix;
    struct FT_Vector font_offset;
};

struct CID_FaceRec_ {
    struct FT_FaceRec_ root;
    struct {
        int num_dicts;
        struct CID_FaceDictRec_* font_dicts;
    } cid;
};

struct CID_Parser_ {
    int num_dict;
};

#define FT_CALLBACK_DEF(x) x
#define FT_THROW(x) (-1)
#define FT_Err_Ok 0
#define FT_ABS(x) ((x) < 0 ? -(x) : (x))
#define FT_DivFix(a, b) ((FT_Fixed)(((long)(a) << 16) / (b)))
#define FT_ERROR(x)

typedef struct CID_FaceRec_* CID_Face;
typedef struct CID_Parser_ CID_Parser;
typedef struct CID_FaceDictRec_* CID_FaceDict;
typedef struct FT_FaceRec_* FT_Face;
typedef struct FT_Matrix FT_Matrix;
typedef struct FT_Vector FT_Vector;

extern FT_Int cid_parser_to_fixed_array(CID_Parser* parser, int count, FT_Fixed* array, int power);