#include <stdint.h>
#include <stddef.h>

typedef uint32_t guint32;
typedef int gint;

typedef struct {
    unsigned int value;
    const char *strptr;
} value_string;

typedef struct {
    int *p_id;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const value_string *strings;
        guint32 bitmask;
        const char *blurb;
        int hf_hint;
    } info;
} hf_register_info;

typedef struct {
    const char *name;
    const char *abbrev;
    const char *filter_name;
} expert_field;

typedef struct {
    expert_field *p_id;
    struct {
        const char *name;
        int group;
        int severity;
        const char *text;
        int hf_hint;
    } info;
} ei_register_info;

typedef struct {
    int dummy;
} expert_module_t;

static int proto_pktc_mtafqdn = -1;
static int hf_pktc_mtafqdn_msgtype = -1;
static int hf_pktc_mtafqdn_enterprise = -1;
static int hf_pktc_mtafqdn_version = -1;
static int hf_pktc_mtafqdn_mac = -1;
static int hf_pktc_mtafqdn_pub_key_hash = -1;
static int hf_pktc_mtafqdn_manu_cert_revoked = -1;
static int hf_pktc_mtafqdn_fqdn = -1;
static int hf_pktc_mtafqdn_ip = -1;
static gint ett_pktc_mtafqdn = -1;

static expert_field ei_pktc_unknown_kmmid = {0};
static expert_field ei_pktc_unknown_doi = {0};
static expert_field ei_pktc_unknown_kerberos_application = {0};

#define FT_UINT8 1
#define FT_UINT32 2
#define FT_ETHER 3
#define FT_BYTES 4
#define FT_ABSOLUTE_TIME 5
#define FT_STRING 6
#define FT_IPv4 7
#define BASE_DEC 1
#define BASE_NONE 2
#define ABSOLUTE_TIME_LOCAL 1
#define PI_PROTOCOL 1
#define PI_WARN 2
#define HFILL 0
#define EXPFILL 0
#define VALS(x) (x)

static const char *array_length(const void *arr) {
    return 0;
}

static int proto_register_protocol(const char *name, const char *short_name, const char *filter_name) { return 0; }
static void proto_register_field_array(int proto, hf_register_info *hf, const char *len) {}
static void proto_register_subtree_array(int **ett, const char *len) {}
static expert_module_t *expert_register_protocol(int proto) { return 0; }
static void expert_register_field_array(expert_module_t *em, ei_register_info *ei, const char *len) {}

static const value_string pktc_mtafqdn_msgtype_vals[] = {
    {0, NULL}
};