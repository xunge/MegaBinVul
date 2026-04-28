#include <stddef.h>
#include <stdint.h>

typedef struct FT_StreamRec_* FT_Stream;
typedef struct TT_FaceRec_* TT_Face;
typedef int FT_Error;
typedef unsigned long FT_ULong;
typedef unsigned char FT_Byte;
typedef unsigned int FT_UInt;
typedef uint32_t FT_UInt32;

#define FT_LOCAL_DEF(x) x
#define TTAG_kern 0x6B65726E
#define FT_THROW(e) (-1)
#define FT_FRAME_EXTRACT(size, buffer) (0)
#define FT_NEXT_USHORT(p) (0)
#define FT_NEXT_ULONG(p) (0)
#define FT_ERROR(x)

struct TT_FaceRec_ {
    FT_Error (*goto_table)(TT_Face, unsigned int, FT_Stream, FT_ULong*);
    FT_Byte* kern_table;
    FT_ULong kern_table_size;
    FT_UInt num_kern_tables;
    FT_UInt32 kern_avail_bits;
    FT_UInt32 kern_order_bits;
};