#include <stdint.h>
#include <stddef.h>

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;

typedef struct dcerpc_info {
    int conformant_run;
} dcerpc_info;

typedef uint8_t guint8;
typedef uint32_t guint32;

#define hf_keybuffer_size 0
#define hf_keybuffer 0

static int dissect_ndr_uint32(tvbuff_t *tvb, int offset, packet_info *pinfo,
                             proto_tree *tree, dcerpc_info *di, guint8 *drep,
                             int hf_index, guint32 *size);

static int dissect_spoolss_uint16uni(tvbuff_t *tvb, int offset, packet_info *pinfo,
                                   proto_tree *tree, guint8 *drep, void *data,
                                   int hf_index);

static int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);