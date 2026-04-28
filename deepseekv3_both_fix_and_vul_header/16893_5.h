#include <stddef.h>

typedef unsigned long FT_ULong;
typedef int FT_Error;
#define FT_Err_Ok 0

typedef struct FT_SizeRec_* FT_Size;
typedef struct TT_FaceRec_* TT_Face;
typedef struct TT_SizeRec_* TT_Size;
typedef struct SFNT_ServiceRec_* SFNT_Service;

struct FT_Size_Metrics {
    FT_ULong dummy;
};

typedef struct FT_Size_Metrics FT_Size_Metrics;

struct FT_FaceRec_ {
    int is_scalable;
};

struct FT_SizeRec_ {
    struct FT_FaceRec_* face;
    struct FT_Size_Metrics metrics;
};

struct TT_FaceRec_ {
    struct SFNT_ServiceRec_* sfnt;
};

struct TT_SizeRec_ {
    FT_ULong strike_index;
};

struct SFNT_ServiceRec_ {
    FT_Error (*load_strike_metrics)(TT_Face, FT_ULong, FT_Size_Metrics*);
};

#define FT_IS_SCALABLE(face) ((face)->is_scalable)

void FT_Select_Metrics(struct FT_FaceRec_* face, FT_ULong strike_index);
void tt_size_reset(TT_Size ttsize, ...);