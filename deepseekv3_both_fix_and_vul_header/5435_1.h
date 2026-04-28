#include <stddef.h>

typedef unsigned long FT_ULong;
typedef int FT_Error;
typedef unsigned char FT_Byte;

typedef struct FT_StreamRec_* FT_Stream;
typedef struct TT_FaceRec_* TT_Face;
typedef struct TT_SBitDecoderRec_* TT_SBitDecoder;
typedef struct TT_SBit_MetricsRec_ TT_SBit_MetricsRec;

#define TTAG_CBDT 0x43424454
#define TTAG_EBDT 0x45424454
#define TTAG_bdat 0x62646174

#define FT_THROW(e) (-1)
#define FT_STREAM_POS() (0)
#define FT_NEXT_ULONG(p) (*(FT_ULong*)(p))

struct FT_GlyphRec_ {
    int bitmap;
};

struct FT_FaceRec_ {
    FT_Stream stream;
    struct FT_GlyphRec_* glyph;
};

struct TT_SBitDecoderRec_ {
    TT_Face face;
    FT_Stream stream;
    void* bitmap;
    TT_SBit_MetricsRec* metrics;
    int metrics_loaded;
    int bitmap_allocated;
    FT_ULong ebdt_start;
    FT_ULong ebdt_size;
    FT_Byte* eblc_base;
    FT_Byte* eblc_limit;
    FT_ULong strike_index_array;
    FT_ULong strike_index_count;
    FT_Byte bit_depth;
};

struct TT_FaceRec_ {
    struct FT_FaceRec_ root;
    FT_ULong (*goto_table)(TT_Face, int, FT_Stream, FT_ULong*);
    FT_Byte* sbit_table;
    FT_ULong sbit_table_size;
};