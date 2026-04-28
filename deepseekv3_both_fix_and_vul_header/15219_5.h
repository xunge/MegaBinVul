#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned char Guchar;
typedef int GBool;
#define gFalse 0
#define gTrue 1

typedef struct SplashGlyphBitmap {
    int x, y, w, h;
    Guchar *data;
    GBool aa;
    GBool freeData;
} SplashGlyphBitmap;

typedef struct SplashClip {
    int testRect(int, int, int, int);
} SplashClip;

typedef int SplashClipResult;
#define splashClipAllOutside 0

typedef struct SplashFTFont {
    GBool makeGlyph(int c, int xFrac, int yFrac,
                   SplashGlyphBitmap *bitmap, int x0, int y0, 
                   SplashClip *clip, SplashClipResult *clipRes);
} SplashFTFont;

typedef struct FT_Glyph_Metrics {
    long width;
    long height;
    long horiBearingX;
    long horiBearingY;
} FT_Glyph_Metrics;

typedef struct FT_Bitmap_ {
    int width;
    int rows;
    int pitch;
    unsigned char* buffer;
} FT_Bitmap;

typedef struct FT_GlyphSlotRec_ {
    FT_Glyph_Metrics metrics;
    int bitmap_left;
    int bitmap_top;
    FT_Bitmap bitmap;
} FT_GlyphSlotRec;

typedef struct FT_SizeRec_ {
    void* size;
} FT_SizeRec;

typedef struct FT_FaceRec_ {
    FT_GlyphSlotRec* glyph;
    FT_SizeRec* size;
} FT_FaceRec;

typedef struct SplashFTFontFile {
    FT_FaceRec* face;
    unsigned short *codeToGID;
    int codeToGIDLen;
    GBool trueType;
} SplashFTFontFile;

typedef double SplashCoord;

typedef struct FT_Vector {
    long x;
    long y;
} FT_Vector;

typedef FT_GlyphSlotRec* FT_GlyphSlot;
typedef unsigned int FT_UInt;
typedef long FT_Pos;

typedef struct FT_Matrix {
    long xx, xy;
    long yx, yy;
} FT_Matrix;

typedef int FT_Load_Flags;
#define FT_LOAD_DEFAULT 0
#define FT_LOAD_NO_HINTING (1 << 5)
#define FT_LOAD_NO_BITMAP (1 << 6)

typedef enum {
    ft_render_mode_normal,
    ft_render_mode_mono
} FT_Render_Mode;

extern int splashFontFractionMul;
extern GBool aa;
extern FT_Matrix matrix;
extern void *fontFile;
extern FT_SizeRec *sizeObj;

static inline int splashRound(double x) {
    return (int)(x + 0.5);
}

static inline void *gmalloc(size_t size) {
    return malloc(size);
}

static inline void *gmallocn(size_t nmemb, size_t size) {
    return malloc(nmemb * size);
}

static inline int FT_Load_Glyph(FT_FaceRec* face, FT_UInt glyph_index, FT_Load_Flags load_flags) {
    return 0;
}

static inline int FT_Render_Glyph(FT_GlyphSlot slot, FT_Render_Mode render_mode) {
    return 0;
}

static inline void FT_Set_Transform(FT_FaceRec* face, FT_Matrix* matrix, FT_Vector* delta) {
}