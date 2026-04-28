#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef long FT_Long;
typedef unsigned long FT_ULong;
typedef int FT_Error;
typedef unsigned char FT_Byte;

typedef struct FT_LibraryRec_ {
    void* memory;
} *FT_Library;

typedef struct FT_StreamRec_ {
    int (*seek)(struct FT_StreamRec_*, FT_Long);
    int (*read)(struct FT_StreamRec_*, FT_Byte*, FT_ULong);
} *FT_Stream;

typedef struct FT_FaceRec_ {} *FT_Face;
typedef void* FT_Memory;

#define FT_READ_USHORT(var) (0)
#define FT_READ_ULONG(var) (0)
#define FT_ALLOC(ptr, size) (*(ptr) = malloc(size), (*(ptr) ? 0 : 1))
#define FT_FREE(ptr) free(ptr)
#define FT_TRACE2(x) 
#define FT_TRACE3(x) 
#define FT_TRACE4(x) 
#define FT_THROW(e) (-1)
#define FT_ERR(e) (-1)

static int FT_Stream_Seek(FT_Stream stream, FT_Long offset) {
    return stream->seek(stream, offset);
}

static int FT_Stream_Read(FT_Stream stream, FT_Byte* buffer, FT_ULong count) {
    return stream->read(stream, buffer, count);
}

static FT_Error open_face_from_buffer(FT_Library library, FT_Byte* buffer, 
                                     FT_ULong length, FT_Long face_index, 
                                     const char* driver_name, FT_Face* aface) {
    return 0;
}