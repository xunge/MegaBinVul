#include <stdint.h>
#include <stdbool.h>

#define G_MAXUINT16 65535
#define ENC_NA 0
#define TRUE true
#define FALSE false

typedef uint32_t guint32;
typedef uint16_t guint16;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

extern int hf_reload_statans;
extern int hf_reload_length_uint32;
extern int ett_reload_statans;
extern expert_field ei_reload_truncated_field;

int dissect_kinddata(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint32 length, bool is_statans);
guint32 tvb_get_ntohl(tvbuff_t *tvb, guint16 offset);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int offset, int length, int encoding);
void expert_add_info_format(packet_info *pinfo, proto_item *item, expert_field *expert, const char *format, ...);
void proto_item_append_text(proto_item *item, const char *format, ...);
proto_tree* proto_item_add_subtree(proto_item *item, int ett);
void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int offset, int length, guint32 value);