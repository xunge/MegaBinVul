#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct module_t module_t;
typedef struct expert_module_t expert_module_t;

typedef struct hf_register_info {
    int *p_id;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const void *strings;
        uint64_t bitmask;
        const char *blurb;
        int hf_hint;
    } hfinfo;
} hf_register_info;

typedef struct ei_register_info {
    int *p_id;
    struct {
        const char *name;
        int severity;
        int summary;
        const char *description;
        int hf_hint;
    } einfo;
} ei_register_info;

typedef struct wmem_array_t {
    void *data;
    size_t count;
} wmem_array_t;

typedef struct g_ptr_array_t {
    void **pdata;
    size_t len;
} g_ptr_array_t;

typedef struct range_t {
    unsigned int low;
    unsigned int high;
} range_t;

typedef int dissector_table_t;
typedef int tap_t;

#define FT_UINT8 0
#define FT_UINT24 0
#define FT_UINT32 0
#define FT_BOOLEAN 0
#define FT_BYTES 0
#define FT_FRAMENUM 0
#define FT_RELATIVE_TIME 0
#define FT_IPv6 0
#define BASE_HEX 0
#define BASE_DEC 0
#define BASE_NONE 0
#define BASE_EXT_STRING 0
#define PI_MALFORMED 0
#define PI_WARN 0
#define PI_ERROR 0
#define PI_UNDECODED 0
#define PI_NOTE 0
#define DISSECTOR_TABLE_ALLOW_DUPLICATE 0
#define FRAMENUM_TYPE(x) 0
#define HFILL 0
#define EXPFILL 0
#define MAX_UDP_PORT 65535
#define MAX_SCTP_PORT 65535
#define DEFAULT_DIAMETER_PORT_RANGE "3868"
#define TRUE 1
#define FALSE 0

typedef uint32_t guint;
typedef int32_t gint;
typedef int gboolean;

static int hf_diameter_version;
static int hf_diameter_length;
static int hf_diameter_flags;
static int hf_diameter_flags_request;
static int hf_diameter_flags_proxyable;
static int hf_diameter_flags_error;
static int hf_diameter_flags_T;
static int hf_diameter_flags_reserved4;
static int hf_diameter_flags_reserved5;
static int hf_diameter_flags_reserved6;
static int hf_diameter_flags_reserved7;
static int hf_diameter_vendor_id;
static int hf_diameter_application_id;
static int hf_diameter_hopbyhopid;
static int hf_diameter_endtoendid;
static int hf_diameter_avp;
static int hf_diameter_avp_len;
static int hf_diameter_avp_code;
static int hf_diameter_avp_flags;
static int hf_diameter_avp_flags_vendor_specific;
static int hf_diameter_avp_flags_mandatory;
static int hf_diameter_avp_flags_protected;
static int hf_diameter_avp_flags_reserved3;
static int hf_diameter_avp_flags_reserved4;
static int hf_diameter_avp_flags_reserved5;
static int hf_diameter_avp_flags_reserved6;
static int hf_diameter_avp_flags_reserved7;
static int hf_diameter_avp_vendor_id;
static int hf_diameter_avp_data_wrong_length;
static int hf_diameter_avp_pad;
static int hf_diameter_code;
static int hf_diameter_answer_in;
static int hf_diameter_answer_to;
static int hf_diameter_answer_time;
static int hf_framed_ipv6_prefix_reserved;
static int hf_framed_ipv6_prefix_length;
static int hf_framed_ipv6_prefix_bytes;
static int hf_framed_ipv6_prefix_ipv6;
static int hf_diameter_3gpp2_exp_res;
static int hf_diameter_other_vendor_exp_res;
static int ei_diameter_invalid_ipv6_prefix_len;

static int ett_diameter;
static int ett_diameter_flags;
static int ett_diameter_avp_flags;
static int ett_diameter_avpinfo;
static int ett_unknown;
static int ett_err;

static int ei_diameter_reserved_bit_set;
static int ei_diameter_avp_code;
static int ei_diameter_avp_vendor_id;
static int ei_diameter_avp_no_data;
static int ei_diameter_avp_pad;
static int ei_diameter_avp_len;
static int ei_diameter_application_id;
static int ei_diameter_version;
static int ei_diameter_code;

