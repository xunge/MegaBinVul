#include <stdint.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef uint8_t guint8;
typedef int32_t gint32;
typedef uint32_t guint32;
typedef int32_t gint;
typedef char gchar;

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_item proto_item;
typedef struct nstime_t {
    time_t secs;
    long nsecs;
} nstime_t;
typedef struct expert_field expert_field;

extern int ett_headers;
extern int hf_wsp_header_shift_code;
extern int hf_wsp_header_text_value;
extern int hf_hdr_x_wap_tod;
extern int hf_hdr_name_string;
extern expert_field ei_wsp_header_invalid;
extern expert_field ei_wsp_text_field_invalid;
extern expert_field ei_hdr_x_wap_tod;
typedef int (*header_dissector_t)(proto_tree *, tvbuff_t *, gint32, packet_info *);
extern header_dissector_t WellKnownHeader[];
extern header_dissector_t WellKnownOpenwaveHeader[];

#define ENC_NA 0
#define ENC_ASCII 0
#define PROTO_ITEM_SET_HIDDEN(item) (void)0
#define wmem_packet_scope() NULL

gint32 tvb_reported_length(tvbuff_t *tvb);
guint8 tvb_get_guint8(tvbuff_t *tvb, gint32 offset);
gchar *tvb_get_stringz_enc(void *scope, tvbuff_t *tvb, gint32 offset, gint *length, int encoding);
proto_item *proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, gint32 offset, gint32 length, int encoding);
proto_tree *proto_item_add_subtree(proto_item *ti, int ett);
void expert_add_info(packet_info *pinfo, proto_item *ti, expert_field *ef);
proto_item *proto_tree_add_uint(proto_tree *tree, int hf, tvbuff_t *tvb, gint32 offset, gint32 length, guint32 value);
proto_item *proto_tree_add_string(proto_tree *tree, int hf, tvbuff_t *tvb, gint32 offset, gint32 length, const gchar *value);
proto_item *proto_tree_add_string_format(proto_tree *tree, int hf, tvbuff_t *tvb, gint32 offset, gint32 length, const gchar *value, const char *format, ...);
proto_item *proto_tree_add_time(proto_tree *tree, int hf, tvbuff_t *tvb, gint32 offset, gint32 length, nstime_t *value);
proto_item *proto_tree_add_time_format_value(proto_tree *tree, int hf, tvbuff_t *tvb, gint32 offset, gint32 length, nstime_t *value, const char *format);
proto_item *proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, gint32 offset, gint32 length, const char *format, ...);
int g_ascii_strcasecmp(const char *s1, const char *s2);
void get_delta_seconds_value(guint32 val, tvbuff_t *tvb, gint32 val_start, gint32 val_len, guint8 ok);