#include <stdint.h>
#include <string.h>

typedef uint32_t guint32;
typedef int32_t gint32;
typedef uint16_t guint16;
typedef int16_t gint16;
typedef uint8_t guint8;
typedef int gint;
typedef int gboolean;
#define FALSE 0
#define TRUE 1
typedef char gchar;

#define ENC_NA 0
#define ENC_LITTLE_ENDIAN 1
#define ENC_BIG_ENDIAN 2

#define COL_PROTOCOL 0
#define COL_INFO 1

typedef struct {
    guint32 mq_strucID;
    guint32 mq_convID;
    guint32 mq_rqstID;
    gint32 mq_int_enc;
    guint8 mq_opcode;
    guint8 mq_ctlf1;
} mq_parm_t;

typedef struct _packet_info {
    guint32 srcport;
    guint32 destport;
    guint32 num;
    void *cinfo;
} packet_info;

typedef struct _tvbuff {
    // tvbuff structure members
} tvbuff_t;

typedef struct _proto_tree {
    // proto_tree structure members
} proto_tree;

typedef struct _proto_item {
    // proto_item structure members
} proto_item;

typedef struct _fragment_head {
    // fragment_head structure members
    guint32 reassembled_in;
    tvbuff_t *tvb_data;
    struct _fragment_head *next;
} fragment_head;

#define MQ_MASK_TSHx 0xFFFF0000
#define MQ_STRUCTID_TSHx 0x544D0000
#define MQ_STRUCTID_TSHx_EBCDIC 0xE3D4C800
#define MQ_STRUCTID_TSHM 0x544D4800
#define MQ_STRUCTID_TSHM_EBCDIC 0xE3D4C8C8
#define MQ_LITTLE_ENDIAN 0
#define MQ_TCF_FIRST 0x01
#define MQ_TCF_LAST 0x02
#define MQ_TST_ASYNC_MESSAGE 0x00

static gboolean mq_reassembly = FALSE;
static gboolean mq_in_reassembly = FALSE;
static void *mq_reassembly_table = NULL;
static void *proto_mq = NULL;
static void *ett_mq_reaasemb = NULL;
static void *ei_mq_reassembly_error = NULL;
static void *opcode = NULL;

static guint32 tvb_get_ntohl(tvbuff_t *tvb, gint offset);
static guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset);
static guint16 tvb_get_guint16(tvbuff_t *tvb, gint offset, gint encoding);
static guint32 tvb_get_guint32(tvbuff_t *tvb, gint offset, gint encoding);
static gint tvb_reported_length(tvbuff_t *tvb);
static void dissect_mq_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);
static void dissect_mq_addCR_colinfo(packet_info *pinfo, mq_parm_t *mq_parm);
static gint dissect_mq_md(tvbuff_t *tvb, proto_tree *tree, gint offset, mq_parm_t *mq_parm, gboolean is_request);
static fragment_head *fragment_add_seq_next(void *reassembly_table, tvbuff_t *tvb, gint offset, packet_info *pinfo, guint32 id, void *data, guint32 frag_data_len, gboolean more_frags);
static void add_new_data_source(packet_info *pinfo, tvbuff_t *tvb, const gchar *name);
static void col_set_str(void *cinfo, gint column, const gchar *str);
static void col_add_fstr(void *cinfo, gint column, const gchar *format, ...);
static void col_append_str(void *cinfo, gint column, const gchar *str);
static proto_item *proto_tree_add_item(proto_tree *tree, void *proto, tvbuff_t *tvb, gint start, gint length, gint encoding);
static void proto_item_append_text(proto_item *item, const gchar *format, ...);
static proto_tree *proto_item_add_subtree(proto_item *item, void *ett);
static const gchar *val_to_str_ext(guint8 value, void *extptr, const gchar *default_str);
static void expert_add_info_format(packet_info *pinfo, proto_item *item, void *expert, const gchar *format, ...);
static tvbuff_t *tvb_new_chain(tvbuff_t *tvb1, tvbuff_t *tvb2);

#define _U_ __attribute__((unused))
#define GET_VALS_EXTP(x) ((void*)0)