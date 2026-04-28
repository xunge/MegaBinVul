#include <stdint.h>

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;

extern int ett_nbap_HSDSCH_Paging_System_InformationFDD;
extern int dissect_per_sequence(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, int ett, void *ptr);

static const int HSDSCH_Paging_System_InformationFDD_sequence[] = {0};

#define _U_