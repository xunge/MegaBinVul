#include <stdint.h>
#include <stddef.h>

typedef struct hf_register_info {
    void *field;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const void *strings;
        uint32_t bitmask;
        const char *blurb;
        int filler;
    } hfinfo;
} hf_register_info;

typedef int gint;

static int hf_mmse_message_type;
static int hf_mmse_transaction_id;
static int hf_mmse_mms_version;
static int hf_mmse_bcc;
static int hf_mmse_cc;
static int hf_mmse_content_location;
static int hf_mmse_date;
static int hf_mmse_delivery_report;
static int hf_mmse_delivery_time_abs;
static int hf_mmse_delivery_time_rel;
static int hf_mmse_expiry_abs;
static int hf_mmse_expiry_rel;
static int hf_mmse_from;
static int hf_mmse_message_class_id;
static int hf_mmse_message_class_str;
static int hf_mmse_message_id;
static int hf_mmse_message_size;
static int hf_mmse_priority;
static int hf_mmse_read_reply;
static int hf_mmse_read_report;
static int hf_mmse_report_allowed;
static int hf_mmse_response_status;
static int hf_mmse_response_text;
static int hf_mmse_sender_visibility;
static int hf_mmse_status;
static int hf_mmse_subject;
static int hf_mmse_to;
static int hf_mmse_ffheader;
static int hf_mmse_retrieve_status;
static int hf_mmse_retrieve_text;
static int hf_mmse_read_status;
static int hf_mmse_reply_charging;
static int hf_mmse_reply_charging_deadline_abs;
static int hf_mmse_reply_charging_deadline_rel;
static int hf_mmse_reply_charging_id;
static int hf_mmse_reply_charging_size;
static int hf_mmse_prev_sent_by;
static int hf_mmse_prev_sent_by_fwd_count;
static int hf_mmse_prev_sent_by_address;
static int hf_mmse_prev_sent_date;
static int hf_mmse_prev_sent_date_fwd_count;
static int hf_mmse_prev_sent_date_date;
static int hf_mmse_header_uint;
static int hf_mmse_header_string;
static int hf_mmse_header_bytes;

static gint ett_mmse;
static gint ett_mmse_hdr_details;

static int proto_mmse;

#define FT_UINT8 1
#define FT_STRING 2
#define FT_UINT32 3
#define FT_BYTES 4
#define FT_NONE 5
#define FT_ABSOLUTE_TIME 6
#define FT_RELATIVE_TIME 7

#define BASE_NONE 0
#define BASE_HEX 1
#define BASE_DEC 2

#define ABSOLUTE_TIME_LOCAL 0

#define VALS(x) NULL

#define HFILL 0

#define array_length(x) (sizeof(x)/sizeof(x[0]))

static void proto_register_field_array(int proto, hf_register_info *hf, int count);
static void proto_register_subtree_array(gint **ett, int count);
static int proto_register_protocol(const char *name, const char *short_name, const char *filter_name);