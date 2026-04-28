#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
#define GF_FALSE 0
#define GF_TRUE 1

typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef int GF_Err;
#define GF_OK 0
#define GF_BAD_PARAM 1
#define GF_OUT_OF_MEM 2
#define GF_ISOM_INVALID_FILE 3
#define GF_NON_COMPLIANT_BITSTREAM 4

typedef struct {
    u32 nal_unit_size;
} GF_AVCConfigurationBox;
typedef struct {
    u32 nal_unit_size;
} GF_HEVCConfigurationBox;
typedef struct {
    u32 nal_unit_size;
} GF_LHVCConfigurationBox;

typedef struct {
    GF_AVCConfigurationBox *config;
} GF_AVCConfigBox;
typedef struct {
    GF_HEVCConfigurationBox *config;
} GF_HEVCConfigBox;
typedef struct {
    GF_LHVCConfigurationBox *config;
} GF_LHVCConfigBox;
typedef struct {
    GF_AVCConfigurationBox *config;
} GF_SVCConfigBox;
typedef struct {
    GF_AVCConfigurationBox *config;
} GF_MVCConfigBox;

typedef struct {
    GF_AVCConfigBox *avc_config;
    GF_HEVCConfigBox *hevc_config;
    GF_LHVCConfigBox *lhvc_config;
    GF_SVCConfigBox *svc_config;
    GF_MVCConfigBox *mvc_config;
} GF_MPEGVisualSampleEntryBox;

typedef struct {
    u32 *trackIDs;
    u32 trackIDCount;
} GF_TrackReferenceTypeBox;

typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_ISOFile GF_ISOFile;

typedef struct {
    u32 dataLength;
    u32 alloc_size;
    u8 *data;
    u32 IsRAP;
    u32 DTS;
} GF_ISOSample;

typedef struct {
    u32 nb_entries;
} GF_SyncSampleBox;

typedef struct {
    GF_SyncSampleBox *SyncSample;
    u32 no_sync_found;
    struct {
        void *child_boxes;
    } *SampleDescription;
} GF_SampleTableBox;

typedef struct {
    GF_SampleTableBox *sampleTable;
} GF_MediaInformationBox;

typedef struct {
    u32 extractor_mode;
    u32 sample_count_at_seg_start;
    GF_TrackBox *mediaTrack;
    GF_MediaInformationBox *information;
    u8 *in_sample_buffer;
    u32 in_sample_buffer_alloc;
    void *nalu_parser;
    void *nalu_out_bs;
    void *nalu_ps_bs;
    char *tmp_nal_copy_buffer;
    u32 tmp_nal_copy_buffer_alloc;
    GF_ISOSample *extracted_samp;
    Bool in_nalu_rewrite;
} GF_MediaBox;

typedef struct GF_TrackBox {
    GF_MediaBox *Media;
    void *trackList;
    GF_ISOFile *moov;
    u32 extractor_mode;
    u32 sample_count_at_seg_start;
} GF_TrackBox;

typedef struct GF_ISOFile {
    GF_TrackBox *mediaTrack;
    GF_ISOFile *mov;
    void *trackList;
} GF_ISOFile;

#define GF_ISOM_REF_SCAL 0
#define GF_ISOM_REF_BASE 1
#define GF_ISOM_REF_SABT 2
#define GF_ISOM_REF_TBAS 3

#define GF_ISOM_NALU_EXTRACT_INBAND_PS_FLAG 0x00010000
#define GF_ISOM_NALU_EXTRACT_ANNEXB_FLAG 0x00020000
#define GF_ISOM_NALU_EXTRACT_VDRD_FLAG 0x00040000
#define GF_ISOM_NALU_EXTRACT_TILE_ONLY 0x00080000
#define GF_ISOM_NALU_EXTRACT_INSPECT 0
#define GF_ISOM_NALU_EXTRACT_DEFAULT 1
#define GF_ISOM_NALU_EXTRACT_LAYER_ONLY 2

#define GF_AVC_NALU_ACCESS_UNIT 9
#define GF_AVC_NALU_FF_AGGREGATOR 29
#define GF_AVC_NALU_FF_EXTRACTOR 30
#define GF_AVC_NALU_SEI 6
#define GF_AVC_NALU_SEQ_PARAM 7
#define GF_AVC_NALU_PIC_PARAM 8
#define GF_AVC_NALU_SEQ_PARAM_EXT 13
#define GF_AVC_NALU_SVC_SUBSEQ_PARAM 15
#define GF_AVC_NALU_VDRD 31

