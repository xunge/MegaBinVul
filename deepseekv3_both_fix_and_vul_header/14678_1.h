#include <stdint.h>
#include <stddef.h>

typedef struct value_string {
    uint32_t value;
    const char *strptr;
} value_string;

#define FT_UINT8   1
#define FT_UINT16  2
#define FT_UINT32  3
#define FT_UINT64  4
#define FT_BYTES   5
#define FT_FRAMENUM 6
#define FT_RELATIVE_TIME 7

#define BASE_DEC   10
#define BASE_HEX   16
#define BASE_NONE  0

#define HFILL 0
#define PI_PROTOCOL 0
#define PI_WARN 1
#define EXPFILL 0

typedef int gint;

typedef struct hf_register_info {
    int *hf_id;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const void *strings;
        uint32_t bitmask;
        const char *blurb;
        int hfiller;
    } finfo;
} hf_register_info;

typedef struct ei_register_info {
    int *ei;
    struct {
        const char *pfx;
        int severity;
        int summary;
        const char *description;
        int expfill;
    } einfo;
} ei_register_info;

typedef struct module_t module_t;
typedef struct expert_module_t expert_module_t;

static int proto_ldss;
static int hf_ldss_message_id;
static int hf_ldss_message_detail;
static int hf_ldss_digest_type;
static int hf_ldss_compression;
static int hf_ldss_cookie;
static int hf_ldss_digest;
static int hf_ldss_size;
static int hf_ldss_offset;
static int hf_ldss_target_time;
static int hf_ldss_reserved_1;
static int hf_ldss_port;
static int hf_ldss_rate;
static int hf_ldss_priority;
static int hf_ldss_property_count;
static int hf_ldss_properties;
static int hf_ldss_file_data;
static int hf_ldss_response_in;
static int hf_ldss_response_to;
static int hf_ldss_initiated_by;
static int hf_ldss_transfer_response_time;
static int hf_ldss_transfer_completed_in;

static int ett_ldss_broadcast;
static int ett_ldss_transfer;
static int ett_ldss_transfer_req;

static int ei_ldss_unrecognized_line;

static const value_string ldss_message_id_value[] = { {0, NULL} };
static const value_string ldss_inferred_value[] = { {0, NULL} };
static const value_string ldss_digest_type_value[] = { {0, NULL} };
static const value_string ldss_compression_value[] = { {0, NULL} };

static uint16_t global_udp_port_ldss;

#define VALS(x) (x)

void proto_reg_handoff_ldss(void);
void ldss_init_protocol(void);
int proto_register_protocol(const char *name, const char *short_name, const char *filter_name);
void proto_register_field_array(int parent, hf_register_info *hf, int count);
void proto_register_subtree_array(gint **ett, int count);
expert_module_t *expert_register_protocol(int proto);
void expert_register_field_array(expert_module_t *em, ei_register_info *ei, int count);
module_t *prefs_register_protocol(int proto, void (*reg_handoff)(void));
void prefs_register_uint_preference(module_t *module, const char *name, const char *title, const char *description, uint32_t base, uint16_t *var);
void register_init_routine(void (*func)(void));