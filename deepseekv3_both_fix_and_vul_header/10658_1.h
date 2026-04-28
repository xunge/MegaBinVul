#include <stdint.h>

#define PN_IO_MAX_RECURSION_DEPTH 10

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef unsigned int guint;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct pnio_ar_t pnio_ar_t;
typedef struct expert_field expert_field;

extern expert_field ei_pn_io_max_recursion_depth_reached;

int dissect_block(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, guint16 *u16Index, guint32 *u32RecDataLen, pnio_ar_t **ar);
int dissect_RecordDataWrite(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, guint16 u16Index, guint32 u32RecDataLen);
int tvb_captured_length(tvbuff_t *tvb);
int tvb_captured_length_remaining(tvbuff_t *tvb, int offset);
tvbuff_t *tvb_new_subset_length(tvbuff_t *tvb, int offset, int length);