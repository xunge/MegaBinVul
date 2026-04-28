#include <stdlib.h>

typedef struct GF_Box GF_Box;
typedef struct GF_SampleTableBox {
    GF_Box *ChunkOffset;
    void *CompositionOffset;
    void *CompositionToDecode;
    void *DegradationPriority;
    void *SampleDescription;
    void *SampleSize;
    void *SampleToChunk;
    void *ShadowSync;
    void *SyncSample;
    void *TimeToSample;
    void *SampleDep;
    void *PaddingBits;
    void *sub_samples;
    void *sampleGroups;
    void *sampleGroupsDescription;
    void *sai_sizes;
    void *sai_offsets;
    struct {
        void *sample_num;
    } *traf_map;
} GF_SampleTableBox;

void gf_isom_box_del(GF_Box *box);
void gf_isom_box_array_del(void *array);
void gf_free(void *ptr);