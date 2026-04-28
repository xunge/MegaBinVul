#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define FT_EXPORT_DEF(x) x
#define FT_THROW(x) FT_Err_##x

typedef int FT_Error;
typedef long FT_Long;
typedef unsigned long FT_ULong;
typedef int FT_Int;
typedef unsigned char FT_Byte;

typedef struct FT_MemoryRec_ {
    void* memory;
} *FT_Memory;

typedef struct FT_LibraryRec_ {
    FT_Memory memory;
} *FT_Library;

typedef struct FT_Bitmap_ {
    int pixel_mode;
    int width;
    int rows;
    int pitch;
    unsigned char* buffer;
    int num_grays;
} FT_Bitmap;

enum {
    FT_PIXEL_MODE_NONE = 0,
    FT_PIXEL_MODE_MONO,
    FT_PIXEL_MODE_GRAY,
    FT_PIXEL_MODE_GRAY2,
    FT_PIXEL_MODE_GRAY4,
    FT_PIXEL_MODE_LCD,
    FT_PIXEL_MODE_LCD_V,
    FT_PIXEL_MODE_BGRA,
    FT_PIXEL_MODE_MAX
};

enum {
    FT_Err_Ok = 0,
    FT_Err_Invalid_Library_Handle,
    FT_Err_Invalid_Argument
};

#define FT_ULONG_MAX ULONG_MAX
#define FT_ARRAY_COPY(d, s, c) memcpy(d, s, c)
#define FT_QREALLOC(p, c, n) realloc(p, n)

static FT_Byte ft_gray_for_premultiplied_srgb_bgra(const FT_Byte* ss) {
    return ss[0];  // Simplified implementation
}