#include <stdlib.h>
#include <string.h>

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct _col_info {
    char* info;
} col_info;
typedef struct _packet_info {
    col_info* cinfo;
    int link_dir;
} packet_info;
typedef struct asn1_ctx {
    packet_info* pinfo;
} asn1_ctx_t;

#define P2P_DIR_DL 0
#define COL_INFO 0
#define _U_

#define ett_nbap_RadioLinkReconfigurationCommit 0

extern int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, const void *sequence);
extern void col_set_str(col_info *cinfo, int column, const char *str);

static const void* RadioLinkReconfigurationCommit_sequence;