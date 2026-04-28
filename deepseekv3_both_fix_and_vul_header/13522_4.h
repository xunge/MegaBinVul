#include <stdint.h>

#define PLC_TIMESTAMP_MB 0
#define PLC_ENERGY_MANAGEMENT_MB 1
#define PLC_MESSAGE_CHANNEL_MB 2
#define PLC_TRIGGER_MB 3

typedef uint8_t guint8;
typedef uint16_t guint16;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

extern int proto_plc;
extern int ett_plc;

struct cinfo_struct {
    char* info;
};

struct packet_info {
    struct cinfo_struct *cinfo;
};

enum {
    COL_INFO
};

void dissect_message_block(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 mb_type, guint16 mb_length);
proto_item* proto_tree_add_protocol_format(proto_tree *tree, int proto, tvbuff_t *tvb, int start, int length, const char *format);
proto_tree* proto_item_add_subtree(proto_item *item, int ett);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
tvbuff_t* tvb_new_subset_remaining(tvbuff_t *tvb, int offset);
int tvb_captured_length(tvbuff_t *tvb);
void col_append_str(struct cinfo_struct *col_info, int column, const char* str);

#define _U_ __attribute__((unused))