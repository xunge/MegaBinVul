#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t Bool;

typedef enum {
    GF_OK,
    GF_ISOM_INVALID_FILE,
    GF_OUT_OF_MEM
} GF_Err;

typedef struct GF_Box {
    u32 type;
} GF_Box;

typedef struct GF_ChunkOffsetBox {
    GF_Box box;
    u32 nb_entries;
    u32 *offsets;
} GF_ChunkOffsetBox;

typedef struct GF_ChunkLargeOffsetBox {
    GF_Box box;
    u32 nb_entries;
    u64 *offsets;
} GF_ChunkLargeOffsetBox;

typedef struct GF_StscEntry {
    u32 firstChunk;
    u32 samplesPerChunk;
    u32 sampleDescriptionIndex;
    u32 nextChunk;
} GF_StscEntry;

typedef struct GF_SampleToChunkBox {
    u32 nb_entries;
    GF_StscEntry *entries;
} GF_SampleToChunkBox;

typedef struct GF_MediaBox {
    // Placeholder for MediaBox structure
} GF_MediaBox;

#define GF_ISOM_BOX_TYPE_STCO 0x7374636F
#define GF_ISOM_BOX_TYPE_CO64 0x636F3634

static GF_Box *gf_isom_box_new(u32 type);
static void *gf_malloc(size_t size);
static Bool Media_IsSelfContained(GF_MediaBox *mdia, u32 sampleDescriptionIndex);