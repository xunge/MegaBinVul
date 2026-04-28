#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef int GF_Err;
typedef bool Bool;

#define GF_ISOM_INVALID_FILE 1
#define GF_OUT_OF_MEM 2
#define GF_OK 0
#define GF_ISOM_BOX_TYPE_STCO 1
#define GF_ISOM_BOX_TYPE_CO64 2

struct GF_StscEntry {
    u32 sampleDescriptionIndex;
    u32 firstChunk;
    u32 nextChunk;
};

struct GF_Box {
    u32 type;
};

struct GF_SampleToChunkBox {
    u32 nb_entries;
    struct GF_StscEntry *entries;
};

struct GF_MediaBox;

struct GF_ChunkOffsetBox {
    struct GF_Box box;
    u32 nb_entries;
    u32 *offsets;
};

struct GF_ChunkLargeOffsetBox {
    struct GF_Box box;
    u32 nb_entries;
    u64 *offsets;
};

typedef struct GF_SampleToChunkBox GF_SampleToChunkBox;
typedef struct GF_MediaBox GF_MediaBox;
typedef struct GF_Box GF_Box;
typedef struct GF_StscEntry GF_StscEntry;
typedef struct GF_ChunkOffsetBox GF_ChunkOffsetBox;
typedef struct GF_ChunkLargeOffsetBox GF_ChunkLargeOffsetBox;

bool Media_IsSelfContained(struct GF_MediaBox *mdia, u32 sampleDescriptionIndex);
struct GF_Box *gf_isom_box_new(u32 type);
void *gf_malloc(size_t size);