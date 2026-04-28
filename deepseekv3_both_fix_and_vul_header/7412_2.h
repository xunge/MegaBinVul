#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint32_t u32;
typedef uint8_t u8;
typedef int32_t GF_Err;
typedef uint8_t bin128[16];
typedef enum {GF_FALSE=0, GF_TRUE=1} GF_Bool;

typedef struct GF_List GF_List;
typedef struct GF_XMLAttribute GF_XMLAttribute;
typedef struct GF_XMLNode GF_XMLNode;
typedef struct GF_MPD_Descriptor GF_MPD_Descriptor;
typedef struct GF_DashStream GF_DashStream;
typedef struct GF_MPD_Period GF_MPD_Period;
typedef struct GF_DasherCtx GF_DasherCtx;
typedef struct GF_PropertyValue GF_PropertyValue;
typedef struct GF_MPD_AdaptationSet GF_MPD_AdaptationSet;
typedef struct GF_BitStream GF_BitStream;

enum {
    GF_BITSTREAM_READ,
    GF_BITSTREAM_WRITE
};

struct GF_List {
    void **items;
    u32 count;
    u32 capacity;
};

struct GF_XMLAttribute {
    const char *name;
    const char *value;
};

struct GF_XMLNode {
    u32 type;
    char *name;
    GF_List *content;
};

struct GF_MPD_Descriptor {
    char *scheme_id_uri;
    char *value;
    GF_List *x_attributes;
    GF_List *x_children;
};

struct GF_DashStream {
    GF_Bool is_encrypted;
    void *ipid;
    GF_MPD_AdaptationSet *set;
    GF_Bool owns_set;
    GF_DashStream *muxed_base;
};

struct GF_MPD_Period {
    GF_List *streams;
};

struct GF_DasherCtx {
    GF_MPD_Period *current_period;
    GF_Bool use_cenc;
    u32 pssh;
    GF_Bool do_mpd;
};

struct GF_PropertyValue {
    u32 type;
    union {
        u32 uint;
        struct {
            void *ptr;
            u32 size;
        } data;
    } value;
};

struct GF_BitStream {
    const u8 *buffer;
    u32 size;
    u32 position;
    u32 mode;
};

#define GF_ISOM_CENC_SCHEME 0x63656E63
#define GF_ISOM_CBC_SCHEME 0x63626331
#define GF_ISOM_CENS_SCHEME 0x63656E73
#define GF_ISOM_CBCS_SCHEME 0x63626373
#define GF_ISOM_BOX_TYPE_PSSH 0x70737368
#define GF_MAX_PATH 256
#define GF_DASH_PSSH_MOOF 1

#define GF_PROP_PID_PROTECTION_SCHEME_TYPE 0
#define GF_PROP_PID_CENC_KEY_INFO 1
#define GF_PROP_PID_CENC_PSSH 2

#define GF_XML_NODE_TYPE 0
#define GF_XML_TEXT_TYPE 1

#define GF_LOG_WARNING 2
#define GF_LOG_DASH 3

#define GF_SAFEALLOC(ptr, type) ptr = malloc(sizeof(type))

static GF_List *gf_list_new(void);
static u32 gf_list_count(const GF_List *list);
static void *gf_list_get(const GF_List *list, u32 index);
static GF_Err gf_list_add(GF_List *list, void *item);
static GF_BitStream *gf_bs_new(const void *buffer, u32 size, u32 mode);
static void gf_bs_reassign_buffer(GF_BitStream *bs, const void *buffer, u32 size);
static u32 gf_bs_read_u32(GF_BitStream *bs);
static u8 gf_bs_read_u8(GF_BitStream *bs);
static void gf_bs_read_data(GF_BitStream *bs, void *data, u32 size);
static void gf_bs_write_u32(GF_BitStream *bs, u32 value);
static void gf_bs_write_u8(GF_BitStream *bs, u8 value);
static void gf_bs_write_u24(GF_BitStream *bs, u32 value);
static void gf_bs_write_data(GF_BitStream *bs, const void *data, u32 size);
static u32 gf_bs_get_position(GF_BitStream *bs);
static void gf_bs_seek(GF_BitStream *bs, u32 position);
static void gf_bs_get_content(GF_BitStream *bs, u8 **data, u32 *size);
static void gf_bs_del(GF_BitStream *bs);
static const GF_PropertyValue *gf_filter_pid_get_property(void *pid, u32 prop);
static GF_MPD_Descriptor *gf_mpd_descriptor_new(const char *scheme_id_uri, const char *value, const char *name);
static GF_XMLAttribute *gf_xml_dom_create_attribute(const char *name, const char *value);
static char *gf_4cc_to_str(u32 fourcc);
static void get_canon_urn(const void *data, char *output);
static char *get_drm_kms_name(const char *urn);
static void GF_LOG(u32 level, u32 category, const char *fmt, ...);
static size_t gf_base64_encode(const char *in, size_t in_len, char *out, size_t out_len);
static char *gf_strdup(const char *str);
static void *gf_malloc(size_t size);
static void gf_free(void *ptr);