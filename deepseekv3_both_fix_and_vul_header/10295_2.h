#include <stddef.h>

typedef int FT_Error;
typedef unsigned char FT_Bool;

#define FT_LOCAL_DEF(x) x
#define FALSE 0
#define TRUE 1
#define FT_THROW(e) (-(e))
#define FT_Err_Ok 0
#define Invalid_PPem 1
#define FT_PIX_ROUND(x) (x)
#define FT_MulFix(a,b) ((a)*(b))
#define FT_DivFix(a,b) ((a)/(b))

struct FT_Size_Metrics {
    long x_ppem;
    long y_ppem;
    long x_scale;
    long y_scale;
    long ascender;
    long descender;
    long height;
    long max_advance;
    long units_per_EM;
};

struct TT_Size_Metrics {
    FT_Bool valid;
    long scale;
    long ppem;
    long x_ratio;
    long y_ratio;
};

struct FT_FaceRec_ {
    long ascender;
    long descender;
    long height;
    long max_advance_width;
    long units_per_EM;
};

struct TT_FaceRec_ {
    struct FT_FaceRec_ root;
    FT_Bool isCFF2;
    struct {
        int Flags;
    } header;
};

struct FT_SizeRec_ {
    struct FT_FaceRec_* face;
    struct FT_Size_Metrics metrics;
};

struct TT_SizeRec_ {
    struct FT_SizeRec_ root;
    struct TT_Size_Metrics ttmetrics;
    struct FT_Size_Metrics metrics;
#ifdef TT_USE_BYTECODE_INTERPRETER
    int cvt_ready;
#endif
};

typedef struct TT_FaceRec_* TT_Face;
typedef struct TT_SizeRec_* TT_Size;
typedef struct FT_Size_Metrics FT_Size_Metrics;