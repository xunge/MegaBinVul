#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t u32;
typedef bool Bool;

typedef struct GF_ImageItemProperties {
    u32 width;
    u32 height;
    Bool hidden;
    Bool alpha;
    u32 mirror;
    u32 angle;
    u32 clap_wnum;
    u32 clap_wden;
    u32 clap_hnum;
    u32 clap_hden;
    u32 clap_honum;
    u32 clap_hoden;
    u32 clap_vonum;
    u32 clap_voden;
    u32 hOffset;
    u32 vOffset;
} GF_ImageItemProperties;

typedef struct GF_Descriptor GF_Descriptor;
typedef struct GF_ESD {
    u32 ESID;
    struct {
        u32 objectTypeIndication;
        struct {
            void* data;
            u32 dataLength;
        } *decoderSpecificInfo;
    } *decoderConfig;
} GF_ESD;

typedef struct GF_FilterPid GF_FilterPid;
typedef struct ISOMChannel {
    GF_FilterPid* pid;
    u32 item_id;
    Bool is_cenc;
    Bool is_encrypted;
} ISOMChannel;

typedef struct ISOMReader {
    void* mov;
    void* filter;
    GF_FilterPid* pid;
    u32 play_only_track_id;
    u32 itemid;
    void* itt;
} ISOMReader;

#define GF_TRUE true
#define GF_FALSE false
#define GF_STREAM_VISUAL 1
#define GF_STREAM_ENCRYPTED 2
#define GF_CODECID_HEVC 3
#define GF_CODECID_HEVC_TILES 4
#define GF_CODECID_RAW_UNCV 5
#define GF_PIXEL_UNCV 6
#define GF_ISOM_ITEM_TYPE_AUXI 7
#define GF_ISOM_ITEM_TYPE_UNCI 8
#define GF_ISOM_SUBTYPE_HVT1 9
#define GF_ISOM_SUBTYPE_UNCV 10
#define GF_ISOM_CBC_SCHEME 11
#define GF_ISOM_CENS_SCHEME 12
#define GF_ISOM_CBCS_SCHEME 13
#define GF_ISOM_CENC_SCHEME 14
#define GF_ISOM_PIFF_SCHEME 15
#define GF_ISOM_REF_TBAS 16

#define GF_PROP_PID_ID "ID"
#define GF_PROP_PID_ITEM_ID "ItemID"
#define GF_PROP_PID_TILE_BASE "TileBase"
#define GF_PROP_PID_STREAM_TYPE "StreamType"
#define GF_PROP_PID_CODECID "CodecID"
#define GF_PROP_PID_TIMESCALE "Timescale"
#define GF_PROP_PID_DECODER_CONFIG "DecoderConfig"
#define GF_PROP_PID_WIDTH "Width"
#define GF_PROP_PID_HEIGHT "Height"
#define GF_PROP_PID_HIDDEN "Hidden"
#define GF_PROP_PID_ALPHA "Alpha"
#define GF_PROP_PID_MIRROR "Mirror"
#define GF_PROP_PID_ROTATE "Rotate"
#define GF_PROP_PID_CLAP_W "ClapW"
#define GF_PROP_PID_CLAP_H "ClapH"
#define GF_PROP_PID_CLAP_X "ClapX"
#define GF_PROP_PID_CLAP_Y "ClapY"
#define GF_PROP_PID_PRIMARY_ITEM "PrimaryItem"
#define GF_PROP_PID_ITEM_NUM "ItemNum"
#define GF_PROP_PID_PIXFMT "PixelFormat"
#define GF_PROP_PID_ISOM_SUBTYPE "ISOMSubType"
#define GF_PROP_PID_CROP_POS "CropPos"
#define GF_PROP_PID_DEPENDENCY_ID "DependencyID"
#define GF_PROP_PID_PROTECTION_SCHEME_TYPE "ProtectionSchemeType"
#define GF_PROP_PID_PROTECTION_SCHEME_VERSION "ProtectionSchemeVersion"
#define GF_PROP_PID_ENCRYPTED "Encrypted"
#define GF_PROP_PID_ORIG_STREAM_TYPE "OrigStreamType"

typedef struct {
    u32 uint_val;
} PROP_UINT_STRUCT;

typedef struct {
    Bool bool_val;
} PROP_BOOL_STRUCT;

typedef struct {
    u32 fourcc_val;
} PROP_4CC_STRUCT;

typedef struct {
    const char* str_val;
} PROP_STRING_STRUCT;

typedef struct {
    int num;
    int den;
} PROP_FRAC_INT_STRUCT;

typedef struct {
    int x;
    int y;
} PROP_VEC2I_INT_STRUCT;

typedef struct {
    void* data;
    u32 length;
} PROP_DATA_NO_COPY_STRUCT;

#define PROP_UINT(x) ((PROP_UINT_STRUCT){x})
#define PROP_BOOL(x) ((PROP_BOOL_STRUCT){x})
#define PROP_4CC(x) ((PROP_4CC_STRUCT){x})
#define PROP_STRING(x) ((PROP_STRING_STRUCT){x})
#define PROP_FRAC_INT(x,y) ((PROP_FRAC_INT_STRUCT){x,y})
#define PROP_VEC2I_INT(x,y) ((PROP_VEC2I_INT_STRUCT){x,y})
#define PROP_DATA_NO_COPY(x,y) ((PROP_DATA_NO_COPY_STRUCT){x,y})

static inline void gf_odf_desc_del(GF_Descriptor* desc) {}
static inline u32 gf_isom_get_meta_item_count(void* mov, Bool arg1, u32 arg2) { return 0; }
static inline void gf_isom_get_meta_item_info(void* mov, Bool arg1, u32 arg2, u32 item_idx, u32* item_id, u32* item_type, u32* scheme_type, u32* scheme_version, void* arg3, void* arg4, void* arg5, const char** item_name, const char** item_mime_type, const char** item_encoding) {}
static inline void gf_isom_get_meta_image_props(void* mov, Bool arg1, u32 arg2, u32 item_id, GF_ImageItemProperties* props, void* arg3) {}
static inline GF_ESD* gf_media_map_item_esd(void* mov, u32 item_id) { return NULL; }
static inline Bool gf_isom_meta_item_has_ref(void* mov, Bool arg1, u32 arg2, u32 item_id, u32 ref_type) { return GF_FALSE; }
static inline u32 gf_isom_get_meta_primary_item_id(void* mov, Bool arg1, u32 arg2) { return 0; }
static inline Bool gf_sys_is_test_mode() { return GF_FALSE; }
static inline GF_FilterPid* gf_filter_pid_new(void* filter) { return NULL; }
static inline void gf_filter_pid_copy_properties(GF_FilterPid* dst, GF_FilterPid* src) {}
static inline void gf_filter_pid_set_property(GF_FilterPid* pid, const char* name, void* value) {}
static inline void gf_filter_pid_set_property_str(GF_FilterPid* pid, const char* name, void* value) {}
static inline ISOMChannel* isor_create_channel(ISOMReader* read, GF_FilterPid* pid, u32 arg1, u32 item_id, Bool arg2) { return NULL; }
static inline void isor_declare_pssh(ISOMChannel* ch) {}
static inline u32 gf_isom_meta_get_item_ref_id(void* mov, Bool arg1, u32 arg2, u32 item_id, u32 ref_type, u32 arg3) { return 0; }