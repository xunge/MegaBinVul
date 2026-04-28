#include <stdlib.h>
#include <stdbool.h>

typedef int GF_Err;
typedef bool Bool;

struct GF_Box {
    int type;
};

typedef struct GF_Box GF_Box;

struct GF_SampleTableBox;
typedef struct GF_SampleTableBox GF_SampleTableBox;
typedef struct GF_TimeToSampleBox GF_TimeToSampleBox;
typedef struct GF_CompositionOffsetBox GF_CompositionOffsetBox;
typedef struct GF_CompositionToDecodeBox GF_CompositionToDecodeBox;
typedef struct GF_SyncSampleBox GF_SyncSampleBox;
typedef struct GF_SampleDescriptionBox GF_SampleDescriptionBox;
typedef struct GF_SampleSizeBox GF_SampleSizeBox;
typedef struct GF_SampleToChunkBox GF_SampleToChunkBox;
typedef struct GF_PaddingBitsBox GF_PaddingBitsBox;
typedef struct GF_ShadowSyncBox GF_ShadowSyncBox;
typedef struct GF_DegradationPriorityBox GF_DegradationPriorityBox;
typedef struct GF_SampleDependencyTypeBox GF_SampleDependencyTypeBox;
typedef struct GF_SubSampleInformationBox GF_SubSampleInformationBox;
typedef struct GF_SubSampleInfoEntry GF_SubSampleInfoEntry;

#define GF_OK 0
#define GF_BAD_PARAM 1

#define GF_ISOM_BOX_TYPE_STTS 0x73747473
#define GF_ISOM_BOX_TYPE_CTTS 0x63747473
#define GF_ISOM_BOX_TYPE_CSLG 0x63736C67
#define GF_ISOM_BOX_TYPE_STSS 0x73747373
#define GF_ISOM_BOX_TYPE_STSD 0x73747364
#define GF_ISOM_BOX_TYPE_STZ2 0x73747A32
#define GF_ISOM_BOX_TYPE_STSZ 0x7374737A
#define GF_ISOM_BOX_TYPE_STSC 0x73747363
#define GF_ISOM_BOX_TYPE_PADB 0x70616462
#define GF_ISOM_BOX_TYPE_CO64 0x636F3634
#define GF_ISOM_BOX_TYPE_STCO 0x7374636F
#define GF_ISOM_BOX_TYPE_STSH 0x73747368
#define GF_ISOM_BOX_TYPE_STDP 0x73746470
#define GF_ISOM_BOX_TYPE_SDTP 0x73647470
#define GF_ISOM_BOX_TYPE_SUBS 0x73756273
#define GF_ISOM_BOX_TYPE_SBGP 0x73626770
#define GF_ISOM_BOX_TYPE_SGPD 0x73677064
#define GF_ISOM_BOX_TYPE_SAIZ 0x7361697A
#define GF_ISOM_BOX_TYPE_SAIO 0x7361696F

#define GF_LOG_WARNING 1
#define GF_LOG_CONTAINER 2

struct GF_SampleTableBox {
    GF_TimeToSampleBox *TimeToSample;
    GF_CompositionOffsetBox *CompositionOffset;
    GF_CompositionToDecodeBox *CompositionToDecode;
    GF_SyncSampleBox *SyncSample;
    GF_SampleDescriptionBox *SampleDescription;
    GF_SampleSizeBox *SampleSize;
    GF_SampleToChunkBox *SampleToChunk;
    GF_PaddingBitsBox *PaddingBits;
    GF_Box *ChunkOffset;
    GF_ShadowSyncBox *ShadowSync;
    GF_DegradationPriorityBox *DegradationPriority;
    GF_SampleDependencyTypeBox *SampleDep;
    void *sub_samples;
    void *sampleGroups;
    void *sampleGroupsDescription;
    void *sai_sizes;
    void *sai_offsets;
};

struct GF_SubSampleInformationBox {
    void *Samples;
};

struct GF_SubSampleInfoEntry {
    int sample_delta;
};

extern Bool use_dump_mode;
extern void *gf_list_new();
extern void gf_list_add(void *list, void *item);
extern void *gf_list_get(void *list, int index);
extern void gf_list_rem(void *list, int index);
extern void gf_isom_box_del(void *box);
extern GF_Err gf_isom_box_add_default(GF_Box *ptr, GF_Box *a);
extern void GF_LOG(int level, int category, const char *format, ...);

#define ERROR_ON_DUPLICATED_BOX(a, ptr) { return GF_BAD_PARAM; }