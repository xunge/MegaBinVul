#include <stdint.h>

typedef struct header_field_info {
    const char *name;
    const char *abbrev;
    int type;
    int display;
    const void *strings;
    uint32_t bitmask;
    const char *blurb;
} header_field_info;

typedef struct gint {
    int value;
} gint;

typedef struct {
    int *id;
    struct {
        const char *name;
        int severity;
        int summary;
        const char *description;
        int filler;
    } ei;
} ei_register_info;

typedef struct module_t module_t;
typedef struct expert_module_t expert_module_t;

extern header_field_info hfi_vlan_priority;
extern header_field_info hfi_vlan_cfi;
extern header_field_info hfi_vlan_id;
extern header_field_info hfi_vlan_id_name;
extern header_field_info hfi_vlan_etype;
extern header_field_info hfi_vlan_len;
extern header_field_info hfi_vlan_trailer;
extern gint ett_vlan;
extern int ei_vlan_len;
extern int ei_vlan_too_many_tags;
extern int proto_vlan;
extern header_field_info* hfi_vlan;
extern int vlan_summary_in_tree;
extern uint32_t q_in_q_ethertype;
extern void* vlan_handle;

#define PI_MALFORMED 0
#define PI_ERROR 0
#define PI_UNDECODED 0
#define PI_WARN 0
#define EXPFILL 0

#define HAVE_HFI_SECTION_INIT 0

static header_field_info *hfi[] = {
    &hfi_vlan_priority,
    &hfi_vlan_cfi,
    &hfi_vlan_id,
    &hfi_vlan_id_name,
    &hfi_vlan_etype,
    &hfi_vlan_len,
    &hfi_vlan_trailer,
};

int proto_register_protocol(const char *name, const char *short_name, const char *filter_name);
header_field_info* proto_registrar_get_nth(int proto);
void proto_register_fields(int proto, header_field_info** hfi, int length);
void proto_register_subtree_array(gint** ett, int length);
expert_module_t* expert_register_protocol(int proto);
void expert_register_field_array(expert_module_t* expert, ei_register_info* ei, int length);
module_t* prefs_register_protocol(int proto, void (*reg_handoff)(void));
void prefs_register_bool_preference(module_t* module, const char* name, const char* title, const char* description, int* var);
void prefs_register_uint_preference(module_t* module, const char* name, const char* title, const char* description, int base, uint32_t* var);
void* create_dissector_handle(void (*dissector)(void), int proto);
void dissect_vlan(void);
void proto_reg_handoff_vlan(void);

#define array_length(arr) (sizeof(arr)/sizeof(arr[0]))