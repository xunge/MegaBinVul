#include <stdint.h>
#include <stdlib.h>

typedef struct {
    int* p_id;
    struct {
        const char* name;
        const char* abbrev;
        int type;
        int display;
        void* strings;
        uint32_t bitmask;
        const char* blurb;
        int hf_hint;
    } hfinfo;
} hf_register_info;

typedef struct {
    int* p_id;
    struct {
        const char* name;
        int severity;
        int summary;
        const char* description;
        int exp_hint;
    } einfo;
} ei_register_info;

typedef struct _module_t module_t;
typedef struct _expert_module_t expert_module_t;
typedef int gint;
typedef unsigned int proto_t;

static int hf_bencoded_string;
static int hf_bencoded_list;
static int hf_bencoded_int;
static int hf_bencoded_dict;
static int hf_bencoded_dict_entry;
static int hf_bencoded_list_terminator;
static int hf_bt_dht_error;
static int hf_bt_dht_peer;
static int hf_bt_dht_peers;
static int hf_bt_dht_node;
static int hf_bt_dht_nodes;
static int hf_bt_dht_id;
static int hf_ip;
static int hf_ip6;
static int hf_port;
static int hf_truncated_data;

static int ett_bt_dht;
static int ett_bencoded_list;
static int ett_bencoded_dict;
static int ett_bt_dht_error;
static int ett_bt_dht_peers;
static int ett_bt_dht_nodes;
static int ett_bencoded_dict_entry;

static int ei_int_string;
static int ei_invalid_len;

static proto_t proto_bt_dht;

#define FT_STRING 1
#define FT_NONE 2
#define FT_BYTES 3
#define FT_IPv4 4
#define FT_IPv6 5
#define FT_UINT16 6
#define BASE_NONE 0
#define BASE_DEC 1
#define PI_MALFORMED 1
#define PI_ERROR 2
#define HFILL 0
#define EXPFILL 0

#define array_length(x) (sizeof(x)/sizeof(x[0]))

proto_t proto_register_protocol(const char *name, const char *short_name, const char *filter_name);
module_t *prefs_register_protocol(proto_t proto, void (*apply_cb)(void));
void prefs_register_obsolete_preference(module_t *module, const char *pref);
void proto_register_field_array(proto_t proto, hf_register_info *hf, int size);
void proto_register_subtree_array(gint *ett[], int size);
expert_module_t *expert_register_protocol(proto_t proto);
void expert_register_field_array(expert_module_t *expert, ei_register_info *ei, int size);