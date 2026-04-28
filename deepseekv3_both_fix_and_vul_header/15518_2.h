#include <stdint.h>
#include <stddef.h>

typedef uint32_t guint32;
typedef int32_t gint32;
typedef unsigned int guint;
typedef int gint;
typedef char gchar;
typedef int gboolean;
#define FALSE 0
#define TRUE 1

#define COL_INFO 0
#define ENC_BIG_ENDIAN 0

typedef struct {
    guint32 extended_bootstrap_address[4];
} gvcp_conv_info_t;

typedef struct {
    void *addr_list;
} gvcp_transaction_t;

typedef struct {
    void *cinfo;
    void *pool;
} packet_info;

typedef struct proto_tree proto_tree;
typedef struct tvbuff tvbuff_t;
typedef struct _wmem_array_t wmem_array_t;

#define GVCP_MAX_STREAM_CHANNEL_COUNT 4
#define GVCP_SC_EXTENDED_BOOTSTRAP_ADDRESS(ch) (0x00000000 + (ch)*4)

extern int ett_gvcp_payload_ack;
extern int hf_gvcp_readregcmd_extended_bootstrap_register;
extern int hf_gvcp_readregcmd_bootstrap_register;
extern int hf_gvcp_custom_read_register_addr;
extern int hf_gvcp_custom_read_register_value;
extern int hf_gvcp_custom_register_value;

const gchar* get_register_name_from_address(guint32 address, void* pool, gvcp_conv_info_t* gvcp_info, gboolean* is_custom_register);
gboolean is_extended_bootstrap_address(gvcp_conv_info_t* gvcp_info, guint32 address, guint32* offset);
void dissect_extended_bootstrap_register(guint32 address, proto_tree* tree, tvbuff_t* tvb, gint offset, gint length);
void dissect_register(guint32 address, proto_tree* tree, tvbuff_t* tvb, gint offset, gint length);
guint wmem_array_get_count(wmem_array_t *array);
void* wmem_array_index(wmem_array_t *array, guint index);
guint32 tvb_get_ntohl(tvbuff_t *tvb, gint offset);
void col_append_fstr(void *cinfo, int col, const char *fmt, ...);
void col_append_str(void *cinfo, int col, const char *str);
proto_tree* proto_tree_add_subtree(proto_tree *parent, tvbuff_t *tvb, gint start, gint length, int idx, void *null, const char *text);
void proto_tree_add_uint_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, guint32 value, const char *format, ...);
void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, guint32 value);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);