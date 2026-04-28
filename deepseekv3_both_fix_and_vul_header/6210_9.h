#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef enum {
    GF_OK,
    GF_BAD_PARAM,
    GF_OUT_OF_MEM
} GF_Err;

typedef struct {
    u32 sampleCount;
    u32 sampleDelta;
} GF_SttsEntry;

typedef struct {
    u32 nb_entries;
    u32 alloc_size;
    GF_SttsEntry *entries;
    u32 r_FirstSampleInEntry;
    u64 w_LastDTS;
    u32 w_currentSampleNum;
} GF_TimeToSampleBox;

typedef struct {
    u32 sampleCount;
} GF_SampleSizeBox;

typedef struct {
    GF_TimeToSampleBox *TimeToSample;
    GF_SampleSizeBox *SampleSize;
} GF_SampleTableBox;

#define CHECK_PACK(x) if (nb_pack == 0) return x;
#define ALLOC_INC(x) (x) = ((x) ? (x)*2 : 1)

static void *gf_malloc(size_t size) { return malloc(size); }
static void *gf_realloc(void *ptr, size_t size) { return realloc(ptr, size); }
static void gf_free(void *ptr) { free(ptr); }