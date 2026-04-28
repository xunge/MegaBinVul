#include <stdint.h>
#include <stddef.h>

typedef int gint;

typedef struct hf_register_info {
    int *id;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const void *strings;
        uint32_t bitmask;
        const char *blurb;
        int hfinfo;
    } info;
} hf_register_info;

typedef struct ei_register_info {
    int *id;
    struct {
        const char *name;
        int severity;
        int summary;
        const char *description;
        int expert_info;
    } info;
} ei_register_info;

typedef struct expert_module_t expert_module_t;

static int hf_fb_zero_puflags;
static int hf_fb_zero_puflags_vrsn;
static int hf_fb_zero_puflags_unknown;
static int hf_fb_zero_version;
static int hf_fb_zero_length;
static int hf_fb_zero_tag;
static int hf_fb_zero_tag_number;
static int hf_fb_zero_tags;
static int hf_fb_zero_tag_type;
static int hf_fb_zero_tag_offset_end;
static int hf_fb_zero_tag_length;
static int hf_fb_zero_tag_value;
static int hf_fb_zero_tag_sni;
static int hf_fb_zero_tag_vers;
static int hf_fb_zero_tag_sno;
static int hf_fb_zero_tag_aead;
static int hf_fb_zero_tag_scid;
static int hf_fb_zero_tag_time;
static int hf_fb_zero_tag_alpn;
static int hf_fb_zero_tag_pubs;
static int hf_fb_zero_tag_kexs;
static int hf_fb_zero_tag_nonc;
static int hf_fb_zero_tag_unknown;
static int hf_fb_zero_padding;
static int hf_fb_zero_payload;
static int hf_fb_zero_unknown;

static gint ett_fb_zero;
static gint ett_fb_zero_puflags;
static gint ett_fb_zero_prflags;
static gint ett_fb_zero_ft;
static gint ett_fb_zero_ftflags;
static gint ett_fb_zero_tag_value;

static int ei_fb_zero_tag_undecoded;
static int ei_fb_zero_tag_length;
static int ei_fb_zero_tag_unknown;
static int ei_fb_zero_length_invalid;

static int proto_fb_zero;
static void *fb_zero_handle;
static void *dissect_fb_zero;

#define FT_UINT8 1
#define FT_BOOLEAN 2
#define FT_STRING 3
#define FT_UINT32 4
#define FT_NONE 5
#define FT_BYTES 6
#define FT_UINT16 7
#define FT_UINT24 8

#define BASE_HEX 1
#define BASE_DEC 2
#define BASE_NONE 3
#define BASE_DEC_HEX 4

#define TFS(x) x
static const char *tfs_yes_no[] = { "No", "Yes" };

#define PUFLAGS_VRSN 0x01
#define PUFLAGS_UNKN 0xFE

#define HFILL 0
#define EXPFILL 0

#define PI_UNDECODED 1
#define PI_NOTE 2
#define PI_MALFORMED 3
#define PI_PROTOCOL 4
#define PI_WARN 5

#define array_length(x) (sizeof(x)/sizeof(x[0]))

int proto_register_protocol(const char *name, const char *short_name, const char *filter_name);
void proto_register_field_array(int proto, hf_register_info *hf, int size);
void proto_register_subtree_array(gint *ett, int size);
void *register_dissector(const char *name, void (*dissector)(void), int proto);
expert_module_t *expert_register_protocol(int proto);
void expert_register_field_array(expert_module_t *em, ei_register_info *ei, int size);