#include <stddef.h>

typedef int FT_Error;
typedef unsigned short FT_UShort;
typedef unsigned int FT_UInt;
typedef unsigned long FT_ULong;
typedef unsigned long FT_UInt32;

typedef struct FT_StreamRec {
    size_t size;
} *FT_Stream;

typedef struct SFNT_HeaderRec {
    FT_ULong offset;
    FT_UShort num_tables;
} *SFNT_Header;

typedef struct TT_TableRec {
    FT_ULong Tag;
    FT_ULong CheckSum;
    FT_ULong Offset;
    FT_ULong Length;
} TT_TableRec;

typedef struct {
    const char* name;
    size_t size;
    size_t offset;
} FT_Frame_Field;

#define FT_FRAME_START(size) { NULL, size, 0 }
#define FT_FRAME_END { NULL, 0, 0 }
#define FT_FRAME_ULONG(field) { #field, sizeof(FT_ULong), offsetof(TT_TableRec, field) }

#define FT_STREAM_SEEK(pos) 0
#define FT_STREAM_READ_FIELDS(fields, ptr) 0
#define FT_READ_ULONG(val) 0
#define FT_TRACE2(args)
#define FT_THROW(code) (-1)
#define FT_Err_Ok 0

#define TTAG_head 0x68656164UL
#define TTAG_bhed 0x62686564UL
#define TTAG_SING 0x53494E47UL
#define TTAG_META 0x4D455441UL