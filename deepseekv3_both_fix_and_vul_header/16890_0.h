#include <stddef.h>

typedef struct FT_FaceRec_* FT_Face;
typedef struct CFF_FaceRec_* CFF_Face;
typedef unsigned int FT_UInt;
typedef int FT_Int;
typedef int FT_Error;

typedef struct FT_Service_MetricsVariationsRec_* FT_Service_MetricsVariations;

struct CFF_FaceRec_ {
    FT_Service_MetricsVariations tt_var;
    FT_Service_MetricsVariations var;
};

struct FT_Service_MetricsVariationsRec_ {
    FT_Error (*hadvance_adjust)(FT_Face, FT_UInt, FT_Int*);
};

#define FT_FACE(face) ((FT_Face)(face))