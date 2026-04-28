#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define FILTER_BORDER_STYLE_3 (1 << 0)
#define FILTER_NONZERO_BORDER (1 << 1)
#define FILTER_NONZERO_SHADOW (1 << 2)
#define OUTLINE_BOX 0
#define OUTLINE_BORDER 1
#define OUTLINE_MAX 1000000
#define STROKER_PRECISION 64.0
#define POSITION_PRECISION 8.0
#define MAX_PERSP_SCALE 1000.0

typedef struct ASS_Vector {
    double x, y;
} ASS_Vector;

typedef struct ASS_DVector {
    double x, y;
} ASS_DVector;

typedef struct ASS_Transform {
    ASS_Vector scale;
    ASS_Vector offset;
} ASS_Transform;

typedef struct ASS_Rect {
    double x_min, y_min, x_max, y_max;
} ASS_Rect;

typedef struct Bitmap {
    uint8_t *buffer;
} Bitmap;

typedef struct Outline {
    ASS_Rect cbox;
    bool valid;
} Outline;

typedef struct OutlineHashKey {
    int type;
    union {
        struct {
            Outline *outline;
            int scale_ord_x, scale_ord_y;
            ASS_Vector border;
        } border;
    } u;
} OutlineHashKey;

typedef struct BitmapHashKey {
    Outline *outline;
} BitmapHashKey;

typedef struct BorderHashKey {
    Outline *outline;
    int scale_ord_x, scale_ord_y;
    ASS_Vector border;
} BorderHashKey;

typedef struct GlyphInfo {
    Outline *outline;
    int symbol;
    bool skip;
    Bitmap *bm;
    Bitmap *bm_o;
    double border_x, border_y;
    double hspacing_scaled;
    ASS_Vector advance;
    double asc, desc;
    double scale_x, scale_y;
    double scale_fix;
    ASS_Transform transform;
} GlyphInfo;

typedef struct ASS_Renderer {
    double border_scale;
    struct {
        void *bitmap_cache;
        void *outline_cache;
    } cache;
} ASS_Renderer;

static inline double FFMAX(double a, double b) { return a > b ? a : b; }

void ass_cache_dec_ref(void *ptr);
void ass_cache_inc_ref(void *ptr);
void *ass_cache_get(void *cache, void *key, void *renderer);
bool quantize_transform(double m[3][3], ASS_Vector *pos, ASS_DVector *offset, bool first, BitmapHashKey *key);
void calc_transform_matrix(ASS_Renderer *render_priv, GlyphInfo *info, double m[3][3]);