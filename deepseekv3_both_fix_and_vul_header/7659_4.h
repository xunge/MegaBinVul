#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t s32;
typedef uint8_t u8;
typedef int64_t s64;
typedef int Bool;

typedef enum {
    GF_OK = 0,
    GF_OUT_OF_MEM,
    GF_ISOM_INVALID_FILE,
    GF_ISOM_INCOMPLETE_FILE,
    GF_ISOM_INVALID_MEDIA,
    GF_ISOM_UNKNOWN_ERROR
} GF_Err;

typedef struct {
    u32 type;
    u64 size;
    void *child_boxes;
} GF_Box;

typedef struct {
    GF_Box box;
    u32 majorBrand;
} GF_FileTypeBox;

typedef struct {
    GF_Box box;
    u32 timeScale;
} GF_MovieHeaderBox;

typedef struct {
    GF_Box box;
    GF_MovieHeaderBox *mvhd;
    void *trackList;
    void *mvex;
    void *mov;
} GF_MovieBox;

typedef struct {
    GF_Box box;
    void *handler;
} GF_MetaBox;

typedef struct {
    GF_Box box;
} GF_MediaDataBox;

typedef struct {
    GF_Box box;
} GF_ProducerReferenceTimeBox;

typedef struct {
    GF_Box box;
    u32 sequence_number;
} GF_MovieFragmentHeaderBox;

typedef struct {
    GF_Box box;
    GF_MovieFragmentHeaderBox *mfhd;
    void *TrackList;
} GF_MovieFragmentBox;

typedef struct {
    GF_Box box;
    u32 trackID;
    u32 sample_desc_index;
} GF_TrackFragmentHeaderBox;

typedef struct {
    GF_Box box;
    u32 trackID;
    u32 def_sample_desc_index;
    void *track;
} GF_TrackExtendsBox;

typedef struct {
    GF_Box box;
    GF_TrackFragmentHeaderBox *tfhd;
    GF_TrackExtendsBox *trex;
    void *sampleGroups;
    void *sample_encryption;
} GF_TrackFragmentBox;

typedef struct {
    void *sampleGroups;
    void *child_boxes;
} GF_SampleTable;

typedef struct {
    GF_SampleTable *sampleTable;
} GF_MediaInformation;

typedef struct {
    GF_Box box;
    GF_MediaInformation *information;
} GF_MediaBox;

typedef struct {
    GF_Box box;
    GF_MediaBox *Media;
    void *sample_encryption;
    u32 current_traf_stsd_idx;
} GF_TrackBox;

typedef struct {
    GF_Box box;
} GF_SegmentIndexBox;

typedef struct {
    GF_Box box;
    u32 original_4cc;
    u32 dataSize;
    void *data;
} GF_UnknownBox;

typedef struct {
    GF_Box box;
} GF_ProgressiveDownloadBox;

typedef struct {
    void *bs;
} GF_BitStream;

typedef struct {
    GF_BitStream *bs;
} GF_FileMap;

typedef struct {
    u32 FragmentsFlags;
    u32 openMode;
    u32 NextMoofNumber;
    u32 is_jp2;
    u32 is_index_segment;
    u32 single_moof_mode;
    u32 single_moof_state;
    u32 signal_frag_bounds;
    u64 current_top_box_start;
    u64 bytes_removed;
    u64 first_data_toplevel_offset;
    u64 first_data_toplevel_size;
    u64 sidx_start_offset;
    u64 sidx_end_offset;
    u64 styp_start_offset;
    u64 main_sidx_end_pos;
    u32 interleavingTime;
    GF_FileMap *movieFileMap;
    GF_MovieBox *moov;
    GF_MetaBox *meta;
    GF_MediaDataBox *mdat;
    GF_FileTypeBox *brand;
    GF_Box *otyp;
    GF_ProgressiveDownloadBox *pdin;
    GF_SegmentIndexBox *root_sidx;
    GF_SegmentIndexBox *main_sidx;
    GF_Box *seg_styp;
    GF_Box *seg_ssix;
    GF_Box *root_ssix;
    GF_ProducerReferenceTimeBox *last_producer_ref_time;
    GF_MovieFragmentBox *moof;
    void *TopBoxes;
    void *emsgs;
    u64 original_moov_offset;
    u64 original_meta_offset;
} GF_ISOFile;

