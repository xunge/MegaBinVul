#include <stdint.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef uint32_t guint32;

#define ENC_NA 0

typedef struct _BUFFER {
    void *tvb;
    void *item;
    void *tree;
} BUFFER;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct dcerpc_info {
    void *private_data;
    int conformant_run;
} dcerpc_info;
typedef struct proto_item proto_item;

extern int hf_buffer_size;
extern int hf_buffer_data;
extern int ett_BUFFER;
extern void *ei_buffer_size_too_long;

int dissect_ndr_uint32(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep, int hf, guint32 *size);
int dissect_ndr_uint8s(tvbuff_t *tvb, int offset, packet_info *pinfo, void *null, dcerpc_info *di, guint8 *drep, int hf, guint32 size, const guint8 **data);
guint32 tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
void expert_add_info(packet_info *pinfo, proto_tree *tree, void *ei);
proto_item *proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int size, int enc);
tvbuff_t *tvb_new_child_real_data(tvbuff_t *tvb, const guint8 *data, int length, int reported_length);
void add_new_data_source(packet_info *pinfo, tvbuff_t *tvb, const char *name);
proto_tree *proto_item_add_subtree(proto_item *item, int ett);