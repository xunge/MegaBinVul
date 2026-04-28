#include <stdlib.h>
#include <stddef.h>

typedef long FT_Long;
typedef unsigned char FT_Byte;
typedef int FT_Error;

struct FT_LibraryRec_ {
    struct FT_MemoryRec_ *memory;
};
typedef struct FT_LibraryRec_* FT_Library;

struct FT_MemoryRec_;
typedef struct FT_MemoryRec_* FT_Memory;

struct FT_StreamRec_;
typedef struct FT_StreamRec_* FT_Stream;

struct FT_FaceRec_;
typedef struct FT_FaceRec_* FT_Face;

#define FT_Err_Cannot_Open_Resource 1
#define FT_READ_LONG(var) 0
#define FT_READ_USHORT(var) 0
#define FT_ALLOC(ptr, size) (*(ptr) = malloc(size), *(ptr) ? 0 : 1)
#define FT_FREE(ptr) free(ptr)
#define FT_Stream_Seek(stream, pos) 0
#define FT_Stream_Read(stream, buffer, count) 0

static FT_Error open_face_from_buffer(FT_Library library, FT_Byte* buffer, 
                                     FT_Long size, FT_Long face_index, 
                                     const char* type, FT_Face* aface) {
    return 0;
}