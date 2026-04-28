#include <stddef.h>
#include <stdlib.h>

typedef long FT_Long;
typedef int FT_Error;
typedef unsigned char FT_Byte;
typedef unsigned short FT_UShort;
typedef void* FT_Memory;

#define FT_Err_Cannot_Open_Resource 1
#define FT_TRACE3(x)

struct FT_LibraryRec_ {
    FT_Memory memory;
};
typedef struct FT_LibraryRec_* FT_Library;

struct FT_StreamRec_;
typedef struct FT_StreamRec_* FT_Stream;

struct FT_FaceRec_;
typedef struct FT_FaceRec_* FT_Face;

#define FT_READ_LONG(x) 0
#define FT_READ_USHORT(x) 0
#define FT_ALLOC(p, s) 0
#define FT_FREE(p) free(p)
#define FT_Stream_Seek(s, o) 0
#define FT_Stream_Read(s, b, l) 0

static FT_Error open_face_from_buffer(FT_Library library, FT_Byte* buffer, FT_Long length, FT_Long face_index, const char* driver_name, FT_Face* aface);