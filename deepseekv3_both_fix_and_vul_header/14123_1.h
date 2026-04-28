#include <stdint.h>

typedef uint32_t u32;

typedef struct {
    u32 firstChunk;
    u32 nextChunk;
} GF_StscEntry;

typedef struct {
    u32 type;
    u32 nb_entries;
} GF_ChunkOffsetBox;

typedef struct {
    u32 type;
    u32 nb_entries;
} GF_ChunkLargeOffsetBox;

typedef struct {
    GF_StscEntry *entries;
    u32 ghostNumber;
} GF_SampleToChunkBox;

typedef struct {
    GF_ChunkOffsetBox *ChunkOffset;
    GF_SampleToChunkBox *SampleToChunk;
} GF_SampleTableBox;

#define GF_ISOM_BOX_TYPE_STCO 0x7374636F