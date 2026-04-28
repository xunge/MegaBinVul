#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef unsigned char Bool;
typedef unsigned int u32;
typedef int GF_Err;

#define GF_OK 0
#define GF_URL_ERROR 1
#define GF_NOT_SUPPORTED 2
#define GF_FALSE 0
#define GF_TRUE 1

#define GF_ISOM_OPEN_READ 1
#define GPAC_OTI_VIDEO_HEVC 1
#define GPAC_OTI_VIDEO_LHVC 2
#define GF_HEVC_NALU_VID_PARAM 1
#define GF_HEVC_NALU_SEQ_PARAM 2
#define GF_ISOM_REF_BASE 1
#define GF_ISOM_REF_TBAS 2
#define GF_ISOM_REF_SABT 3
#define GF_ISOM_REF_SCAL 4
#define GF_ISOM_MEDIA_VISUAL 1
#define GF_ISOM_MEDIA_AUDIO 2
#define GF_ISOM_MEDIA_AUXV 3
#define GF_ISOM_MEDIA_PICT 4
#define GF_ISOM_SUBTYPE_LHE1 1
#define GF_ISOM_SUBTYPE_LHV1 2
#define GF_ISOM_SUBTYPE_HEV2 3
#define GF_ISOM_SUBTYPE_HVC2 4
#define GF_LOG_ERROR 1
#define GF_LOG_DASH 2

typedef struct GF_DashSegInput {
    char file_name[256];
    char szMime[256];
    char representationID[256];
    char* dependencyID;
    u32 trackNum;
    u32 single_track_num;
    u32 protection_scheme_type;
    u32 nb_representations;
    u32 idx_representations;
    u32 x, y, w, h;
    u32 moof_seqnum_increase;
    Bool isHdrHlg;
    Bool isHdrPq10;
    Bool virtual_representation;
    u32 lower_layer_track;
    void (*dasher_create_init_segment)(void);
    void (*dasher_input_classify)(void);
    void (*dasher_get_components_info)(void);
    void (*dasher_segment_file)(void);
} GF_DashSegInput;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_ESD {
    struct {
        u32 objectTypeIndication;
    } *decoderConfig;
} GF_ESD;
typedef struct GF_HEVCConfig GF_HEVCConfig;

typedef struct HEVC_SPS {
    u32 colour_description_present_flag;
    u32 colour_primaries;
    u32 matrix_coeffs;
    u32 transfer_characteristic;
} HEVC_SPS;

typedef struct HEVCState {
    HEVC_SPS sps[1];
    u32 sps_active_idx;
} HEVCState;

typedef struct GF_TSSegmenter {
    struct {
        struct {
            u32 count;
        } *programs;
    } *ts;
} GF_TSSegmenter;
typedef struct GF_Descriptor GF_Descriptor;

static int strnicmp(const char *s1, const char *s2, size_t n) {
    while (n-- && *s1 && *s2) {
        int diff = tolower(*s1) - tolower(*s2);
        if (diff) return diff;
        s1++;
        s2++;
    }
    return 0;
}

static int stricmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        int diff = tolower(*s1) - tolower(*s2);
        if (diff) return diff;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

static void GF_LOG(u32 level, u32 category, const char *fmt, ...) {}

static FILE* gf_fopen(const char* path, const char* mode) { return fopen(path, mode); }
static void gf_fclose(FILE* f) { fclose(f); }
static void* gf_realloc(void* ptr, size_t size) { return realloc(ptr, size); }
static void gf_free(void* ptr) { free(ptr); }
static void* gf_malloc(size_t size) { return malloc(size); }
static GF_Err gf_isom_last_error(void* ptr) { return GF_OK; }
static GF_ISOFile* gf_isom_open(const char* file, u32 mode, void* ptr) { return NULL; }
static void gf_isom_close(GF_ISOFile* file) {}
static u32 gf_isom_get_track_count(GF_ISOFile* file) { return 0; }
static Bool gf_isom_needs_layer_reconstruction(GF_ISOFile* file) { return GF_FALSE; }
static u32 gf_isom_get_track_by_id(GF_ISOFile* file, u32 id) { return 0; }
static u32 gf_isom_get_track_id(GF_ISOFile* file, u32 track) { return 0; }
static Bool gf_isom_is_media_encrypted(GF_ISOFile* file, u32 track, u32 sample) { return GF_FALSE; }
static GF_ESD* gf_isom_get_esd(GF_ISOFile* file, u32 track, u32 sample) { return NULL; }
static GF_HEVCConfig* gf_isom_hevc_config_get(GF_ISOFile* file, u32 track, u32 sample) { return NULL; }
static void gf_odf_hevc_cfg_del(GF_HEVCConfig* cfg) {}
static void gf_odf_desc_del(GF_Descriptor* desc) {}
static u32 gf_isom_get_media_type(GF_ISOFile* file, u32 track) { return 0; }
static u32 gf_isom_get_media_subtype(GF_ISOFile* file, u32 track, u32 sample) { return 0; }
static Bool gf_isom_is_video_subtype(u32 mtype) { return mtype == GF_ISOM_MEDIA_VISUAL; }
static u32 gf_isom_get_reference_count(GF_ISOFile* file, u32 track, u32 ref_type) { return 0; }
static void gf_isom_get_reference(GF_ISOFile* file, u32 track, u32 ref_type, u32 idx, u32* ref_track) {}
static void gf_isom_get_tile_info(GF_ISOFile* file, u32 track, u32 sample, u32* sg_idx, u32* id, Bool* indep, Bool* full_frame, u32* x, u32* y, u32* w, u32* h) {}
static void gf_isom_get_visual_info(GF_ISOFile* file, u32 track, u32 sample, u32* w, u32* h) {}
static Bool gf_isom_is_same_sample_description(GF_ISOFile* f1, u32 t1, u32 s1, GF_ISOFile* f2, u32 t2, u32 s2) { return GF_FALSE; }
static void gf_isom_delete(GF_ISOFile* file) {}
static void gf_media_hevc_parse_ps(GF_HEVCConfig* cfg, HEVCState* hevc, u32 type) {}
static Bool gf_isom_probe_file(const char* file) { return GF_FALSE; }
static Bool gf_m2ts_probe_file(const char* file) { return GF_FALSE; }
static GF_Err dasher_get_ts_demux(GF_TSSegmenter* seg, const char* file, u32 probe) { return GF_OK; }
static void dasher_del_ts_demux(GF_TSSegmenter* seg) {}
static void dasher_isom_create_init_segment(void) {}
static void dasher_isom_classify_input(void) {}
static void dasher_isom_get_components_info(void) {}
static void dasher_isom_segment_file(void) {}
static void dasher_generic_classify_input(void) {}
static void dasher_mp2t_get_components_info(void) {}
static void dasher_mp2t_segment_file(void) {}
static char* gf_dash_get_representationID(GF_DashSegInput* inputs, u32 count, const char* file, u32 track) { return NULL; }
static u32 gf_list_count(void* list) { return 0; }