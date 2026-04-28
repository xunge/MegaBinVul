#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define TRUE true
#define FALSE false

typedef uint32_t UINT32;
typedef bool BOOL;

typedef struct _RECTANGLE_16 {
    int16_t left;
    int16_t top;
    int16_t right;
    int16_t bottom;
} RECTANGLE_16;

typedef struct _REGION16_DATA {
    UINT32 size;
    UINT32 nbRects;
    RECTANGLE_16 rects[1];
} REGION16_DATA;

typedef struct _REGION16 {
    RECTANGLE_16 extents;
    REGION16_DATA* data;
} REGION16;

static REGION16_DATA empty_region = {0};

#define ZeroMemory(ptr, size) memset(ptr, 0, size)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static inline const RECTANGLE_16* region16_rects(const REGION16* region, UINT32* nbRects) {
    *nbRects = region->data->nbRects;
    return region->data->rects;
}

static inline const RECTANGLE_16* region16_extents(const REGION16* region) {
    return &region->extents;
}

static void region16_clear(REGION16* region) {
    if (region->data && region->data != &empty_region) {
        free(region->data);
    }
    region->data = &empty_region;
    region->extents.left = 0;
    region->extents.top = 0;
    region->extents.right = 0;
    region->extents.bottom = 0;
}

static BOOL rectangles_intersection(const RECTANGLE_16* a, const RECTANGLE_16* b, RECTANGLE_16* dst) {
    dst->left = MAX(a->left, b->left);
    dst->top = MAX(a->top, b->top);
    dst->right = MIN(a->right, b->right);
    dst->bottom = MIN(a->bottom, b->bottom);
    return (dst->left < dst->right) && (dst->top < dst->bottom);
}

static REGION16_DATA* allocateRegion(UINT32 nbRects) {
    size_t size = sizeof(REGION16_DATA) + (nbRects - 1) * sizeof(RECTANGLE_16);
    return (REGION16_DATA*)malloc(size);
}

static BOOL rectangle_is_empty(const RECTANGLE_16* rect) {
    return (rect->left >= rect->right) || (rect->top >= rect->bottom);
}

static BOOL region16_union_rect(REGION16* dst, const REGION16* src, const RECTANGLE_16* rect) {
    // Simplified implementation
    return TRUE;
}

static BOOL region16_simplify_bands(REGION16* region) {
    // Simplified implementation
    return TRUE;
}