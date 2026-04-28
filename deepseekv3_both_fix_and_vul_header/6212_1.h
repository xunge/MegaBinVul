#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;
typedef unsigned char Bool;

#define GF_OK 0
#define GF_OUT_OF_MEM 1
#define GF_ISOM_INVALID_FILE 2

#define CHECK_PACK(x) if (x) return x;
#define ALLOC_INC(x) x = (x) ? (x)*2 : 4

typedef struct {
    u32 sampleSize;
    u32 sampleCount;
    u32 alloc_size;
    u32 *sizes;
    u32 max_size;
    u32 total_size;
    u32 total_samples;
} GF_SampleSizeBox;

typedef struct {
    GF_SampleSizeBox *SampleSize;
} GF_SampleTableBox;

typedef int GF_Err;

void *gf_realloc(void *ptr, size_t size);