#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct tvbuff tvbuff_t;
typedef struct asn1_ctx asn1_ctx_t;
typedef struct proto_tree proto_tree;

typedef enum {
    ehs
} entity_type;

typedef struct {
    int crnc_port;
    entity_type entity;
} nbap_hsdsch_channel_info_t;

#define TRUE 1
#define _U_ 

extern nbap_hsdsch_channel_info_t nbap_hsdsch_channel_info[];
extern int hsdsch_macdflow_id;

int dissect_per_constrained_integer(tvbuff_t *tvb, int offset, asn1_ctx_t *actx, proto_tree *tree, int hf_index, 
                                   uint32_t lower, uint32_t upper, void *data, bool is_signed);