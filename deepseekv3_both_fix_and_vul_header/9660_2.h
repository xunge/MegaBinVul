#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

typedef int FT_Error;
typedef unsigned char FT_Byte;
typedef unsigned int FT_UInt;
typedef int FT_Int;
typedef long FT_Pos;
typedef unsigned long FT_ULong;
typedef void* FT_Memory;

typedef struct FT_Vector {
    FT_Pos x;
    FT_Pos y;
} FT_Vector;

typedef struct FT_Outline {
    FT_Int n_points;
    FT_Vector* points;
} FT_Outline;

typedef struct FT_BBox {
    FT_Pos xMin, yMin, xMax, yMax;
} FT_BBox;

typedef struct FT_Bitmap {
    FT_UInt width, rows, pitch;
    FT_Byte* buffer;
    FT_Int pixel_mode;
    FT_Int num_grays;
} FT_Bitmap;

typedef struct FT_GlyphSlotRec {
    int format;
    FT_Outline outline;
    FT_Bitmap bitmap;
    struct {
        unsigned int flags;
    }* internal;
    FT_Int bitmap_left;
    FT_Int bitmap_top;
} *FT_GlyphSlot;

typedef struct FT_Raster_Params {
    FT_Bitmap* target;
    FT_Outline* source;
    FT_Int flags;
} FT_Raster_Params;

typedef struct FT_RendererRec {
    struct {
        FT_Memory memory;
    } root;
    int glyph_format;
    void* raster;
    FT_Error (*raster_render)(void*, FT_Raster_Params*);
} *FT_Renderer;

typedef int FT_Render_Mode;

#define FT_PIX_FLOOR(x) ((x) & ~63)
#define FT_PIX_CEIL(x) (((x) + 63) & ~63)
#define FT_PAD_CEIL(x, a) (((x) + (a)-1) & ~((a)-1))
#define FT_FREE(ptr) free(ptr)
#define FT_ALLOC(ptr, size) (*(ptr) = malloc(size), *(ptr) ? 0 : 1)
#define FT_GLYPH_OWN_BITMAP (1 << 0)
#define FT_GLYPH_FORMAT_BITMAP 1
#define FT_PIXEL_MODE_GRAY 2
#define FT_RASTER_FLAG_AA (1 << 0)
#define FT_RENDER_MODE_LCD 1
#define FT_RENDER_MODE_LCD_V 2
#define Smooth_Err_Invalid_Argument 1
#define Smooth_Err_Cannot_Render_Glyph 2
#define Smooth_Err_Raster_Overflow 3
#define Smooth_Err_Invalid_Pixel_Size 4
#define FT_INT_MAX INT_MAX
#define FT_UINT_MAX UINT_MAX

static void FT_Outline_Translate(FT_Outline* outline, FT_Pos x, FT_Pos y);
static void FT_Outline_Get_CBox(const FT_Outline* outline, FT_BBox* acbox);
static void ft_memcpy(void* dest, const void* src, size_t n);