#include <stdint.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef uint64_t u64;

#define GF_BAD_PARAM 1
#define GF_OUT_OF_MEM 2
#define GF_OK 0

#define RAP 1
#define SAP_TYPE_2 2
#define RAP_REDUNDANT 3

typedef struct GF_ISOSample {
    u64 DTS;
    u32 dataLength;
    u32 nb_pack;
    u32 CTS_Offset;
    u32 IsRAP;
} GF_ISOSample;

typedef struct GF_Box {
    // minimal definition
} GF_Box;

typedef struct GF_CompositionOffsetBox {
    // minimal definition
} GF_CompositionOffsetBox;

typedef struct GF_SyncSampleBox {
    // minimal definition
} GF_SyncSampleBox;

typedef struct GF_ShadowSyncBox {
    // minimal definition
} GF_ShadowSyncBox;

typedef struct GF_SampleSizeBox {
    u32 sampleCount;
    // other members
} GF_SampleSizeBox;

typedef struct GF_SampleTableBox {
    GF_SampleSizeBox *SampleSize;
    GF_CompositionOffsetBox *CompositionOffset;
    GF_SyncSampleBox *SyncSample;
    GF_ShadowSyncBox *ShadowSync;
    GF_Box child_boxes;
    // other members
} GF_SampleTableBox;

typedef struct GF_MediaHeaderBox {
    u32 timeScale;
    // other members
} GF_MediaHeaderBox;

typedef struct GF_TrackBox {
    void *chunk_cache;
    // other members
} GF_TrackBox;

typedef struct GF_MediaInformationBox {
    GF_SampleTableBox *sampleTable;
    // other members
} GF_MediaInformationBox;

typedef struct GF_MediaBox {
    GF_MediaInformationBox *information;
    GF_MediaHeaderBox *mediaHeader;
    GF_TrackBox *mediaTrack;
    // other members
} GF_MediaBox;

#define GF_ISOM_BOX_TYPE_CTTS 0
#define GF_ISOM_BOX_TYPE_STSS 0
#define GF_ISOM_BOX_TYPE_STSH 0

GF_Box* gf_isom_box_new_parent(GF_Box* parent, u32 box_type);

GF_Err stbl_AddDTS(GF_SampleTableBox *stbl, u64 DTS, u32 *sampleNumber, u32 timeScale, u32 nb_pack);
GF_Err stbl_AddSize(GF_SampleSizeBox *stsz, u32 sampleNumber, u32 size, u32 nb_pack);
GF_Err stbl_AddCTS(GF_SampleTableBox *stbl, u32 sampleNumber, u32 CTS_Offset);
GF_Err stbl_AddRAP(GF_SyncSampleBox *stss, u32 sampleNumber);
GF_Err stbl_AddRedundant(GF_SampleTableBox *stbl, u32 sampleNumber);
GF_Err stbl_AddChunkOffset(GF_MediaBox *mdia, u32 sampleNumber, u32 StreamDescIndex, u64 data_offset, u32 nb_pack);
GF_Err stbl_AddShadow(GF_ShadowSyncBox *stsh, u32 sampleNumber, u32 syncShadowNumber);