#include <stddef.h>

typedef unsigned char   FT_Byte;
typedef signed short    FT_Short;
typedef unsigned short  FT_UShort;
typedef signed int      FT_Int;
typedef unsigned int    FT_UInt;
typedef unsigned long   FT_ULong;
typedef int             FT_Error;
typedef int             FT_Bool;

typedef struct FT_StreamRec_*  FT_Stream;
typedef struct FT_FaceRec_*    FT_Face;

struct FT_FaceRec_ {
    FT_Stream  stream;
};

typedef struct TT_HoriHeader_ {
    FT_UShort  number_Of_HMetrics;
} TT_HoriHeader;

typedef struct TT_FaceRec_ {
    struct FT_FaceRec_  root;
    FT_Stream           stream;
    TT_HoriHeader       horizontal;
    void*               vertical;
    FT_ULong            horz_metrics_offset;
    FT_ULong            vert_metrics_offset;
    FT_ULong            horz_metrics_size;
    FT_ULong            vert_metrics_size;
    void*               var;
} *TT_Face;

#define FT_LOCAL_DEF(x) x
#define FT_FACE(x) ((FT_Face)(x))
#define FT_STREAM_SEEK(pos) 0
#define FT_READ_USHORT(val) 0
#define FT_READ_SHORT(val) 0

#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
typedef struct FT_Service_MetricsVariationsRec_ {
    void (*hadvance_adjust)(FT_Face, FT_UInt, FT_Int*);
    void (*vadvance_adjust)(FT_Face, FT_UInt, FT_Int*);
    void (*lsb_adjust)(FT_Face, FT_UInt, FT_Int*);
    void (*tsb_adjust)(FT_Face, FT_UInt, FT_Int*);
} *FT_Service_MetricsVariations;
#endif