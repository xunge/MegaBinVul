#include <stdint.h>
#include <stddef.h>

typedef int gint;

typedef struct _hf_register_info {
    int *id;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const void *strings;
        uint64_t bitmask;
        const char *blurb;
        int hfill;
    } info;
} hf_register_info;

typedef struct _expert_module_t {
    int dummy;
} expert_module_t;

typedef struct _ei_register_info {
    int *id;
    struct {
        const char *name;
        int severity;
        int summary;
        const char *description;
        int fill;
    } info;
} ei_register_info;

#define FT_NONE 0
#define FT_UINT8 1
#define FT_BOOLEAN 2
#define FT_STRING 3
#define FT_BYTES 4
#define FT_INT16 5
#define FT_UINT16 6
#define FT_INT32 7
#define FT_UINT32 8
#define FT_INT64 9
#define FT_UINT64 10
#define FT_DOUBLE 11
#define FT_IPv4 12
#define FT_IPv6 13

#define BASE_NONE 0
#define BASE_DEC 1
#define BASE_HEX 2
#define BASE_CUSTOM 3

#define PI_MALFORMED 0
#define PI_ERROR 1

#define HFILL 0
#define EXPFILL 0

#define WHOHAS_T 0x80
#define WHOHAS_U 0x40
#define WHOHAS_S 0x20
#define WHOHAS_F 0x10

#define ISAT_G 0x80
#define ISAT_C 0x40
#define ISAT_T 0x20
#define ISAT_U 0x10
#define ISAT_S 0x08
#define ISAT_F 0x04
#define ISAT_U6 0x02
#define ISAT_R6 0x01
#define ISAT_U4 0x80
#define ISAT_R4 0x40

#define TRANSPORT_LOCAL 0x0001
#define TRANSPORT_BLUETOOTH 0x0002
#define TRANSPORT_TCP 0x0004
#define TRANSPORT_WWAN 0x0008
#define TRANSPORT_LAN 0x0010
#define TRANSPORT_ICE 0x0020
#define TRANSPORT_WFD 0x0040

#define MESSAGE_HEADER_FLAG_NO_REPLY_EXPECTED 0x01
#define MESSAGE_HEADER_FLAG_NO_AUTO_START 0x02
#define MESSAGE_HEADER_FLAG_ALLOW_REMOTE_MSG 0x04
#define MESSAGE_HEADER_FLAG_SESSIONLESS 0x08
#define MESSAGE_HEADER_FLAG_GLOBAL_BROADCAST 0x10
#define MESSAGE_HEADER_FLAG_COMPRESSED 0x20
#define MESSAGE_HEADER_FLAG_ENCRYPTED 0x40

#define ARDP_SYN 0x01
#define ARDP_ACK 0x02
#define ARDP_EAK 0x04
#define ARDP_RST 0x08
#define ARDP_NUL 0x10
#define ARDP_UNUSED 0x20
#define ARDP_VER 0xC0

