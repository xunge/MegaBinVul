#include <stdint.h>
#include <stdbool.h>

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct _frame_data {
    struct {
        bool visited;
    } flags;
} frame_data;

typedef struct _packet_info {
    frame_data *fd;
} packet_info;

typedef struct asn1_ctx {
    packet_info *pinfo;
} asn1_ctx_t;

static uint32_t MACdPDU_Size;
static int num_items;
static struct {
    uint32_t *edch_macd_pdu_size;
} nbap_edch_channel_info[1];

#define e_dch_macdflow_id 0
#define TRUE 1
#define _U_ __attribute__((unused))

extern int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, unsigned min, unsigned max, uint32_t *val, bool flag);