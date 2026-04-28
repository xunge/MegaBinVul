#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define MAX_BUF_LEN 256
#define DCM_EBE 0
#define TRUE true
#define FALSE false

typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint8;
typedef int32_t gint32;
typedef int16_t gint16;
typedef char gchar;
typedef bool gboolean;
typedef void* gpointer;
typedef float gfloat;
typedef double gdouble;

typedef struct {
    gchar *name;
} dcm_uid_t;

typedef struct {
    guint32 syntax;
    gboolean is_warning;
    gchar *comment;
    gchar *command;
    gchar *status;
    guint16 message_id;
    guint16 message_id_resp;
    guint16 no_remaining;
    guint16 no_completed;
    guint16 no_failed;
    guint16 no_warning;
} dcm_state_pdv_t;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

extern void *dcm_uid_table;
extern int hf_dcm_tag_value_str;
extern int hf_dcm_tag_value_byte;
extern int hf_dcm_tag_value_32u;
extern int hf_dcm_tag_value_32s;
extern int hf_dcm_tag_value_16u;
extern int hf_dcm_tag_value_16s;
extern expert_field ei_dcm_status_msg;

/* Function prototypes */
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
gchar* tvb_format_text(tvbuff_t *tvb, int offset, int length);
void* g_hash_table_lookup(void *table, gpointer key);
int g_snprintf(gchar *str, size_t size, const gchar *format, ...);
void proto_tree_add_string_format(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, const gchar *value, const gchar *format, ...);
gchar* wmem_strdup(void *scope, const gchar *str);
void* wmem_file_scope(void);
gchar* g_strstrip(gchar *str);
void proto_tree_add_bytes_format(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, const void *value, const gchar *format, ...);
guint16 tvb_get_letohs(tvbuff_t *tvb, int offset);
guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
proto_item* proto_tree_add_uint_format(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, guint32 value, const gchar *format, ...);
gchar* wmem_strdup_printf(void *scope, const gchar *format, ...);
void* wmem_packet_scope(void);
gfloat tvb_get_letohieee_float(tvbuff_t *tvb, int offset);
gfloat tvb_get_ntohieee_float(tvbuff_t *tvb, int offset);
gdouble tvb_get_letohieee_double(tvbuff_t *tvb, int offset);
gdouble tvb_get_ntohieee_double(tvbuff_t *tvb, int offset);
guint32 tvb_get_letohl(tvbuff_t *tvb, int offset);
guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset);
void proto_tree_add_int_format(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, gint32 value, const gchar *format, ...);
void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *ef);

const gchar* dcm_cmd2str(guint16 cmd);
const gchar* dcm_rsp2str(guint16 rsp);