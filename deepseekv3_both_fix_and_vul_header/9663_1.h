#include <stddef.h>
#include <stdio.h>

typedef int FT_Error;
typedef long FT_Long;
typedef unsigned short FT_UShort;
typedef unsigned char FT_Byte;

struct FT_MemoryRec_;
typedef struct FT_MemoryRec_* FT_Memory;

struct FT_LibraryRec_ {
    FT_Memory memory;
};
typedef struct FT_LibraryRec_* FT_Library;

struct FT_StreamRec_ {
    void* descriptor;
    unsigned long pos;
    unsigned long base;
    unsigned long size;
    unsigned long read;
    unsigned long close;
    unsigned long memory;
    unsigned long cursor;
    unsigned long limit;
};
typedef struct FT_StreamRec_* FT_Stream;

typedef struct FT_FaceRec_* FT_Face;

#define FT_Err_Cannot_Open_Resource 1
#define FT_READ_LONG(x) 0
#define FT_READ_USHORT(x) 0
#define FT_ALLOC(p, s) 0
#define FT_FREE(p) 
#define FT_Stream_Seek(s, o) 0
#define FT_Stream_Read(s, b, l) 0

static FT_Error open_face_from_buffer(FT_Library library, FT_Byte* buffer, FT_Long length, FT_Long face_index, const char* driver_name, FT_Face* aface) {
    return 0;
}