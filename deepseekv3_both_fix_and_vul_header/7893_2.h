#include <stdint.h>
#include <stddef.h>

#define S7COMM_UD_SUBF_CPU_ALARM8_IND    0x01
#define S7COMM_UD_SUBF_CPU_ALARMACK_IND  0x02
#define S7COMM_UD_SUBF_CPU_ALARMSQ_IND   0x03
#define S7COMM_UD_SUBF_CPU_ALARMS_IND    0x04
#define S7COMM_UD_SUBF_CPU_NOTIFY_IND    0x05
#define S7COMM_UD_SUBF_CPU_NOTIFY8_IND   0x06

#define S7COMM_UD_TYPE_REQ   0x01
#define S7COMM_UD_TYPE_RES   0x02
#define S7COMM_UD_TYPE_PUSH  0x03

#define S7COMM_SYNTAXID_ALARM_LOCKFREESET   0x01
#define S7COMM_SYNTAXID_ALARM_INDSET        0x02
#define S7COMM_SYNTAXID_NOTIFY_INDSET       0x03
#define S7COMM_SYNTAXID_ALARM_ACKSET        0x04
#define S7COMM_SYNTAXID_ALARM_QUERYREQSET   0x05

#define S7COMM_ALARM_MESSAGE_QUERYTYPE_BYALARMTYPE 0x01
#define S7COMM_ALARM_MESSAGE_QUERYTYPE_BYEVENTID   0x02

#define ENC_NA 0
#define ENC_BIG_ENDIAN 1
#define TRUE 1
#define FALSE 0
#define COL_INFO 0

typedef uint32_t guint32;
typedef uint8_t guint8;
typedef int32_t gint32;
typedef int gint;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info {
    struct {
        int cinfo;
    } *cinfo;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

extern int hf_s7comm_cpu_alarm_message_item;
extern int hf_s7comm_cpu_alarm_message_timestamp_coming;
extern int hf_s7comm_cpu_alarm_message_function;
extern int hf_s7comm_cpu_alarm_message_nr_objects;
extern int hf_s7comm_cpu_alarm_message_obj_item;
extern int hf_s7comm_item_varspec;
extern int hf_s7comm_item_varspec_length;
extern int hf_s7comm_item_syntax_id;
extern int hf_s7comm_cpu_alarm_message_nr_add_values;
extern int hf_s7comm_cpu_alarm_message_eventid;
extern int hf_s7comm_cpu_alarm_message_eventstate;
extern int hf_s7comm_cpu_alarm_message_state;
extern int hf_s7comm_cpu_alarm_message_ackstate_going;
extern int hf_s7comm_cpu_alarm_message_ackstate_coming;
extern int hf_s7comm_cpu_alarm_message_event_going;
extern int hf_s7comm_cpu_alarm_message_event_coming;
extern int hf_s7comm_cpu_alarm_message_event_lastchanged;
extern int hf_s7comm_cpu_alarm_message_event_reserved;
extern int hf_s7comm_cpu_alarm_message_associated_value;
extern int hf_s7comm_cpu_alarm_query_unknown1;
extern int hf_s7comm_cpu_alarm_query_querytype;
extern int hf_s7comm_cpu_alarm_query_unknown2;
extern int hf_s7comm_cpu_alarm_query_alarmtype;
extern int hf_s7comm_data_returncode;

extern int ett_s7comm_cpu_alarm_message;
extern int ett_s7comm_cpu_alarm_message_timestamp;
extern int ett_s7comm_cpu_alarm_message_object;
extern int ett_s7comm_cpu_alarm_message_signal;
extern int ett_s7comm_cpu_alarm_message_associated_value;

extern const char *val_to_str(guint32 val, const void *vs, const char *fmt);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, guint32 offset);
extern guint32 tvb_get_ntohl(tvbuff_t *tvb, guint32 offset);
extern proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, gint length, int encoding);
extern proto_tree *proto_item_add_subtree(proto_item *pi, int tree_type);
extern void proto_item_append_text(proto_item *pi, const char *format, ...);
extern void proto_item_set_len(proto_item *pi, gint length);
extern proto_item *proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, gint length, guint32 value);
extern proto_item *proto_tree_add_bitmask(proto_tree *tree, tvbuff_t *tvb, guint32 offset, int hf_hdr, int ett, const int *fields, int encoding);
extern void col_append_fstr(packet_info *pinfo, int col, const char *format, ...);

extern guint32 s7comm_add_timestamp_to_tree(tvbuff_t *tvb, proto_tree *tree, guint32 offset, int show_date, int show_time);
extern guint32 s7comm_decode_response_read_data(tvbuff_t *tvb, proto_tree *tree, guint8 nr_values, guint32 offset);

extern const void *alarm_message_query_alarmtype_names;
extern const void *s7comm_item_return_valuenames;
extern const int *s7comm_cpu_alarm_message_signal_fields;