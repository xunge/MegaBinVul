#include <stdlib.h>
#include <string.h>

typedef int FT_Error;
typedef unsigned long FT_ULong;
typedef int FT_Int;

typedef struct FT_MemoryRec_ {
    void* memory;
} *FT_Memory;

typedef struct FT_LibraryRec_ {
    FT_Memory memory;
} *FT_Library;

typedef struct FT_Bitmap_ {
    int            rows;
    int            width;
    int            pitch;
    unsigned char* buffer;
} FT_Bitmap;

#define FT_EXPORT_DEF(x) x
#define FT_Err_Ok 0
#define FT_QREALLOC(ptr, old_size, new_size) realloc(ptr, new_size)
#define FT_QALLOC(ptr, size) malloc(size)
#define FT_MEM_COPY(dest, src, size) memcpy(dest, src, size)