static int proto_diameter;
static dissector_table_t diameter_dissector_table;
static dissector_table_t diameter_3gpp_avp_dissector_table;
static dissector_table_t diameter_ericsson_avp_dissector_table;
static dissector_table_t diameter_expr_result_vnd_table;
static tap_t diameter_tap;

static range_t global_diameter_tcp_port_range;
static range_t global_diameter_sctp_port_range;
static range_t global_diameter_udp_port_range;
static gboolean gbl_diameter_desegment;

struct unknown_avp_t {
    int hf_value;
    int ett;
} unknown_avp;

struct build_dict_t {
    wmem_array_t *hf;
    g_ptr_array_t *ett;
} build_dict;

struct dictionary_t {
    void *applications;
} dictionary;

struct tfs_t {
    const char *set;
    const char *notset;
} tfs_set_notset;

static const char *diameter_3gpp2_exp_res_vals[] = {
    NULL
};

static const char *sminmpec_values_ext = NULL;
static const char *VALS_EXT_PTR(void *ptr) { return NULL; }
static const char *VALS(const char **vals) { return NULL; }
static const char *TFS(struct tfs_t *tfs) { return NULL; }

static void dissect_diameter(void) {}
static void wmem_array_append(wmem_array_t *array, void *data, size_t count) {}
static void *wmem_array_get_raw(wmem_array_t *array) { return NULL; }
static size_t wmem_array_get_count(wmem_array_t *array) { return 0; }
static void g_ptr_array_add(g_ptr_array_t *array, void *data) {}
static void g_ptr_array_free(g_ptr_array_t *array, gboolean free_segment) {}
static int proto_register_protocol(const char *name, const char *short_name, const char *filter_name) { return 0; }
static void proto_register_field_array(int proto, hf_register_info *hf, int count) {}
static void proto_register_subtree_array(gint **ett, int count) {}
static expert_module_t *expert_register_protocol(int proto) { return NULL; }
static void expert_register_field_array(expert_module_t *em, ei_register_info *ei, int count) {}
static void new_register_dissector(const char *name, void (*func)(void), int proto) {}
static dissector_table_t register_dissector_table(const char *name, const char *ui_name, int type, int base, int flags) { return 0; }
static void range_convert_str(range_t *range, const char *str, int max) {}
static module_t *prefs_register_protocol(int proto, void (*func)(void)) { return NULL; }
static void prefs_register_range_preference(module_t *module, const char *name, const char *title, const char *description, range_t *range, int max) {}
static void prefs_register_bool_preference(module_t *module, const char *name, const char *title, const char *description, gboolean *var) {}
static void prefs_register_obsolete_preference(module_t *module, const char *name) {}
static tap_t register_tap(const char *name) { return 0; }
static void register_srt_table(int proto, const char *name, int num_fields, void (*packet_func)(void), void (*init_func)(void), void *user_data) {}
static void diameterstat_packet(void) {}
static void diameterstat_init(void) {}
static void proto_reg_handoff_diameter(void) {}

#define array_length(x) (sizeof(x)/sizeof(x[0]))
#define DIAM_FLAGS_R 0x80
#define DIAM_FLAGS_P 0x40
#define DIAM_FLAGS_E 0x20
#define DIAM_FLAGS_T 0x10
#define DIAM_FLAGS_RESERVED4 0x08
#define DIAM_FLAGS_RESERVED5 0x04
#define DIAM_FLAGS_RESERVED6 0x02
#define DIAM_FLAGS_RESERVED7 0x01
#define AVP_FLAGS_V 0x80
#define AVP_FLAGS_M 0x40
#define AVP_FLAGS_P 0x20
#define AVP_FLAGS_RESERVED3 0x10
#define AVP_FLAGS_RESERVED4 0x08
#define AVP_FLAGS_RESERVED5 0x04
#define AVP_FLAGS_RESERVED6 0x02
#define AVP_FLAGS_RESERVED7 0x01