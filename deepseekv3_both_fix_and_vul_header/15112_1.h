#include <stddef.h>
#include <stdlib.h>

typedef int FT_Error;
typedef struct FT_RendererRec_* FT_Renderer;
typedef struct FT_GlyphSlotRec_* FT_GlyphSlot;
typedef unsigned int FT_Render_Mode;
typedef struct FT_Vector_ FT_Vector;
typedef struct FT_Outline_ FT_Outline;
typedef struct FT_BBox_ FT_BBox;
typedef unsigned int FT_UInt;
typedef struct FT_Bitmap_ FT_Bitmap;
typedef struct FT_MemoryRec_* FT_Memory;
typedef int FT_Int;
typedef long FT_Pos;
typedef struct FT_Raster_Params_ FT_Raster_Params;
typedef unsigned long FT_ULong;
typedef unsigned char FT_Byte;

#define FT_PIX_FLOOR(x) ((x) & ~63)
#define FT_PIX_CEIL(x) (((x) + 63) & ~63)
#define FT_PAD_CEIL(x, a) (((x) + (a)-1) & ~((a)-1))
#define FT_FREE(p) free(p)
#define FT_ALLOC(p, s) (*(p) = malloc(s), *(p) == NULL ? 1 : 0)
#define FT_RASTER_FLAG_AA 1
#define FT_GLYPH_OWN_BITMAP (1 << 0)

#define FT_RENDER_MODE_LCD 1
#define FT_RENDER_MODE_LCD_V 2
#define FT_GLYPH_FORMAT_BITMAP 1
#define FT_PIXEL_MODE_GRAY 1

#define Smooth_Err_Invalid_Argument 1
#define Smooth_Err_Cannot_Render_Glyph 2
#define Smooth_Err_Raster_Overflow 3

struct FT_Vector_ {
    FT_Pos x;
    FT_Pos y;
};

struct FT_Outline_ {
    FT_Vector* points;
    FT_UInt n_points;
};

struct FT_BBox_ {
    FT_Pos xMin, yMin;
    FT_Pos xMax, yMax;
};

struct FT_Bitmap_ {
    FT_Byte* buffer;
    FT_UInt width;
    FT_UInt rows;
    FT_UInt pitch;
    FT_Int pixel_mode;
    FT_UInt num_grays;
};

struct FT_GlyphSlotRec_ {
    FT_Outline outline;
    FT_Bitmap bitmap;
    struct {
        unsigned int flags;
    } * internal;
    struct {
        FT_Error (*lcd_filter_func)(FT_Bitmap*, FT_Render_Mode, void*);
        FT_Int lcd_extra;
    } * library;
    FT_Int format;
    FT_Int bitmap_left;
    FT_Int bitmap_top;
};

struct FT_RendererRec_ {
    FT_Memory memory;
    struct {
        FT_Memory memory;
    } root;
    void* raster;
    FT_Error (*raster_render)(void*, FT_Raster_Params*);
    FT_UInt glyph_format;
};

struct FT_Raster_Params_ {
    FT_Bitmap* target;
    FT_Outline* source;
    int flags;
};

static inline void ft_memcpy(void* dest, const void* src, size_t n) {
    char* d = dest;
    const char* s = src;
    while (n--) *d++ = *s++;
}

static inline void FT_Outline_Translate(FT_Outline* outline, FT_Pos xOffset, FT_Pos yOffset) {
    FT_Vector* vec = outline->points;
    FT_UInt count = outline->n_points;
    while (count--) {
        vec->x += xOffset;
        vec->y += yOffset;
        vec++;
    }
}

static inline void FT_Outline_Get_CBox(const FT_Outline* outline, FT_BBox* cbox) {
    if (outline->n_points == 0) {
        cbox->xMin = cbox->xMax = cbox->yMin = cbox->yMax = 0;
        return;
    }
    FT_Vector* vec = outline->points;
    cbox->xMin = cbox->xMax = vec->x;
    cbox->yMin = cbox->yMax = vec->y;
    FT_UInt count = outline->n_points - 1;
    while (count--) {
        vec++;
        if (vec->x < cbox->xMin) cbox->xMin = vec->x;
        if (vec->x > cbox->xMax) cbox->xMax = vec->x;
        if (vec->y < cbox->yMin) cbox->yMin = vec->y;
        if (vec->y > cbox->yMax) cbox->yMax = vec->y;
    }
}