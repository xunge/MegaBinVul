#include <stdlib.h>
#include <string.h>

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;

typedef struct _col_info {
    char *COL_INFO;
} col_info;

typedef struct _packet_info {
    col_info *cinfo;
    int link_dir;
} packet_info;

typedef struct asn1_ctx {
    packet_info *pinfo;
} asn1_ctx_t;

enum {
    P2P_DIR_DL,
    P2P_DIR_UL
};

#define ett_nbap_RadioLinkReconfigurationCommit 0
#define _U_ __attribute__((unused))
#define COL_INFO "COL_INFO"

static void col_set_str(col_info *cinfo, const char *col, const char *str);
static int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, const void *sequence);

extern const void *RadioLinkReconfigurationCommit_sequence;