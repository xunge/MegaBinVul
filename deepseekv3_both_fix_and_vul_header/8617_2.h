#include <stdint.h>
#include <stddef.h>

typedef int32_t gint32;
typedef uint8_t guint8;
typedef unsigned int guint;
typedef int gint;
typedef int gboolean;

#define FALSE 0
#define TRUE 1
#define ENC_NA 0
#define HDR_INVALID 0

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

static int hf_alljoyn_mess_body_parameters;
static int ett_alljoyn_mess_body_parameters;

extern gint parse_arg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint encoding, gint offset, proto_tree *subtree, gboolean little_endian, guint8 signature, int hdr_type, guint8 **signature_ptr, guint8 *signature_length_ptr, gint starting_offset);
extern gint tvb_reported_length(tvbuff_t *tvb);
extern proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);
extern proto_tree* proto_item_add_subtree(proto_item *item, int ett);