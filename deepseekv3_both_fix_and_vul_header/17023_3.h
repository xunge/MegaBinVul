#include <stdint.h>
#include <stdbool.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int32_t gint;
typedef bool gboolean;

#define FALSE false
#define TRUE true

typedef struct _tvbuff tvbuff_t;
typedef struct _packet_info packet_info;
typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;
typedef struct _col_item_t col_item_t;

typedef enum {
    FCTYPE_PACKET,
    FCTYPE_ATMPDU,
    FCTYPE_RESRVD,
    FCTYPE_MACSPC
} fctype_t;

typedef struct _packet_info {
    col_item_t *cinfo;
} packet_info;

typedef struct _col_item_t {
    int COL_PROTOCOL;
    int COL_INFO;
} col_item_t;

#define COL_PROTOCOL 0
#define COL_INFO 1

#define ENC_BIG_ENDIAN 0
#define ReportedBoundsError 1
#define _U_ __attribute__((unused))

extern int proto_docsis;
extern int ett_docsis;
extern int hf_docsis_fctype;
extern int hf_docsis_fcparm;
extern int hf_docsis_ehdron;
extern int hf_docsis_ehdrlen;
extern int hf_docsis_len;
extern int hf_docsis_hcs;
extern int hf_docsis_macparm;
extern int hf_docsis_machdr_fcparm;
extern int hf_docsis_mini_slots;
extern int hf_docsis_sid;
extern int hf_docsis_requested_size;
extern int hf_docsis_concat_cnt;
extern void* eth_withoutfcs_handle;
extern void* docsis_mgmt_handle;
extern void* docsis_handle;

guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset);
guint16 tvb_get_ntohs(tvbuff_t *tvb, gint offset);
gint tvb_captured_length_remaining(tvbuff_t *tvb, gint offset);
gint tvb_captured_length(tvbuff_t *tvb);
tvbuff_t *tvb_new_subset(tvbuff_t *tvb, gint offset, gint length, gint reported_length);
void col_set_str(col_item_t *cinfo, int column, const char *str);
void col_add_fstr(col_item_t *cinfo, int column, const char *format, ...);
proto_item *proto_tree_add_protocol_format(proto_tree *tree, int proto, tvbuff_t *tvb, gint start, gint length, const char *format);
proto_tree *proto_item_add_subtree(proto_item *ti, int ett);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);
void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, guint32 value);
void proto_item_append_text(proto_item *ti, const char *text);
void dissect_ehdr(tvbuff_t *tvb, proto_tree *tree, gboolean isfrag);
void call_dissector(void *handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);
void call_data_dissector(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);
void THROW(int error);