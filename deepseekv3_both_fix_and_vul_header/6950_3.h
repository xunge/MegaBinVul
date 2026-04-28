#include <stdint.h>
#include <stddef.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef int32_t s32;
typedef int64_t s64;
typedef uint64_t u64;

struct GF_CompositionOffsetBox {
    u32 nb_entries;
    struct {
        s32 decodingOffset;
    } *entries;
    u32 version;
};

struct GF_CompositionToDecodeBox {
    s32 compositionToDTSShift;
};

struct GF_Box {
    // base box fields
};

struct GF_EdtsEntry {
    s64 mediaTime;
};

struct GF_ISOFile {
    struct {
        struct {
            struct {
                u32 timeScale;
            } *mvhd;
            void *trackList;
        } *moov;
    };
};

struct GF_TrackBox {
    struct {
        struct {
            struct {
                struct {
                    struct GF_CompositionOffsetBox *CompositionOffset;
                    struct GF_CompositionToDecodeBox *CompositionToDecode;
                    void *child_boxes;
                } *sampleTable;
            } *information;
            struct {
                u64 duration;
                u32 timeScale;
            } *mediaHeader;
        } *Media;
        struct {
            struct {
                void *entryList;
            } *editList;
        } *editBox;
    };
};

#define GF_OK 0
#define GF_FALSE 0
#define GF_ISOM_BRAND_ISO4 0
#define GF_ISOM_EDIT_NORMAL 0

int gf_list_find(void *list, void *item);
u32 gf_list_count(void *list);
void *gf_list_get(void *list, u32 index);
void gf_isom_box_del_parent(void **child_boxes, struct GF_Box *box);
GF_Err gf_isom_set_edit(struct GF_ISOFile *file, u32 track_num, u64 start_time, u64 duration, s32 shift, u32 edit_type);
void gf_isom_modify_alternate_brand(struct GF_ISOFile *file, u32 brand, u32 is_alt_brand);
void SetTrackDuration(struct GF_TrackBox *trak);

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_CompositionOffsetBox GF_CompositionOffsetBox;
typedef struct GF_CompositionToDecodeBox GF_CompositionToDecodeBox;
typedef struct GF_Box GF_Box;
typedef struct GF_EdtsEntry GF_EdtsEntry;