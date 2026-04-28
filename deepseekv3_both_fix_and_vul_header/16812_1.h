#include <stdint.h>
#include <assert.h>
#include <stddef.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef uint64_t u64;

#define GF_BAD_PARAM 1
#define GF_ISOM_INVALID_FILE 2
#define GF_OK 0
#define GF_ISOM_BOX_TYPE_STCO 0x7374636F

typedef struct {
    u32 sampleDescriptionIndex;
    u32 firstChunk;
    u32 samplesPerChunk;
} GF_StscEntry;

typedef struct {
    u32 type;
    u32 nb_entries;
    u32 *offsets;
} GF_ChunkOffsetBox;

typedef struct {
    u32 type;
    u32 nb_entries;
    u64 *offsets;
} GF_ChunkLargeOffsetBox;

typedef struct {
    u32 sampleCount;
    u32 sampleSize;
} GF_SampleSizeBox;

typedef struct {
    u32 nb_entries;
    GF_StscEntry *entries;
    u32 firstSampleInCurrentChunk;
    u32 currentIndex;
    u32 currentChunk;
    u32 ghostNumber;
} GF_SampleToChunkBox;

typedef struct {
    GF_ChunkOffsetBox *ChunkOffset;
    GF_SampleToChunkBox *SampleToChunk;
    GF_SampleSizeBox *SampleSize;
    u32 r_last_chunk_num;
    u32 r_last_sample_num;
    u32 r_last_offset_in_chunk;
} GF_SampleTableBox;

GF_Err stbl_GetSampleSize(GF_SampleSizeBox *sampleSize, u32 sampleNumber, u32 *size);
void GetGhostNum(GF_StscEntry *ent, u32 index, u32 nb_entries, GF_SampleTableBox *stbl);