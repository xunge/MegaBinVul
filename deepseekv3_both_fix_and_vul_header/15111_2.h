#include <stddef.h>
#include <stdio.h>
#include <string.h>

typedef int FT_Error;
typedef unsigned int FT_UInt;
typedef unsigned long FT_ULong;
typedef unsigned short FT_UShort;
typedef int FT_Bool;

struct FT_MemoryRec_;
typedef struct FT_MemoryRec_* FT_Memory;

struct FT_StreamRec_ {
    FT_Memory memory;
};

struct CFF_CharsetRec_ {
    FT_ULong offset;
    FT_UInt format;
    FT_UShort* sids;
    FT_UShort* cids;
};

typedef struct FT_StreamRec_* FT_Stream;
typedef struct CFF_CharsetRec_* CFF_Charset;

#define CFF_Err_Ok 0
#define CFF_Err_Invalid_File_Format 1

#define FT_STREAM_SEEK(offset) 0
#define FT_READ_BYTE(var) 0
#define FT_READ_USHORT(var) 0
#define FT_NEW_ARRAY(ptr, count) 0
#define FT_FRAME_ENTER(size) 0
#define FT_FRAME_EXIT()
#define FT_GET_USHORT() 0
#define FT_FREE(ptr) free(ptr)
#define FT_ARRAY_COPY(dest, src, count) memcpy(dest, src, (count) * sizeof(*(dest)))
#define FT_ERROR(args) fprintf(stderr, args)

static const FT_UShort cff_isoadobe_charset[229];
static const FT_UShort cff_expert_charset[166];
static const FT_UShort cff_expertsubset_charset[87];

static FT_Error cff_charset_compute_cids(CFF_Charset charset, FT_UInt num_glyphs, FT_Memory memory);