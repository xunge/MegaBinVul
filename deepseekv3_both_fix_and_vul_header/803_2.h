#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BOOL bool
#define TRUE true
#define FALSE false

typedef struct _RECTANGLE_16 {
    int top;
    int bottom;
    int left;
    int right;
} RECTANGLE_16;

typedef struct _REGION16_DATA {
    int nbRects;
    size_t size;
    RECTANGLE_16* rects;
} REGION16_DATA;

typedef struct _REGION16 {
    REGION16_DATA* data;
} REGION16;

static REGION16_DATA empty_region = {0};

static inline void MoveMemory(void* dest, const void* src, size_t len) {
    memmove(dest, src, len);
}

static int region16_n_rects(const REGION16* region) {
    return region->data->nbRects;
}

static RECTANGLE_16* region16_rects_noconst(REGION16* region) {
    return region->data->rects;
}

static RECTANGLE_16* next_band(RECTANGLE_16* band, RECTANGLE_16* endPtr, int* bandItems) {
    RECTANGLE_16* next = band;
    *bandItems = 0;
    while (next < endPtr && next->top == band->top) {
        (*bandItems)++;
        next++;
    }
    return next;
}

static bool band_match(RECTANGLE_16* band1, RECTANGLE_16* band2, RECTANGLE_16* endPtr) {
    int count = band2 - band1;
    if (band2 + count > endPtr)
        return false;
    for (int i = 0; i < count; i++) {
        if (band1[i].left != band2[i].left || band1[i].right != band2[i].right)
            return false;
    }
    return true;
}