static int hf_alljoyn_ns_header;
static int hf_alljoyn_ns_sender_version;
static int hf_alljoyn_ns_message_version;
static int hf_alljoyn_ns_questions;
static int hf_alljoyn_ns_answers;
static int hf_alljoyn_ns_timer;
static int hf_alljoyn_ns_whohas;
static int hf_alljoyn_ns_whohas_t_flag;
static int hf_alljoyn_ns_whohas_u_flag;
static int hf_alljoyn_ns_whohas_s_flag;
static int hf_alljoyn_ns_whohas_f_flag;
static int hf_alljoyn_ns_whohas_count;
static int hf_alljoyn_answer;
static int hf_alljoyn_isat_entry;
static int hf_alljoyn_isat_guid_string;
static int hf_alljoyn_ns_isat_g_flag;
static int hf_alljoyn_ns_isat_c_flag;
static int hf_alljoyn_ns_isat_count;
static int hf_alljoyn_ns_isat_ipv6;
static int hf_alljoyn_ns_isat_ipv4;
static int hf_alljoyn_ns_isat_t_flag;
static int hf_alljoyn_ns_isat_u_flag;
static int hf_alljoyn_ns_isat_s_flag;
static int hf_alljoyn_ns_isat_f_flag;
static int hf_alljoyn_ns_isat_port;
static int hf_alljoyn_ns_isat_u6_flag;
static int hf_alljoyn_ns_isat_r6_flag;
static int hf_alljoyn_ns_isat_u4_flag;
static int hf_alljoyn_ns_isat_r4_flag;
static int hf_alljoyn_ns_isat_transport_mask;
static int hf_alljoyn_ns_isat_transport_mask_local;
static int hf_alljoyn_ns_isat_transport_mask_bluetooth;
static int hf_alljoyn_ns_isat_transport_mask_tcp;
static int hf_alljoyn_ns_isat_transport_mask_wwan;
static int hf_alljoyn_ns_isat_transport_mask_lan;
static int hf_alljoyn_ns_isat_transport_mask_ice;
static int hf_alljoyn_ns_isat_transport_mask_wfd;
static int hf_alljoyn_connect_byte_value;
static int hf_alljoyn_sasl_command;
static int hf_alljoyn_sasl_parameter;
static int hf_alljoyn_mess_header;
static int hf_alljoyn_mess_header_endian;
static int hf_alljoyn_mess_header_type;
static int hf_alljoyn_mess_header_flags;
static int hf_alljoyn_mess_header_flags_no_reply;
static int hf_alljoyn_mess_header_flags_no_auto_start;
static int hf_alljoyn_mess_header_flags_allow_remote_msg;
static int hf_alljoyn_mess_header_flags_sessionless;
static int hf_alljoyn_mess_header_flags_global_broadcast;
static int hf_alljoyn_mess_header_flags_compressed;
static int hf_alljoyn_mess_header_flags_encrypted;
static int hf_alljoyn_mess_header_majorversion;
static int hf_alljoyn_mess_header_body_length;
static int hf_alljoyn_mess_header_serial;
static int hf_alljoyn_mess_header_header_length;
static int hf_alljoyn_mess_header_fields;
static int hf_alljoyn_mess_header_field;
static int hf_alljoyn_mess_body_header_fieldcode;
static int hf_alljoyn_mess_body_header_typeid;
static int hf_alljoyn_mess_body_parameters;
static int hf_alljoyn_mess_body_array;
static int hf_alljoyn_mess_body_structure;
static int hf_alljoyn_mess_body_dictionary_entry;
static int hf_alljoyn_mess_body_variant;
static int hf_alljoyn_mess_body_signature_length;
static int hf_alljoyn_mess_body_signature;
static int hf_alljoyn_boolean;
static int hf_alljoyn_uint8;
static int hf_alljoyn_int16;
static int hf_alljoyn_uint16;
static int hf_alljoyn_handle;
static int hf_alljoyn_int32;
static int hf_alljoyn_uint32;
static int hf_alljoyn_int64;
static int hf_alljoyn_uint64;
static int hf_alljoyn_double;
static int hf_padding;
static int hf_alljoyn_string;
static int hf_alljoyn_string_size_8bit;
static int hf_alljoyn_string_size_32bit;
static int hf_alljoyn_string_data;
static int hf_ardp_syn_flag;
static int hf_ardp_ack_flag;
static int hf_ardp_eak_flag;
static int hf_ardp_rst_flag;
static int hf_ardp_nul_flag;
static int hf_ardp_unused_flag;
static int hf_ardp_version_field;
static int hf_ardp_hlen;
static int hf_ardp_src;
static int hf_ardp_dst;
static int hf_ardp_dlen;
static int hf_ardp_seq;
static int hf_ardp_ack;
static int hf_ardp_ttl;
static int hf_ardp_lcs;
static int hf_ardp_nsa;
static int hf_ardp_fss;
static int hf_ardp_fcnt;
static int hf_ardp_bmp;
static int hf_ardp_segmax;
static int hf_ardp_segbmax;
static int hf_ardp_dackt;
static int hf_ardp_options;

static int ett_alljoyn_ns;
static int ett_alljoyn_ns_header;
static int ett_alljoyn_ns_answers;
static int ett_alljoyn_ns_guid_string;
static int ett_alljoyn_ns_isat_entry;
static int ett_alljoyn_ns_string;
static int ett_alljoyn_whohas;
static int ett_alljoyn_string;
static int ett_alljoyn_isat_entry;
static int ett_alljoyn_mess;
static int ett_alljoyn_header;
static int ett_alljoyn_header_flags;
static int ett_alljoyn_mess_header_field;
static int ett_alljoyn_mess_header;
static int ett_alljoyn_mess_body_parameters;
static int ett_alljoyn_ardp;

static int ei_alljoyn_empty_arg;

static int proto_AllJoyn_ns;
static int proto_AllJoyn_mess;
static int proto_AllJoyn_ardp;

typedef struct {
    int value;
    const char *str;
} value_string;

static const value_string endian_encoding_vals[] = {
    {0, "Little Endian"},
    {1, "Big Endian"},
    {0, NULL}
};

static const value_string message_header_encoding_vals[] = {
    {0, "Invalid"},
    {1, "Method Call"},
    {2, "Method Reply"},
    {3, "Error"},
    {4, "Signal"},
    {0, NULL}
};

static const value_string mess_header_field_encoding_vals[] = {
    {0, "Invalid"},
    {1, "Path"},
    {2, "Interface"},
    {3, "Member"},
    {4, "Error Name"},
    {5, "Reply Serial"},
    {6, "Destination"},
    {7, "Sender"},
    {8, "Signature"},
    {0, NULL}
};

#define VALS(x) x
#define array_length(x) (sizeof(x)/sizeof(x[0]))

static int alljoyn_typeid(void) {
    return 0;
}
#define CF_FUNC(x) x