#include <stddef.h>
#include <stdint.h>

typedef int FT_Error;
typedef unsigned long FT_ULong;
typedef unsigned short FT_UShort;
typedef char FT_Char;
typedef int FT_Int;
typedef struct FT_MemoryRec_* FT_Memory;
typedef struct FT_StreamRec_* FT_Stream;

#define FT_LOCAL_DEF(x) x
#define FT_TRACE2(x) 
#define FT_STREAM_POS() 0
#define FT_READ_ULONG(x) 0
#define FT_STREAM_READ_FIELDS(x, y) 0
#define FT_THROW(x) 0
#define FT_QNEW_ARRAY(x, y) 0
#define FT_STREAM_SEEK(x) 0
#define FT_FRAME_ENTER(x) 0
#define FT_GET_TAG4() 0
#define FT_GET_ULONG() 0
#define FT_GET_USHORT() 0
#define FT_FRAME_EXIT() 
#define TTAG_OTTO 0

struct TT_FaceRec_;
typedef struct TT_FaceRec_* TT_Face;

struct TT_TableRec {
    FT_ULong Tag;
    FT_ULong CheckSum;
    FT_ULong Offset;
    FT_ULong Length;
};
typedef struct TT_TableRec TT_TableRec;

struct SFNT_HeaderRec {
    FT_ULong offset;
    FT_ULong format_tag;
    FT_UShort num_tables;
    FT_UShort search_range;
    FT_UShort entry_selector;
    FT_UShort range_shift;
};
typedef struct SFNT_HeaderRec SFNT_HeaderRec;

struct FT_Frame_Field {
    const char* name;
    size_t offset;
    size_t size;
};
typedef struct FT_Frame_Field FT_Frame_Field;

#define FT_FRAME_START(x) {NULL, 0, 0}
#define FT_FRAME_USHORT(x) {#x, offsetof(SFNT_HeaderRec, x), sizeof(FT_UShort)}
#define FT_FRAME_END {NULL, 0, 0}

struct FT_StreamRec_ {
    FT_Memory memory;
    size_t size;
};

struct TT_FaceRec_ {
    FT_UShort num_tables;
    FT_ULong format_tag;
    TT_TableRec* dir_tables;
};

FT_Error check_table_dir(SFNT_HeaderRec* sfnt, FT_Stream stream);