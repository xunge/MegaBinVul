#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef bool BOOL;
typedef uint32_t UINT32;
typedef uint16_t UINT16;

typedef struct _RECTANGLE_16 {
    UINT16 left;
    UINT16 top;
    UINT16 right;
    UINT16 bottom;
} RECTANGLE_16;

typedef struct _REGION16_DATA {
    UINT32 size;
    UINT32 nbRects;
    RECTANGLE_16 rects[];
} REGION16_DATA;

typedef struct _REGION16 {
    RECTANGLE_16 extents;
    REGION16_DATA* data;
} REGION16;

static REGION16_DATA empty_region = {0};

static inline UINT16 MIN(UINT16 a, UINT16 b) { return (a < b) ? a : b; }
static inline UINT16 MAX(UINT16 a, UINT16 b) { return (a > b) ? a : b; }

static REGION16_DATA* allocateRegion(UINT32 size);
static const RECTANGLE_16* region16_extents(const REGION16* region);
static RECTANGLE_16* region16_extents_noconst(REGION16* region);
static UINT32 region16_n_rects(const REGION16* region);
static RECTANGLE_16* region16_rects_noconst(REGION16* region);
static const RECTANGLE_16* region16_rects(const REGION16* region, UINT32* nbRects);
static BOOL rectangle_contained_in_band(const RECTANGLE_16* currentBand, const RECTANGLE_16* endSrcRect, const RECTANGLE_16* rect);
static void region16_copy_band_with_union(RECTANGLE_16* dstRect, const RECTANGLE_16* currentBand, const RECTANGLE_16* endSrcRect, UINT16 top, UINT16 bottom, const RECTANGLE_16* rect, UINT32* usedRects, const RECTANGLE_16** nextBand, RECTANGLE_16** dstRectPtr);
static BOOL region16_simplify_bands(REGION16* region);