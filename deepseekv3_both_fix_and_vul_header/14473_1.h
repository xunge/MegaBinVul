#include <stdint.h>
#include <limits.h>
#include <stddef.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;

#define GF_ISOM_OPEN_WRITE 1
#define GF_BAD_PARAM 2
#define GF_OUT_OF_MEM 3
#define GF_OK 0
#define GF_INT_MAX INT_MAX
#define GF_ISOM_BOX_TYPE_CSLG 0x63736C67
#define GF_ISOM_BRAND_ISO4 0x69736F34
#define GF_TRUE 1

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_Box GF_Box;
typedef struct GF_List GF_List;

typedef struct {
    s32 decodingOffset;
} GF_CTTS_Entry;

typedef struct {
    u32 version;
    u32 nb_entries;
    GF_CTTS_Entry *entries;
} GF_CompositionOffsetBox;

typedef struct {
    s32 compositionToDTSShift;
    s32 leastDecodeToDisplayDelta;
    s32 greatestDecodeToDisplayDelta;
    s32 compositionStartTime;
    s32 compositionEndTime;
} GF_CompositionToDecodeBox;

typedef struct {
    s32 mediaTime;
} GF_EdtsEntry;

typedef struct {
    GF_List *entryList;
} GF_EditListBox;

typedef struct {
    GF_EditListBox *editList;
} GF_EditBox;

typedef struct {
    GF_CompositionOffsetBox *CompositionOffset;
    GF_CompositionToDecodeBox *CompositionToDecode;
    void *child_boxes;
} GF_SampleTableBox;

typedef struct {
    GF_SampleTableBox *sampleTable;
} GF_MediaInformationBox;

typedef struct {
    GF_MediaInformationBox *information;
} GF_MediaBox;

typedef struct {
    GF_MediaBox *Media;
    GF_EditBox *editBox;
    void *child_boxes;
} GF_TrackBox;

GF_Err CanAccessMovie(GF_ISOFile *file, u32 mode);
GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *file, u32 track);
void gf_isom_box_del_parent(void **parent, GF_Box *box);
GF_Box *gf_isom_box_new_parent(void **parent, u32 box_type);
u64 gf_isom_get_media_duration(GF_ISOFile *file, u32 track);
void gf_isom_modify_alternate_brand(GF_ISOFile *file, u32 brand, u32 add_brand);
void SetTrackDuration(GF_TrackBox *trak);
u32 gf_list_count(GF_List *list);
void *gf_list_get(GF_List *list, u32 index);