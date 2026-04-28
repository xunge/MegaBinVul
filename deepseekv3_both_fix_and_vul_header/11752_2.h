#include <stdint.h>
#include <string.h>
#include <time.h>

typedef uint8_t guint8;
typedef uint32_t guint;
typedef uint32_t guint32;
typedef int gint;
typedef int gboolean;
#define TRUE 1
#define FALSE 0

typedef struct tvbuff tvbuff_t;
typedef struct packet_info {
    guint num;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct nstime {
    time_t secs;
    unsigned nsecs;
} nstime_t;

#define ENC_NA 0
#define ENC_ASCII 0
#define ABSOLUTE_TIME_LOCAL 0
#define PDU_M_MBOX_DELETE_CONF 0
#define MM_CTYPE_HDR 0
#define MM_TID_HDR 1
#define MM_VERSION_HDR 2
#define MM_BCC_HDR 3
#define MM_CC_HDR 4
#define MM_CLOCATION_HDR 5
#define MM_DATE_HDR 6
#define MM_DREPORT_HDR 7
#define MM_DTIME_HDR 8
#define MM_EXPIRY_HDR 9
#define MM_FROM_HDR 10
#define MM_MCLASS_HDR 11
#define MM_MID_HDR 12
#define MM_MSIZE_HDR 13
#define MM_PRIORITY_HDR 14
#define MM_RREPLY_HDR 15
#define MM_RALLOWED_HDR 16
#define MM_RSTATUS_HDR 17
#define MM_RTEXT_HDR 18
#define MM_SVISIBILITY_HDR 19
#define MM_STATUS_HDR 20
#define MM_SUBJECT_HDR 21
#define MM_TO_HDR 22
#define MM_RETRIEVE_STATUS_HDR 23
#define MM_RETRIEVE_TEXT_HDR 24
#define MM_READ_STATUS_HDR 25
#define MM_REPLY_CHARGING_HDR 26
#define MM_REPLY_CHARGING_DEADLINE_HDR 27
#define MM_REPLY_CHARGING_ID_HDR 28
#define MM_REPLY_CHARGING_SIZE_HDR 29
#define MM_PREV_SENT_BY_HDR 30
#define MM_PREV_SENT_DATE_HDR 31

extern int proto_mmse;
extern int ett_mmse;
extern int ett_mmse_hdr_details;
extern int hf_mmse_message_type;
extern int hf_mmse_transaction_id;
extern int hf_mmse_mms_version;
extern int hf_mmse_bcc;
extern int hf_mmse_cc;
extern int hf_mmse_content_location;
extern int hf_mmse_date;
extern int hf_mmse_delivery_report;
extern int hf_mmse_delivery_time_abs;
extern int hf_mmse_delivery_time_rel;
extern int hf_mmse_expiry_abs;
extern int hf_mmse_expiry_rel;
extern int hf_mmse_from;
extern int hf_mmse_message_class_id;
extern int hf_mmse_message_class_str;
extern int hf_mmse_message_id;
extern int hf_mmse_message_size;
extern int hf_mmse_priority;
extern int hf_mmse_read_reply;
extern int hf_mmse_read_report;
extern int hf_mmse_report_allowed;
extern int hf_mmse_response_status;
extern int hf_mmse_response_text;
extern int hf_mmse_sender_visibility;
extern int hf_mmse_status;
extern int hf_mmse_subject;
extern int hf_mmse_to;
extern int hf_mmse_retrieve_status;
extern int hf_mmse_retrieve_text;
extern int hf_mmse_read_status;
extern int hf_mmse_reply_charging;
extern int hf_mmse_reply_charging_deadline_abs;
extern int hf_mmse_reply_charging_deadline_rel;
extern int hf_mmse_reply_charging_id;
extern int hf_mmse_reply_charging_size;
extern int hf_mmse_prev_sent_by;
extern int hf_mmse_prev_sent_by_fwd_count;
extern int hf_mmse_prev_sent_by_address;
extern int hf_mmse_prev_sent_date;
extern int hf_mmse_prev_sent_date_fwd_count;
extern int hf_mmse_prev_sent_date_date;
extern int hf_mmse_header_uint;
extern int hf_mmse_header_string;
extern int hf_mmse_header_bytes;
extern int hf_mmse_ffheader;
extern int ei_mmse_oversized_uintvar;

extern const char *vals_mm_header_names[];
extern const char *val_to_str(guint8 val, const char *const *array, const char *fmt);
extern void DebugLog(const char *fmt, ...);
extern guint tvb_reported_length(const tvbuff_t *tvb);
extern guint8 tvb_get_guint8(const tvbuff_t *tvb, guint offset);
extern guint tvb_get_guintvar(const tvbuff_t *tvb, guint offset, guint *length_len, packet_info *pinfo, int *ei);
extern char *tvb_get_string_enc(void *scope, const tvbuff_t *tvb, guint offset, guint length, int encoding);
extern tvbuff_t *tvb_new_subset_remaining(const tvbuff_t *tvb, guint offset);
extern guint get_text_string(const tvbuff_t *tvb, guint offset, const char **strval);
extern guint get_encoded_strval(const tvbuff_t *tvb, guint offset, const char **strval, packet_info *pinfo);
extern guint get_long_integer(const tvbuff_t *tvb, guint offset, guint *count);
extern guint get_value_length(const tvbuff_t *tvb, guint offset, guint *count, packet_info *pinfo);
extern guint32 get_integer_value(const tvbuff_t *tvb, guint offset, guint *count);
extern int pdu_has_content(guint8 pdut);
extern guint add_content_type(proto_tree *tree, packet_info *pinfo, const tvbuff_t *tvb, guint offset, guint *type, const char **type_str);
extern void add_post_data(proto_tree *tree, const tvbuff_t *tvb, guint type, const char *type_str, packet_info *pinfo);
extern proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, const tvbuff_t *tvb, gint start, gint length, int encoding);
extern void proto_item_append_text(proto_item *ti, const char *format, ...);
extern proto_tree *proto_item_add_subtree(proto_item *ti, int ett_subtree);
extern proto_item *proto_tree_add_uint(proto_tree *tree, int hfindex, const tvbuff_t *tvb, gint start, gint length, guint32 value);
extern proto_item *proto_tree_add_string(proto_tree *tree, int hfindex, const tvbuff_t *tvb, gint start, gint length, const char *value);
extern proto_item *proto_tree_add_time(proto_tree *tree, int hfindex, const tvbuff_t *tvb, gint start, gint length, const nstime_t *value);
extern proto_item *proto_tree_add_bytes_format(proto_tree *tree, int hfindex, const tvbuff_t *tvb, gint start, gint length, const void *value, const char *format, ...);
extern proto_item *proto_tree_add_string_format(proto_tree *tree, int hfindex, const tvbuff_t *tvb, gint start, gint length, const char *value, const char *format, ...);
extern proto_item *proto_tree_add_uint_format(proto_tree *tree, int hfindex, const tvbuff_t *tvb, gint start, gint length, guint32 value, const char *format, ...);
extern char *wmem_strdup_printf(void *scope, const char *format, ...);
extern void *wmem_packet_scope(void);
extern char *abs_time_to_str(void *scope, const nstime_t *abs_time, int type, gboolean show_zone);
extern char *format_text(void *scope, const char *str, size_t len);