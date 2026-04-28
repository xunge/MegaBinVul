#include <stdint.h>
#include <stdlib.h>

typedef int gint;

typedef struct _hf_register_info {
    int *p_id;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const void *strings;
        uint32_t bitmask;
        const void *blurb;
        int hfinfo;
    } hf_hdr;
} hf_register_info;

typedef struct _ei_register_info {
    int *p_id;
    struct {
        const char *name;
        int severity;
        int summary;
        const char *description;
        int hf_hdr;
    } ei_hdr;
} ei_register_info;

typedef struct {
    const char *true_string;
    const char *false_string;
} true_false_string;

typedef struct {
    unsigned int value;
    const char *strptr;
} value_string;

static int hf_bacapp_type;
static int hf_bacapp_pduflags;
static int hf_bacapp_SEG;
static int hf_bacapp_MOR;
static int hf_bacapp_SA;
static int hf_bacapp_max_adpu_size;
static int hf_bacapp_response_segments;
static int hf_bacapp_objectType;
static int hf_bacapp_instanceNumber;
static int hf_BACnetPropertyIdentifier;
static int hf_BACnetVendorIdentifier;
static int hf_BACnetRestartReason;
static int hf_bacapp_invoke_id;
static int hf_bacapp_sequence_number;
static int hf_bacapp_window_size;
static int hf_bacapp_service;
static int hf_bacapp_uservice;
static int hf_bacapp_NAK;
static int hf_bacapp_SRV;
static int hf_Device_Instance_Range_Low_Limit;
static int hf_Device_Instance_Range_High_Limit;
static int hf_BACnetRejectReason;
static int hf_BACnetAbortReason;
static int hf_BACnetApplicationTagNumber;
static int hf_BACnetContextTagNumber;
static int hf_BACnetExtendedTagNumber;
static int hf_BACnetNamedTag;
static int hf_BACnetCharacterSet;
static int hf_BACnetCodePage;
static int hf_BACnetTagClass;
static int hf_bacapp_tag_lvt;
static int hf_bacapp_tag_ProcessId;
static int hf_bacapp_tag_IPV4;
static int hf_bacapp_tag_IPV6;
static int hf_bacapp_tag_PORT;
static int hf_bacapp_tag_mac_address_broadcast;
static int hf_bacapp_reserved_ashrea;
static int hf_bacapp_unused_bits;
static int hf_bacapp_bit;
static int hf_bacapp_complete_bitstring;
static int hf_msg_fragments;
static int hf_msg_fragment;
static int hf_msg_fragment_overlap;
static int hf_msg_fragment_overlap_conflicts;
static int hf_msg_fragment_multiple_tails;
static int hf_msg_fragment_too_long_fragment;
static int hf_msg_fragment_error;
static int hf_msg_fragment_count;
static int hf_msg_reassembled_in;
static int hf_msg_reassembled_length;

static gint ett_bacapp;
static gint ett_bacapp_control;
static gint ett_bacapp_tag;
static gint ett_bacapp_list;
static gint ett_bacapp_value;
static gint ett_msg_fragment;
static gint ett_msg_fragments;

static int ei_bacapp_bad_length;
static int ei_bacapp_bad_tag;
static int ei_bacapp_opening_tag;
static int ei_bacapp_max_recursion_depth_reached;

static true_false_string segments_follow;
static true_false_string more_follow;
static true_false_string segmented_accept;
static true_false_string BACnetTagClass;

static const value_string BACnetTypeName[];
static const value_string BACnetMaxAPDULengthAccepted[];
static const value_string BACnetMaxSegmentsAccepted[];
static const value_string BACnetObjectType[];
static const value_string BACnetPropertyIdentifier[];
static const value_string BACnetVendorIdentifiers_ext[];
static const value_string BACnetRestartReason[];
static const value_string BACnetConfirmedServiceChoice[];
static const value_string BACnetUnconfirmedServiceChoice[];
static const value_string BACnetRejectReason[];
static const value_string BACnetAbortReason[];
static const value_string BACnetApplicationTagNumber[];
static const value_string BACnetTagNames[];
static const value_string BACnetCharacterSet[];

static int proto_bacapp;
static void *bacapp_dissector_table;
static void *msg_reassembly_table;
static void *bacapp_tap;
static void *addresses_reassembly_table_functions;
static void *dissect_bacapp;

typedef struct _expert_module_t {
    int dummy;
} expert_module_t;

#define FT_UINT8 1
#define FT_UINT16 2
#define FT_UINT32 3
#define FT_BOOLEAN 4
#define FT_BYTES 5
#define FT_NONE 6
#define FT_FRAMENUM 7
#define FT_IPv4 8
#define FT_IPv6 9

#define BASE_DEC 1
#define BASE_HEX 2
#define BASE_NONE 3
#define BASE_EXT_STRING 4

#define PI_MALFORMED 1
#define PI_ERROR 2
#define PI_PROTOCOL 3
#define PI_WARN 4

#define HFILL 0
#define EXPFILL 0

#define VALS(x) (x)
#define TFS(x) (x)

#define array_length(x) (sizeof(x)/sizeof(x[0]))

static int proto_register_protocol(const char *name, const char *short_name, const char *filter_name) { return 0; }
static void proto_register_field_array(int proto, hf_register_info *hf, int size) {}
static void proto_register_subtree_array(gint *ett, int size) {}
static expert_module_t* expert_register_protocol(int proto) { return NULL; }
static void expert_register_field_array(expert_module_t *expert, ei_register_info *ei, int size) {}
static void* register_dissector(const char *name, void *func, int proto) { return NULL; }
static void reassembly_table_register(void **table, void **funcs) {}
static void* register_dissector_table(const char *name, const char *ui_name, int proto, int type, int base) { return NULL; }
static void register_bacapp_stat_trees(void) {}
static void* register_tap(const char *name) { return NULL; }