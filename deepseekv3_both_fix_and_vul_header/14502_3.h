#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t s32;
typedef int64_t s64;
typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef int16_t s16;
typedef bool Bool;

typedef enum {
    GF_OK = 0,
    GF_OUT_OF_MEM,
    GF_ISOM_INVALID_FILE,
    GF_ISOM_INCOMPLETE_FILE,
    GF_ISOM_BOX_TYPE_MOOV,
    GF_ISOM_BOX_TYPE_META,
    GF_ISOM_BOX_TYPE_MDAT,
    GF_ISOM_BOX_TYPE_FTYP,
    GF_ISOM_BOX_TYPE_OTYP,
    GF_ISOM_BOX_TYPE_PDIN,
    GF_ISOM_BOX_TYPE_STYP,
    GF_ISOM_BOX_TYPE_SIDX,
    GF_ISOM_BOX_TYPE_SSIX,
    GF_ISOM_BOX_TYPE_MOOF,
    GF_ISOM_BOX_TYPE_UNKNOWN,
    GF_ISOM_BOX_TYPE_PRFT,
    GF_ISOM_BOX_TYPE_JP,
    GF_ISOM_BRAND_SISX,
    GF_ISOM_BRAND_RISX,
    GF_ISOM_BRAND_SSSS
} GF_Err;

typedef struct GF_Box {
    u32 type;
    u64 size;
    void *child_boxes;
} GF_Box;

typedef struct GF_UnknownBox {
    GF_Box box;
    u32 original_4cc;
    u8 *data;
    u32 dataSize;
} GF_UnknownBox;

typedef struct GF_FileTypeBox {
    GF_Box box;
    u32 majorBrand;
    u32 minorVersion;
    u32 *compatibleBrands;
    u32 nb_compatible_brands;
} GF_FileTypeBox;

typedef struct GF_ProgressiveDownloadBox {
    GF_Box box;
} GF_ProgressiveDownloadBox;

typedef struct GF_MovieBox {
    GF_Box box;
    void *mvhd;
    void *trackList;
    void *mvex;
    void *mov;
} GF_MovieBox;

typedef struct GF_MetaBox {
    GF_Box box;
    void *handler;
} GF_MetaBox;

typedef struct GF_MediaDataBox {
    GF_Box box;
} GF_MediaDataBox;

typedef struct GF_SegmentIndexBox {
    GF_Box box;
} GF_SegmentIndexBox;

typedef struct GF_MovieFragmentBox {
    GF_Box box;
    void *mfhd;
    void *TrackList;
    void *mov;
} GF_MovieFragmentBox;

typedef struct GF_TrackFragmentBox {
    void *tfhd;
    void *trex;
    void *sample_encryption;
    void *sampleGroups;
    void *child_boxes;
} GF_TrackFragmentBox;

typedef struct GF_TrackExtendsBox {
    u32 trackID;
    u32 def_sample_desc_index;
    void *track;
} GF_TrackExtendsBox;

typedef struct GF_TrackBox {
    struct GF_Media *Media;
    void *sample_encryption;
    u32 current_traf_stsd_idx;
} GF_TrackBox;

typedef struct GF_Media {
    struct GF_MediaInformation *information;
} GF_Media;

typedef struct GF_MediaInformation {
    struct GF_SampleTable *sampleTable;
} GF_MediaInformation;

typedef struct GF_SampleTable {
    void *sampleGroups;
    void *child_boxes;
} GF_SampleTable;

typedef struct GF_ProducerReferenceTimeBox {
    GF_Box box;
} GF_ProducerReferenceTimeBox;

