#include <stddef.h>
#include <limits.h>

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

struct FT_StreamRec_;
typedef struct FT_StreamRec_* FT_Stream;

struct FT_FaceRec_;
typedef struct FT_FaceRec_* FT_Face;

#define FT_ERR(e) (e)
#define FT_THROW(e) (e)
#define FT_READ_LONG(var) 0
#define FT_READ_USHORT(var) 0
#define FT_ALLOC(ptr, size) 0
#define FT_FREE(ptr) 
#define FT_TRACE3(x) 
#define FT_Stream_Seek(stream, pos) 0
#define FT_Stream_Read(stream, buffer, count) 0

enum {
    Cannot_Open_Resource,
    Invalid_Offset,
    Array_Too_Large
};

static FT_Error open_face_from_buffer(FT_Library library, FT_Byte* buffer, FT_Long length, FT_Long face_index, const char* format, FT_Face* aface) {
    return 0;
}