#include <stdint.h>
#include <stdlib.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uint8_t u8;
typedef int Bool;
#define GF_FALSE 0
#define GF_TRUE 1
#define GF_OK 0
#define GF_BAD_PARAM 1
#define GF_EOS 2
#define GF_OUT_OF_MEM 3
#define RAP 1
#define SAP_TYPE_3 3

typedef enum {
    GF_ISOM_SEARCH_FORWARD,
    GF_ISOM_SEARCH_BACKWARD,
    GF_ISOM_SEARCH_SYNC_FORWARD,
    GF_ISOM_SEARCH_SYNC_BACKWARD,
    GF_ISOM_SEARCH_SYNC_SHADOW
} GF_ISOSearchMode;

typedef enum {
    GF_ISOSampleRollType_None
} GF_ISOSampleRollType;

typedef struct GF_ISOFile GF_ISOFile;

typedef struct GF_ISOSample {
    u32 dataLength;
    u8 *data;
    u32 alloc_size;
    u8 IsRAP;
} GF_ISOSample;

typedef struct GF_SampleSizeBox {
    u32 sampleCount;
} GF_SampleSizeBox;

typedef struct GF_SyncSampleBox GF_SyncSampleBox;
typedef struct GF_ShadowSyncBox GF_ShadowSyncBox;

typedef struct GF_SampleTableBox {
    GF_SampleSizeBox *SampleSize;
    GF_SyncSampleBox *SyncSample;
    GF_ShadowSyncBox *ShadowSync;
} GF_SampleTableBox;

typedef struct GF_MediaInformationBox {
    GF_SampleTableBox *sampleTable;
} GF_MediaInformationBox;

typedef struct GF_MediaBox {
    GF_MediaInformationBox *information;
} GF_MediaBox;

typedef struct GF_TrackBox {
    GF_MediaBox *Media;
    u64 dts_at_seg_start;
    u32 sample_count_at_seg_start;
} GF_TrackBox;

#define GF_EXPORT

GF_Err stbl_findEntryForTime(GF_SampleTableBox *stbl, u64 desiredTime, u32 flags, u32 *sampleNumber, u32 *prevSampleNumber);
GF_Err Media_FindSyncSample(GF_SampleTableBox *stbl, u32 sampleNumber, u32 *syncNum, GF_ISOSearchMode SearchMode);
GF_Err Media_GetSample(GF_MediaBox *media, u32 sampleNumber, GF_ISOSample **sample, u32 *StreamDescriptionIndex, Bool no_data, u64 *data_offset);
GF_Err stbl_GetSampleShadow(GF_ShadowSyncBox *ShadowSync, u32 *sampleNumber, u32 *shadowSync);
GF_Err gf_isom_get_sample_rap_roll_info(GF_ISOFile *the_file, u32 trackNumber, u32 sampleNumber, Bool *is_rap, GF_ISOSampleRollType *roll_type, void *unused);
GF_ISOSample *gf_isom_sample_new(void);
void gf_isom_sample_del(GF_ISOSample **sample);
GF_ISOSample *gf_isom_get_sample(GF_ISOFile *the_file, u32 trackNumber, u32 sampleNumber, u32 *StreamDescriptionIndex);
GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *the_file, u32 trackNumber);
void gf_free(void *ptr);