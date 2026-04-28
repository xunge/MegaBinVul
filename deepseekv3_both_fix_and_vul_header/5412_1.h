#include <stddef.h>

typedef struct FT_MemoryRec_* FT_Memory;
typedef unsigned int FT_UInt;
typedef unsigned long FT_ULong;
typedef signed long FT_Long;
typedef unsigned char FT_Byte;
typedef int FT_Error;

struct FT_StreamRec_ {
    FT_Memory memory;
};

typedef struct FT_StreamRec_* FT_Stream;

#define FT_LOCAL_DEF(x) x
#define FT_THROW(e) (-(e))
#define FT_Err_Ok 0
#define Invalid_File_Format 1
#define FT_NEXT_USHORT(p) (*(p)++ << 8 | *(p)++)
#define FT_NEXT_ULONG(p) (*(p)++ << 24 | *(p)++ << 16 | *(p)++ << 8 | *(p)++)

#define FT_FRAME_EXTRACT(size, buffer) 0
#define FT_FRAME_RELEASE(buffer) 
#define FT_NEW_ARRAY(ptr, count) 0

typedef struct TT_FaceRec_* TT_Face;
struct TT_FaceRec_ {
    FT_Error (*goto_table)(TT_Face, unsigned long, FT_Stream, FT_ULong*);
    FT_Byte* hdmx_table;
    FT_Byte* hdmx_record_sizes;
    FT_UInt hdmx_record_count;
    FT_ULong hdmx_table_size;
    FT_ULong hdmx_record_size;
};

#define TTAG_hdmx 0x68646D78