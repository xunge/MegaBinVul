#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;

#define GF_OK 0
#define GF_ISOM_INVALID_FILE 1
#define GF_OUT_OF_MEM 2
#define GF_LOG_ERROR 1
#define GF_LOG_CONTAINER 1
#define SIZE_MAX UINT_MAX
#define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box GF_Box;
typedef struct GF_DttsEntry {
    u32 sampleCount;
    s32 decodingOffset;
} GF_DttsEntry;

typedef struct GF_CompositionOffsetBox {
    GF_Box *s;
    u32 nb_entries;
    u32 alloc_size;
    GF_DttsEntry *entries;
    u32 version;
    s32 max_cts_delta;
    u64 size;
    u32 w_LastSampleNumber;
} GF_CompositionOffsetBox;

#define ISOM_DECREASE_SIZE(ptr, val) (ptr)->size -= (val)

void GF_LOG(int level, int category, const char *format, ...);
u32 gf_bs_read_u32(GF_BitStream *bs);
s32 gf_bs_read_int(GF_BitStream *bs, int bits);
void *gf_malloc(size_t size);