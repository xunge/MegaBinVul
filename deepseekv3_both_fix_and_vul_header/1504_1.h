#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned int u32;
typedef unsigned char u8;

typedef enum {
    GF_OK,
    GF_LOG_INFO,
    GF_LOG_WARNING,
    GF_LOG_ERROR
} GF_Err;

typedef enum {
    GF_ISOM_MEDIA_SCENE,
    GF_ISOM_MEDIA_OD,
    GF_ISOM_MEDIA_VISUAL,
    GF_ISOM_MEDIA_AUXV,
    GF_ISOM_MEDIA_PICT,
    GF_ISOM_MEDIA_AUDIO,
    GF_ISOM_MEDIA_HINT
} GF_ISOM_MediaType;

typedef enum {
    GF_ISOM_SUBTYPE_MPEG4,
    GF_ISOM_SUBTYPE_MPEG4_CRYP
} GF_ISOM_SubType;

typedef enum {
    GF_ISOM_BRAND_ISMA,
    GF_ISOM_NALU_EXTRACT_LAYER_ONLY
} GF_ISOM_Flags;

typedef enum {
    GF_SDP_IOD_NONE,
    GF_SDP_IOD_ISMA,
    GF_SDP_IOD_REGULAR
} GF_SDP_IODProfile;

typedef enum {
    GP_RTP_PCK_USE_INTERLEAVING,
    GP_RTP_PCK_SYSTEMS_CAROUSEL
} GF_RTP_Flags;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_RTPHinter GF_RTPHinter;

typedef struct GF_Descriptor {
    // base descriptor fields
} GF_Descriptor;

typedef struct GF_DecoderConfig {
    u32 streamType;
    // other decoder config fields
} GF_DecoderConfig;

typedef struct GF_ESD {
    GF_DecoderConfig *decoderConfig;
    u32 OCRESID;
    u32 ESID;
    // other ESD fields
} GF_ESD;

typedef struct GF_InitialObjectDescriptor {
    GF_ESD **ESDescriptors;
    // other IOD fields
} GF_InitialObjectDescriptor;

typedef struct GF_ISOSample {
    u8 *data;
    u32 dataLength;
    // other sample fields
} GF_ISOSample;

#define BASE_PAYT 0
#define M4_LOG(level, format, ...)

GF_ISOFile* gf_isom_get_root_od(GF_ISOFile* file);
u32 gf_list_count(void* list);
void gf_odf_desc_del(GF_Descriptor* desc);
u32 gf_isom_guess_specification(GF_ISOFile* file);
Bool gf_isom_is_single_av(GF_ISOFile* file);
u32 gf_isom_get_track_count(GF_ISOFile* file);
u32 gf_isom_get_media_type(GF_ISOFile* file, u32 track);
Bool gf_isom_is_track_in_root_od(GF_ISOFile* file, u32 track);
void gf_isom_set_default_sync_track(GF_ISOFile* file, u32 track);
u32 gf_isom_get_sample_count(GF_ISOFile* file, u32 track);
Bool gf_isom_is_track_enabled(GF_ISOFile* file, u32 track);
u32 gf_isom_get_track_id(GF_ISOFile* file, u32 track);
u32 gf_isom_get_media_subtype(GF_ISOFile* file, u32 track, u32 sample);
u32 gf_isom_get_mpeg4_subtype(GF_ISOFile* file, u32 track, u32 sample);
GF_ESD* gf_isom_get_esd(GF_ISOFile* file, u32 track, u32 sample);
GF_ISOSample* gf_isom_get_sample(GF_ISOFile* file, u32 track, u32 sample, u32* val);
void gf_isom_sample_del(GF_ISOSample** samp);
u32 gf_hinter_can_embbed_data(void* data, u32 length, u32 streamType);
GF_RTPHinter* gf_hinter_track_new(GF_ISOFile* file, u32 track, u32 mtu, u32 max_ptime, u32 rate, u32 flags, u8 payt, Bool copy, u32 group, u8 prio, GF_Err* err);
void gf_hinter_track_force_no_offsets(GF_RTPHinter* hinter);
u32 gf_hinter_track_get_bandwidth(GF_RTPHinter* hinter);
u32 gf_hinter_track_get_flags(GF_RTPHinter* hinter);
void gf_isom_set_nalu_extract_mode(GF_ISOFile* file, u32 track, u32 mode);
void gf_hinter_track_get_payload_name(GF_RTPHinter* hinter, char* name);
GF_Err gf_hinter_track_process(GF_RTPHinter* hinter);
GF_Err gf_hinter_track_finalize(GF_RTPHinter* hinter, Bool has_iod);
void gf_hinter_track_del(GF_RTPHinter* hinter);
char* gf_error_to_string(GF_Err err);
char* gf_4cc_to_str(u32 code);
void gf_hinter_finalize(GF_ISOFile* file, GF_SDP_IODProfile iod_mode, u32 tot_bw);