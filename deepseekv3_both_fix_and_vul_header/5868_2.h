#include <stdint.h>
#include <stddef.h>

typedef struct module_t module_t;
typedef int gint;

typedef struct {
    int* p_id;
    struct {
        const char* name;
        const char* abbrev;
        int type;
        int display;
        const void* strings;
        int bitmask;
        const char* blurb;
        int hf_hint;
    } hfinfo;
} hf_register_info;

typedef struct {
    int* p_id;
    struct {
        const char* name;
        int severity;
        int level;
        const char* description;
        int exp_hint;
    } einfo;
} ei_register_info;

typedef struct expert_module_t expert_module_t;

typedef struct {
    const char* name;
    int value;
} value_string;

typedef struct {
    char* string;
    int byte_order;
    char* label;
} uat_key_record_t;

typedef struct {
    const char* name;
    int type;
    int cb;
    const char* desc;
    const void* values;
} uat_field_t;

#define FT_UINT8 1
#define FT_BOOLEAN 2
#define FT_UINT32 3
#define FT_EUI64 4
#define FT_BYTES 5
#define FT_FRAMENUM 6
#define FT_STRING 7

#define BASE_HEX 1
#define BASE_DEC 2
#define BASE_NONE 3

#define HFILL 0
#define ZBEE_SEC_CONTROL_KEY 0
#define ZBEE_SEC_CONTROL_NONCE 0

#define PI_UNDECODED 0
#define PI_WARN 1
#define PI_PROTOCOL 2
#define PI_NOTE 3
#define EXPFILL 0

#define UAT_FLD_CSTRING(a,b,c,d) {c, 0, 0, d, NULL}
#define UAT_FLD_VS(a,b,c,d,e) {c, 0, 0, e, d}
#define UAT_END_FIELDS {NULL, 0, 0, NULL, NULL}

#define UAT_AFFECTS_DISSECTION 0
#define FALSE 0
#define TRUE 1

static int hf_zbee_sec_field;
static int hf_zbee_sec_key_id;
static int hf_zbee_sec_nonce;
static int hf_zbee_sec_counter;
static int hf_zbee_sec_src64;
static int hf_zbee_sec_key_seqno;
static int hf_zbee_sec_mic;
static int hf_zbee_sec_key;
static int hf_zbee_sec_key_origin;
static int hf_zbee_sec_decryption_key;

static gint ett_zbee_sec;
static gint ett_zbee_sec_control;

static int ei_zbee_sec_encrypted_payload;
static int ei_zbee_sec_encrypted_payload_sliced;
static int ei_zbee_sec_extended_source_unknown;

static const value_string zbee_sec_key_names[] = {{NULL, 0}};
static const value_string zbee_sec_level_enums[] = {{NULL, 0}};
static const value_string byte_order_vals[] = {{NULL, 0}};

static int gPREF_zbee_sec_level;
static void* zbee_sec_key_table_uat;
static uat_key_record_t* uat_key_records;
static unsigned num_uat_key_records;

static void uat_key_record_copy_cb(void*, const void*, size_t) {}
static void uat_key_record_update_cb(void*, char**) {}
static void uat_key_record_free_cb(void*) {}
static void uat_key_record_post_update(void) {}

static module_t* prefs_register_protocol(int, void*) { return NULL; }
static void prefs_register_enum_preference(module_t*, const char*, const char*, const char*, int*, const value_string*, int) {}
static void* uat_new(const char*, size_t, const char*, int, void**, unsigned*, int, void*, void*, void*, void*, void*, uat_field_t*) { return NULL; }
static void prefs_register_uat_preference(module_t*, const char*, const char*, const char*, void*) {}
static void proto_register_field_array(int, hf_register_info*, int) {}
static void proto_register_subtree_array(gint**, int) {}
static expert_module_t* expert_register_protocol(int) { return NULL; }
static void expert_register_field_array(expert_module_t*, ei_register_info*, int) {}

#define VALS(x) (x)
#define array_length(x) (sizeof(x)/sizeof(x[0]))