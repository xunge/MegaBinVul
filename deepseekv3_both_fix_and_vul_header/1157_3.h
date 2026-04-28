#include <stdint.h>
#include <stddef.h>

typedef int gint;

typedef struct _hf_register_info {
    int *hf_id;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const void *strings;
        uint64_t bitmask;
        const char *blurb;
        int hfinfo;
    } name_info;
} hf_register_info;

typedef struct _ei_register_info {
    int *ei_id;
    struct {
        const char *name;
        int severity;
        int summary;
        const char *description;
        int hf_info;
    } name_info;
} ei_register_info;

typedef struct _expert_module_t expert_module_t;

static int hf_amf_version;
static int hf_amf_header_count;
static int hf_amf_header_name;
static int hf_amf_header_must_understand;
static int hf_amf_header_length;
static int hf_amf_message_count;
static int hf_amf_message_target_uri;
static int hf_amf_message_response_uri;
static int hf_amf_message_length;
static int hf_amf_amf0_type;
static int hf_amf_amf3_type;
static int hf_amf_number;
static int hf_amf_integer;
static int hf_amf_boolean;
static int hf_amf_stringlength;
static int hf_amf_string;
static int hf_amf_string_reference;
static int hf_amf_object_reference;
static int hf_amf_date;
static int hf_amf_longstring;
static int hf_amf_xml_doc;
static int hf_amf_xmllength;
static int hf_amf_xml;
static int hf_amf_int64;
static int hf_amf_bytearraylength;
static int hf_amf_bytearray;
static int hf_amf_object;
static int hf_amf_traitcount;
static int hf_amf_classnamelength;
static int hf_amf_classname;
static int hf_amf_membernamelength;
static int hf_amf_membername;
static int hf_amf_trait_reference;
static int hf_amf_ecmaarray;
static int hf_amf_strictarray;
static int hf_amf_array;
static int hf_amf_arraylength;
static int hf_amf_arraydenselength;
static int hf_amf_end_of_object_marker;
static int hf_amf_end_of_associative_part;
static int hf_amf_end_of_dynamic_members;

static int ei_amf_loop;

static gint ett_amf;
static gint ett_amf_headers;
static gint ett_amf_messages;
static gint ett_amf_value;
static gint ett_amf_property;
static gint ett_amf_string;
static gint ett_amf_array_element;
static gint ett_amf_traits;
static gint ett_amf_trait_member;

static int proto_amf;

#define FT_UINT16 1
#define FT_UINT_STRING 2
#define FT_BOOLEAN 3
#define FT_UINT32 4
#define FT_UINT8 5
#define FT_DOUBLE 6
#define FT_STRING 7
#define FT_ABSOLUTE_TIME 8
#define FT_INT64 9
#define FT_BYTES 10
#define FT_NONE 11

#define BASE_DEC 1
#define BASE_NONE 2
#define BASE_HEX 3

#define ABSOLUTE_TIME_LOCAL 1

#define PI_MALFORMED 1
#define PI_ERROR 2

#define HFILL 0
#define EXPFILL 0

#define VALS(x) (x)

#define array_length(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef struct {
    unsigned int value;
    const char *strptr;
} value_string;

static const value_string amf0_type_vals[] = {
    {0, NULL}
};

static const value_string amf3_type_vals[] = {
    {0, NULL}
};

void proto_register_field_array(int proto, hf_register_info *hf, int count);
void proto_register_subtree_array(gint **ett, int count);
expert_module_t* expert_register_protocol(int proto);
void expert_register_field_array(expert_module_t *em, ei_register_info *ei, int count);
int proto_register_protocol(const char *name, const char *short_name, const char *filter_name);