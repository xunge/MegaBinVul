#include <stdint.h>
#include <stddef.h>

#define FT_UINT8 1
#define FT_UINT32 2
#define FT_STRING 3
#define FT_STRINGZ 4
#define FT_BYTES 5
#define FT_NONE 6

#define BASE_HEX 0x10
#define BASE_DEC 0x20
#define BASE_NONE 0x00
#define BASE_EXT_STRING 0x40
#define STR_UNICODE 0x80

#define HFILL {0,0,0,0,0,0,0,0}
#define EXPFILL {0,0,0,0,0,0,0,0}

#define PI_PROTOCOL 0
#define PI_NOTE 1
#define PI_UNDECODED 2
#define PI_WARN 3
#define PI_MALFORMED 4
#define PI_ERROR 5

typedef int gint;
typedef int gboolean;

struct value_string {
    unsigned int value;
    const char *strptr;
};

typedef struct {
    int *p_id;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const struct value_string *strings;
        uint32_t bitmask;
        const char *blurb;
        int hf_hint[8];
    } hfinfo;
} hf_register_info;

typedef struct {
    int *p_id;
    struct {
        const char *name;
        int severity;
        int type;
        const char *description;
        int exp_hint[8];
    } expert_info;
} ei_register_info;

typedef struct module_t module_t;
typedef struct expert_module_t expert_module_t;

static int proto_wbxml;
static int hf_wbxml_version;
static int hf_wbxml_public_id_known;
static int hf_wbxml_public_id_literal;
static int hf_wbxml_charset;
static int hf_wbxml_string_table_item_offset;
static int hf_wbxml_string_table_item_string;
static int hf_wbxml_switch_page;
static int hf_wbxml_known_tag;
static int hf_wbxml_end_known_tag;
static int hf_wbxml_end_known_tag_uint;
static int hf_wbxml_str_i;
static int hf_wbxml_str_t;
static int hf_wbxml_opaque_data;
static int hf_wbxml_entity;
static int hf_wbxml_literal;
static int hf_wbxml_ext_i;
static int hf_wbxml_ext_t;
static int hf_wbxml_extension_token;
static int hf_wbxml_reserved_2;
static int hf_wbxml_invalid_token;
static int hf_wbxml_known_attrvalue;
static int hf_wbxml_known_attrstart;
static int hf_wbxml_end_literal_tag;
static int hf_wbxml_literal_a;
static int hf_wbxml_literal_c;
static int hf_wbxml_literal_ac;
static int hf_wbxml_end_pi;
static int hf_wbxml_end_attribute_list;
static int hf_wbxml_pi_xml;

static gint ett_wbxml;
static gint ett_wbxml_str_tbl;
static gint ett_wbxml_content;
static gint ett_wbxml_tags;
static gint ett_wbxml_string_table_item;

static int ei_wbxml_data_not_shown;
static int ei_wbxml_content_type_not_supported;
static int ei_wbxml_content_type_disabled;
static int ei_wbxml_oversized_uintvar;
static int ei_wbxml_too_much_recursion;

static const struct value_string vals_wbxml_versions_ext[];
static const struct value_string vals_wbxml_public_ids_ext[];
static const struct value_string mibenum_vals_character_sets_ext[];

static gboolean skip_wbxml_token_mapping;
static gboolean disable_wbxml_token_parsing;

int proto_register_protocol(const char *name, const char *short_name, const char *filter_name);
void proto_register_field_array(int parent, hf_register_info *hf, int count);
void proto_register_subtree_array(gint **ett, int count);
expert_module_t* expert_register_protocol(int proto);
void expert_register_field_array(expert_module_t* em, ei_register_info *ei, int count);
module_t* prefs_register_protocol(int id, void (*apply_cb)(void));
void prefs_register_bool_preference(module_t *module, const char *name, const char *title, const char *description, gboolean *var);
void register_dissector(const char *name, void (*dissector)(void), int proto);

void dissect_wbxml(void);
void dissect_uaprof(void);