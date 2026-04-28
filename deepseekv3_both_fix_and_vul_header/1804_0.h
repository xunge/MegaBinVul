#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t GF_Err;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_MetaBox GF_MetaBox;
typedef struct GF_ItemLocationBox GF_ItemLocationBox;
typedef struct GF_ItemInfoBox GF_ItemInfoBox;
typedef struct GF_ItemLocationEntry GF_ItemLocationEntry;
typedef struct GF_ItemExtentEntry GF_ItemExtentEntry;
typedef struct GF_ItemInfoEntryBox GF_ItemInfoEntryBox;
typedef struct GF_MovieBox GF_MovieBox;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_TrackHeaderBox GF_TrackHeaderBox;
typedef struct GF_MediaBox GF_MediaBox;
typedef struct GF_HandlerBox GF_HandlerBox;
typedef struct GF_MediaInformationBox GF_MediaInformationBox;
typedef struct GF_SampleTableBox GF_SampleTableBox;
typedef struct GF_SampleSizeBox GF_SampleSizeBox;

struct GF_ItemLocationBox {
    void *location_entries;
};

struct GF_ItemInfoBox {
    void *item_infos;
};

struct GF_ItemLocationEntry {
    u32 item_ID;
    u64 base_offset;
    void *extent_entries;
};

struct GF_ItemExtentEntry {
    u64 extent_offset;
    u64 extent_length;
};

struct GF_ItemInfoEntryBox {
    u32 item_ID;
    u32 ref_it_id;
    u32 tk_id;
    u32 sample_num;
    u32 data_len;
};

struct GF_ISOFile {
    struct GF_MovieBox *moov;
};

struct GF_MovieBox {
    void *trackList;
};

struct GF_TrackBox {
    struct GF_TrackHeaderBox *Header;
    struct GF_MediaBox *Media;
};

struct GF_TrackHeaderBox {
    u32 trackID;
};

struct GF_MediaBox {
    struct GF_HandlerBox *handler;
    struct GF_MediaInformationBox *information;
};

struct GF_HandlerBox {
    u32 handlerType;
};

struct GF_MediaInformationBox {
    struct GF_SampleTableBox *sampleTable;
};

struct GF_SampleTableBox {
    struct GF_SampleSizeBox *SampleSize;
};

struct GF_SampleSizeBox {
    u32 sampleCount;
    u32 sampleSize;
    u32 *sizes;
};

struct GF_MetaBox {
    struct GF_ItemLocationBox *item_locations;
    struct GF_ItemInfoBox *item_infos;
    u32 use_item_sample_sharing;
    u32 use_item_item_sharing;
};

GF_Err stbl_GetSampleInfos(void *sampleTable, u32 sampleNumber, u64 *sampleOffset, u32 *chunkNumber, u32 *descIndex, u32 *isRAP);
u32 gf_list_count(void *list);
void *gf_list_get(void *list, u32 position);
void *gf_list_enum(void *list, u32 *pos);
u32 gf_isom_is_video_handler_type(u32 handlerType);