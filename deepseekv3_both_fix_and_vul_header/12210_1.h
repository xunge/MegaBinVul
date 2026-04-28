#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint8_t Bool;
#define GF_TRUE 1
#define GF_FALSE 0

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackFragmentBox GF_TrackFragmentBox;
typedef struct GF_TrackFragmentRunBox GF_TrackFragmentRunBox;
typedef struct GF_TrunEntry GF_TrunEntry;
typedef struct GF_Box GF_Box;

#define GF_ISOM_MOOF_BASE_OFFSET 0x01
#define GF_ISOM_TRAF_BASE_OFFSET 0x02
#define GF_ISOM_TRAF_DUR_EMPTY 0x04
#define GF_ISOM_TRAF_SAMPLE_DUR 0x08
#define GF_ISOM_TRUN_SIZE 0x01
#define GF_ISOM_TRUN_DURATION 0x02
#define GF_ISOM_TRUN_FLAGS 0x04
#define GF_ISOM_TRUN_FIRST_FLAG 0x08
#define GF_ISOM_TRUN_CTS_OFFSET 0x10
#define GF_ISOM_TRUN_DATA_OFFSET 0x20
#define GF_ISOM_TRAF_SAMPLE_SIZE 0x40
#define GF_ISOM_TRAF_SAMPLE_FLAGS 0x80
#define GF_ISOM_TRAF_SAMPLE_DESC 0x100

struct GF_TrackFragmentRunBox {
    u32 flags;
    u32 nb_samples;
    GF_TrunEntry *samples;
    u32 data_offset;
    u32 sample_count;
    u32 first_sample_flags;
};

struct GF_TrunEntry {
    u32 size;
    u32 Duration;
    u32 flags;
    u32 CTS_Offset;
    u32 nb_pack;
};

struct GF_TrackFragmentBox {
    struct {
        u32 flags;
        u32 def_sample_size;
        u32 def_sample_duration;
        u32 def_sample_flags;
        u32 sample_desc_index;
        u32 EmptyDuration;
    } *tfhd;
    struct {
        u32 def_sample_size;
        u32 def_sample_duration;
        u32 def_sample_flags;
        u32 def_sample_desc_index;
        Bool cannot_use_default;
    } *trex;
    void *TrackRuns;
    void *child_boxes;
    Bool no_sdtp_first_flags;
};

struct GF_ISOFile {
    Bool use_segments;
    Bool force_moof_base_offset;
    struct {
        void *trun_list;
    } *moof;
};

u32 gf_list_count(void *list);
void *gf_list_get(void *list, u32 index);
void gf_list_rem(void *list, u32 index);
void gf_list_del_item(void *list, void *item);
void gf_isom_box_del_parent(void **parent, GF_Box *box);
void *gf_list_enum(void *list, u32 *index);