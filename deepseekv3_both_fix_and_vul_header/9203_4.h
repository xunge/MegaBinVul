#include <stdint.h>
#include <stdbool.h>

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;

#define FALSE false
#define TRUE true

extern int num_items;
extern int maxNrOfMACdFlows;
extern int ett_nbap_HSDSCH_MACdFlows_to_Delete;
extern int HSDSCH_MACdFlows_to_Delete_sequence_of;

int dissect_per_constrained_sequence_of(tvbuff_t *tvb, int offset, asn1_ctx_t *actx,
                                      proto_tree *tree, int hf_index, int ett,
                                      int sequence, int min_len, int max_len,
                                      bool has_extension);

#define _U_ __attribute__((unused))