typedef struct GF_ISOFile {
    u32 openMode;
    u32 FragmentsFlags;
    u32 single_moof_mode;
    u32 single_moof_state;
    u64 current_top_box_start;
    u64 bytes_removed;
    u64 first_data_toplevel_offset;
    u64 first_data_toplevel_size;
    u64 sidx_start_offset;
    u64 sidx_end_offset;
    u64 styp_start_offset;
    u64 original_moov_offset;
    u64 original_meta_offset;
    u32 NextMoofNumber;
    u64 main_sidx_end_pos;
    u32 interleavingTime;
    u32 is_jp2;
    Bool is_index_segment;
    Bool signal_frag_bounds;
    GF_MovieBox *moov;
    GF_MetaBox *meta;
    GF_MediaDataBox *mdat;
    GF_FileTypeBox *brand;
    GF_Box *otyp;
    GF_ProgressiveDownloadBox *pdin;
    GF_SegmentIndexBox *root_sidx;
    GF_SegmentIndexBox *main_sidx;
    GF_Box *seg_ssix;
    GF_Box *seg_styp;
    GF_MovieFragmentBox *moof;
    GF_ProducerReferenceTimeBox *last_producer_ref_time;
    void *TopBoxes;
    struct GF_MovieFileMap *movieFileMap;
} GF_ISOFile;

typedef struct GF_MovieFileMap {
    struct GF_BitStream *bs;
} GF_MovieFileMap;

typedef struct GF_BitStream {
    // Bitstream implementation details
} GF_BitStream;

#define GF_TRUE 1
#define GF_FALSE 0
#define GF_ISOM_OPEN_READ 1
#define GF_ISOM_OPEN_KEEP_FRAGMENTS 2
#define GF_ISOM_FRAG_READ_DEBUG 1
#define GF_4CC(a,b,c,d) ((a)<<24 | (b)<<16 | (c)<<8 | (d))
#define GPAC_DISABLE_ISOM_FRAGMENTS
#define GPAC_DISABLE_ISOM_WRITE
#define GF_ENABLE_CTRN
#define GF_LOG_DEBUG 1
#define GF_LOG_CONTAINER 2
#define GF_LOG_ERROR 3
#define GF_LOG_WARNING 4

void GF_LOG(int level, int category, const char *fmt, ...);
void gf_bs_seek(GF_BitStream *bs, u64 pos);
u64 gf_bs_get_position(GF_BitStream *bs);
u32 gf_bs_available(GF_BitStream *bs);
GF_Err gf_isom_parse_root_box(GF_Box **a, GF_BitStream *bs, u32 *boxType, u64 *bytesMissing, Bool progressive_mode);
void gf_isom_box_del(GF_Box *a);
GF_Box *gf_isom_box_new(u32 type);
GF_Box *gf_isom_box_find_child(void *child_boxes, u32 type);
s32 gf_list_del_item(void *list, void *item);
void gf_list_insert(void *list, void *item, u32 pos);
u32 gf_list_count(void *list);
void *gf_list_get(void *list, u32 index);
GF_Err gf_list_add(void *list, void *item);
void gf_isom_meta_restore_items_ref(GF_ISOFile *mov, GF_MetaBox *meta);
void gf_isom_setup_traf_inheritance(GF_ISOFile *mov);
void gf_isom_push_mdat_end(GF_ISOFile *mov, u64 mdat_end);
void gf_isom_disable_inplace_rewrite(GF_ISOFile *mov);
GF_TrackBox *gf_isom_get_track_from_id(GF_MovieBox *moov, u32 trackID);
GF_TrackBox *GetTrackbyID(GF_MovieBox *moov, u32 trackID);
GF_Err senc_Parse(GF_BitStream *bs, GF_TrackBox *trak, GF_TrackFragmentBox *traf, void *sample_encryption);
void convert_compact_sample_groups(void *child_boxes, void *sampleGroups);
GF_Err MergeFragment(GF_MovieFragmentBox *a, GF_ISOFile *mov);
void FixTrackID(GF_ISOFile *mov);
void FixSDTPInTRAF(GF_MovieFragmentBox *moof);
Bool gf_opts_get_bool(const char *section, const char *name);