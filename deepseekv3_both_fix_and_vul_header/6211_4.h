#include <stdlib.h>
#include <string.h>

typedef int GF_Err;
typedef unsigned int u32;
#define GF_OK 0
#define GF_OUT_OF_MEM 1
#define GF_ISOM_INVALID_FILE 2

#define CHECK_PACK(x) if (x) return x;
#define ALLOC_INC(size) size = (size) ? (size)*2 : 1

typedef struct {
    u32 sampleCount;
    u32 sampleDelta;
} GF_SttsEntry;

typedef struct {
    GF_SttsEntry *entries;
    u32 nb_entries;
    u32 alloc_size;
    u32 max_ts_delta;
} GF_TimeToSampleBox;

typedef struct {
    GF_TimeToSampleBox *TimeToSample;
} GF_SampleTableBox;

static void *gf_realloc(void *ptr, size_t size) {
    return realloc(ptr, size);
}