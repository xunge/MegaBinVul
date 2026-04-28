#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;

typedef enum {
    GF_OK,
    GF_ISOM_INVALID_FILE,
    GF_OUT_OF_MEM
} GF_Err;

typedef enum {
    GF_FALSE,
    GF_TRUE
} GF_Bool;

typedef enum {
    GF_ISOM_BOX_TYPE_STSC,
    GF_ISOM_BOX_TYPE_STCO,
    GF_ISOM_BOX_TYPE_CO64,
    GF_ISOM_BOX_TYPE_SMHD
} GF_BoxType;

typedef enum {
    GF_ISOM_STORE_INTERLEAVED
} GF_StorageMode;

typedef struct {
    u32 sampleDelta;
} GF_SttsEntry;

typedef struct {
    u32 nb_entries;
    GF_SttsEntry *entries;
} GF_TimeToSampleBox;

typedef struct {
    u32 sampleSize;
    u32 sampleCount;
} GF_SampleSizeBox;

typedef struct {
    GF_BoxType type;
} GF_Box;

typedef struct GF_SampleToChunkBox {
    GF_Box box;
} GF_SampleToChunkBox;

typedef struct {
    GF_Box box;
    GF_Box *sampleGroupsDescription;
    GF_Box **child_boxes;
    GF_SampleSizeBox *SampleSize;
    GF_TimeToSampleBox *TimeToSample;
    GF_Box *ChunkOffset;
    GF_SampleToChunkBox *SampleToChunk;
    u32 MaxSamplePerChunk;
} GF_SampleTableBox;

typedef struct {
    u32 timeScale;
} GF_MediaHeaderBox;

typedef struct {
    GF_MediaHeaderBox *mediaHeader;
    GF_Box *InfoHeader;
    GF_SampleTableBox *sampleTable;
} GF_MediaInformationBox;

typedef struct {
    GF_MediaInformationBox *information;
    GF_MediaHeaderBox *mediaHeader;
} GF_MediaBox;

typedef struct {
    GF_MediaBox *Media;
    GF_Box *sample_encryption;
} GF_TrackBox;

typedef struct GF_List {
    u32 size;
    void **vals;
} GF_List;

typedef struct {
    GF_List *trackList;
} GF_MovieBox;

typedef struct {
    GF_MovieBox *moov;
    u32 sample_groups_in_traf;
    GF_StorageMode storageMode;
} GF_ISOFile;

typedef struct {
    GF_ISOFile *movie;
    u32 total_samples;
    u32 nb_done;
} MovieWriter;

typedef struct {
    GF_MediaBox *mdia;
    GF_SampleTableBox *stbl;
    u32 timeScale;
    u32 sampleNumber;
    u32 DTSprev;
    u32 chunkDur;
    u32 chunkSize;
    u32 constant_size;
    u32 constant_dur;
    GF_Bool all_dref_mode;
    GF_Bool prevent_dispatch;
    GF_Bool isDone;
    GF_SampleToChunkBox *stsc;
    GF_Box *stco;
} TrackWriter;

#define GF_SAFEALLOC(ptr, type) ptr = (type*)calloc(1, sizeof(type))

GF_List *gf_list_new();
void gf_list_add(GF_List *list, void *item);
void gf_list_insert(GF_List *list, void *item, u32 position);
u32 gf_list_count(GF_List *list);

GF_TrackBox *gf_isom_get_track(GF_MovieBox *moov, u32 track_num);
GF_Box *gf_isom_box_new(GF_BoxType box_type);
void gf_isom_box_array_del_parent(GF_Box ***parent_box_array, GF_Box *box_to_remove);

GF_Bool Media_IsSelfContained(GF_MediaBox *mdia, u32 descIndex);
GF_Bool Media_SelfContainedType(GF_MediaBox *mdia);

void CleanWriters(GF_List *writers);