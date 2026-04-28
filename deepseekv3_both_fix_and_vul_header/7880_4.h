#include <stdint.h>
#include <stddef.h>

typedef int gint;

typedef struct module_t module_t;
typedef struct expert_module_t expert_module_t;

typedef struct {
    int *hf_field;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const void *strings;
        uint64_t mask;
        const char *blurb;
        int hf_field_type;
    } info;
} hf_register_info;

typedef struct {
    int *ei_field;
    struct {
        const char *name;
        int severity;
        int summary;
        const char *description;
        int expert_field_type;
    } info;
} ei_register_info;

typedef struct {
    unsigned int value;
    const char *strptr;
} value_string;

typedef struct {
    const char *true_string;
    const char *false_string;
} true_false_string;

static int hf_rpkirtr_version;
static int hf_rpkirtr_pdu_type;
static int hf_rpkirtr_reserved;
static int hf_rpkirtr_session_id;
static int hf_rpkirtr_length;
static int hf_rpkirtr_serial_number;
static int hf_rpkirtr_flags;
static int hf_rpkirtr_flags_aw;
static int hf_rpkirtr_flags_rk;
static int hf_rpkirtr_prefix_length;
static int hf_rpkirtr_max_length;
static int hf_rpkirtr_ipv4_prefix;
static int hf_rpkirtr_ipv6_prefix;
static int hf_rpkirtr_as_number;
static int hf_rpkirtr_error_code;
static int hf_rpkirtr_length_pdu;
static int hf_rpkirtr_error_pdu;
static int hf_rpkirtr_length_text;
static int hf_rpkirtr_error_text;
static int hf_rpkirtr_refresh_interval;
static int hf_rpkirtr_retry_interval;
static int hf_rpkirtr_expire_interval;
static int hf_rpkirtr_subject_key_identifier;
static int hf_rpkirtr_subject_public_key_info;

static gint ett_rpkirtr;
static gint ett_flags;
static gint ett_flags_nd;

static int ei_rpkirtr_wrong_version_router_key;
static int ei_rpkirtr_bad_length;

static int proto_rpkirtr;
static int g_port_rpkirtr_tls;
static void *rpkirtr_handle;
static void (*dissect_rpkirtr)(void);

static const value_string rtr_pdu_type_vals[] = {
    {0, NULL},
    {0, NULL}
};

static const value_string rtr_error_code_vals[] = {
    {0, NULL},
    {0, NULL}
};

static const true_false_string tfs_flag_type_aw = {
    "AW",
    "Not AW"
};

static const true_false_string tfs_flag_type_rk = {
    "RK",
    "Not RK"
};

#define FT_UINT8 0
#define FT_BYTES 1
#define FT_UINT16 2
#define FT_UINT32 3
#define FT_BOOLEAN 4
#define FT_IPv4 5
#define FT_IPv6 6
#define FT_STRING 7
#define FT_NONE 8

#define BASE_DEC 0
#define BASE_NONE 1
#define BASE_HEX 2

#define HFILL 0
#define EXPFILL 0

#define PI_MALFORMED 0
#define PI_WARN 1
#define PI_ERROR 2

#define VALS(x) x

#define TFS(x) x

#define array_length(x) (sizeof(x)/sizeof(x[0]))

int proto_register_protocol(const char *name, const char *short_name, const char *filter_name);
void proto_register_field_array(int proto_id, hf_register_info *hf, int size);
void proto_register_subtree_array(gint *ett, int size);
module_t *prefs_register_protocol(int proto_id, void (*reg_handoff)(void));
void prefs_register_uint_preference(module_t *module, const char *name, const char *title, const char *description, int base, int *var);
expert_module_t *expert_register_protocol(int proto_id);
void expert_register_field_array(expert_module_t *expert, ei_register_info *ei, int size);
void *register_dissector(const char *name, void (*dissector)(void), int proto_id);

static void proto_reg_handoff_rpkirtr(void) {}