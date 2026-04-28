#include <stdlib.h>
#include <stdint.h>

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;

static int num_items;
static int ett_nbap_HSDSCH_MACdFlows_to_Delete_Item;
static void* HSDSCH_MACdFlows_to_Delete_Item_sequence;

extern int dissect_per_sequence(tvbuff_t*, int, asn1_ctx_t*, proto_tree*, int, int, void*);

#define _U_ __attribute__((unused))