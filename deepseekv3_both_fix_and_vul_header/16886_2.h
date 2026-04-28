#include <stddef.h>

typedef int FT_Error;
typedef int FT_Bool;
typedef struct FT_SizeRec_* FT_Size;
typedef struct FT_FaceRec_* FT_Face;
typedef struct TT_SizeRec_* TT_Size;
typedef struct TT_FaceRec_* TT_Face;

#define FT_LOCAL_DEF(x) x
#define FALSE 0
#define TRUE 1
#define FT_Err_Ok 0
#define FT_THROW(x) (-1)

struct FT_Size_Metrics {
    long x_ppem;
    long y_ppem;
    long x_scale;
    long y_scale;
    long ascender;
    long descender;
    long height;
    long max_advance;
};

struct TT_SizeRec_ {
    struct {
        FT_Bool valid;
        long scale;
        long ppem;
        long x_ratio;
        long y_ratio;
    } ttmetrics;
    struct FT_Size_Metrics hinted_metrics;
    struct FT_Size_Metrics* metrics;
    struct {
        FT_Face face;
        struct FT_Size_Metrics metrics;
    } root;
#ifdef TT_USE_BYTECODE_INTERPRETER
    int cvt_ready;
#endif
};

struct TT_FaceRec_ {
    FT_Bool is_cff2;
    struct {
        unsigned short Flags;
    } header;
    struct {
        long ascender;
        long descender;
        long height;
        long max_advance_width;
        unsigned int units_per_EM;
    } root;
};

#define FT_PIX_ROUND(x) (((x) + 0x8000) >> 16)
#define FT_MulFix(a, b) (((long)(a) * (long)(b)) >> 16)
#define FT_DivFix(a, b) (((long)(a) << 16) / (long)(b))

typedef struct FT_Size_Metrics FT_Size_Metrics;