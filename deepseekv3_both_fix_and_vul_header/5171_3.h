#include <stdbool.h>

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;
typedef struct _packet_info {
    void *cinfo;
} packet_info_t;

struct asn1_ctx {
    packet_info_t *pinfo;
};

#define _U_
#define COL_INFO 0
#define ett_tcap_Begin 0

typedef enum {
    TC_BEGIN
} TCAP_OperationType;

typedef struct {
    TCAP_OperationType ope;
} gp_tcapsrt_info_t;

extern gp_tcapsrt_info_t *gp_tcapsrt_info;

typedef bool gboolean;

extern void *Begin_sequence;

void col_set_str(void *cinfo, int col, const char *str);
int dissect_ber_sequence(gboolean implicit_tag, asn1_ctx_t *actx, proto_tree *tree, tvbuff_t *tvb, int offset, void *sequence, int hf_index, int ett);