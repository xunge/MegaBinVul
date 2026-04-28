#include <stdint.h>
#include <stddef.h>

typedef int gint;
typedef void* dissector_handle_t;

typedef struct value_string {
    unsigned int value;
    const char *strptr;
} value_string;

static int hf_blip_message_number;
static int hf_blip_frame_flags;
static int hf_blip_properties_length;
static int hf_blip_properties;
static int hf_blip_message_body;
static int hf_blip_ack_size;
static int hf_blip_checksum;
static gint ett_blip;
static int ei_blip_decompress_buffer_too_small;
static int proto_blip;
static dissector_handle_t blip_handle;
static const value_string *flag_combos_ext;

typedef struct hf_register_info {
    int *id;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const void *strings;
        uint64_t mask;
        const char *blurb;
        int hf_hint;
    } hfinfo;
} hf_register_info;

typedef struct ei_register_info {
    int *id;
    struct {
        const char *name;
        int group;
        int severity;
        const char *summary;
        int hf_hint;
    } einfo;
} ei_register_info;

typedef struct expert_module_t expert_module_t;
typedef struct module_t module_t;
typedef void (*dissector_t)(void);

#define FT_UINT64 1
#define FT_UINT8 2
#define FT_STRING 3
#define FT_UINT32 4
#define BASE_DEC 1
#define BASE_HEX 2
#define BASE_EXT_STRING 4
#define STR_UNICODE 1
#define PI_UNDECODED 1
#define PI_WARN 2
#define EXPFILL 0
#define HFILL 0

static unsigned int max_uncompressed_size;

static inline unsigned int array_length(const void *arr) {
    return 0;
}

static int proto_register_protocol(const char *name, const char *short_name, const char *filter_name) { return 0; }
static void proto_register_field_array(int proto, const hf_register_info *hf, unsigned int size) {}
static void proto_register_subtree_array(gint *const *ett, unsigned int size) {}
static expert_module_t* expert_register_protocol(int proto) { return NULL; }
static void expert_register_field_array(expert_module_t *expert, const ei_register_info *ei, unsigned int size) {}
static dissector_handle_t register_dissector(const char *name, dissector_t dissector, int proto) { return NULL; }
static module_t* prefs_register_protocol(int proto, void *apply_cb) { return NULL; }
static void prefs_register_uint_preference(module_t *module, const char *name, const char *title, const char *description, unsigned int base, unsigned int *var) {}

static void dissect_blip(void) {}