#define GF_HEVC_NALU_ACCESS_UNIT 35
#define GF_HEVC_NALU_FF_AGGREGATOR 47
#define GF_HEVC_NALU_FF_EXTRACTOR 48
#define GF_HEVC_NALU_VID_PARAM 32
#define GF_HEVC_NALU_SEQ_PARAM 33
#define GF_HEVC_NALU_PIC_PARAM 34
#define GF_HEVC_NALU_SEI_SUFFIX 39
#define GF_HEVC_NALU_SLICE_TSA_N 2
#define GF_HEVC_NALU_SLICE_STSA_N 3
#define GF_HEVC_NALU_SLICE_TSA_R 4
#define GF_HEVC_NALU_SLICE_STSA_R 5
#define GF_HEVC_NALU_SLICE_BLA_W_LP 16
#define GF_HEVC_NALU_SLICE_BLA_W_DLP 17
#define GF_HEVC_NALU_SLICE_BLA_N_LP 18
#define GF_HEVC_NALU_SLICE_IDR_W_DLP 19
#define GF_HEVC_NALU_SLICE_IDR_N_LP 20
#define GF_HEVC_NALU_SLICE_CRA 21

#define GF_ISOM_SUBTYPE_HVC1 0x68766331
#define GF_ISOM_SUBTYPE_HVC2 0x68766332
#define GF_ISOM_SUBTYPE_HEV1 0x68657631
#define GF_ISOM_SUBTYPE_HEV2 0x68657632

#define SAP_TYPE_2 2

#define GF_BITSTREAM_WRITE 0
#define GF_BITSTREAM_READ 1

#define GF_LOG_WARNING 1
#define GF_LOG_CODING 2
#define GF_LOG_ERROR 3
#define GF_LOG_CONTAINER 4

typedef struct GF_BitStream GF_BitStream;

GF_BitStream* gf_bs_new(void *buffer, u32 size, u32 mode);
void gf_bs_seek(GF_BitStream *bs, u32 position);
u32 gf_bs_available(GF_BitStream *bs);
u32 gf_bs_read_int(GF_BitStream *bs, u32 nbits);
u32 gf_bs_get_position(GF_BitStream *bs);
void gf_bs_skip_bytes(GF_BitStream *bs, u32 count);
u8 gf_bs_read_u8(GF_BitStream *bs);
u16 gf_bs_read_u16(GF_BitStream *bs);
void gf_bs_read_data(GF_BitStream *bs, void *buffer, u32 size);
void gf_bs_write_int(GF_BitStream *bs, u32 value, u32 nbits);
void gf_bs_write_u8(GF_BitStream *bs, u8 value);
void gf_bs_write_u16(GF_BitStream *bs, u16 value);
void gf_bs_write_u32(GF_BitStream *bs, u32 value);
void gf_bs_write_data(GF_BitStream *bs, void *data, u32 size);
void gf_bs_transfer(GF_BitStream *dst, GF_BitStream *src, Bool keep_src);
void gf_bs_get_content(GF_BitStream *bs, void **buffer, u32 *size);
void gf_bs_get_content_no_truncate(GF_BitStream *bs, void **buffer, u32 *size, u32 *alloc_size);
void gf_bs_del(GF_BitStream *bs);
GF_Err gf_bs_reassign_buffer(GF_BitStream *bs, void *buffer, u32 size);

void* gf_realloc(void *ptr, u32 size);
void* gf_malloc(u32 size);
void gf_free(void *ptr);
u32 gf_list_find(void *list, void *item);
void* gf_list_get(void *list, u32 index);
GF_Err Track_FindRef(GF_TrackBox *track, u32 ref_type, GF_TrackReferenceTypeBox **ref);
GF_Err process_extractor(GF_ISOFile *file, GF_MediaBox *mdia, u32 sampleNumber, u32 DTS, u32 nal_size, u32 nal_hdr, u32 nal_unit_size_field, Bool is_hevc, Bool rewrite_ps, Bool rewrite_start_codes, u32 extractor_mode);
void nalu_merge_ps(GF_BitStream *bs, Bool rewrite_start_codes, u32 nal_unit_size_field, GF_MPEGVisualSampleEntryBox *entry, Bool is_hevc, Bool *has_vps);
u32 sap_type_from_nal_type(u32 nal_type);
u32 is_sample_idr(GF_MediaBox *mdia, GF_ISOSample *sample, GF_MPEGVisualSampleEntryBox *entry);
GF_TrackBox* GetTrackbyID(GF_ISOFile *moov, u32 trackID);
GF_ISOSample* gf_isom_sample_new(void);
u32 gf_isom_get_reference_count(GF_ISOFile *mov, u32 track_num, u32 ref_type);
GF_Err gf_isom_get_reference(GF_ISOFile *mov, u32 track_num, u32 ref_type, u32 idx, u32 *ref_track);
u32 gf_isom_get_media_subtype(GF_ISOFile *mov, u32 track_num, u32 idx);
GF_ISOSample* gf_isom_get_sample_ex(GF_ISOFile *mov, u32 track_num, u32 sample_num, u32 *di, GF_ISOSample *samp, void *unk);
void GF_LOG(int level, int category, const char *fmt, ...);