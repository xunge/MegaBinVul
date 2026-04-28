#include <stdint.h>
#include <stdbool.h>

#define _U_ __attribute__((unused))
#define TRUE true
#define FALSE false

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx {
    struct _packet_info *pinfo;
} asn1_ctx_t;
typedef struct proto_tree proto_tree;
typedef struct _packet_info {
    struct {
        struct {
            unsigned visited;
        } flags;
    } *fd;
} packet_info;

typedef struct {
    int *edch_macd_pdu_size;
} nbap_edch_channel_info_t;

static int MACdPDU_Size;
static int num_items;
static int e_dch_macdflow_id;
static nbap_edch_channel_info_t *nbap_edch_channel_info;

extern int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, unsigned min, unsigned max, int *value, bool is_unsigned);