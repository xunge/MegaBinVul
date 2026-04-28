#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long long s64;
typedef int Bool;

#define GF_EXPORT
#define GF_ISOM_BOX_TYPE_TRAF 0x74726166
#define GF_ISOM_BOX_TYPE_TFHD 0x74666864
#define GF_ISOM_BOX_TYPE_TRUN 0x7472756e
#define GF_ISOM_MEDIA_OD 0x6F64736D
#define GF_BITSTREAM_WRITE 1
#define GF_LOG_WARNING 1
#define GF_LOG_CONTAINER 2

#define GF_SAFEALLOC(ptr, type) ptr = (type *)malloc(sizeof(type))
#define GF_ISOM_FORMAT_FRAG_FLAGS(pad, rap, pri) (((pad) << 16) | ((rap) << 8) | (pri))
#define GF_ISOM_GET_FRAG_DEPEND_FLAGS(a,b,c,d) (((a)<<24)|((b)<<16)|((c)<<8)|(d))

typedef enum {
    GF_OK,
    GF_BAD_PARAM,
    GF_OUT_OF_MEM,
    GF_ISOM_FRAG_WRITE_READY
} GF_Err;

typedef struct GF_ISOFile {
    struct {
        struct {
            struct _gf_list *child_boxes;
            u32 fragment_offset;
            struct _gf_list *TrackList;
            u32 trun_ref_size;
        } *moof;
        u32 FragmentsFlags;
        struct {
            struct GF_BitStream *bs;
        } *editFileMap;
        Bool moof_first;
        void (*on_block_out)(void);
    };
} GF_ISOFile;

typedef u32 GF_ISOTrackID;

typedef struct GF_ISOSample {
    u32 dataLength;
    u8 *data;
    u64 DTS;
    s64 CTS_Offset;
    u32 nb_pack;
    u8 IsRAP;
} GF_ISOSample;

typedef struct GF_TrunEntry {
    u32 Duration;
    u64 dts;
    s64 CTS_Offset;
    u32 size;
    u32 flags;
    u32 SAP_type;
    u32 nb_pack;
} GF_TrunEntry;

typedef struct GF_TrackFragmentHeaderBox {
    u32 trackID;
    u32 sample_desc_index;
    u64 base_data_offset;
} GF_TrackFragmentHeaderBox;

typedef struct GF_RandomAccessEntry {
    u64 time;
    u32 trun_number;
    u32 sample_number;
} GF_RandomAccessEntry;

typedef struct GF_TrackExtendsBox {
    u32 def_sample_desc_index;
    u32 def_sample_duration;
    struct {
        struct {
            struct {
                struct {
                    u32 handlerType;
                } *handler;
            } *Media;
        } *track;
        struct {
            struct GF_RandomAccessEntry *entries;
            u32 nb_entries;
        } *tfra;
    };
} GF_TrackExtendsBox;

typedef struct GF_TrackFragmentRunBox {
    u32 version;
    u32 data_offset;
    u32 run_size;
    u32 nb_samples;
    u32 sample_alloc;
    u32 sample_count;
    u32 interleave_id;
    u8 use_ctrn;
    u8 use_inherit;
    u32 ctso_multiplier;
    GF_TrunEntry *samples;
    void *cache;
    struct _gf_list *sample_refs;
} GF_TrackFragmentRunBox;

typedef struct GF_TrackFragmentBox {
    struct _gf_list *child_boxes;
    struct _gf_list *TrackRuns;
    u32 IFrameSwitching;
    u32 use_sample_interleave;
    u32 interleave_id;
    u32 truns_first;
    u32 truns_v1;
    u32 large_tfdt;
    u32 DataCache;
    u32 force_new_trun;
    u32 trun_ref_size;
    GF_TrackFragmentHeaderBox *tfhd;
    GF_TrackExtendsBox *trex;
} GF_TrackFragmentBox;

typedef struct GF_TrafSampleRef {
    u8 *data;
    u32 len;
    void *ref;
    u32 ref_offset;
} GF_TrafSampleRef;

struct _gf_list;
struct GF_BitStream;

GF_TrackFragmentBox *gf_isom_get_traf(GF_ISOFile *movie, GF_ISOTrackID TrackID);
void *gf_isom_box_new_parent(struct _gf_list **child_boxes, u32 box_type);
u64 gf_bs_get_position(struct GF_BitStream *bs);
void gf_bs_get_content(void *cache, u8 **buffer, u32 *buffer_size);
u32 gf_bs_write_data(struct GF_BitStream *bs, const u8 *data, u32 size);
void gf_bs_del(struct GF_BitStream *bs);
struct GF_BitStream *gf_bs_new(void *buffer, u64 size, u32 mode);
void *gf_realloc(void *ptr, size_t size);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
u32 gf_list_count(struct _gf_list *list);
void *gf_list_get(struct _gf_list *list, u32 index);
void gf_list_add(struct _gf_list *list, void *item);
struct _gf_list *gf_list_new();
void GF_LOG(u32 log_level, u32 log_type, const char *fmt, ...);
GF_Err Media_ParseODFrame(void *Media, const GF_ISOSample *sample, GF_ISOSample **od_sample);
void gf_isom_sample_del(GF_ISOSample **sample);