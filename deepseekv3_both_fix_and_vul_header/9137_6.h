#include <stdlib.h>
#include <string.h>

typedef struct tvbuff tvbuff_t;
typedef struct _col_info {
    char *COL_INFO;
} col_info_t;
typedef struct _packet_info {
    col_info_t *cinfo;
    int link_dir;
} packet_info_t;
typedef struct asn1_ctx {
    packet_info_t *pinfo;
} asn1_ctx_t;
typedef struct proto_tree proto_tree;

#define P2P_DIR_DL 0
#define ett_nbap_RadioLinkReconfigurationCommit 0
#define _U_
#define COL_INFO ""

extern void col_set_str(col_info_t *col_info, const char *str, const char *info);
extern int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, const void *sequence);

static const void *RadioLinkReconfigurationCommit_sequence;