#include <stddef.h>

typedef long FT_Error;
typedef unsigned long FT_ULong;

#define FT_BASE_DEF(x) x
#define FT_Err_Ok 0
#define FT_Err_Invalid_Stream_Operation 1
#define FT_DEBUG_MEMORY
#define FT_ASSERT(cond) ((void)0)
#define FT_ERROR(args) ((void)0)
#define FT_QALLOC(ptr,size) 0
#define FT_FREE(ptr) ((void)0)

typedef struct FT_MemoryRec_* FT_Memory;

typedef struct FT_StreamRec_ {
    unsigned char* base;
    unsigned char* cursor;
    unsigned char* limit;
    FT_ULong size;
    FT_ULong pos;
    FT_Memory memory;
    FT_ULong (*read)(struct FT_StreamRec_*, FT_ULong, unsigned char*, FT_ULong);
} *FT_Stream;

extern void* ft_mem_qalloc(FT_Memory memory, FT_ULong size, FT_Error* error);