#include <stdlib.h>
#include <string.h>

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct _packet_info {
    struct _col_info* cinfo;
    int link_dir;
} packet_info;

typedef struct _col_info {
    char* info;
} col_info;

typedef struct asn1_ctx {
    packet_info* pinfo;
} asn1_ctx_t;

#define P2P_DIR_DL 0
#define COL_INFO 0

#define ett_nbap_RadioLinkReconfigurationCommit 0
#define _U_ __attribute__((unused))

extern int dissect_per_sequence(tvbuff_t*, int, asn1_ctx_t*, proto_tree*, int, int, void*);
extern void col_set_str(col_info*, int, const char*);

static const int RadioLinkReconfigurationCommit_sequence[] = {0};