#define GF_ISOM_BOX_TYPE_MOOV 0x6d6f6f76
#define GF_ISOM_BOX_TYPE_META 0x6d657461
#define GF_ISOM_BOX_TYPE_MDAT 0x6d646174
#define GF_ISOM_BOX_TYPE_FTYP 0x66747970
#define GF_ISOM_BOX_TYPE_OTYP 0x6f747970
#define GF_ISOM_BOX_TYPE_PDIN 0x7064696e
#define GF_ISOM_BOX_TYPE_STYP 0x73747970
#define GF_ISOM_BOX_TYPE_SIDX 0x73696478
#define GF_ISOM_BOX_TYPE_SSIX 0x73736978
#define GF_ISOM_BOX_TYPE_MOOF 0x6d6f6f66
#define GF_ISOM_BOX_TYPE_PRFT 0x70726674
#define GF_ISOM_BOX_TYPE_EMSG 0x656d7367
#define GF_ISOM_BOX_TYPE_MFRA 0x6d667261
#define GF_ISOM_BOX_TYPE_MFRO 0x6d66726f
#define GF_ISOM_BOX_TYPE_UNKNOWN 0
#define GF_ISOM_BOX_TYPE_JP 0x6a702020

#define GF_ISOM_OPEN_READ 1
#define GF_ISOM_OPEN_KEEP_FRAGMENTS 2

#define GF_ISOM_FRAG_READ_DEBUG 1

#define GF_4CC(a,b,c,d) ((a)<<24 | (b)<<16 | (c)<<8 | (d))

#define GF_TRUE 1
#define GF_FALSE 0

#define GPAC_DISABLE_ISOM_FRAGMENTS 0
#define GPAC_DISABLE_ISOM_WRITE 0
#define GF_ENABLE_CTRN 0

#define GF_LOG_DEBUG 0
#define GF_LOG_ERROR 1
#define GF_LOG_WARNING 2
#define GF_LOG_CONTAINER 3

#define GF_ISOM_BRAND_SISX 0x73697378
#define GF_ISOM_BRAND_RISX 0x72697378
#define GF_ISOM_BRAND_SSSS 0x73737373

static GF_Err gf_isom_parse_root_box(GF_Box **box, GF_BitStream *bs, u32 *boxType, u64 *bytesMissing, Bool progressive_mode);
static void gf_isom_box_del(GF_Box *box);
static GF_Box *gf_isom_box_new(u32 boxType);
static GF_Box *gf_isom_box_find_child(void *child_boxes, u32 boxType);
static s32 gf_list_del_item(void *list, void *item);
static void gf_list_insert(void *list, void *item, u32 pos);
static u32 gf_list_count(void *list);
static void *gf_list_get(void *list, u32 index);
static void *gf_list_enum(void *list, u32 *index);
static GF_Err gf_list_add(void *list, void *item);
static void *gf_list_new();
static void gf_bs_seek(GF_BitStream *bs, u64 offset);
static u64 gf_bs_get_position(GF_BitStream *bs);
static Bool gf_bs_available(GF_BitStream *bs);
static void gf_isom_box_array_del(void *list);
static void gf_isom_disable_inplace_rewrite(GF_ISOFile *mov);
static void gf_isom_setup_traf_inheritance(GF_ISOFile *mov);
static void gf_isom_meta_restore_items_ref(GF_ISOFile *mov, GF_MetaBox *meta);
static void gf_isom_push_mdat_end(GF_ISOFile *mov, u64 mdat_end);
static GF_Err MergeFragment(GF_MovieFragmentBox *moof, GF_ISOFile *mov);
static GF_Err senc_Parse(GF_BitStream *bs, GF_TrackBox *trak, GF_TrackFragmentBox *traf, void *senc);
static void convert_compact_sample_groups(void *child_boxes, void *sampleGroups);
static void FixTrackID(GF_ISOFile *mov);
static void FixSDTPInTRAF(GF_MovieFragmentBox *moof);
static GF_TrackBox *gf_isom_get_track_from_id(GF_MovieBox *moov, u32 trackID);
static GF_TrackBox *GetTrackbyID(GF_MovieBox *moov, u32 trackID);
static Bool gf_opts_get_bool(const char *category, const char *name);
static void GF_LOG(u32 level, u32 module, const char *format, ...);
static void gf_isom_box_del_parent(void **child_boxes, GF_Box *box);