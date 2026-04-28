#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;
typedef unsigned long long u64;
typedef int s32;
typedef enum {
    GF_OK,
    GF_BAD_PARAM,
    GF_OUT_OF_MEM
} GF_Err;

typedef struct {
    u32 type;
} GF_Box;

typedef struct {
    u32 nb_entries;
    u32 alloc_size;
    u32 *offsets;
} GF_ChunkOffsetBox;

typedef struct {
    u32 nb_entries;
    u32 alloc_size;
    u64 *offsets;
} GF_ChunkLargeOffsetBox;

typedef struct {
    u32 firstChunk;
    u32 samplesPerChunk;
    u32 sampleDescriptionIndex;
    u32 nextChunk;
    u32 isEdited;
} GF_StscEntry;

typedef struct {
    u32 nb_entries;
    u32 alloc_size;
    GF_StscEntry *entries;
    u32 w_lastSampleNumber;
    u32 w_lastChunkNumber;
    u32 currentIndex;
    u32 firstSampleInCurrentChunk;
    u32 currentChunk;
    u32 ghostNumber;
} GF_SampleToChunkBox;

typedef struct {
    GF_Box *ChunkOffset;
    GF_SampleToChunkBox *SampleToChunk;
    void *child_boxes;
} GF_SampleTableBox;

typedef struct {
    GF_SampleTableBox *sampleTable;
} GF_InformationBox;

typedef struct {
    GF_InformationBox *information;
} GF_MediaBox;

#define GF_ISOM_BOX_TYPE_STCO 0x7374636F
#define GF_ISOM_BOX_TYPE_CO64 0x636F3634

#define CHECK_PACK(x) if (nb_pack == 0) { return x; }
#define ALLOC_INC(x) x = ((x) ? (x)*2 : 1)

void *gf_malloc(size_t size);
void *gf_realloc(void *ptr, size_t size);
void gf_free(void *ptr);
GF_Box *gf_isom_box_new_parent(void **parent, u32 type);
void gf_isom_box_del_parent(void **parent, GF_Box *box);
int Media_IsSelfContained(GF_MediaBox *mdia, u32 StreamDescIndex);