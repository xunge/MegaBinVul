#include <stddef.h>
#include <stdio.h>

typedef int FT_Error;
typedef struct FT_LibraryRec_ *FT_Library;
typedef struct FT_StreamRec_ *FT_Stream;
typedef long FT_Long;
typedef struct FT_FaceRec_ *FT_Face;
typedef struct FT_MemoryRec_ *FT_Memory;
typedef unsigned char FT_Byte;
typedef unsigned short FT_UShort;

#define FT_Err_Cannot_Open_Resource 0
#define FT_READ_LONG(x) 0
#define FT_READ_USHORT(x) 0
#define FT_ALLOC(p, s) 0
#define FT_FREE(p) 
#define FT_TRACE3(x)
#define FT_Stream_Seek(s, o) 0
#define FT_Stream_Read(s, b, l) 0

struct FT_FaceRec_;
struct FT_LibraryRec_ {
    FT_Memory memory;
};
struct FT_StreamRec_;
struct FT_MemoryRec_;

static FT_Error open_face_from_buffer(FT_Library library, FT_Byte* buffer, FT_Long length, FT_Long face_index, const char* type, FT_Face* aface);