#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

typedef uint32_t u32;
typedef int32_t GF_Err;

#define GF_OK 0
#define GF_OUT_OF_MEM -1
#define GF_ISOM_INVALID_FILE -2

#define GF_LOG_ERROR 1
#define GF_LOG_CONTAINER 2

#define ISOM_DECREASE_SIZE(box, val) ((box)->size -= (val))

typedef struct {
    u32 firstChunk;
    u32 samplesPerChunk;
    u32 sampleDescriptionIndex;
    u32 isEdited;
    u32 nextChunk;
} GF_StscEntry;

typedef struct {
    u32 size;
    u32 nb_entries;
    u32 alloc_size;
    GF_StscEntry *entries;
    u32 currentIndex;
    u32 firstSampleInCurrentChunk;
    u32 currentChunk;
    u32 ghostNumber;
} GF_SampleToChunkBox;

typedef struct GF_Box GF_Box;

typedef struct {
    // BitStream implementation details would go here
} GF_BitStream;

u32 gf_bs_read_u32(GF_BitStream *bs);
void *gf_malloc(size_t size);
void GF_LOG(int level, int category, const char *format, ...);