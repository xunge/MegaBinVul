#include <stdint.h>
#include <stddef.h>

typedef struct module_t module_t;
typedef struct expert_module_t expert_module_t;
typedef struct wmem_tree_t wmem_tree_t;

typedef struct {
    int* field;
    struct {
        const char* name;
        const char* abbrev;
        int type;
        int display;
        const void* strings;
        uint32_t bitmask;
        const char* blurb;
        int hfinfo;
    } info;
} hf_register_info;

typedef struct {
    int* expert_field;
    struct {
        const char* name;
        int severity;
        int group;
        const char* text;
        int expinfo;
    } info;
} ei_register_info;

#define FT_UINT16 1
#define FT_BOOLEAN 2
#define FT_FRAMENUM 3
#define FT_NONE 4
#define BASE_HEX 1
#define BASE_DEC 2
#define BASE_NONE 3
#define HFILL 0
#define PI_MALFORMED 1
#define PI_WARN 2
#define EXPFILL 0
#define VALS(x) ((const void*)(x))

typedef int gint;

static int proto_bthci_iso = -1;
static int hf_bthci_iso_chandle = -1;
static int hf_bthci_iso_pb_flag = -1;
static int hf_bthci_iso_ts_flag = -1;
static int hf_bthci_iso_reserved = -1;
static int hf_bthci_iso_continuation_to = -1;
static int hf_bthci_iso_reassembled_in = -1;
static int hf_bthci_iso_connect_in = -1;
static int hf_bthci_iso_disconnect_in = -1;
static int hf_bthci_iso_data_length = -1;
static int hf_bthci_iso_data = -1;
static int ett_bthci_iso = -1;
static int ei_length_bad = -1;
static int bthci_iso_handle = -1;
static int iso_reassembly = 0;
static wmem_tree_t *chandle_tree = NULL;

static const char* const iso_pb_flag_vals[] = {
    "Complete",
    "Continuation",
    "First",
    "Last",
    NULL
};

static void dissect_bthci_iso(void) {}
static int proto_register_protocol(const char*, const char*, const char*) { return 0; }
static int register_dissector(const char*, void (*)(void), int) { return 0; }
static void proto_register_field_array(int, hf_register_info*, int) {}
static void proto_register_subtree_array(int**, int) {}
static expert_module_t* expert_register_protocol(int) { return NULL; }
static void expert_register_field_array(expert_module_t*, ei_register_info*, int) {}
static module_t* prefs_register_protocol_subtree(const char*, int, void*) { return NULL; }
static void prefs_register_bool_preference(module_t*, const char*, const char*, const char*, int*) {}
static wmem_tree_t* wmem_tree_new_autoreset(void*, void*) { return NULL; }
static void* wmem_epan_scope(void) { return NULL; }
static void* wmem_file_scope(void) { return NULL; }
static int array_length(const void* a) { return 0; }